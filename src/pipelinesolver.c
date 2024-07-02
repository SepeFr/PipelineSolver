#include "parser/fileparser.h"
#include "parser/instructionloader.h"
#include "parser/instructionparser.h"
#include "parser/line.h"
#include "parser/tokenizer.h"
#include "pipeline.h"
#include "util/hashmap.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isLabel(char *str) {
  int lenght = strlen(str);
  bool found = false;

  for (int i = lenght - 1; i >= 0; i--) {
    if (str[i] == ':') {
      return true;
    }
  }
  return false;
}

void solve(char ***lines, HashMap *instructions) {
  printf("Identifying Instructions!\n");
  for (int i = 0; i < PROGRAM_SIZE; i++) {
    if (lines[i] != NULL) {
      char *name = lines[i][0];
      printf("Current Instruction : %s\n", name);
      if (isLabel(name)) {
        printf("Skipping Label\n");
        continue;
      }
      if (strncmp("syscall", name, strlen("syscall")) == 0) {
        printf("Skipping Syscall\n");
        continue;
      }
      HashNode *node = getHashMap(instructions, name);
      while (node != NULL) {
        if (strncmp(node->element.name, name, strlen(node->element.name)) ==
            0) {
          break;
        }
        node = node->next;
      }
      if (node == NULL) {
        continue;
      }
      printf("Found Instruction %s - His type is ", node->element.name);
      switch (node->element.type) {
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
      node = node->next;

      printf("\n");
    }
  }
}

void solvePipeline(char *file) {
  loadMap();
  HashMap *instructionMap = loadRArithLog("res/instRAritmLog.txt");
  loadILoadSave("res/instILoadSave.txt");
  loadIAritmLogA("res/instIAritmLogA.txt");
  loadIAritmLogI("res/instIAritmLogI.txt");
  loadJump("res/Jump.txt");

  char ***parsedLines = parseFile(file);
  printParsedLines(parsedLines);

  solve(parsedLines, instructionMap);

  freeParsedLines(parsedLines);
}
