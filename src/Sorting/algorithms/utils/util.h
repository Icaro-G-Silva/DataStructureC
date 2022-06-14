#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <time.h>

#define ARRAY_MAX 250000
#define TIME_MULTIPLIER 1000000

struct timeval {
  time_t tv_sec;   
  long int tv_usec;  
};

double time_diff(struct timeval x , struct timeval y) {
  double x_ms , y_ms , diff;
  x_ms = (double) x.tv_sec * TIME_MULTIPLIER + (double) x.tv_usec;
  y_ms = (double) y.tv_sec * TIME_MULTIPLIER + (double) y.tv_usec;
  diff = (double) y_ms - (double) x_ms;
  return diff;
}

void writeResults(double timeInMicroseconds, int numberOfIteractions, char *algorithmName, char *fileAnalyzed) {
  FILE *file;
  if(file = fopen("stats.csv", "a")) {
    fprintf(file, "%s;%0.0lf;%d;%s\n", algorithmName, timeInMicroseconds, numberOfIteractions, fileAnalyzed);
  }
}

void printArray(int array[], int arraySize) {
  for(int i = 0; i < arraySize; i++) {
    printf("%d\n", array[i]);
  }
}

void addIteraction(int *iteractorPtr) {
  *iteractorPtr += 1;
}

#endif