#include <stdio.h>
#include <stdlib.h>

struct Node {

  int coeff;
  int exp;
  struct Node *link;
};

struct Node *a; // poly 1
struct Node *b; // poly b
struct Node *c; // poly c

void Insert(struct Node **head, int coeff, int exp) { // Insert Rear
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->coeff = coeff;
  temp->exp = exp;
  temp->link = NULL;

  if (*head == NULL) {
    *head = temp;
  } else {
    struct Node *temp1 = *head;
    while (temp1->link != NULL) {
      temp1 = temp1->link;
    }
    temp1->link = temp;
  }
}

int main(int argc, char *argv[]) {
  a = NULL;
  b = NULL;
  c = NULL;

  // Example: 3x^2 + 2x + 1
  Insert(&a, 3, 2);
  Insert(&a, 2, 1);
  Insert(&a, 1, 0);

  // Example: 4x^3 + 2x^2 + 5
  Insert(&b, 4, 3);
  Insert(&b, 2, 2);
  Insert(&b, 5, 0);

  while (a != NULL || b != NULL) {
    if (a == NULL) {
      Insert(&c, b->coeff, b->exp);
      b = b->link;
    } else if (b == NULL) {
      Insert(&c, a->coeff, a->exp);
      a = a->link;
    }
    if (a->exp == b->exp) {
      int x = a->coeff + b->coeff;
      // add to c
      Insert(&c, x, a->exp);
      a = a->link;
      b = b->link;

    } else if (a->exp > b->exp) {
      Insert(&c, a->coeff, a->exp);
      a = a->link;
    } else {
      // b greater than a
      Insert(&c, b->coeff, b->exp);
      b = b->link;
    }
  }

  // Print the result polynomial c
  struct Node *temp = c;
  printf("Resultant Polynomial: ");
  while (temp != NULL) {
    printf("%dx^%d", temp->coeff, temp->exp);
    if (temp->link != NULL) {
      printf(" + ");
    }
    temp = temp->link;
  }
  printf("\n");

  return 0;
}
