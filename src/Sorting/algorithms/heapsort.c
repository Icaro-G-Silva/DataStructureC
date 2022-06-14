#include <stdio.h>
#include "utils/util.h"

void swap(int *a, int *b);
void heapify(int arr[], int n, int i, int *iteraction);
void heapSort(int arr[], int n, int *iteraction);

void main(int argc, char *argv[]) {
  struct timeval inicio, fim;
  double timeDiff;
  int num[ARRAY_MAX];
  int tamanho = 0;
  FILE *file;
  int iteractions = 0;
  int i, j, eleito;

  if (file = fopen(argv[1], "r")) {
    while (fscanf(file, "%d", &num[tamanho]) != EOF) {
      tamanho++;
    }
    fclose(file);
    num[tamanho] = '\0';

    gettimeofday(&inicio, NULL);
    heapSort(num, tamanho, &iteractions);
    gettimeofday(&fim, NULL);

    printArray(num, tamanho);

    timeDiff = time_diff(inicio, fim);

    printf("Tempo gasto: %.0lf microsegundos", timeDiff);
    writeResults(timeDiff, iteractions, "Heap", argv[1]);
  }
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void heapify(int arr[], int n, int i, int *iteraction) {
  addIteraction(iteraction);
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest, iteraction);
  }
}

void heapSort(int arr[], int n, int *iteraction) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i, iteraction);
  }

  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0, iteraction);
  }
}
