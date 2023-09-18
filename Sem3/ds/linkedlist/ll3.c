#include <stdio.h>
#include <stdlib.h>

// Global Head; Insert at N'th and Delete a N'th position
//
//

struct Node {

  int data;
  struct Node *link;
};

struct Node *head;

// Insert at N'th position
void Insert(int data, int n) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  if (n == 1) { // will work even when the head is empty
    temp->link = head;
    head = temp;
    return;
  } // go to n-1 th node

  struct Node *temp1 = head;
  for (int i = 0; i < n - 2; i++) { // 0 to n - 1 : n ; 0 to n - 2 ; n - 1 th
    temp1 = temp1->link;            // n - 1 th node
  }
  temp->link = temp1->link;
  temp1->link = temp;
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

void Delete(int n) {
  if (head == NULL) {
    printf("LL EMpty \n");
    return;
  }
  struct Node *temp1 = head;
  struct Node *temp2 = head;

  if (n == 1) {
    head = temp1->link;
    free(temp1);
    return;
  } else {
    // joing (n-1).link to nth.link. free nth
    for (int i = 0; i < n - 1; i++) { // go till nth node
      temp1 = temp1->link;
    }
    for (int i = 0; i < n - 2; i++) { // go till n - 1 th node
      temp2 = temp2->link;
    }
    temp2->link = temp1->link;
    free(temp1);
  }
}

int main() {
  head = NULL;
  Insert(3, 1);
  Insert(4, 2);
  Insert(5, 3);
  Insert(2, 3);
  Insert(6, 1);
  Display();
  Delete(1);
  Delete(2);
  Delete(3);
  Display();

  return 0;
}
