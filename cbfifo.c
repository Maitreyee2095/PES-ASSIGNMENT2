#include <stdio.h>
#include <stdlib.h>
#include"cbfifo.h"

int read = -1;
int write = -1;

char Buffer[12];
int buffersize = sizeof(Buffer);
int isempty();
int isfull();

// to check if buffer is empty
int isempty()
{
  if (read == -1 && write == -1)
    return 1;
  else
    return 0;
}
// to check if buffer is full
int isfull()
{
  if (((write + 1) % buffersize) == read)
    return 1;
  else
    return 0;
}
/* *****************************************************************************/
size_t cbfifo_enqueue(void *buf, size_t nbyte)
{
  size_t mbyte = 0;
  char *ptr = (char*) buf;
 	//queue is full
  if (isfull())
    return -1;

 	//update read when inserting first element 
  if (read == -1)
    read = 0;
 	//insert element at rear
  if (nbyte < buffersize)	//check if size of bytes required are less than buffersize

  {
   	// keep on inserting bytes till required bytes are enqued
    while (mbyte != nbyte)
    {
     	// increment write pointer by 1;
      write = (write + 1) % buffersize;
     	//check if buffer is full 
      if (isfull())
      {
        break;
      }

      if(ptr == NULL)
      {
       break;
      }
      Buffer[write] = *ptr;
      mbyte = mbyte + sizeof(Buffer[write]);
      ptr++;
    }
    if(mbyte<=buffersize)
       return (mbyte);
    else
       return (-1);
  }
  return -1;
}
/* *****************************************************************************/
size_t cbfifo_dequeue(void *buf, size_t nbyte)
{
  size_t mbyte = 0;
  char *ptr = (char*) buf;
 	// check if buffer is empty
  if (isempty())
    return (-1);

 	//check if required bytes are less than capacity
  if (nbyte < buffersize)
  {

   	//keep on deleting till the reuired bytes are dequequed
    while (mbyte != nbyte)
    {
     	// dequque from the first element *ptr = Buffer[read];
     	//increment read to next;
      read = (read + 1) % buffersize;
      mbyte = mbyte + (sizeof(Buffer[read]));

      if (isempty())
        break;
      ptr++;
    }
    return (mbyte);
  }
 	//if required bytes and  grater than buffersize
  else if (nbyte >= buffersize)
  {
   	//deque all the element in buffer
    while (mbyte != buffersize)
    {
      *ptr = Buffer[read];
      read = (read + 1) % buffersize;
      mbyte = mbyte + (sizeof(Buffer[read]));

      if (isempty())
        break;
      ptr++;
      }
     //int read= -1;
     //int write =-1;
    return (mbyte);
  }
  else
    return -1;
}
/* ******************************************************************************/
size_t cbfifo_length()
{
  size_t total_length = 0;

  if (isfull())
    return (buffersize);

  if (isempty())
    return (0);

 	//traverse through buffer to find its length
  for (int i = read; i <= write; i++)
  {
    if (isfull())
      return (buffersize);
    total_length += ((sizeof(Buffer[i])));
  }

  if (total_length > buffersize)
    return (-1);

  return total_length;
}
/* * *******************************************************************************/
size_t cbfifo_capacity()
{
  return (buffersize);
}
int main()
{
  int success;
  success = test_cbfifo();
  if (success >0)
   return 0;
}
