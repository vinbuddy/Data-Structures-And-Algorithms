#include "Stack_DoiCoSo.h"

StackNode* createStackNode(ItemType x)
{
	StackNode* p = new StackNode;

	if (p == NULL) {
		printf("Khong du bo nho de cap phat");
		_getch();
		return NULL;
	}

	p->Info = x;
	p->Next = NULL;

	return p;

}

void initStack(Stack &st)
{
	st.top = NULL;
}

bool isEmpty(Stack st)
{
	return (st.top == NULL);
}

bool push(Stack &st, StackNode* pnew)
{
	if (pnew == NULL) 
		return false;

	if (isEmpty(st)) {
		st.top = pnew;
	}
	else {
		pnew->Next = st.top;
		st.top = pnew;
	}

	return true;
}

bool pop(Stack &st, ItemType &x) {
	if (isEmpty(st))
		return false;

	StackNode* p = st.top;

	p = st.top;
	st.top = st.top->Next;
	x = p->Info;

	delete p;

	return true;
}

void showStackNode(Stack st)  // Show list 
{
	if (isEmpty(st)) {
		printf("Danh sach rong");
		return;
	}

	StackNode* p = st.top;

	printf("\nNoi dung cua danh sach la: ");
	while (p != NULL)
	{
		printf("%d ", p->Info);
		p = p->Next;
	}
}

void createStack_auto(Stack& st) {
	int n;
	ItemType x;
	StackNode* p;

	initStack(st);
	printf("\nNhap so node can tao: ");
	scanf_s("%d", &n);

	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++) {
		x = rand() % 100;
		p = createStackNode(x);
		push(st, p);
	}
}

void xuat(ItemType x) {
	if (x < 10)
		printf("%d ", x);
	else {
		switch (x)
		{
		case 10: printf("A"); break;
		case 11: printf("B"); break;
		case 12: printf("C"); break;
		case 13: printf("D"); break;
		case 14: printf("E"); break;
		case 15: printf("F"); break;

		default:
			break;
		}
	}
}

void stack_DoiCoSo(int n, int a) {
	ItemType x, temp = n;

	StackNode* p;

	Stack st;

	initStack(st);

	while (n > 0)
	{
		x = n % a;
		n /= a;
		p = createStackNode(x);
		push(st, p);
	}
	printf("\nKet qua doi %d tu he 10 sang he %d la: ", temp, a);

	while (1) {
		if (pop(st, x) == true) {
			xuat(x);
		}
		else {
			break;
		}
	}
}

