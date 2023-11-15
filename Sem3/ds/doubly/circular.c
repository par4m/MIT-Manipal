#include "stdio.h"
#include "stdlib.h"

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *head;

void InsertEnd(int data) {
  struct Node *temp = malloc(sizeof(struct Node));
  struct Node *temp1 = head;
  temp->data = data;
  temp->next = NULL;
  temp->prev = NULL;
  if (head == NULL) {
    head = temp;
    head->next = head;
    head->prev = head;
    return;
  }

  // go to last, point prev of new to it
  while (temp1->next != head) {
    temp1 = temp1->next;
  }
  temp1->next = temp;
  temp->prev = temp1;
  temp->next = head;
  head->prev = temp;
}

void InsertAtHead(int data) {
  struct Node *temp = malloc(sizeof(struct Node));
  struct Node *temp1 = head;
  temp->data = data;
  temp->next = NULL;
  temp->prev = NULL;
  if (head == NULL) {
    head = temp;
    head->next = head;
    head->prev = head;
    return;
  }

  // go to last, point prev of new to it
  while (temp1->next != head) {
    temp1 = temp1->next;
  }
  temp1->next = temp;
  temp->prev = temp1;
  temp->next = head;
  head->prev = temp;

  head = temp;
}

void display() {
  struct Node *temp = head;
  printf("%d", temp->data);
  temp = temp->next;
  while (temp != head) {
    printf("%d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void displayRev() {
  struct Node *temp = head;
  temp = temp->prev;
  while (temp != head) {
    printf("%d", temp->data);
    temp = temp->prev;
  }
  printf("%d", head->data);
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

void deleteFront() { head = head->next; }

void deleteEnd() {
  struct Node *temp = head;
  while (temp->next->next != head) {
    temp = temp->next;
  }
  temp->next = head;
  head->prev = temp;
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
  InsertEnd(1);
  InsertEnd(2);
  display();
  InsertAtHead(3);
  display();
  displayRev();
  InsertN(2, 4);
  display();
  deleteFront();
  display();
  displayRev();
  return 0;
}
