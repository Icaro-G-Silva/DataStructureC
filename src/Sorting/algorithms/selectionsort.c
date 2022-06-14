#include <stdio.h>
#include "utils/util.h"

void swap(int *a, int *b);
void selectionSort(int array[], int size, int *iteraction);

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
    selectionSort(num, tamanho, &iteractions);
    gettimeofday(&fim, NULL);

    printArray(num, tamanho);

    timeDiff = time_diff(inicio, fim);

    printf("Tempo gasto: %.0lf microsegundos", timeDiff);
    writeResults(timeDiff, iteractions, "Selection", argv[1]);
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size, int *iteraction) {
  for (int step = 0; step < size - 1; step++) {
    addIteraction(iteraction);
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[min_idx]) {
        min_idx = i;
      }
    }
    swap(&array[min_idx], &array[step]);
  }
}
