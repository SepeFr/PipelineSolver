#include "parser/instructionhelper.h"
#include "parser/instructionparser.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void parseComments(char line[MAX_INST_LEN]) {
  bool comments = false;
  int len = MAX_INST_LEN;
  for (int i = 0; i < len; i++) {
    if (comments) {
      line[i] = ' ';
    } else if (line[i] == '#') {
      line[i] = '\0';
      comments = true;
    }
  }
}

void strip(char str[MAX_INST_LEN]) {
  char *end;
  char *start = str;

  while (isspace((unsigned char)*start))
    start++;

  if (*start == 0) {
    str[0] = '\0';
    return;
  }

  size_t size = strlen(start);
  unsigned int len = 0;
  if (size > MAX_INST_LEN) {
    len = MAX_INST_LEN;
  } else {
    len = (unsigned int)size;
  }

  end = start + (int)len - 1;
  while (end > start && isspace((unsigned char)*end))
    end--;

  end[1] = '\0';

  if (start != str) {
    char temp[MAX_INST_LEN];
    for (unsigned int i = 0; i < len; i++) {
      temp[i] = start[i];
    }
    for (unsigned int i = 0; i < len; i++) {
      str[i] = temp[i];
    }
  }
}
