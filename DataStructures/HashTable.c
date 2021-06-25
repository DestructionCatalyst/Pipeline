#include "pch.h"
#include "framework.h"

#include "HashTable.h"

HashTable CreateHashTable(int size) {
	HashTable table;
	table.nodes = (Node**)malloc(sizeof(Node*) * size);

	table.size = size;
	table.stored = 0;
	table.collisionCount = 0;

	return table;
}