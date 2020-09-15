#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "llfifo.h"
typedef struct llfifo_s
{
  void *data;
  struct llfifo_s * next;
}
llfifo_t;


llfifo_t* llfifo_create(int capacity)
{
  llfifo_t *CNode, *Head, *TNode;
  Head = NULL;

  for (int i = 0; i < capacity; i++)
  {
    CNode = (llfifo_t*) malloc(sizeof(llfifo_t));	//Create new node
    CNode->next = NULL;
    if (Head == NULL)	//check if headnode is present
    {
      Head = CNode;
      Head->data = NULL;
    }
    else
    {
      TNode->next = CNode;
      TNode->data = NULL;
    }

    TNode = CNode;
  }

  if (capacity > 0)
    return Head;

  else
    return (NULL);
}

int llfifo_enqueue(llfifo_t *fifo, void *element)
{
  if (fifo == NULL)
    return (-1);
  int counter = 0;
  while (fifo->data != NULL)	// check if the linked list capacity is full
  {
    if (fifo->next == NULL)	// check if the node is empty
    {
      counter++;
      break;
    }
    counter++;
    fifo = fifo->next;
  }

  if (fifo->data == NULL)	// check if the node is empty
  {
    fifo->data = element;	//insert element in node
    counter++;
    return (counter);
  }

  if (fifo->next == NULL)	//check if the node is last node i.e capacity is full
  {
    llfifo_t *p = (llfifo_t*) malloc(sizeof(llfifo_t));
    p->data = element;	//create node to enque new element
    p->next = NULL;
    fifo->next = p;
    fifo = p;
    counter++;
    return counter;
  }

  if (counter > 0)
    return (counter);
  else
    return (-1);
}

void *llfifo_dequeue(llfifo_t *fifo)
{
 	//if(fifo == NULL || fifo->data == NULL)
 	// return NULL;
  void *el;
  el = fifo->data; //dequeue 1 element from linked list

  while (fifo->next->next != NULL)
  {
  	
    fifo->data = (fifo->next)->data;
   	//copy the next element to the previous dequeued space

   	// (fifo->next)->data = NULL;
    fifo = fifo->next;
  }
                
  
  

  return (el);
}

int llfifo_capacity(llfifo_t *fifo)
{
  int capacity = 0;
 	//if (fifo == NULL)
 	//return(-1);

  while (fifo != NULL)
  {
    capacity++;
    fifo = fifo->next;
  }

  return (capacity);

}

int llfifo_length(llfifo_t *fifo)
{
 	//if(fifo->data == NULL)
 	// return (-1);

  int capacity = 0;
  while (fifo != NULL)
  {
    if (fifo->data != NULL)
    {
      capacity++;
    }

    fifo = fifo->next;
  }

  return (capacity);
}


void llfifo_destroy(llfifo_t *fifo)
{

  while (fifo != NULL)
  {
    llfifo_t *temp = fifo;
    fifo = fifo->next;
    free(temp);
  }
}

int main()
{
 int success,test;
  success=test_fifo();
  test = test_dequeue();
  if((success > 0)&& test>0) 	
      return 0;
  else
   return -1;

}