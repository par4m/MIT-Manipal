
#include <stdio.h>
#include <stdlib.h>

struct stack {
  int top;
  int *marks;
  int size;
};

struct stack *student;

void initialise(int n) {
  student = (struct stack *)malloc(sizeof(struct stack));
  student->marks = (int *)malloc(n * sizeof(int));
  student->size = n;
  student->top = -1;
}

void push(int data) {
  student->top++;
  student->marks[student->top] = data;
}

int pop() {
  int popped = student->marks[student->top];
  student->top--;
  return popped;
}

void display() {
  for (int i = 0; i <= student->top; i++) {
    printf("%d ", student->marks[i]);
  }
}

void bubbleSort(int n) {
  if (n <= 1)
    return;

  for (int i = 0; i < n - 1; i++) {
    int a = pop();
    int b = pop();
    if (a > b) {
      push(a);
      push(b);
    } else {
      push(b);
      push(a);
    }

    // Push the elements back onto the stack to maintain order
    for (int i = 0; i < n - 1; i++) {
      push(pop());
    }
  }

  // Recursively sort the remaining stack
  bubbleSort(n - 1);
  push(pop());
}

int main(int argc, char *argv[]) {
  int n;
  printf("Enter number of marks: ");
  scanf("%d", &n);
  printf("\n");

  initialise(n);

  push(5);
  push(4);
  push(3);
  push(2);
  printf("Original Stack: ");
  display();

  bubbleSort(student->top + 1);

  printf("\nSorted Stack: ");
  display();

  return 0;
}
