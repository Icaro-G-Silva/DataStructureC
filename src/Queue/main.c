#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "queue.h"

#ifdef __unix__ 
#elif defined(_WIN32) || defined(WIN32) 
  #define OS_Windows 
#endif

#define MAX_SIZE 4 //5 Positions

void clearScreen();
int getOption();

void main() {
  int queue[MAX_SIZE];
  int tail = -1;
  
  int dequeued;
  int value;
  int option;
  while(1) {
    clearScreen();
    option = getOption();
    switch(option) {
      case 1:
        //Enqueue
        printf("Value to enqueue: ");
        scanf("%d", &value);
        if(!enqueue(queue, value, &tail, MAX_SIZE)) getch();
        break;
      case 2:
        //Dequeue
        dequeued = dequeue(queue, &tail);
        if(dequeued) {
          printf("Dequeued value %d from the queue", dequeued);
        }
        getch();
        break;
      case 3:
        //printQueue
        printQueue(queue, tail);
        getch();
        break;
      case 0:
        exit(0);
        break;
      default:
        printf("Unknown option. Try again.");
        getch();
    }
  }
}

void clearScreen() {
  #ifdef OS_Windows
    system("cls");
  #else
    system("clear");
  #endif  
}

int getOption() {
  int tmp;
  printf("1) Enqueue\n2) Dequeue\n3) Print Queue\n0) Exit\n\n>> ");
  scanf("%d", &tmp);
  return tmp;
}
