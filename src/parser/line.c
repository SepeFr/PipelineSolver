#include "parser/line.h"
#include <stdio.h>

void printLine(Line *line) {
  printf("Name [%s]\n", line->name);
  switch (line->type) {
  case RAritmLog:
    printf("RAritmLog\n");
    break;
  case IAritmLogA:
    printf("IAritmLogA\n");
    break;
  case IAritmLogI:
    printf("IAritmLogI\n");
    break;
  case ILoadSave:
    printf("ILoadSave\n");
    break;
  case J:
    printf("J\n");
    break;
  }

  printf("Source Register %s\n", line->sourceRegister);
  printf("Target Register %s\n", line->targetRegister);
  printf("Destination Register %s\n", line->destinationRegister);
  printf("Immediate %s\n", line->immediate);
  printf("Address %s\n", line->address);
  printf("Label %s\n", line->label);
}

void printLineNoNL(Line *line) {
  printf("Name [%s] ", line->name);
  switch (line->type) {
  case RAritmLog:
    printf("RAritmLog ");
    break;
  case IAritmLogA:
    printf("IAritmLogA ");
    break;
  case IAritmLogI:
    printf("IAritmLogI ");
    break;
  case ILoadSave:
    printf("ILoadSave ");
    break;
  case J:
    printf("J ");
    break;
  }

  printf("Source Register %s ", line->sourceRegister);
  printf("Target Register %s ", line->targetRegister);
  printf("Destination Register %s ", line->destinationRegister);
  printf("Immediate %s ", line->immediate);
  printf("Address %s ", line->address);
  printf("Label %s ", line->label);
}
