#include "pch.h"
#include "framework.h"

#include "Node.h"

Node* CreateNode(void* content, Node* next) {

	Node* node = (Node*)malloc(sizeof(Node));

	node->content = content;
	node->next = next;

	return node;
}
