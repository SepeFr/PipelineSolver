#ifndef INSTRUCTIONPARSER_H
#define INSTRUCTIONPARSER_H

#define MAX_INST_LEN 32
#define MAX_INST_COUNT 10

char **instructionParse(char *str);
char **parseLine(char *str);
void freeParsedLines(char ***lines);
void printParsedLines(char ***lines);

#endif // INSTRUCTIONPARSER_H
