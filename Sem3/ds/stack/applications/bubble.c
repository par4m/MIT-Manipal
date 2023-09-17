#include "stdio.h"

int main(int argc, char *argv[]) {
  int arr[] = {1, 5, 3, 6, 7, 8};
  int n = 6;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
  }
  return 0;
}
