#include <stdio.h>
#include <stdlib.h>

int size = 1;

typedef struct {
  int data;
} STACK;

void stackFull(STACK *s) {
  s = realloc(s, (2 * size) * sizeof(STACK));
  size = size * 2;
}

void Push(STACK *s, int *top, int data) {
  if (*top >= size - 1) {
    printf("Stack is Full, Allocating Memory");
    stackFull(s);
  }
  (*top)++;
  s[*top].data = data;
}

void Display(STACK *s, int *top) {
  printf("Stack Is \n");
  for (int i = *top; i >= 0; i--) {
    printf("%d\n", s[i].data);
  }
}

void Pop(STACK *s, int *top) {
  if (*top == -1) {
    printf("Stack Empty\n");
    return;
  }
  printf("Popping %d\n", s[*top].data);
  (*top)--;
}

int main(int argc, char *argv[]) {

  STACK *s = (STACK *)malloc(size * sizeof(STACK));
  int top = -1;
  int ch;
  int data;
  do {

    Display(s, &top);
    printf(" 1. Push\n 2. Pop\n 3. Exit \n ");
    printf("Enter a choice: ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      printf(" Enter what to push: ");
      scanf("%d", &data);
      Push(s, &top, data);
      break;

    case 2:
      Pop(s, &top);
      break;
    }

  } while (ch != 3);

  return 0;
}
