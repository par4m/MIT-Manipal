#include <stdio.h>

// higher values have higher priority
// elements inserted in descending order

#define MAX 5

struct PQ {
  int Q[MAX];
  int rear;
};

void EnQueue(struct PQ *pq, int element) {
  if (pq->rear >= MAX - 1) {
    printf("Queue is Full\n");
    return;
  }
  int i = pq->rear;
  while (i >= 0 && element > pq->Q[i]) {
    pq->Q[i + 1] = pq->Q[i];
    i--;
  }
  pq->Q[i + 1] = element;
  pq->rear++;
}

int DeQueue(struct PQ *pq) {
  if (pq->rear == -1) {
    return -1;
  }
  for (int i = 0; i < pq->rear;
       i++) { // go till 1 less than rear and shift all to left
    pq->Q[i] = pq->Q[i + 1];
  }
  int dequed = pq->Q[pq->rear];
  pq->rear--;
  return dequed;
}

void Display(struct PQ *pq) {
  printf("Descending Queue is : ");
  for (int i = 0; i <= pq->rear; i++) {
    printf(" %d\t", pq->Q[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  struct PQ pq;
  pq.rear = -1;
  EnQueue(&pq, 1);
  EnQueue(&pq, 2);
  EnQueue(&pq, 3);
  EnQueue(&pq, 4);
  Display(&pq);
  DeQueue(&pq);
  Display(&pq);
  return 0;
}
