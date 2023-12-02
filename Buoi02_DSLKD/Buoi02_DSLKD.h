/*
	Họ và tên:	Huỳnh Thế Vinh
	MSSV:		2001210660
	Lớp:		12DHTH07
	Tiết/Buổi:	1-5 / ST4 / Buổi 2
*/

#ifndef Buoi02_SDLKD_h
#define	Buoi02_SDLKD_h

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// Define data type
typedef int ItemType;

// Single Node
struct SNode {
	ItemType Info;
	SNode* Next;
};

SNode* createSNode(ItemType x);
void showSNode(SNode* p);

// Single Linked List
struct SList {
	SNode* Head;
	SNode* Tail;
};

void initSList(SList& slist); // Init empty list
bool isEmpty(SList slist); // check empty in list
bool insertHead(SList& slist, SNode* p);
bool insertTail(SList& slist, SNode* p);
void showSList(SList slist); // Show list 

void createSList_input(SList& slist);
void createList_Auto(SList& slist); // create int list random
void createList_Increase(SList& slist);

void swap(ItemType& a, ItemType& b);
void sortIncrease(SList& slist);
void sortDecrease(SList& slist);

// Buổi 2
bool deleteHead(SList& slist);
bool deleteTail(SList& slist);
bool deleteAfter(SList& slist, SNode* q);
bool deleteXNode(SList& slist, ItemType x);
bool deleteAll(SList& slist);


#endif