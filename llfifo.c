/*
 * llfifo.c - llfifo implementation
 * 
 * Author: Maitreyee Rao
 *
 *code inspiration : Howdy Pierce, howdy.pierce@colorado.edu
 * 
 */


#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include "llfifo.h"


typedef struct llfifo_node_s 
{
  struct llfifo_node_s *next;
  void *data;
} llfifo_node_t;


 
struct llfifo_s
{
  
  int length;
  int capacity;
   llfifo_node_t * head;
   llfifo_node_t * tail;
   llfifo_node_t * unused;
  
};
/*
*
*function to create nodes for the linked list
*
*/
static llfifo_node_t *new_node(llfifo_node_t *next)
{

 llfifo_node_t *new = (llfifo_node_t *)malloc(sizeof(llfifo_node_t));
 if(new ==NULL)
   return NULL;

  new->next = (llfifo_node_t *)next;
  new->data =NULL;
  return new;
 
}

/*
*
*function to create the linked list
*
*/

llfifo_t* llfifo_create(int capacity)
{
  assert(capacity >= 0);
  llfifo_t *fifo = NULL;
   // create head node;
   
   fifo=(llfifo_t*)malloc(sizeof(llfifo_t));
    if(fifo == NULL)
       return NULL;
    fifo->capacity=capacity;
    fifo->length = 0;
    
    fifo->head= NULL; //initialize head  to NULL
    fifo->tail= NULL; //initialize tail  to NULL
    fifo->unused = NULL; //initialize unused  to NULL

    //create all rest nodes
    for(int i=0;i<capacity;i++)
    {
     fifo->unused = new_node(fifo->unused);
    if(fifo->unused == NULL)
      return NULL;
    }
  return fifo;

}

int llfifo_enqueue(llfifo_t *fifo, void *element)
{
   
  assert(fifo);
  llfifo_node_t *temp;
  llfifo_node_t *el = fifo->unused;
  if(el)  // check if unused linked list is full?             
  {
    fifo->unused = el->next; //if not full decrement unused pointer to point the next element thats not empty
   }
   else                      // if unused list is full, then create new node
   {

     el=new_node(fifo->head); // create new node in new list
     if(el==NULL)         
     return -1;
     fifo->capacity++;  //increase the capacity
   }
   el->next = NULL;    
   el->data = element;
    temp=fifo->tail;
    if(fifo->tail)     //check if already element in new list
     {
       temp->next=el;   //enqueue element at the tail
       fifo->tail= temp;
     }
    fifo->tail=el;      //enqueue element at the tail
    if(!fifo->head)     //if no element 
    fifo->head = el;    
  return ++fifo->length;
}

void *llfifo_dequeue(llfifo_t *fifo)
{
  assert(fifo);
  llfifo_node_t *element = fifo->head; 
       if(element==NULL)       //check if no element is present
     return NULL;


   fifo->head=element->next;    
   element->next = fifo->unused; // dequeue element at the head

   if(fifo->head == NULL)
      fifo->tail=NULL;      //if head is null no elements present set tail to null    
   fifo->unused=element;         
   fifo->length--;

   return element->data;

       
}

int llfifo_capacity(llfifo_t *fifo)
{
  assert(fifo);
 
  return (fifo->capacity);

}

int llfifo_length(llfifo_t *fifo)
{
  assert(fifo);
   
  return (fifo->length);
}


void llfifo_destroy(llfifo_t *fifo)
{
  
  assert(fifo);
  llfifo_node_t *element;
  int num;
   while(fifo->head!=NULL)    //destroy the lists
   {
       element=fifo->head;
       fifo->head=element->next;
       free(element);
       num++;
   }

      while(fifo->unused!=NULL) //destroy both lists
   {
       element=fifo->unused;
       fifo->unused=element->next;
       free(element);
       num++;
   }
 
} 


