#include <math.h>
#include <stdio.h>

#include "pipeline.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <file>\n", argv[0]);
    return 1;
  }

  solvePipeline(argv[1]);

  return 0;
}
