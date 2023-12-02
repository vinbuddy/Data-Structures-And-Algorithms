/*
	Họ và tên:	Huỳnh Thế Vinh
	MSSV:		2001210660
	Lớp:		12DHTH07
	Tiết/Buổi:	1-5 / ST4 / Buổi 3
*/

#ifndef DSLKD_SoNguyen_h
#define	DSLKD_SoNguyen_h

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// Define data type
typedef int ItemType;

// Single Node
struct StackNode {
	ItemType Info;
	StackNode* Next;
};

struct Stack
{
	StackNode* top;
};

StackNode* createStackNode(ItemType x);

void initStack(Stack &st); // Init empty list
bool isEmpty(Stack st); // check empty in list
bool push(Stack& st, StackNode* pnew);
bool pop(Stack& st, ItemType &x);
void showStackNode(Stack st); // Show list stack

void createStack_auto(Stack& st);

void xuat(ItemType x);
void stack_DoiCoSo(int n, int a);

void thaoTac();
#endif