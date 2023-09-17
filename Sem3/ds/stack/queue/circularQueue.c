#include "stdlib.h"
#include <stdio.h>

#define MAX_QUEUE_SIZE 6

int rear = -1;
int front = -1;
int arr[MAX_QUEUE_SIZE];

int IsEmpty() {
  if (rear == -1 && front == -1) {
    return 1;
    // 1 for true (empty)
  }
  // 0 for false (not empty)
  return 0;
}

int IsFull() {
  if (((rear + 1) % MAX_QUEUE_SIZE) == front) {
    return 1; // true if full
  }
  return 0; // 0 if not full
}

void EnQueue(int x) {
  if (IsFull() == 1) {
    printf("Queue is Full\n");
    return;
  } else if (IsEmpty() == 1) {
    front = 0;
    rear = 0;
    arr[rear] = x;
    printf("Enqueued %d\n", x);
    return;
  } else {
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    arr[rear] = x;
    printf("Enqueued %d\n", x);
  }
}

int DeQueue() {
  if (IsEmpty() == 1) { // only if -1
    printf("Queue is Empty");
    return 0;
  } else if (front == rear) { // when theres only 1 element in the queue, so
                              // dequeue it and set front and rear = -1
    int deq = arr[front];
    printf("DeQueued %d \n", deq);
    front = rear = -1;
    return deq;
  }
  int deq = arr[front];
  printf("DeQueued %d \n", deq);
  front = (front + 1) % MAX_QUEUE_SIZE;
  return deq;
}

void peek() {
  printf("Rear of Queue : %d\n", arr[rear]);
  printf("Front of Queue : %d\n", arr[front]);
}

void Display() {
  printf("Queue Is : ");
  for (int i = front; i <= rear; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {

  EnQueue(1);
  EnQueue(2);
  EnQueue(3);
  EnQueue(4);
  EnQueue(5);
  Display();
  DeQueue();
  Display();
  EnQueue(6);
  Display();
  peek();
  printf("front index: %d\n", front);
  DeQueue();
  printf("front index: %d\n", front);

  return 0;
}
