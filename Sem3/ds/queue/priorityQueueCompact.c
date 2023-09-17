#include "stdio.h"
#include "stdlib.h"

//  PQ by Compacting the Array
//
// elements with highest priority are dequeued first
// when an element is dequeued, the array is compacted to remove the dequeued
// element
// higher priority (greater value of priority) , that element will be first.
// 0 index element will always have highest priority

#define MAX_SIZE 5

struct PQ {
  int element;
  int priority;
};

struct PQ pq;

struct PQ priorityQueue[MAX_SIZE];
int size = 0;

int isEmpty() {
  if (size == 0) {
    return 1; // 1 if empty
  }
  return 0;
}

int isFull() {
  if (size == MAX_SIZE) {
    return 1; // 1 if full
  }
  return 0; // 0 if empty
}

void EnQueue(int value, int priority) {

  if (isFull() == 1) {
    printf("Priority queue is full\n");
    return;
  }

  int i = size - 1;
  while (i >= 0 && priority > priorityQueue[i].priority) {
    priorityQueue[i + 1] = priorityQueue[i]; // while priority of currrent is
                                             // more shift elements to right
    i--;
  }

  priorityQueue[i + 1].element = value;
  priorityQueue[i + 1].priority = priority;
  size++;
}

int DeQueue() {
  if (isEmpty() == 1) {
    exit(-1);
    ; // empty stack
  }
  int popped = priorityQueue[0].element;

  for (int i = 0; i < size; i++) {
    priorityQueue[i] = priorityQueue[i + 1]; // shift elements to the left
  }
  size--;
  return popped;
}

void display() {
  printf("Compact Array PQ: \n");
  for (int i = 0; i < size; i++) {
    printf(" Value: %d  Priority: %d \n", priorityQueue[i].element,
           priorityQueue[i].priority);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {

  EnQueue(1, 3);
  EnQueue(2, 4);
  display();
  DeQueue();
  display();
  EnQueue(7, 8);
  display();

  return 0;
}
