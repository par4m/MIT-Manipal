#include <stdio.h>

// using two temporary stacks
//
// int arr[n];
// int arr2[n]:
// int arr3[n];
//

int n = 5;
int top = -1;
int top2 = -1;
int top3 = -1;
void push(int *arr, int element, int *top) {
  (*top)++;
  arr[*top] = element;
}

int pop(int *arr, int *top) {
  int popped = arr[*top];
  top--;
  return popped;
}

void display(int *arr, int *top) {
  for (int i = 0; i < *top; i++) {
    printf("%d\n", arr[i]);
  }
}

int main(int argc, char *argv[]) {
  int arr[n];  // original
  int arr2[n]; // pop from original and add
  int arr3[n]; // pop from arr2 and add

  push(arr, 1, &top);
  push(arr, 2, &top);
  push(arr, 3, &top);
  push(arr, 4, &top);
  push(arr, 5, &top);
  // while (top2 != n - 1) {
  //   int element = pop(arr, top);
  //   push(arr2, element, top2);
  // }
  display(arr, &top);
  while (top != -1) {
    int x = pop(arr2, &top);
    push(arr2, x, &top2);
  }
  display(arr2, &top2);

  return 0;
}
