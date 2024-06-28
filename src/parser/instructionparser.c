#include "parser/instructionparser.h"
#include "parser/line.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INST_LEN 6
#define MAX_INST_COUNT 6

char **instructionParse(char *str) {
  char **instruction = calloc(MAX_INST_COUNT, sizeof(char *));
  int arrayIndex = 0;
  int charIndex = 0;

  size_t strLength = strlen(str);
  bool addedRecently = false;
  for (size_t i = 0; i < strLength; i++) {
    char character = str[i];
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

char **parseLine(char *str) {
  char **instruction = NULL;
  if (strlen(str) > 0) {
    instruction = instructionParse(str);
  }
  return instruction;
}
