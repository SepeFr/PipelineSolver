#include "util/hashmap.h"
#include "parser/instructionparser.h"
#include "parser/line.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeMap(HashMap *map) {
  for (int i = 0; i < HASHMAP_SIZE; i++) {
    map->linkedLists[i].count = 0;
    for (int j = 0; j < MAX_ELEMENETS; j++) {
      map->linkedLists[i].nodes[j].name = NULL;
    }
  }
}

unsigned int hashName(char name[MAX_INST_LEN]) {
  const unsigned int p = 31;
  const unsigned int m = HASHMAP_SIZE;
  unsigned int hash = 17;
  unsigned int pow = 1;
  while (*name != '\0') {
    hash = (hash + (unsigned int)(*name - 'a' + 1) * pow) % m;
    pow = (pow * p) % m;
    name++;
  }
  return hash;
}

void insertHashMap(HashMap *hashMap, char name[MAX_INST_LEN], Type type) {
  unsigned int hash = hashName(name);
  char *nameCopy = strdup(name);
  if (nameCopy == NULL) {
    perror("Error copying the name");
    exit(0);
  }

  Element element = {.name = nameCopy, .type = type};

  int currCount = hashMap->linkedLists[hash].count;
  for (int i = 0; i < currCount; i++) {
    char *entryName = hashMap->linkedLists[hash].nodes[i].name;
    size_t entryLength = strlen(entryName);
    if (strncmp(nameCopy, entryName, entryLength) == 0) {
      free(nameCopy);
      return;
    }
  }

  if (currCount < MAX_ELEMENETS) {
    hashMap->linkedLists[hash].nodes[currCount] = element;
    hashMap->linkedLists[hash].count++;
  } else {
    fprintf(stderr, "Error : HashMap bucket is full\n");
    exit(0);
  }
}

HashLL *getHashMap(HashMap *hashMap, char name[MAX_INST_LEN]) {
  unsigned int hash = hashName(name);
  if (hashMap->linkedLists[hash].count == 0) {
    return NULL;
  }
  return &hashMap->linkedLists[hash];
}

void printHashMap(HashMap *map, char name[MAX_INST_LEN]) {
  HashLL *elements = getHashMap(map, name);
  if (elements == NULL) {
    printf("No entries found for %s.\n", name);
    return;
  }
  for (int i = 0; i < elements->count; i++) {
    Element element = elements->nodes[i];
    printf("%s - ", element.name);
    switch (element.type) {
    case RAritmLog:
      printf("RAritmLog");
      break;
    case IAritmLogA:
      printf("IAritmLogA");
      break;
    case IAritmLogI:
      printf("IAritmLogI");
      break;
    case ILoadSave:
      printf("ILoadSave");
      break;
    case J:
      printf("Jump");
      break;
    }
    printf(" ");
  }
  printf("\n");
}

void printHashMapAll(HashMap *map) {
  for (int i = 0; i < HASHMAP_SIZE; i++) {
    HashLL elements = map->linkedLists[i];
    for (int j = 0; j < elements.count; j++) {
      Element element = elements.nodes[j];
      printf("%s - ", element.name);
      switch (element.type) {
      case RAritmLog:
        printf("RAritmLog");
        break;
      case IAritmLogA:
        printf("IAritmLogA");
        break;
      case IAritmLogI:
        printf("IAritmLogI");
        break;
      case ILoadSave:
        printf("ILoadSave");
        break;
      case J:
        printf("Jump");
        break;
      }
      printf(" ");
    }
    if (map->linkedLists[i].count > 0) {
      printf("\n");
    }
  }
}
