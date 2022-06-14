#include <stdio.h>
#include "utils/util.h"

void main(int argc, char *argv[]) {
  struct timeval inicio, fim;
  double timeDiff;
  int num[ARRAY_MAX];
  int tamanho = 0;
  FILE *file;
  int iteractions = 0;
  int i, j, aux;

  if(file = fopen(argv[1], "r")) {
    while(fscanf(file, "%d", &num[tamanho]) != EOF) {
      tamanho++;
    }
    fclose(file);
    num[tamanho] = '\0';

    gettimeofday(&inicio, NULL);
    
    for(j = 0; j < tamanho; j++) {
      for(i = tamanho-1; i > j; i--) {
        addIteraction(&iteractions);
        if(num[i] < num[i-1]) {
          aux = num[i];
          num[i] = num[i-1];
          num[i-1] = aux;
        }
      }
    }

    gettimeofday(&fim, NULL);

    printArray(num, tamanho);

    timeDiff = time_diff(inicio, fim);

    printf("Tempo gasto: %.0lf microsegundos" , timeDiff);
    writeResults(timeDiff, iteractions, "Bubble", argv[1]);
  }
}
