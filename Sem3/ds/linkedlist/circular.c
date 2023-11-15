#include "stdio.h"
#include "stdlib.h"

struct Node {
  int data;
  struct Node *link;
};

struct Node *head;

void insertEnd(int data) {
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->link = head;
  struct Node *temp1 = head;
  if (head == NULL) {
    head = temp;
    head->link = head;
    return;
  }
  while (temp1->link != head) {
    temp1 = temp1->link;
  }
  temp1->link = temp;
}

void InsertFront(int data) {
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->link = head;
  struct Node *temp1 = head;
  if (head == NULL) {
    head = temp;
    head->link = head;
    return;
  }
  while (temp1->link != head) {
    temp1 = temp1->link;
  }
  temp1->link = temp;
  head = temp;
}

void InsertN(int n, int data) {
  // insert front if first node
  if (n == 1) {
    InsertFront(data);
    return;
  }
  struct Node *temp3 = head;
  for (int i = 0; i < n - 1; i++) {
    temp3 = temp3->link;
  }

  // Check if temp3 is the lat node then insert at end if it is
  if (temp3->link == head) {
    insertEnd(data);
    return;
  }
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->link = temp3->link;
  temp3->link = temp;
}

void deleteFront() { head = head->link; }

void deleteEnd() {
  struct Node *temp = head;
  while (temp->link->link != head) {
    temp = temp->link;
  }
  temp->link = head;
}

void deleteN(int n) {
  struct Node *temp1 = head;
  struct Node *temp2 = head;
  if (n == 1) {
    deleteFront();
  }
  for (int i = 0; i < n - 2; i++) {
    temp1 = temp1->link;
  }
  for (int i = 0; i < n - 1; i++) {

    temp2 = temp2->link;
  }
  if (temp2->link == head) {
    deleteEnd();
  } else {
    temp1->link = temp2->link;
  }
}

void display() {
  struct Node *temp = head;
  printf("%d", temp->data);
  temp = temp->link;
  while (temp != head) {
    printf("%d", temp->data);
    temp = temp->link;
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  head = NULL;
  insertEnd(1);
  insertEnd(2);
  insertEnd(3);
  insertEnd(4);
  display();
  InsertFront(3);
  display();
  InsertN(3, 3);
  display();
  deleteFront();
  display();
  deleteEnd();
  display();
  deleteN(2);
  display();

  return 0;
}
