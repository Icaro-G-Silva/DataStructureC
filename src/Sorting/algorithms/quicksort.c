#include <stdio.h>
#include "utils/util.h"

void swap(int *a, int *b);
int partition(int array[], int low, int high, int *iteraction);
void quickSort(int array[], int low, int high, int *iteraction);

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
    quickSort(num, 0, tamanho - 1, &iteractions);
    gettimeofday(&fim, NULL);

    printArray(num, tamanho);

    timeDiff = time_diff(inicio, fim);

    printf("Tempo gasto: %.0lf microsegundos", timeDiff);
    writeResults(timeDiff, iteractions, "Quick", argv[1]);
  }
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high, int *iteraction) {
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high, int *iteraction) {
  addIteraction(iteraction);
  if (low < high) {
    int pi = partition(array, low, high, iteraction);

    quickSort(array, low, pi - 1, iteraction);
    quickSort(array, pi + 1, high, iteraction);
  }
}
