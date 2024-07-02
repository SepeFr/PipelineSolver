#include "parser/fileparser.h"
#include "parser/instructionparser.h"
#include "parser/line.h"
#include "util/hashmap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashMap *map;

void loadMap() { map = malloc(sizeof(HashMap)); }

HashMap *loadRArithLog(char *filename) {
  FILE *filePointer;

  filePointer = fopen(filename, "r");
  if (filePointer == NULL) {
    printf("Error: file not found!\n");
    return NULL;
  }

  int lineBufferLength = MAX_INST_LEN;
  char *lineBuffer = malloc(sizeof(char) * lineBufferLength);
  while (fgets(lineBuffer, lineBufferLength, filePointer)) {
    lineBuffer = strip(lineBuffer);
    if (lineBuffer == NULL) {
      continue;
    }
    if (strlen(lineBuffer)) {
      insertHashMap(map, lineBuffer, RAritmLog);
    }
  }

  free(lineBuffer);
  fclose(filePointer);
  return map;
}

HashMap *loadIAritmLogA(char *filename) {
  FILE *filePointer;

  filePointer = fopen(filename, "r");
  if (filePointer == NULL) {
    fclose(filePointer);
    printf("Error: file not found!\n");
    return NULL;
  }

  int lineBufferLength = MAX_INST_LEN;
  char *lineBuffer = malloc(sizeof(char) * lineBufferLength);
  while (fgets(lineBuffer, lineBufferLength, filePointer)) {
    lineBuffer = strip(lineBuffer);
    if (lineBuffer == NULL) {
      continue;
    }

    if (strlen(lineBuffer)) {
      if (*lineBuffer == '#') {
        continue;
      }
      insertHashMap(map, lineBuffer, IAritmLogA);
    }
  }

  free(lineBuffer);
  fclose(filePointer);
  return map;
}

HashMap *loadIAritmLogI(char *filename) {
  FILE *filePointer;

  filePointer = fopen(filename, "r");
  if (filePointer == NULL) {
    fclose(filePointer);
    printf("Error: file not found!\n");
    return NULL;
  }

  int lineBufferLength = MAX_INST_LEN;
  char *lineBuffer = malloc(sizeof(char) * lineBufferLength);
  while (fgets(lineBuffer, lineBufferLength, filePointer)) {
    lineBuffer = strip(lineBuffer);
    if (lineBuffer == NULL) {
      continue;
    }
    if (strlen(lineBuffer)) {
      insertHashMap(map, lineBuffer, IAritmLogI);
    }
  }

  free(lineBuffer);
  fclose(filePointer);
  return map;
}

HashMap *loadILoadSave(char *filename) {
  FILE *filePointer;

  filePointer = fopen(filename, "r");
  if (filePointer == NULL) {
    printf("Error: file not found!\n");
    return NULL;
  }

  int lineBufferLength = MAX_INST_LEN;
  char *lineBuffer = malloc(sizeof(char) * lineBufferLength);
  while (fgets(lineBuffer, lineBufferLength, filePointer)) {
    lineBuffer = strip(lineBuffer);
    if (lineBuffer == NULL) {
      continue;
    }
    if (strlen(lineBuffer)) {
      insertHashMap(map, lineBuffer, ILoadSave);
    }
  }

  free(lineBuffer);
  fclose(filePointer);
  return map;
}

HashMap *loadJump(char *filename) {
  FILE *filePointer;

  filePointer = fopen(filename, "r");
  if (filePointer == NULL) {
    fclose(filePointer);
    printf("Error: file not found!\n");
    return NULL;
  }

  int lineBufferLength = MAX_INST_LEN;
  char *lineBuffer = malloc(sizeof(char) * lineBufferLength);
  while (fgets(lineBuffer, lineBufferLength, filePointer)) {
    lineBuffer = strip(lineBuffer);
    if (lineBuffer == NULL) {
      continue;
    }
    if (strlen(lineBuffer)) {
      insertHashMap(map, lineBuffer, J);
    }
  }

  free(lineBuffer);
  fclose(filePointer);
  return map;
}
