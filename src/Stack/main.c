#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stack.h"

#ifdef __unix__ 
#elif defined(_WIN32) || defined(WIN32) 
  #define OS_Windows 
#endif

#define MAX_SIZE 4 //5 Positions

void clearScreen();
int getOption();

void main() {
  int stack[MAX_SIZE];
  int top = -1;
  
  int stackedOut;
  int value;
  int option;
  while(1) {
    clearScreen();
    option = getOption();
    switch(option) {
      case 1:
        //stackIn
        printf("Value to stack: ");
        scanf("%d", &value);
        if(!stackIn(stack, value, &top, MAX_SIZE)) getch();
        break;
      case 2:
        //stackOut
        stackedOut = stackOut(stack, &top);
        if(stackedOut) {
          printf("Value %d has been stacked out from the stack", stackedOut);
        }
        getch();
        break;
      case 3:
        //printStack
        printStack(stack, top);
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
  printf("1) Stack In\n2) Stack Out\n3) Print Stack\n0) Exit\n\n>> ");
  scanf("%d", &tmp);
  return tmp;
}
