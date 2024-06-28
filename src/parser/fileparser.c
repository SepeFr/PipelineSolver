#include "parser/fileparser.h"
#include "parser/instructionparser.h"
#include "parser/line.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 255

char *addNewLine(char *str) {
  char *strNewLine;
  size_t len = strlen(str);
  if (len > 0) {
    strNewLine = malloc(sizeof(char) * (len + 2));
    strlcpy(strNewLine, str, len + 1);
    strNewLine[len] = '\n';
    strNewLine[len + 1] = '\0';
  }
  return strNewLine;
}

char *strip(char *lineBuffer) {
  char *backChar = lineBuffer + strlen(lineBuffer);
  while (isspace(*--backChar))
    ;
  *(backChar + 1) = '\0';

  while (isspace(*lineBuffer))
    lineBuffer++;

  if (addNewLine(lineBuffer) != NULL && strlen(lineBuffer) > 0) {
    return addNewLine(lineBuffer);
  }
  return lineBuffer;
}

char ***parseFile(const char *filename) {
  FILE *filePointer;
  char current;

  filePointer = fopen(filename, "r");
  if (filePointer == NULL) {
    printf("Error: file not found!\n");
    return NULL;
  }

  int lineBufferLength = LINE_LENGTH;
  char *lineBuffer = malloc(sizeof(char) * LINE_LENGTH);
  char ***parsedLines = calloc(PROGRAM_SIZE, sizeof(char **));
  int currentIndex = 0;

  while (fgets(lineBuffer, lineBufferLength, filePointer)) {
    lineBuffer = strip(lineBuffer);
    if (strlen(lineBuffer)) {
      char **parsedLine = parseLine(strip(lineBuffer));
      parsedLines[currentIndex] = parsedLine;
      currentIndex++;
    }
  }

  free(lineBuffer);
  fclose(filePointer);
  return parsedLines;
}
