

#include "stdio.h"
#include <stdlib.h>

struct QUEUE {
  int data;
};

int rear;
int front;
int size = 1;

struct QUEUE *q;

void initialise() {
  q = (struct QUEUE *)malloc(sizeof(struct QUEUE));
  rear = -1;
  front = -1;
}

int IsFull() {
  if (rear == size) {
    return 1;
  }
  return 0;
  // 1 if full
  // 0 if not full
}

int IsEmpty() {
  if (front == -1 && rear == -1) {
    return 1;
  }
  return 0;
  // 1 if empty
  // 0 if not empty
}

void display() {

  if (front == -1 && rear == -1) {
    printf("Queue is Empty\n");
    return;
  }

  printf("QUEUE is : ");
  for (int i = front; i <= rear; i++) {
    printf("%d\t", q[i].data);
  }
  printf("\n");
}

void EnQueue(int x) {

  if (IsFull() == 1) {
    printf("Queue is Full, Resizinng\n");
    q = realloc(q, 2 * size * sizeof(struct QUEUE));
    size = 2 * size;
  } else if (IsEmpty() == 1) {
    front = rear = 0;
    q[rear].data = x;
    return;
  }
  rear++;
  q[rear].data = x;
}

int DeQueue() {
  if (IsEmpty() == 1) { // when front = rear = -1
    printf("Cannot DeQueue, Queue is full");
    return 0;
  } else if (front != -1 && rear != -1 &&
             front == rear) { // only 1 element in queue
    int dequed = q[front].data;
    front = rear = -1; // set both to -1 to mark empty
    printf("DeQueued %d , Queue is Now Empty\n", dequed);
    return dequed;
  }
  int dequed = q[front].data;
  front++;
  printf("DeQueued %d\n", dequed);
  return dequed;
}

int main(int argc, char *argv[]) {
  initialise();
  EnQueue(1);
  EnQueue(3);
  EnQueue(5);
  EnQueue(5);
  EnQueue(5);
  EnQueue(5);

  return 0;
}
