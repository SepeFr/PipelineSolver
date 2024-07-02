#include "parser/fileparser.h"
#include "parser/instructionparser.h"
#include "parser/line.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 1024

char *addNewLine(char *str) {
  char *strNewLine;
  size_t len = strlen(str);
  if (len > 0) {
    strNewLine = malloc(sizeof(char) * (len + 2));
    strlcpy(strNewLine, str, len + 1);
    strNewLine[len] = '\n';
    strNewLine[len + 1] = '\0';
  } else {
    return str;
  }
  return strNewLine;
}

char *strip(char *str) {
  char *backChar = str + strlen(str);
  while (isspace(*--backChar))
    ;
  *(backChar + 1) = '\0';

  while (isspace(*str))
    str++;

  if (str == NULL) {
    return "";
  }
  return str;
}

int strArrayLen(char **array) {
  int i = 0;
  while (*array != NULL) {
    i++;
    array++;
  }
  return i;
}

char ***parseFile(const char *filename) {
  FILE *filePointer;

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
    if (lineBuffer == NULL) {
      continue;
    }
    if (strlen(lineBuffer)) {
      char **parsedLine = parseLine(strip(lineBuffer));
      if (parsedLine != NULL && strArrayLen(parsedLine) != 0) {
        parsedLines[currentIndex] = parsedLine;
        currentIndex++;
      }
    }
  }

  fclose(filePointer);
  return parsedLines;
}
