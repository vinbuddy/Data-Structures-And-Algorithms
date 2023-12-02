﻿#ifndef BTree_h
#define BTree_h

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

#define M 5
typedef int ItemType;
struct BNode {
	int numTree; /* numTree < M (Số khóa trong nút sẽ luôn ít hơn M của cây B) */
	ItemType Keys[M - 1]; /*Mảng chứa các khóa*/
	BNode* Branch[M]; /* numTree + 1 (M con trỏ sẽ được sử dụng) */
};

struct BTree
{
	BNode* Root; /* Con trỏ quản lý node gốc */
};
typedef BNode* NodePtr;

enum KeyStatus { Duplicate, SearchFailure, Success, InsertIt, LessKeys };

void initBTree(BTree& bt);
KeyStatus insertNode(NodePtr pCurrent, ItemType key, ItemType* upKey, NodePtr* newNode);
void insert(NodePtr& root, ItemType key);
void displayBTree(NodePtr root, ItemType key);
KeyStatus remove(NodePtr& root, NodePtr pCurrent, ItemType key);
void deleteNode(NodePtr& root, ItemType key);
NodePtr searchNode(NodePtr root, ItemType key);
void search(NodePtr root, ItemType key);
enum KeyStatus insertNode(NodePtr root, ItemType key, ItemType* y, NodePtr* u);
int searchPosition(ItemType key, ItemType* keyArray, int numTree);
enum KeyStatus remove(NodePtr& root, NodePtr pCurrent, ItemType key);

#endif