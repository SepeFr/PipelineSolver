#include "util/hashmap.h"
#include "parser/line.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hashName(char *name) {
  const int p = 31;
  const int m = HASHMAP_SIZE;
  int hash = 17;
  int pow = 1;
  while (*name != '\0') {
    hash = (hash + (*name - 'a' + 1) * pow) % m;
    pow = (pow * p) % m;
    name++;
  }
  return hash;
}

void insertHashMap(HashMap *hashMap, char *name, Type type) {
  int hash = hashName(name);

  Element element = {.name = strdup(name), .type = type};

  HashNode *newNode = malloc(sizeof(HashNode));
  newNode->element = element;
  newNode->next = NULL;

  if (hashMap->linkedLists[hash] == NULL) {
    HashLL *linkedList = malloc(sizeof(HashLL));
    linkedList->curr = newNode;
    linkedList->head = newNode;
    hashMap->linkedLists[hash] = linkedList;
  } else {
    HashNode *node = hashMap->linkedLists[hash]->head;
    while (node != NULL) {
      if (strncmp(node->element.name, name, strlen(node->element.name)) == 0) {
        return;
      }
      node = node->next;
    }
    hashMap->linkedLists[hash]->curr->next = newNode;
    hashMap->linkedLists[hash]->curr = newNode;
  }
}

HashNode *getHashMap(HashMap *hashMap, char *name) {
  int hash = hashName(name);
  if (hashMap->linkedLists[hash] == NULL) {
    return NULL;
  }
  return hashMap->linkedLists[hash]->head;
}

void printHashMap(HashMap *map, char *name) {
  HashNode *node = getHashMap(map, name);

  if (node == NULL) {
    printf("No entries found for %s.\n", name);
  } else {
    while (node != NULL) {
      printf("%s - ", node->element.name);
      switch (node->element.type) {
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
      node = node->next;
    }
    printf("\n");
  }
}

void printHashMapAll(HashMap *map) {
  for (int i = 0; i < HASHMAP_SIZE; i++) {
    if (map->linkedLists[i] != NULL) {
      HashNode *node = map->linkedLists[i]->head;
      while (node != NULL) {
        printf("%s - ", node->element.name);
        switch (node->element.type) {
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
        node = node->next;
      }
      printf("\n");
    }
  }
}
