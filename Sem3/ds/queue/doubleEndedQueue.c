#include "stdio.h"
#include "stdlib.h"

#define MAX_SIZE 10

struct DQ {
  int arr[MAX_SIZE];
  int front;
  int rear;
};

// initialise a new deque

void initDeque(struct DQ *deque) {
  deque->front = -1;
  deque->rear = -1;
}

int isEmpty(struct DQ *deque) {
  if (deque->rear == -1 && deque->front == -1) {
    return 1; // 1 if empty
  }
  return 0;
}

int isFull(struct DQ *deque) {
  if (((deque->rear + 1) % MAX_SIZE) == deque->front) {
    return 1; // 1 if full
  }
  return 0;
}

void addToFront(struct DQ *deque, int x) {
  if (isFull(deque) == 1) {
    printf("deque is full, cannot add");
    return;
  }
  if (isEmpty(deque) == 1) {
    deque->front = 0;
    deque->rear = 0;
  } else {
    deque->front = (deque->front + 1) % MAX_SIZE;
  }
  deque->arr[deque->front] = x;
}

void addToRear(struct DQ *deque, int x) {
  if (isFull(deque) == 1) {
    printf("It is Full");
    return;
  }
  if (isEmpty(deque) == 1) {
    deque->rear = 0;
    deque->front = 0;
  } else {
    deque->rear = (deque->rear + 1) % MAX_SIZE;
  }
  deque->arr[deque->rear] = x;
}

int removeFromFront(struct DQ *deque) {
  if (isEmpty(deque) == 1) {
    printf("DeQ empty\n");
    return -1;
  }
  int removed = deque->arr[deque->front];
  if (deque->front == deque->rear) {
    deque->front = -1;
    deque->rear = -1;
    return removed;
  }
  deque->front = (deque->front + 1) % MAX_SIZE;
  return removed;
}

int removeFromRear(struct DQ *deque) {
  if (isEmpty(deque) == 1) {
    printf("Empty Queue, Cannot Remove from Rear\n");
    return -1;
  }

  int removed = deque->arr[deque->rear];
  if (deque->rear == deque->front) {
    deque->front = -1;
    deque->rear = -1;
  } else {
    deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
  }
  return removed;
}

void display(struct DQ *deque) {
  if (isEmpty(deque) == 1) {
    printf("Empty DeQ\n");
    return;
  }
  printf("DeQ Elements : ");

  int i = deque->front;
  while (i != deque->rear + 1) { // print last element when rear == front
    printf("%d \t", deque->arr[i]);
    i = (i + 1) % MAX_SIZE;
  }
}

int main(int argc, char *argv[]) {
  struct DQ deq;
  initDeque(&deq);
  addToFront(&deq, 1);
  addToRear(&deq, 2);
  addToRear(&deq, 3);
  display(&deq);
  return 0;
}
