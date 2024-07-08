#ifndef FILEPARSER_H
#define FILEPARSER_H

#include "parser/instructionparser.h"
#include "parser/line.h"
#define LINE_LENGTH 1024

int parseFile(const char filename[],
              char parsedLines[PROGRAM_SIZE][MAX_INST_COUNT][MAX_INST_LEN]);

#endif // FILEPARSER_H
