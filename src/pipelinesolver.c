#include "parser/fileparser.h"
#include "parser/instructionhelper.h"
#include "parser/instructionloader.h"
#include "parser/instructionparser.h"
#include "parser/line.h"
#include "pipeline.h"
#include "util/hashmap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static bool isLabel(char str[MAX_INST_LEN]) {
  int len = MAX_INST_LEN;

  for (int i = len - 1; i >= 0; i--) {
    if (str[i] == ':') {
      return true;
    }
  }
  return false;
}

static void solve(char lines[PROGRAM_SIZE][MAX_INST_COUNT][MAX_INST_LEN],
                  HashMap *instructionMap) {
  for (int i = 0; i < PROGRAM_SIZE; i++) {
    char name[MAX_INST_LEN] = {0};
    strlcpy(name, lines[i][0], MAX_INST_LEN - 1);
    if (isLabel(name)) {
      continue;
    }
    if (strlen(name) <= 1) {
      continue;
    }
    HashLL *instBuffer = getHashMap(instructionMap, name);
    if (instBuffer == NULL) {
      printf("Instruction : %s - not present in the Map\n", name);
      continue;
    }
    Element *node;
    for (int j = 0; j < MAX_ELEMENETS; j++) {
      node = &instBuffer->nodes[j];
      if (node->name == NULL) {
        printf("Instruction :%s : Node's name not present! Possible hash "
               "collision",
               name);
        return;
      }
      if (strncmp(node->name, name, MAX_INST_LEN) == 0) {
        break;
      }
    }
    if (node == NULL) {
      printf("Instruction : %s False Positive \n", name);
      return;
    }
    printf("Found Instruction %s - His type is ", node->name);
    switch (node->type) {
    case RAritmLog:
      printf("RAritmLog");
      break;
    case IAritmLogA:
      printf("IAritmLogA");
      break;
    case IAritmLogI:
      printf("IAritmLogI");
      break;
    case ILoadSave:
      printf("ILoadSave");
      break;
    case J:
      printf("Jump");
      break;
    }
    printf(" ");
    printf("\n");
  }
}

void solvePipeline(char *file) {
  HashMap *instructionMap = loadRArithLog("res/instRAritmLog.txt");
  loadILoadSave("res/instILoadSave.txt");
  loadIAritmLogA("res/instIAritmLogA.txt");
  loadIAritmLogI("res/instIAritmLogI.txt");
  loadJump("res/Jump.txt");

  char parsedLines[PROGRAM_SIZE][MAX_INST_COUNT][MAX_INST_LEN] = {0};
  parseFile(file, parsedLines);
  printParsedLines(parsedLines);

  solve(parsedLines, instructionMap);
  printf("\n");
}
