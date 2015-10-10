#include <stdio.h>
#include <stdlib.h>

#include "file_ops.h"

void tryOpen(FILE **file, char *filename, char *mode) {

  if (filename == NULL) {
    printf("Usage: ./a.out <filename> [-keyUp <number> -keyDown <number> -o <filename>]");
    exit(1);
  }
  
  *file = fopen(filename, mode);

  if (*file == NULL) {
    printf("%s could not be opened.", filename);
    exit(1);
  }
  
}

void writeNewTab(FILE **inputTab, FILE **outputTab, int shift) {
  
  char *file;
  long size;
  int c;
  size_t index = 0;

  // Seek through the file and allocate line length to the size
  fseek(inputTab, 0, SEEK_END);
  size = ftell(file);
  fseek(inputTab, 0, SEEK_SET);
  
  if (size == 0) return;
  
  while ((c = fgetc(file)) != EOF) {

    index++;
    if ((char) c == '\n') {

  }
  
}