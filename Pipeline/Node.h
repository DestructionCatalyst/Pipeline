#pragma once

#include <stdlib.h>

typedef struct Node {
	void* content;
	struct Node* next;
} Node;

Node* CreateNode(void* content, Node* next);
