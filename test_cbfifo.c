#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"cbfifo.h"

int test_enqueue_dequeue();
int test_dequeue();

int test_enqueue_dequeue()
{
  size_t test[20];
  char str[] = "universityofcoloradoboulder";
  char buff[126] = { 1, 2, 3, 4, 5, 6, 7 };
  int buff1[500] = { 2, -2, 30, 40, 60, 700 };
  int buff2[20] = { 0x30, 0x40, 0xffff, 0x0000
  };
  int test_enqueue_success = 0;
  size_t len;
 	//enqueue 10 bytes data
  test[0] = cbfifo_enqueue(str, 10);
  test[1] = cbfifo_enqueue(buff, 0);
        //check enqued bytes
  //printf("\n enqued byte %lu",test[1]);
 	//dequeue 10 bytes data
  test[2] = cbfifo_dequeue(buff, 10);

 	//check if current length has become 0;
  len = cbfifo_length();
  //printf("\n length is %lu", len);
  if (len == 0)
    test_enqueue_success++;

  test[3] = cbfifo_enqueue(buff, 30);
  test[4] = cbfifo_enqueue(buff1, 15);
  test[5] = cbfifo_dequeue(buff, 10);
 	//length check
  len = cbfifo_length();
 // printf("\n length is %lu", len);

  test[6] = cbfifo_enqueue(buff1, -10);
  test[7] = cbfifo_enqueue(buff2, 20);
  test[8] = cbfifo_enqueue(str, 0);
  test[9] = cbfifo_enqueue(str, 40);
  test[10] = cbfifo_enqueue(buff, 5);

  test[11] = cbfifo_enqueue(buff2, 100);
  test[12] = cbfifo_dequeue(buff, 156);
  len = cbfifo_length();
  if (len == 0)
    test_enqueue_success++;
  //printf("\n length is %lu", len);

  test[13] = cbfifo_enqueue(buff, 5);
  test[14] = cbfifo_dequeue(buff, 10);

  test[15] = cbfifo_enqueue(buff, 100);
  for (int i = 0; i < 9; i++)
  {
    if (test[i] > 0)
    {
      test_enqueue_success++;
    }
  }

  return (test_enqueue_success);

}

int test_cbfifo()
{
  int current_length, total_capacity;
  int test_passed;
  test_passed = test_enqueue_dequeue();

  //printf("\n No of tests passed  %d", test_passed);
  current_length = cbfifo_length();
  //printf("\n %d", current_length);
  total_capacity = cbfifo_capacity();
  //printf("\n %d", total_capacity);

  return (0);

}
