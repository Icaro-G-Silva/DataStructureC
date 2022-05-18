#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "list.h"

#ifdef __unix__ 
#elif defined(_WIN32) || defined(WIN32) 
  #define OS_Windows 
#endif

void clearScreen();
int getOption();

void main() {
  Node *head = NULL;
  
  int removedValue;
  int value;
  int option;
  while(1) {
    clearScreen();
    fflush(stdin);
    option = getOption();
    switch(option) {
      case 1:
        //add in List
        printf("Value to add: ");
        scanf("%d", &value);
        add(&head, value);
        break;
      case 2:
        //remove from List
        printf("Index to remove: ");
        scanf("%d", &value);
        removedValue = delete(&head, value);
        if(removedValue) printf("Value removed: %d", removedValue);
        getch();
        break;
      case 3:
        //print List
        printList(head);
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
  printf("1) Add in List\n2) Remove from List\n3) Print List\n0) Exit\n\n>> ");
  scanf("%d", &tmp);
  return tmp;
}
