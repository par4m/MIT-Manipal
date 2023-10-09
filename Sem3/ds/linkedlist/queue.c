#include "stdio.h"
#include "stdlib.h"

// stack ->
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
void Delete() { // delete front
  struct Node *temp = head;
  if (head == NULL) {
    printf("Cannot Delete, LinkedList empty\n");
    return;
  }
  head = head->link;
  free(temp);
}

int main(int argc, char *argv[]) {

  head = NULL;
  return 0;
}
