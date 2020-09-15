#include <stdio.h>
#include <stdlib.h>
#include"cbfifo.h"
#include "llfifo.h"

int main()
{
  int success,success1,test;

  success = test_cbfifo();
  if (success >0)
   return 0;
  success1=test_fifo();
  test = test_dequeue();
  if((success1 > 0)&& test>0) 	
      return 0;
  else
   return -1;
 
 return 0;

}
