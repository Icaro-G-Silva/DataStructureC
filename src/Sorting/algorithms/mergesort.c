#include <stdio.h>
#include "utils/util.h"

void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int l, int r, int *iteraction);

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
    mergeSort(num, 0, tamanho - 1, &iteractions);
    gettimeofday(&fim, NULL);

    printArray(num, tamanho);

    timeDiff = time_diff(inicio, fim);

    printf("Tempo gasto: %.0lf microsegundos", timeDiff);
    writeResults(timeDiff, iteractions, "Merge", argv[1]);
  }
}

void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[p + i];
  }
  for (int j = 0; j < n2; j++) {
    M[j] = arr[q + 1 + j];
  }

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r, int *iteraction) {
  addIteraction(iteraction);
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m, iteraction);
    mergeSort(arr, m + 1, r, iteraction);

    merge(arr, l, m, r);
  }
}
