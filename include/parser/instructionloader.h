#ifndef INSTRUCTIONLOADER_H
#define INSTRUCTIONLOADER_H
#include "util/hashmap.h"

void loadMap();
HashMap *loadIAritmLogA(char *filename);
HashMap *loadIAritmLogI(char *filename);
HashMap *loadILoadSave(char *filename);
HashMap *loadRArithLog(char *filename);
HashMap *loadJump(char *filename);

#endif // INSTRUCTIONLOADER_H
