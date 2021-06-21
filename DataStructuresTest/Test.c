#include "Test.h"

void* TestNode() {
	int arr[10];

	Node* list = NULL;
	Node* prev = NULL;

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;

		if (list == NULL) {
			list = CreateNode(arr, NULL);
			prev = list;
		}
		else {
			prev->next = CreateNode(arr + i, NULL);
			prev = prev->next;
		}
	}

	int a = 100;
	//list->content = &a;

	Node* cur = list;
	int i = 0;

	while (cur != NULL) {

		assert_equals(*(int*)cur->content, i, "List content is corrupted");

		cur = cur->next;
		++i;
	}

	pass_test;
}

void* TestQueue() {

	Queue q = CreateQueue();

	assert_equals(Dequeue(&q), NULL, "Getting from empty queue doesn't return NULL");

	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i * i;
	}

	Enqueue(&q, arr);
	Enqueue(&q, arr + 2);

	assert_equals(*(int*)Dequeue(&q), 0, "Error getting element, length = 2");

	Enqueue(&q, arr + 3);

	assert_equals(*(int*)Dequeue(&q), 4, "Error getting element, length = 2");
	assert_equals(*(int*)Dequeue(&q), 9, "Error getting element, length = 1");

	Enqueue(&q, arr + 4);
	Enqueue(&q, arr + 6);
	Enqueue(&q, arr + 8);
	Enqueue(&q, arr + 8);

	assert_equals(*(int*)Dequeue(&q), 16, "Error getting element, length = 4");

	ClearQueue(&q);
	assert_equals(Dequeue(&q), NULL, "Getting from cleared queue doesn't return NULL");

	//Make sure clearing 2 times doesn't cause a crash
	ClearQueue(&q);

	Enqueue(&q, arr);
	Enqueue(&q, arr + 1);
	assert_equals(*(int*)Dequeue(&q), 0, "Error getting element, length = 2, after clearing");
	ClearQueue(&q);

	pass_test;
}