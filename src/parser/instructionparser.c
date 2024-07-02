#include "parser/instructionparser.h"
#include "parser/line.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **instructionParse(char *str) {
  char **instruction = calloc(MAX_INST_LEN, sizeof(char *));
  int arrayIndex = 0;
  int charIndex = 0;

  size_t strLength = strlen(str);
  bool addedRecently = false;
  for (size_t i = 0; i < strLength; i++) {
    char character = str[i];
    if (character == '#') {
      break;
    }
    if (!isspace(character) && character != ',' && charIndex < MAX_INST_LEN) {
      if (instruction[arrayIndex] == NULL) {
        instruction[arrayIndex] = calloc(MAX_INST_LEN, sizeof(char));
      }
      instruction[arrayIndex][charIndex++] = character;
      addedRecently = true;
    } else {
      if (addedRecently) {
        instruction[arrayIndex][charIndex] = '\0';
        charIndex = 0;
        arrayIndex++;
        addedRecently = false;
      }
    }
  }
  return instruction;
}

void printParsedLines(char ***lines) {
  printf("[PROGRAM INPUT]\n");

  for (int i = 0; i < PROGRAM_SIZE; i++) {
    if (lines[i] != NULL) {
      for (int j = 0; j < MAX_INST_LEN; j++) {
        if (lines[i][j] != NULL) {
          printf("[%-5s]", lines[i][j]);
        }
      }
      printf("\n");
    }
  }
  printf("[END]\n");
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

char **parseLine(char *str) {
  char **instruction = NULL;
  if (strlen(str) > 0) {
    instruction = instructionParse(str);
  }
  return instruction;
}
