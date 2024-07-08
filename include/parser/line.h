#ifndef LINE_H
#define LINE_H

#define PROGRAM_SIZE 1024

// this way i can do if (type), and if not set the value is 0 :9
typedef enum type { RAritmLog = 1, IAritmLogA, IAritmLogI, ILoadSave, J } Type;

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
