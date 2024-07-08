#include "parser/fileparser.h"
#include "parser/instructionhelper.h"
#include "parser/instructionparser.h"
#include "parser/line.h"
#include "util/hashmap.h"
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

  while (fgets(lineBuffer, LINE_LENGTH, filePointer)) {
    char instructions[PROGRAM_SIZE][MAX_INST_LEN] = {0};
    parseComments(lineBuffer);
    strip(lineBuffer);
    if (strlen(lineBuffer)) {
      addNewLine(lineBuffer, LINE_LENGTH);
      parseLine(lineBuffer, instructions);
      if (sizeof(instructions) > 1) {
        for (int i = 0; i < MAX_INST_LEN; i++) {
          strlcpy(parsedLines[currentIndex][i], instructions[i], MAX_INST_LEN);
        }
        currentIndex++;
      }
    }
  }
  fclose(filePointer);
  return 0;
}
