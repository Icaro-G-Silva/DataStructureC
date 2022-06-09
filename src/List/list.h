#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#define FIRST_INDEX 1

typedef struct {
  int index;
  int value;
  struct Node *next;
} Node;

void add(Node **head, int value);
int delete(Node **head, int index);
void printList(Node *head);

void add(Node **head, int value) {
  Node *node, *newNode;
  if(*head == NULL) {
    //CREATES HEAD
    *head = (Node *) malloc(sizeof(Node));
    (*head)->index = FIRST_INDEX;
    (*head)->value = value;
    (*head)->next = NULL;
  }
  else {
    node = *head;
    while(node->next != NULL) {
      node = node->next;
    }

    newNode = (Node *) malloc(sizeof(Node));
    newNode->index = node->index + 1;
    newNode->value = value;
    newNode->next = NULL;
    node->next = newNode;
  }
}

void rearrangeIndexes(Node **head) {
  if(*head == NULL) {
    fprintf(stderr, "Cannot rearrange empty list!\n");
    return;
  }

  Node *lastNode, *node = *head, *nextNode;
  int index = FIRST_INDEX;

  do {
    node->index = index++;
    nextNode = node->next;
    lastNode = node;
    node = nextNode;
  } while(node != NULL);
}

int delete(Node **head, int index) {
  if(index <= 0) {
    fprintf(stderr, "Index cannot be negative or zero!\n");
    return 0;
  }
  if(*head == NULL) {
    fprintf(stderr, "List is Empty!\n");
    return 0;
  }

  Node *lastNode, *node = *head, *nextNode;

  while(node->index != index) {
    lastNode = node;
    node = node->next;

    if(node == NULL) {
      fprintf(stderr, "Index out of bounds!\n");
      return 0;
    }
  }
  nextNode = node->next;

  if(nextNode != NULL && index == FIRST_INDEX) {
    *head = nextNode;
  }
  if(nextNode != NULL && index != FIRST_INDEX) {
    lastNode->next = nextNode;
  }
  if(nextNode == NULL && index != FIRST_INDEX) {
    lastNode->next = NULL;
  }

  int valueRemoved = node->value;
  node = NULL;

  rearrangeIndexes(head);

  return valueRemoved;
}

void printList(Node *node) {
  int i = 0;
  while(node != NULL) {
    printf("\nElement %d\nOn index %d\nvalue: %d\n", ++i, node->index, node->value);
    node = node->next;
  }
}

#endif
