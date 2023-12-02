﻿#include "Buoi02_DSLKD.h"

SNode* createSNode(ItemType x)
{
	SNode* p = new SNode;

	if (p == NULL) {
		printf("Khong du bo nho de cap phat");
		_getch();
		return NULL;
	}

	p->Info = x;
	p->Next = NULL;

	return p;

}

void showSNode(SNode* p)
{
	printf("%4d", p->Info);
}

void initSList(SList& slist)
{
	slist.Head = NULL;
	slist.Tail = NULL;
}

bool isEmpty(SList slist)
{
	return (slist.Head == NULL);
}

bool insertHead(SList& slist, SNode* p) // Add node p into head
{
	p->Next = slist.Head;
	slist.Head = p;
	return true;
}

bool insertTail(SList& slist, SNode* p)
{
	if (p == NULL) return false;
	if (isEmpty(slist) == true)
		slist.Head = slist.Tail = p;
	else {
		slist.Tail->Next = p;
		slist.Tail = p;
	}

	return true;
}

void showSList(SList slist) // Show list 
{
	if (isEmpty(slist)) {
		printf("Danh sach rong");
		return;
	}

	SNode* p = slist.Head;

	printf("\nNoi dung cua danh sach la: ");
	while (p != NULL)
	{
		showSNode(p);
		p = p->Next;
	}
}

void createList_Auto(SList& slist) {
	int n;
	ItemType x;
	SNode* p;

	initSList(slist);
	printf("\nNhap so node can tao: ");
	scanf_s("%d", &n);

	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++) {
		x = rand() % 100;
		p = createSNode(x);
		insertTail(slist, p);
	}
}

void createSList_input(SList& slist) {
	int n;
	ItemType x;
	SNode* p;

	initSList(slist);

	printf("Nhap so node: ");
	scanf_s("%d", &n);

	for (int i = 1; i < n; i++) {
		printf("\nNhap gia tri cho node [%d]", i);
		scanf_s("%d", &x);

		p = createSNode(x);
		insertHead(slist, p);

	}
}

SNode* findSNode(SList slist, ItemType x)
{
	SNode* p = slist.Head;

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

void createList_Increase(SList& slist) {
	int n;
	ItemType x;
	SNode* p;

	initSList(slist);
	printf("\nNhap so node can tao: ");
	scanf_s("%d", &n);

	srand((unsigned)time(NULL));

	for (int i = 1; i < n; i++) {
		x = rand() % 100;
		p = createSNode(x);
		insertHead(slist, p);
	}

	sortIncrease(slist);
}
void sortIncrease(SList& slist) {
	for (SNode* i = slist.Head; i != slist.Tail; i = i->Next)
		for (SNode* j = i->Next; j != NULL; j = j->Next)
			if ((i->Info) > (j->Info)) {
				swap(i->Info, j->Info);
			}
}

void sortDecrease(SList& slist) {
	for (SNode* i = slist.Head; i != slist.Tail; i = i->Next)
		for (SNode* j = i->Next; j != NULL; j = j->Next)
			if ((i->Info) < (j->Info)) {
				swap(i->Info, j->Info);
			}
}

bool deleteHead(SList& slist) {
	// Xóa node p ở đầu list
	if (isEmpty(slist))
		return false;

	SNode* p = slist.Head;

	slist.Head = slist.Head->Next;
	p->Next = NULL;

	if (slist.Head == NULL)
		slist.Tail = NULL;
	
	delete p;
	return true;
}

bool deleteTail(SList& slist) {

	if (isEmpty(slist))
		return false;
	
	SNode* q = slist.Head, *p = slist.Tail;

	// Tìm node kế cuối -> save
	while (q->Next != slist.Tail) {
		q = q->Next;
	}

	
	slist.Tail = q; // Dời node tail = kế cuối
	slist.Tail->Next = NULL; // Cố định NULL ở vị trí tiếp theo
	delete p;
	return true;

}

bool deleteAfter(SList& slist, SNode* q) {
	if (isEmpty(slist))
		return false;
	
	// p đứng sau q
	SNode* p = q->Next;
	q->Next = p->Next;
	p->Next = NULL;
	delete p;
	return true;
}

bool deleteXNode(SList& slist, ItemType x) {
	if (isEmpty(slist))
		return false;

	SNode *p = findSNode(slist, x);
	SNode* g = new SNode;

	if (p == NULL) // NotFound
		printf("\nKhong tim thay node X co gia tri la %d", x);
	else {
		if (slist.Head == p) {
			deleteHead(slist);
		}
		if (slist.Tail == p) {
			deleteTail(slist);
		}
		
		for (SNode* i = slist.Head; i != NULL; i = i->Next) {
			if (i->Info == x) {
				g->Next = i->Next;
				delete i;
				return true;
			}

			g = i;
		}
	}
	
	return true;
}

bool deleteAll(SList& slist) {
	if (isEmpty(slist))
		return false;


	SNode* p = slist.Head;
	while (slist.Head != NULL)
	{
		p = slist.Head;
		slist.Head = slist.Head->Next;
		delete p;
	}

	return true;
}