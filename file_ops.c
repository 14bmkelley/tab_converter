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
  
  char *sharps[12] = { "C ", "C#", "D ", "D#", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B " };
  char *flats[12] = { "C ", "Db", "D ", "Eb", "E ", "F ", "Gb", "G ", "Ab", "A ", "Bb", "B " };
  int *file;
  long size;
  int c;
  size_t index = 0;
  int whiteChars = 0;
  int nonWhiteChars = 0;

  // Seek through the file and allocate line length to the size
  fseek(*inputTab, 0, SEEK_END);
  size = ftell(*inputTab);
  fseek(*inputTab, 0, SEEK_SET);
  file = (int *) malloc(sizeof(int) * size);

  if (size == 0) return;
  
  while ((c = fgetc(*inputTab)) != EOF) {
    
    switch (file[index++] = c) {
      
      case '\t':
      case ' ':
        whiteChars++;
        break;

      case '\n':
      case '\r':
        if (whiteChars > nonWhiteChars) {
          for (int i = 0; i < index; i++) {
            int output = (char) file[i];
            int offset = 0;
            char *newValue;
            if ((char) file[i + 1] == '#') offset = 1;
            if ((char) file[i + 1] == 'b') offset = -1;
            if (output == 'a' || output == 'A') {
              int newIndex = (9 + offset + shift) % 12;
              newValue = sharps[newIndex];
            } else if (output == 'b' || output == 'B') {
              int newIndex = (11 + offset + shift) % 12;
              newValue = sharps[newIndex];
            } else if (output == 'c' || output == 'C') {
              int newIndex = (0 + offset + shift) % 12;
              newValue = sharps[newIndex];
            } else if (output == 'd' || output == 'D') {
              int newIndex = (2 + offset + shift) % 12;
              newValue = sharps[newIndex];
            } else if (output == 'e' || output == 'E') {
              int newIndex = (4 + offset + shift) % 12;
              newValue = sharps[newIndex];
            } else if (output == 'f' || output == 'F') {
              int newIndex = (5 + offset + shift) % 12;
              newValue = sharps[newIndex];
            } else if (output == 'g' || output == 'G') {
              int newIndex = (7 + offset + shift) % 12;
              newValue = sharps[newIndex];
            } else {
              char str[2] = "\0";
              str[0] = output;
              newValue = str;
            }
            fprintf(*outputTab, "%s", newValue);
          }
        } else {
          for (int i = 0; i < index; i++) {
            fputc(file[i], *outputTab);
          }
        }
        whiteChars = 0;
        nonWhiteChars = 0;
        index = 0;
        break;

      default:
        nonWhiteChars++;

    }
  }

  free(file);
  
}
