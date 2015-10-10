#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <stdio.h>

void tryOpen(FILE **file, char *filename, char *mode);
void writeNewTab(FILE **inputTab, FILE **outputTab, int shift);

#endif
