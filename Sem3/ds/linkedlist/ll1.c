#include <stdio.h>
#include <stdlib.h>

// LinkedList with Global Head and Insert from front and delete from front

struct Node {
  int data;
  struct Node *link;
};

struct Node *head;

void Insert(int data) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;

  if (head == NULL) {
    head = temp;
    temp->link = NULL;
    return;
  } else {
    temp->link = head;
    head = temp;
  }
}

void Print() {
  printf("LinkedList is : ");
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp = head;
  while (temp != NULL) {
    printf("%d \t ", temp->data);
    temp = temp->link;
  }
  printf("\n");
}

void Delete() {
  struct Node *temp = head;
  if (head == NULL) {
    printf("Cannot Delete, LinkedList empty\n");
    return;
  }
  head = head->link;
  free(temp);
}

int main(int argc, char *argv[]) {
  head = NULL; // empty linked list
  Insert(1);
  Insert(2);
  Insert(3);
  Insert(4);
  Print();
  Delete();
  Print();

  return 0;
}
