#include "pch.h"
#include "framework.h"

#include "HashTable.h"

HashTable CreateHashTable(int size) {
	HashTable table;
	table.nodes = (Node**)calloc(size, sizeof(Node*));

	table.size = size;
	table.stored = 0;
	table.collisionCount = 0;

	return table;
}

int AddPair(HashTable* table, KeyValuePair* keyValuePair) {

	// Resize if needed

	int hash = HashFunctionHorner(keyValuePair->key, table->size);

	Node* prevNode = NULL;
	Node* targetNode = table->nodes[hash];

	while (targetNode != NULL) {
		if (!strcmp(((KeyValuePair*)targetNode->content)->key, keyValuePair->key))
			return 0;

		prevNode = targetNode;
		targetNode = targetNode->next;
		
		table->collisionCount++;
	}

	if (prevNode != NULL)
		prevNode->next = CreateNode(keyValuePair, NULL);
	else
		table->nodes[hash] = CreateNode(keyValuePair, NULL);

	table->stored++;

	return 1;
}

int Add(HashTable* table, const char* key, void* value) {
	KeyValuePair* pair = (KeyValuePair*) malloc(sizeof(KeyValuePair));
	pair->key = key;
	pair->value = value;

	return AddPair(table, pair);
}

void* Find(HashTable* table, const char* key) {

	int hash = HashFunctionHorner(key, table->size);

	Node* targetNode = table->nodes[hash];
	
	while ((targetNode != NULL) && (strcmp(((KeyValuePair*)(targetNode->content))->key, key))) {
		targetNode = targetNode->next;
	}

	if (targetNode == NULL)
		return NULL;

	return ((KeyValuePair*)(targetNode->content))->value;
}