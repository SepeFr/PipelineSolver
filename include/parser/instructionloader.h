#ifndef INSTRUCTIONLOADER_H
#define INSTRUCTIONLOADER_H
#include "util/hashmap.h"

HashMap *loadIAritmLogA(const char *filename);
HashMap *loadIAritmLogI(const char *filename);
HashMap *loadILoadSave(const char *filename);
HashMap *loadRArithLog(const char *filename);
HashMap *loadJump(const char *filename);

#endif // INSTRUCTIONLOADER_H
