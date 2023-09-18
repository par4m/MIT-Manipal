
#include <stdio.h>
#include <stdlib.h>

// LinkedList with Global Head and Insert from rear and delete from rear

struct Node {
  int data;
  struct Node *link;
};

struct Node *head;

void Insert(int data) { // Insert Rear
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->link = NULL;

  if (head == NULL) {
    head = temp;
  } else {
    struct Node *temp1 = head;
    while (temp1->link != NULL) {
      temp1 = temp1->link;
    }
    temp1->link = temp;
  }
}

void Delete() {
  struct Node *temp = head;
  while (temp->link->link != NULL) {
    temp = temp->link;
  }
  struct Node *temp1 = temp->link;
  temp->link = NULL;
  free(temp1);
}

void Display() {
  printf("LinkedList is : ");
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d \t", temp->data);
    temp = temp->link;
  }
  printf("\n");
}

int main() {
  head = NULL;
  Insert(2);
  Insert(3);
  Insert(4);
  Display();
  Delete();
  Display();

  return 0;
}
