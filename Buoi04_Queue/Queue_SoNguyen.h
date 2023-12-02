/*
	Họ và tên:	Huỳnh Thế Vinh
	MSSV:		2001210660
	Lớp:		12DHTH07
	Tiết/Buổi:	1-5 / ST4 / Buổi 4
*/

#ifndef Queue_SoNguyen_h
#define	Queue_SoNguyen_h

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// Define data type
typedef int ItemType;

// Single Node
struct QueueNode {
	ItemType Info;
	QueueNode* Next;
};

QueueNode* createQueueNode(ItemType x);
void showQueueNode(QueueNode* p);

// Single Linked List
struct Queue {
	QueueNode* Head;
	QueueNode* Tail;
};

void initQueue(Queue& queue); // Init empty list
bool isEmpty(Queue queue); // check empty in list
bool insertHead(Queue& queue, QueueNode* p); // Add node p into head
void showQueue(Queue queue); // Show list 

void createQueue_input(Queue& queue);
void createQueue_Auto(Queue& queue); // create int list random
void createList_Increase(Queue& queue);

void swap(ItemType& a, ItemType& b);
void sortIncrease(Queue& queue);
void sortDecrease(Queue& queue);

// Bai 2
bool remove(Queue& queue, ItemType &x);
bool showFirstQueue(Queue queue, ItemType& x);
bool showLastQueue(Queue queue, ItemType& x);
bool removeAll(Queue& queue, Queue &deletedQueue);

#endif