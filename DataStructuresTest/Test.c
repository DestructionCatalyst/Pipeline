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

void* TestHashFunction() {
	
	const char* str1 = "Hello World!";
	const char* str2 = "Test Test";

	assert_equals(59, HashFunctionHorner(str1, 64), "Hash function is inconsistent");
	assert_equals(65, HashFunctionHorner(str2, 128), "Hash function is inconsistent");

	pass_test;
}

void* TestHashTable() {
	HashTable table = CreateHashTable(8);

	assert_equals(table.size, 8, "Hash table creation error");
	assert_equals(table.stored, 0, "Hash table creation error");
	assert_equals(table.collisionCount, 0, "Hash table creation error");

	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i + 1;
	}

	assert_equals(Add(&table, "item1", a), 1, "Error adding new item");

	assert_equals(
		*(int*)(((KeyValuePair*)table.nodes[HashFunctionHorner("item1", 8)]->content)->value),
		1, "New item not found in place");

	assert_equals(Add(&table, "item1", a), 0, "Duplicate keys not detected");

	assert_equals(*(int*)Find(&table, "item1"), 1, "Error finding item");
	assert_equals(Find(&table, "item2"), NULL, "Error identifying non-existance of item");

	assert_equals(Add(&table, "item2", a + 1), 1, "Error adding new item");
	assert_equals(Add(&table, "item3", a + 2), 1, "Error adding new item");
	assert_equals(Add(&table, "item4", a + 3), 1, "Error adding new item");
	assert_equals(Add(&table, "item5", a + 4), 1, "Error adding new item");
	assert_equals(Add(&table, "item6", a + 5), 1, "Error adding new item");
	assert_equals(Add(&table, "item7", a + 6), 1, "Error adding new item");
	assert_equals(Add(&table, "item8", a + 7), 1, "Error adding new item");
	assert_equals(Add(&table, "item9", a + 8), 1, "Error adding new item");

	assert_equals(*(int*)Find(&table, "item7"), 7, "Error finding item");
	assert_equals(*(int*)Find(&table, "item9"), 9, "Error finding item");
	assert_equals(*(int*)Find(&table, "item5"), 5, "Error finding item");
	assert_equals(*(int*)Find(&table, "item1"), 1, "Error finding item");
	assert_equals(*(int*)Find(&table, "item3"), 3, "Error finding item");
	assert_equals(Find(&table, "item0"), NULL, "Error identifying non-existance of item");


	pass_test;
}
