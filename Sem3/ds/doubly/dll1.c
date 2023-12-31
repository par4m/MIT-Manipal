#include "stdio.h"
#include "stdlib.h"

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *head;

void InsertAtHead(int data) {
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;
  temp->prev = NULL;
  if (head == NULL) {
    head = temp;
    return;
  }
  head->prev = temp; // point prev of current head to newNode
  temp->next = head; // point next of newNode to head
  head = temp;
}

void InsertEnd(int data) {
  struct Node *temp = malloc(sizeof(struct Node));
  struct Node *temp1 = head;
  temp->data = data;
  temp->next = NULL;
  temp->prev = NULL;
  // go to last, point prev of new to it
  while (temp1->next != NULL) {
    temp1 = temp1->next;
  }
  temp->prev = temp1;
  temp1->next = temp;
}

void display() {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void ReversePrint() {
  printf("Printing in Reverse\n");
  struct Node *temp = head;
  // go to last element
  while (temp->next != NULL) {
    temp = temp->next;
  }
  // print in reverse
  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->prev;
  }
  printf("\n");
}

void InsertN(int n, int data) {
  if (n == 1) {
    InsertAtHead(data);
    return;
  }

  // check if inserting at end
  struct Node *temp = head;
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;

  for (int i = 0; i < n - 1; i++) {
    temp = temp->next;
  }
  if (temp->next == NULL) {
    InsertEnd(data);
    return;
  } else {
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
  }
}

void deleteFront() {
  head = head->next;
  head->prev = NULL;
}

void deleteEnd() {
  struct Node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  temp->next = NULL;
}

void deleteN(int n) {
  struct Node *temp1 = head;
  struct Node *temp2 = head;

  if (n == 1) {
    deleteFront();
    return;
  }

  for (int i = 0; i < n - 2; i++) {
    temp1 = temp1->next;
  }
  for (int i = 0; i < n - 1; i++) {
    temp2 = temp2->next;
  }
  if (temp2->next == NULL) {
    deleteEnd();
    return;
  } else {
    temp2->next->prev = temp1;
    temp1->next = temp2->next;
  }
}

int main(int argc, char *argv[]) {
  head = NULL;
  InsertAtHead(1);
  display();
  InsertAtHead(2);
  display();
  InsertAtHead(3);
  display();
  ReversePrint();
  InsertEnd(4);
  display();
  ReversePrint();
  InsertN(1, 4);
  display();
  InsertN(3, 3);
  display();
  deleteN(2);
  display();
  deleteFront();
  display();
  deleteEnd();
  display();

  return 0;
}
