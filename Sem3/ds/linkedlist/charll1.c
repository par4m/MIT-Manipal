#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LinkedList with Global Head and Insert from front and delete from front

struct Node {
  char name[50];
  struct Node *link;
};

struct Node *head;

void Insert(char *arr) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  strcpy(temp->name, arr);
  // temp->name = arr;

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
    printf("%s \t ", temp->name);
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
  Insert("param");
  Insert("arora");
  Insert("is");
  Insert("here");
  Print();
  Delete();
  Print();

  return 0;
}
