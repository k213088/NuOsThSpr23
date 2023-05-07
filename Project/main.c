#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
// We will use banker's algorithm to avoid deadlock.
// Bankers algorithm in Operating System is used to avoid deadlock and for resource allocation safely to each process in the system.

//  Some global variables
int i=0, j=0, ind=0, numProcess=0, numResources=0;
int **alloc, **max, **need, *avail, *safeSequecne;

// First we need queue and stack to push process in wait queue or ready queue
struct queue{
  int front;
  int rear;
  int *data;
  int itemcount;
}waiting_queue,reay_queue

void push(struct queue *q1, int num){
    if(q1->itemCount != num_process)
    {
      if(q1->itemCount == 0)
      {
        q1->data = (int) calloc(num_process, sizeof(int));
        q1->front = 0;
        q1->rear = -1;
      }
      q1->rear++;
      q1->data[q1->rear] = num;
      q1->itemcount++;
    }
}

int pop(struct queue *q1)
{
  int temp = 0;
  if(q1->itemCount != 0)
  {
      temp = q1->data[q1->front++];
      q1->itemCount--;
  }
  return temp;
}


void main{ // main will just call the function so no return type
  
  
}
