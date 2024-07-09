#include "parser/fileparser.h"
#include "parser/instructionhelper.h"
#include "parser/instructionparser.h"
#include "parser/line.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void addNewLine(char str[], size_t size) {
  size_t len = strlen(str);
  if (len + 1 < size) {
    str[len] = '\n';
    str[len + 1] = '\0';
  }
}

static bool containsData(char str[LINE_LENGTH]) {
  return str[0] == '.' && str[1] == 'd' && str[2] == 'a' && str[3] == 't' &&
         str[4] == 'a';
}

static bool containsText(char str[LINE_LENGTH]) {
  return str[0] == '.' && str[1] == 't' && str[2] == 'e' && str[3] == 'x' &&
         str[4] == 't';
}

int parseFile(const char filename[],
              char parsedLines[PROGRAM_SIZE][MAX_INST_COUNT][MAX_INST_LEN]) {
  FILE *filePointer;

  filePointer = fopen(filename, "r");
  if (filePointer == NULL) {
    printf("Error: file not found!\n");
    return -1;
  }

  char lineBuffer[LINE_LENGTH];
  int currentIndex = 0;
  bool dataSection = false;

  while (fgets(lineBuffer, LINE_LENGTH, filePointer)) {
    char instructions[PROGRAM_SIZE][MAX_INST_LEN] = {0};
    parseComments(lineBuffer);
    strip(lineBuffer);
    if (strlen(lineBuffer)) {
      if (dataSection == false && containsData(lineBuffer)) {
        dataSection = true;
      }
      if (dataSection) {
        dataSection = !(containsText(lineBuffer));
      } else {
        addNewLine(lineBuffer, LINE_LENGTH);
        parseLine(lineBuffer, instructions);
        if (sizeof(instructions) > 1) {
          for (int i = 0; i < MAX_INST_LEN; i++) {
            strlcpy(parsedLines[currentIndex][i], instructions[i],
                    MAX_INST_LEN);
          }
          currentIndex++;
        }
      }
    }
  }
  fclose(filePointer);
  return 0;
}
