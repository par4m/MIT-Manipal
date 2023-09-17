#include <stdbool.h>
#include <stdio.h>

#define MAX_STACK_SIZE 100
int top = -1;

typedef struct {
  int element;

} STACK;

STACK stack[MAX_STACK_SIZE];

void Push(int data) {
  if (top >= MAX_STACK_SIZE - 1) {
    printf("Stack is Full Cannot Add\n");
    return;
  }
  top++;
  stack[top].element = data;
}

void Pop() {
  if (top == -1) {
    printf("Stack Empty cannot Pop\n");
    return;
  }
  printf("Popped Element: %d\n", stack[top].element);
  top--;
}

void Display() {
  printf("in  Binary is : ");
  for (int i = top; i >= 0; i--) {
    printf("%d", stack[i].element);
  }
}

int main(int argc, char *argv[]) {
  int ch;
  STACK data;
  int num;
  printf("Enter Num: ");
  scanf("%d", &num);
  printf("\n");

  int rem = 0;
  while (num != 0) {
    rem = num % 2;
    num = num / 2;
    Push(rem);
  }
  Display();
  return 0;
}
