#include <stdio.h>
#include "utils/util.h"

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

    for (i = 1; i < tamanho; i++) {
      eleito = num[i];
      j = i - 1;
      while (j >= 0 && num[j] > eleito) {
        addIteraction(&iteractions);
        num[j+1] = num[j];
        j = j - 1;
      }
      num[j+1] = eleito;
    }
    
    gettimeofday(&fim, NULL);

    printArray(num, tamanho);

    timeDiff = time_diff(inicio, fim);

    printf("Tempo gasto: %.0lf microsegundos", timeDiff);
    writeResults(timeDiff, iteractions, "Insertion", argv[1]);
  }
}
