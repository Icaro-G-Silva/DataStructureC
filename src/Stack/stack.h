/*NOT DYNAMIC STACK. STATIC INT ARRAY USED.*/
#ifndef STACK_H
#define STACK_H

#include <stdio.h>

int isStackFull(int top, int MAX_SIZE);
int isStackEmpty(int top);
int stackOut(int *stack, int *top);
int stackIn(int *stack, int value, int *top, int MAX_SIZE);
void printStack(int *stack, int top);

int isStackEmpty(int top) {
  return (top < 0) ? 1 : 0;
}

int isStackFull(int top, int MAX_SIZE) {
  return (top >= MAX_SIZE) ? 1 : 0;
}

int stackIn(int *stack, int value, int *top, int MAX_SIZE) {
  if(!isStackFull(*top, MAX_SIZE)) {
    *top += 1;
    stack[*top] = value;
    return 1;
  }
  else {
    fprintf(stderr, "Stack's Full!");
    return 0;
  }
}

int stackOut(int *stack, int *top) {
  if(!isStackEmpty(*top)) {
    *top -= 1;
    return stack[*top+1];
  }
  else {
    fprintf(stderr, "Stack's Empty!");
    return NULL;
  }
}

void printStack(int *stack, int top) {
  if(!isStackEmpty(top)) {
    printf("[");
    for(int i = 0; i <= top; i++) {
      (i >= top)
      ? printf("%d", stack[i])
      : printf("%d, ", stack[i]);
    }
    printf("]");
  }
  else {
    fprintf(stderr, "Stack's Empty!");
  }
}

#endif
