#pragma once

#include <stdlib.h>
#include <string.h>

#include "Node.h"
#include "StringHashFunction.h"

typedef struct HashTable {
	Node** nodes;
	int size;
	int stored;
	int collisionCount;
} HashTable;

typedef struct KeyValuePair {
	const char* key;
	void* value;
} KeyValuePair;

HashTable CreateHashTable(int size);

int Add(HashTable* table, const char* key, void* value);

int AddPair(HashTable* table, KeyValuePair* keyValuePair);

void* Find(HashTable* table, const char* key);

