#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
int top = -1;

typedef struct {
  char element;

} STACK;

STACK stack[MAX_STACK_SIZE];

void Push(char data) {
  if (top >= MAX_STACK_SIZE - 1) {
    printf("Stack is Full Cannot Add\n");
    return;
  }
  top++;
  stack[top].element = data;
}

char Pop() {
  if (top == -1) {
    printf("Stack Empty cannot Pop\n");
    exit(0);
  }
  printf("Popped Element: %c\n", stack[top].element);
  char charCopy = stack[top].element;
  top--;
  return charCopy;
}

void Display() {
  printf("Rev is : ");
  for (int i = top; i >= 0; i--) {
    printf("%c", stack[i].element);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int ch;
  STACK data;
  char num[20];
  char num2[20];
  printf("Enter Name: ");
  scanf("%s", num);
  printf("\n");

  int rem = 0;
  for (int i = 0; i < strlen(num); i++) {
    Push(num[i]);
  }
  Display();
  for (int j = 0; j < strlen(num); j++) {
    num2[j] = Pop();
  }

  if (strcmp(num, num2) == 0) {
    printf("it is palindrome ");
  }
  return 0;
}
