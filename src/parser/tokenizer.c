#include "parser/tokenizer.h"
#include "parser/line.h"
#include "util/hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInstructionNumber(char ***instructions) {
  int total = 0;
  while (*instructions != NULL) {
    instructions++;
    total++;
  }
  return total;
}

Line *tokenize(char ***instructions) { getInstructionNumber(instructions); }
