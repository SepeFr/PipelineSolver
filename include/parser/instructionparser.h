#ifndef INSTRUCTIONPARSER_H
#define INSTRUCTIONPARSER_H

#include "parser/line.h"
#define MAX_INST_LEN 32
#define MAX_INST_COUNT 10

void parseLine(char str[], char instructions[PROGRAM_SIZE][MAX_INST_LEN]);
void printParsedLines(char line[PROGRAM_SIZE][MAX_INST_COUNT][MAX_INST_LEN]);

#endif // INSTRUCTIONPARSER_H
