#include <stdio.h>
#include <malloc.h>
#include "llfifo.h"

int test_llfifo_enqueue(llfifo_t *fifo)
{
  int totallength, currentcapacity;
  int currentlength;
  char str[] = "sleepy";
  char str1[] = "sad";
  char str2[] = "maitreyee";
  char str3[] = "cold";
  char str4[] = "boulder";
  currentcapacity = llfifo_capacity(fifo);
 // printf("\n Current Capacity %d", currentcapacity);
  currentlength = llfifo_enqueue(fifo, str);
  currentlength = llfifo_enqueue(fifo, str1);
  currentlength = llfifo_enqueue(fifo, str2);
  currentlength = llfifo_enqueue(fifo, str3);
  currentlength = llfifo_enqueue(fifo, str4);

 	//check if the capacity initalised is less than elements enqued and test if the enque lets add more nodes
  if (currentcapacity < currentlength)
  {

    currentcapacity = llfifo_capacity(fifo);
    totallength = llfifo_length(fifo);
    //printf("\n total length is %d", totallength);
    //printf("\n Capacity after enqueue %d", currentcapacity);
    if (currentcapacity == totallength)
      return 0;
  }

  if ((currentlength != -1))	// check if list is not empty &first element entered is same as first enqueued
    return 0;

  else
    return -1;

}

int test_fifo()
{

  int capacity[] = { -1, 2, 4, 20, 5, 3, 1, 0 };
  int totallength, currentcapacity, length;
  int test_success = 0;
  int test1;
  llfifo_t * list1;

  for (int i = 0; i < 7; i++)
  {

    list1 = llfifo_create(capacity[i]);
    currentcapacity = llfifo_capacity(list1);
    if (currentcapacity == capacity[i])
    {
      printf("\nPassed for capacity %d", capacity[i]);
    }

    test1 = test_llfifo_enqueue(list1);

    if ((test1 == 0))
      test_success++;
  }

  printf("test success %d", test_success);

  return (0);
}

int test_dequeue()
{
  int totallength, currentcapacity, length;
  int test_success = 0;
  llfifo_t * list1;
  void *el, *t, *p;
  char str[] = "sleepy";
  char str1[] = "run";
  char str2[] = "bat";
  length = 10;
  list1 = llfifo_create(length);
  llfifo_enqueue(list1, str);
  llfifo_enqueue(list1, str1);
  llfifo_enqueue(list1, str2);
  totallength = llfifo_length(list1);

  currentcapacity = llfifo_capacity(list1);

  el = llfifo_dequeue(list1);
  t = llfifo_dequeue(list1);
  p = llfifo_dequeue(list1);
 	//check order of dequeue
  if ((el == str) && (t == str1) && (p == str2))
  {
    currentcapacity = llfifo_capacity(list1);
    if (currentcapacity == length)	//check if capcity hasnt shrunk
     { 
        test_success++;
      }   

   }
   printf("test success %d", test_success);

llfifo_destroy(list1);
return (test_success);
}
