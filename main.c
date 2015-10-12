#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "file_ops.h"

int main(int argc, char *argv[]) {
  
  // Files and such
  FILE *tab;
  FILE *newTab;
  char *inputFilename = argv[1];
  char *outputFilename;
  char inputKey;
  int keyShift;
  
  // Open input file and determine key
  tryOpen(&tab, inputFilename, "r");
  
  // Process commandline arguments
  if (argc > 1) {
    for (int i = 2; i < argc; i++) {
      
      // If the number of half steps up is specified
      if (strcmp(argv[i], "-keyUp") == 0) {
        keyShift = atoi(argv[i + 1]);
      
      // If the number of half steps down is specified
      } else if (strcmp(argv[i], "-keyDown") == 0) {
        keyShift = -1 * atoi(argv[i + 1]);
      
      // If output filename is specified
      } else if (strcmp(argv[i], "-o") == 0) {
        outputFilename = argv[i + 1];
      }

    }
  }
  
  // Name the output file and open it
  if (outputFilename == NULL) outputFilename = "tab.txt";
  tryOpen(&newTab, outputFilename, "w");
  
  // Generate new tab
  writeNewTab(&tab, &newTab, keyShift);
  
  return 0;
  
}
