#pragma once

#include <stdlib.h>

#include "Node.h"

typedef struct HashTable {
	Node** nodes;
	int size;
	int stored;
	int collisionCount;
} HashTable;

HashTable CreateHashTable(int size);