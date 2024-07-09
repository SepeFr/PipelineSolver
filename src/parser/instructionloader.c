#include "parser/instructionloader.h"
#include "parser/instructionhelper.h"
#include "parser/instructionparser.h"
#include "parser/line.h"
#include "util/hashmap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static HashMap *map;

static void loadMap(void) {
  static HashMap localMap;

  if (map == NULL) {
    initializeMap(&localMap);
    map = &localMap;
  }
}

HashMap *loadRArithLog(const char *filename) {
  loadMap();
  FILE *filePointer;

  filePointer = fopen(filename, "r");
  if (filePointer == NULL) {
    printf("Error: file not found!\n");
    return NULL;
  }

  char lineBuffer[MAX_INST_LEN];
  while (fgets(lineBuffer, MAX_INST_LEN, filePointer)) {
    strip(lineBuffer);
    if (strlen(lineBuffer) != 0) {
      parseComments(lineBuffer);
      printf("Inserting RAirthLog into HahsMap %s\n", lineBuffer);
      insertHashMap(map, lineBuffer, RAritmLog);
    }
  }

  fclose(filePointer);
  return map;
}

HashMap *loadIAritmLogA(const char *filename) {
  loadMap();
  FILE *filePointer;

  filePointer = fopen(filename, "r");
  if (filePointer == NULL) {
    printf("Error: file not found!\n");
    return NULL;
  }

  char lineBuffer[MAX_INST_LEN];
  while (fgets(lineBuffer, MAX_INST_LEN, filePointer)) {
    strip(lineBuffer);
    if (strlen(lineBuffer)) {
      parseComments(lineBuffer);
      insertHashMap(map, lineBuffer, IAritmLogA);
    }
  }

  fclose(filePointer);
  return map;
}

HashMap *loadIAritmLogI(const char *filename) {
  FILE *filePointer;

  filePointer = fopen(filename, "r");
  if (filePointer == NULL) {
    printf("Error: file not found!\n");
    return NULL;
  }

  char lineBuffer[MAX_INST_LEN];
  while (fgets(lineBuffer, MAX_INST_LEN, filePointer)) {
    strip(lineBuffer);
    if (strlen(lineBuffer)) {
      parseComments(lineBuffer);
      insertHashMap(map, lineBuffer, IAritmLogI);
    }
  }

  fclose(filePointer);
  return map;
}

HashMap *loadILoadSave(const char *filename) {
  FILE *filePointer;

  filePointer = fopen(filename, "r");
  if (filePointer == NULL) {
    printf("Error: file not found!\n");
    return NULL;
  }

  char lineBuffer[MAX_INST_LEN];
  while (fgets(lineBuffer, MAX_INST_LEN, filePointer)) {
    strip(lineBuffer);
    if (strlen(lineBuffer)) {
      parseComments(lineBuffer);
      insertHashMap(map, lineBuffer, ILoadSave);
    }
  }

  fclose(filePointer);
  return map;
}

HashMap *loadJump(const char *filename) {
  FILE *filePointer;

  filePointer = fopen(filename, "r");
  if (filePointer == NULL) {
    printf("Error: file not found!\n");
    return NULL;
  }

  char lineBuffer[MAX_INST_LEN];
  while (fgets(lineBuffer, MAX_INST_LEN, filePointer)) {
    strip(lineBuffer);
    if (strlen(lineBuffer)) {
      parseComments(lineBuffer);
      insertHashMap(map, lineBuffer, J);
    }
  }

  fclose(filePointer);
  return map;
}
