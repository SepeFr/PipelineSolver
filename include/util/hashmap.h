#ifndef HASHMAP_H
#define HASHMAP_H

#include "parser/instructionparser.h"
#define HASHMAP_SIZE 256
#define MAX_ELEMENETS 128

#include "parser/line.h"

typedef struct {
  char *name;
  Type type;
} Element;

typedef struct {
  Element nodes[MAX_ELEMENETS];
  int count;
} HashLL;

typedef struct {
  HashLL linkedLists[HASHMAP_SIZE];
} HashMap;

unsigned int hashName(char name[MAX_INST_LEN]);
void insertHashMap(HashMap *hashMap, char name[MAX_INST_LEN], Type type);
HashLL *getHashMap(HashMap *hashMap, char name[MAX_INST_LEN]);
void printHashMap(HashMap *map, char name[MAX_INST_LEN]);
void printHashMapAll(HashMap *map);
void initializeMap(HashMap *map);

#endif // HASHMAP_H
