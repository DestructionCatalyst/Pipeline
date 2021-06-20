#pragma once

#include <stdlib.h>

#include "Node.h"

typedef struct Queue {
	Node* start;
	Node* end;

	int length;
} Queue;

Queue CreateQueue();

//Put an item to the end of the queue
void Enqueue(Queue* queue, void* content);

//Delete an item from the start of the queue, and return it. If the queue is empty, return NULL
void* Dequeue(Queue* queue);

//Delete all nodes of the queue. Doesn't delete their actual content. Call before queue deletion
void ClearQueue(Queue* queue);