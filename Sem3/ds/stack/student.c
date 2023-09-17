#include "stdio.h"
#include "stdlib.h"

struct stack {
  int size;
  int top;
  int *marks;
};

struct stack *createStack(int n) {
  struct stack *sp;
  sp = (struct stack *)malloc(sizeof(struct stack));
  if (sp == NULL) {
    printf("Memory Allocation Failed");
    exit(1);
  }
  sp->marks = (int *)malloc(n * sizeof(int));
  sp->top = -1;
  sp->size = n;
}

int main(int argc, char *argv[]) { return 0; }
