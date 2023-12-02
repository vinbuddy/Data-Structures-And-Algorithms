#ifndef DSLKD_BaiHat_h
#define DSLKD_BaiHat_h

#include "BaiHat.h"

// Single Node
struct SNode {
	ItemType Info;
	SNode* Next;
};

SNode* createSNode(ItemType x);
void showSNode(SNode* p);
void initSList(SList& slist); // Init empty list
bool insertTail(SList& slist, SNode* p);
bool isEmpty(SList slist);

void docTTBaiHat(FILE* fi, ItemType& x);
void luuTTBaiHat(FILE* fo, ItemType x);


// Single Linked List
struct SList {
	SNode* Head;
	SNode* Tail;
};

void docDuLieu(SList& slist, char fileName[]);
void luuDuLieu(SList slist, char fileName[]);

void showSlist(SList slist);

#endif