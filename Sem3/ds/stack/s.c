#include "stdlib.h"
#include <stdio.h>

struct stack {

  int *marks;
  int top;
  int size;
};

struct stack *createStack(int n) {
  struct stack *s;
  s = (struct stack *)malloc(sizeof(struct stack));
  s->marks = (int *)malloc(n * sizeof(struct stack));
  s->top = -1;
  s->size = n;

  return s;
}

void display(struct stack *s) {
  if (s->top >= 0) {
    printf("Marks in the stack are :");
    for (int i = 0; i < s->size; i++) {
      printf("%d\t", s->marks[i]);
    }
    printf("\n");
  }
}

void push(struct stack *s, int data) {
  s->top++;
  s->marks[s->top] = data;
}

int pop(struct stack *s) {
  int popped = s->marks[s->top];
  s->top--;

  return popped;
}

int main(int argc, char *argv[]) { return 0; }
