#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "line.h"
#include "util/hashmap.h"

Line *tokenize(char ***parsedInstructions);
HashMap **tokenizeRInstructions(char ***RInstructions);

#endif // TOKENIZER_H
