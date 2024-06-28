#include "parser/fileparser.h"
#include "parser/line.h"
#include "pipeline.h"
#include <stdio.h>
#include <stdlib.h>

void printParsedLines(char ***lines) {
  for (int i = 0; i < PROGRAM_SIZE; i++) {
    if (lines[i] != NULL) {
      for (int j = 0; j < 6; j++) {
        if (lines[i][j] != NULL) {
          printf("%s ", lines[i][j]);
        }
      }
      printf("\n");
    }
  }
}

void freeParsedLines(char ***lines) {
  if (lines == NULL)
    return;
  for (int i = 0; lines[i] != NULL; i++) {
    for (int j = 0; lines[i][j] != NULL; j++) {
      free(lines[i][j]);
    }
    free(lines[i]);
  }
  free(lines);
}

void solvePipeline(char *file) {
  Line buffer[1024];
  char ***RInstructions = parseFile("res/instR.txt");
  char ***parsedLines = parseFile(file);

  printParsedLines(RInstructions);

  freeParsedLines(RInstructions);
  freeParsedLines(parsedLines);
}
