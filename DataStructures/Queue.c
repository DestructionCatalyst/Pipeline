#include "pch.h"
#include "framework.h"

#include "Queue.h"

Queue CreateQueue() {
	Queue q;

	q.start = NULL;
	q.end = NULL;
	q.length = 0;

	return q;
}

void Enqueue(Queue* queue, void* content) {
	Node* newNode = CreateNode(content, NULL);

	if (queue->length == 0) {
		queue->start = newNode;
		queue->end = newNode;
	}
	else {
		queue->end->next = newNode;
		queue->end = newNode;
	}

	++queue->length;
}

void* Dequeue(Queue* queue) {
	if (queue->length == 0)
		return NULL;

	void* content = queue->start->content;

	Node* oldStart = queue->start;
	queue->start = queue->start->next;

	if (queue->length == 1)
		queue->end = NULL;

	free(oldStart);
	--queue->length;

	return(content);
}

void ClearQueue(Queue* queue) {
	Node* iter = queue->start;
	Node* next;

	while (iter != NULL) {
		next = iter->next;
		free(iter);
		iter = next;
	}

	queue->start = NULL;
	queue->end = NULL;
	queue->length = 0;
}