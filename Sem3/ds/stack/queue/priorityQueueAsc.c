#include <stdio.h>

// ascending priority queue
// item with high priority is served before an item with low priority
// lowest value = highest priority => dequeued first
// lower value => higher priority

#define MAX 5

struct PQ {
  int Q[MAX];
  int rear; // last element in the queue
};

void EnQueue(struct PQ *pq, int element) {
  if (pq->rear >= MAX - 1) {
    printf("Queue is Full");
    return;
  }
  int i = pq->rear;
  while (i >= 0 && pq->Q[i] > element) {
    pq->Q[i + 1] = pq->Q[i];
    i--;
  }
  pq->Q[i + 1] = element;
  pq->rear++;
}

int DeQueue(struct PQ *pq) {
  // remove front element and shift all other elements to the left

  if (pq->rear == -1) {
    printf("Queue is Empty");
    return -1; // error
  }
  int dequeued = pq->Q[pq->rear];
  for (int i = 0; i < pq->rear; i++) { // 1 less than rear
    pq->Q[i] = pq->Q[i + 1];
  }
  pq->rear--;
  return dequeued;
}

void Display(struct PQ *pq) {
  printf("Ascending PQ is : ");
  for (int i = 0; i <= pq->rear; i++) {
    printf("%d\t", pq->Q[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {

  struct PQ pq;
  pq.rear = -1;
  EnQueue(&pq, 2);
  EnQueue(&pq, 5);
  EnQueue(&pq, 4);
  EnQueue(&pq, 1);
  Display(&pq);
  DeQueue(&pq);
  Display(&pq);

  return 0;
}
