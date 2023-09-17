#include <stdbool.h>
#include <stdio.h>

#define MAX_STACK_SIZE 100
int top = -1;

typedef struct {
  int element;

} STACK;

STACK stack[MAX_STACK_SIZE];

void Push(STACK data) {
  if (top >= MAX_STACK_SIZE - 1) {
    printf("Stack is Full Cannot Add\n");
    return;
  }
  top++;
  stack[top] = data;
}

void Pop() {
  if (top == -1) {
    printf("Stack Empty cannot Pop\n");
    return;
  }
  printf("Popped Element: %d\n", stack[top]);
  top--;
}

void Display() {
  printf("Stack is : \n");
  for (int i = top; i >= 0; i--) {
    printf("Element %d is %d\n", top - i + 1, stack[i]);
  }
}

int main(int argc, char *argv[]) {
  int ch;
  STACK data;
  do {
    printf(" 1. Push\n 2. Pop\n 3. Exit \n ");
    printf("Enter a choice: ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      printf(" Enter what to push: ");
      scanf("%d", &data.element);
      Push(data);
      Display();
      break;

    case 2:
      Pop();
      Display();
      break;
    }

  } while (ch != 3);

  return 0;
}
