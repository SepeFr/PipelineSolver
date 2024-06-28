#ifndef LINE_H
#define LINE_H

#define PROGRAM_SIZE 1024

typedef struct {
  char type;
  char *sourceAddress;
  char *targetAddress;
  char *destinationAddress;
  char *immediate;
  char *shamt;
  char *funct;
  char *jumpAddress;
} Line;

#endif // LINE_H
