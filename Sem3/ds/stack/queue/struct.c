#include "stdio.h"
#define QUEUE_MAX_SIZE 100

int front = -1;
int rear = -1;

struct QUEUE {
  int element;
};

struct QUEUE q[QUEUE_MAX_SIZE];

int IsFull() {
  if (rear >= QUEUE_MAX_SIZE - 1) {
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
    printf("%d\t", q[i].element);
  }
  printf("\n");
}

void EnQueue(int x) {

  if (IsFull() == 1) {
    printf("Queue is Full");
    return;
  } else if (IsEmpty() == 1) {
    front = rear = 0;
    q[rear].element = x;
    return;
  }
  rear++;
  q[rear].element = x;
}

int DeQueue() {
  if (IsEmpty() == 1) { // when front = rear = -1
    printf("Cannot DeQueue, Queue is full");
    return 0;
  } else if (front != -1 && rear != -1 &&
             front == rear) { // only 1 element in queue
    int dequed = q[front].element;
    front = rear = -1; // set both to -1 to mark empty
    printf("DeQueued %d , Queue is Now Empty\n", dequed);
    return dequed;
  }
  int dequed = q[front].element;
  front++;
  printf("DeQueued %d\n", dequed);
  return dequed;
}

int main(int argc, char *argv[]) {
  EnQueue(4);
  EnQueue(5);
  EnQueue(6);
  display();
  EnQueue(7);
  DeQueue();
  display();
  DeQueue();
  display();
  DeQueue();
  display();
  DeQueue();
  display();
  display();
  EnQueue(1);
  EnQueue(2);
  display();

  return 0;
}
