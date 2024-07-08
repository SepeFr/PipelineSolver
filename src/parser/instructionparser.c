#include "parser/instructionparser.h"
#include "parser/instructionhelper.h"
#include "parser/line.h"
#include "util/hashmap.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static void instructionParse(char str[],
                             char instructions[PROGRAM_SIZE][MAX_INST_LEN]) {
  size_t strLength = strlen(str);
  int arrayIndex = 0;
  int charIndex = 0;
  bool addedRecently = false;

  // we want to break down the instruction from
  // addi $ra, $ra, 1
  // to
  // [addi][$ra][$ra][1]
  for (size_t i = 0; i < strLength; i++) {
    char currCharacter = str[i];
    // delimiter in mips is ','
    if (!isspace(currCharacter) && currCharacter != ',' &&
        charIndex < MAX_INST_LEN) {
      // if char exists, we add it
      instructions[arrayIndex][charIndex++] = currCharacter;
      addedRecently = true;
    } else {
      if (addedRecently) {
        instructions[arrayIndex][charIndex] = '\0';
        charIndex = 0;
        arrayIndex++;
        addedRecently = false;
      }
    }
  }

  if (addedRecently) {
    instructions[arrayIndex][charIndex] = '\0';
  }
}

void parseLine(char str[], char instructions[PROGRAM_SIZE][MAX_INST_LEN]) {
  if (strlen(str) > 0) {
    instructionParse(str, instructions);
  }
}

void printParsedLines(char lines[PROGRAM_SIZE][MAX_INST_COUNT][MAX_INST_LEN]) {
  for (int i = 0; i < PROGRAM_SIZE; i++) {
    for (int j = 0; j < MAX_INST_COUNT; j++) {
      if (strlen(lines[i][j])) {
        printf("%s ", lines[i][j]);
      }
    }
    if (strlen(lines[i][0]) != 0) {
      printf("\n");
    }
  }
}
