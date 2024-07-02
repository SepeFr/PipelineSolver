#ifndef HASHMAP_H
#define HASHMAP_H

#define HASHMAP_SIZE 256

#include "parser/line.h"

typedef struct {
  char *name;
  Type type;
} Element;

typedef struct hashNode {
  Element element;
  struct hashNode *next;
} HashNode;

typedef struct {
  HashNode *head;
  HashNode *curr;
} HashLL;

typedef struct {
  HashLL *linkedLists[HASHMAP_SIZE];
} HashMap;

int hashName(char *name);
void insertHashMap(HashMap *hashMap, char *name, Type type);
HashNode *getHashMap(HashMap *hashMap, char *name);
void printHashMap(HashMap *map, char *name);
void printHashMapAll(HashMap *map);
void inzializeMap(HashMap *map);

#endif // HASHMAP_H
