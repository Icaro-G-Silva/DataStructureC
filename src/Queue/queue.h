/*NOT DYNAMIC QUEUE. STATIC INT ARRAY USED.*/
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

int isQueueFull(int tail, int MAX_SIZE);
int isQueueEmpty(int tail);
int dequeue(int *queue, int *tail);
int enqueue(int *queue, int value, int *tail, int MAX_SIZE);
void printQueue(int *queue, int tail);

int isQueueEmpty(int tail) {
  return (tail < 0) ? 1 : 0;
}

int isQueueFull(int tail, int MAX_SIZE) {
  return (tail >= MAX_SIZE) ? 1 : 0;
}

int enqueue(int *queue, int value, int *tail, int MAX_SIZE) {
  if(!isQueueFull(*tail, MAX_SIZE)) {
    *tail += 1;
    queue[*tail] = value;
    return 1;
  }
  else {
    fprintf(stderr, "Queue's Full!");
    return 0;
  }
}

int dequeue(int *queue, int *tail) {
  if(!isQueueEmpty(*tail)) {
    int firstValue = queue[0];

    for(int i = 0; i <= *tail; i++) {
      if((i + 1) <= *tail) {
        queue[i] = queue[i+1];
      }
    }
    
    *tail -= 1;
    return firstValue;
  }
  else {
    fprintf(stderr, "Queue's Empty!");
    return NULL;
  }
}

void printQueue(int *queue, int tail) {
  if(!isQueueEmpty(tail)) {
    printf("[");
    for(int i = 0; i <= tail; i++) {
      (i >= tail)
      ? printf("%d", queue[i])
      : printf("%d, ", queue[i]);
    }
    printf("]");
  }
  else {
    fprintf(stderr, "Queue's Empty!");
  }
}

#endif
