
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

struct QUEUE {

  int arr[MAX_ELEMENTS];
  int front;
  int rear;
};

struct QUEUE *q;

void initialise() {
  q->rear = -1;
  q->front = -1;
}

int isEmpty() {
  if (q->rear == -1 && q->front == -1) {
    return 1; // 1 if empty
  }
  return 0;
}

int isFull() {
  if (q->rear == MAX_ELEMENTS - 1) {
    return 1;
  }
  return 0;
}

void EnQueue(int data) {

  if (isEmpty() == 1) {
    q->front = 0;
    q->rear = 0;
    q->arr[q->front] = data;
    return;
  } else if (isFull() == 1) {
    printf("Full\n");
    return;
  }
  q->rear++;
  q->arr[q->rear] = data;
}

int DeQueue() {

  if (isEmpty() == 1) {
    printf("Empty Queue\n");
    exit(1);
  } else if (q->front != -1 && q->rear != -1 && q->front == q->rear) {
    int deqd = q->arr[q->rear];
    q->rear = q->front = -1;
    return (1);
  }

  int deqd = q->arr[q->rear];
  q->rear--;

  return deqd;
}

int main(int argc, char *argv[]) {

  initialise();
  EnQueue(1);
  EnQueue(2);

  return 0;
}
