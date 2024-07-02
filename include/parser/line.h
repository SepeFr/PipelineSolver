#ifndef LINE_H
#define LINE_H

#define PROGRAM_SIZE 1024

typedef enum type { RAritmLog, IAritmLogA, IAritmLogI, ILoadSave, J } Type;

typedef struct {
  char *name;
  Type type;
  char *sourceRegister;
  char *targetRegister;
  char *destinationRegister;
  char *immediate;
  char *address;
  char *label;
} Line;

void printLine(Line *line);
void printLineNoNL(Line *line);

#endif // LINE_H
