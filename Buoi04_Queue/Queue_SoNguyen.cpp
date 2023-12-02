#include "Queue_SoNguyen.h"

QueueNode* createQueueNode(ItemType x)
{
	QueueNode* p = new QueueNode;

	if (p == NULL) {
		printf("Khong du bo nho de cap phat");
		_getch();
		return NULL;
	}

	p->Info = x;
	p->Next = NULL;

	return p;

}

void showQueueNode(QueueNode* p)
{
	printf("%4d", p->Info);
}

void initQueue(Queue& queue)
{
	queue.Head = NULL;
	queue.Tail = NULL;
}

bool isEmpty(Queue queue)
{
	return (queue.Head == NULL);
}

bool insertHead(Queue& queue, QueueNode* p) 
{
	if (queue.Head == NULL)
		queue.Head = queue.Tail = p;
	else {
		p->Next = queue.Head;
		queue.Head = p;
	}

	return true;
}

bool insertTail(Queue& queue, QueueNode* p)
{
	if (p == NULL) return false;
	if (isEmpty(queue) == true)
		queue.Head = queue.Tail = p;
	else {
		queue.Tail->Next = p;
		queue.Tail = p;
	}

	return true;
}

void showQueue(Queue queue) // Show list 
{
	if (isEmpty(queue)) {
		printf("Danh sach rong");
		return;
	}

	QueueNode* p = queue.Head;

	printf("\nNoi dung cua danh sach la: ");
	while (p != NULL)
	{
		showQueueNode(p);
		p = p->Next;
	}
}

void createQueue_Auto(Queue& queue) {
	int n;
	ItemType x;
	QueueNode* p;

	initQueue(queue);
	printf("\nNhap so node can tao: ");
	scanf_s("%d", &n);

	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++) {
		x = rand() % 100;
		p = createQueueNode(x);
		insertHead(queue, p);
	}
}

void createQueue_input(Queue& queue) {
	int n;
	ItemType x;
	QueueNode* p;

	initQueue(queue);

	printf("Nhap so node: ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("\nNhap gia tri cho node [%d]", i);
		scanf_s("%d", &x);

		p = createQueueNode(x);
		insertHead(queue, p);

	}
}

QueueNode* findQueueNode(Queue queue, ItemType x)
{
	QueueNode* p = queue.Head;

	while (p != NULL)
	{
		if (p->Info == x)
			return p;
		p = p->Next;
	}

	return NULL; // Not Found
}

void swap(ItemType& a, ItemType& b) {
	ItemType temp = a;
	a = b;
	b = temp;
}

// Bai 2
bool remove(Queue& queue, ItemType& x) {

	if (isEmpty(queue))
		return false;

	QueueNode* p = queue.Head;
	queue.Head = queue.Head->Next; 

	if (queue.Head == NULL)
		queue.Tail = NULL;

	x = p->Info; // get info delete node
	delete p;

	return true;
}

bool showFirstQueue(Queue queue, ItemType& x) {
	if (isEmpty(queue))
		return false;

	QueueNode* p = queue.Head;

	x = p->Info;

	return true;
}

bool showLastQueue(Queue queue, ItemType& x) {
	if (isEmpty(queue))
		return false;

	x = queue.Tail->Info;

	return true;
}

bool removeAll(Queue& queue, Queue& deletedQueue) {
	if (isEmpty(queue))
		return false;

	while (queue.Head != NULL)
	{
		QueueNode* p = queue.Head;
		queue.Head = queue.Head->Next;

		QueueNode* q;
		q = createQueueNode(p->Info);
		insertTail(deletedQueue, q);

		delete p;
	}

	queue.Tail = NULL;
	return true;
}



void createList_Increase(Queue& queue) {
	int n;
	ItemType x;
	QueueNode* p;

	initQueue(queue);
	printf("\nNhap so node can tao: ");
	scanf_s("%d", &n);

	srand((unsigned)time(NULL));

	for (int i = 1; i < n; i++) {
		x = rand() % 100;
		p = createQueueNode(x);
		insertHead(queue, p);
	}

	sortIncrease(queue);
}
void sortIncrease(Queue& queue) {
	for (QueueNode* i = queue.Head; i != queue.Tail; i = i->Next)
		for (QueueNode* j = i->Next; j != NULL; j = j->Next)
			if ((i->Info) > (j->Info)) {
				swap(i->Info, j->Info);
			}
}
void sortDecrease(Queue& queue) {
	for (QueueNode* i = queue.Head; i != queue.Tail; i = i->Next)
		for (QueueNode* j = i->Next; j != NULL; j = j->Next)
			if ((i->Info) < (j->Info)) {
				swap(i->Info, j->Info);
			}
}

