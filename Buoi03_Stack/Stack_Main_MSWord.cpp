#include <stdio.h>
#include <conio.h>

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

void option();
void process();
void action();

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

void initStack(Stack& st)
{
	st.top = NULL;
}

bool isEmpty(Stack st)
{
	return (st.top == NULL);
}

bool push(Stack& st, StackNode* pnew)
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

bool pop(Stack& st, ItemType& x) {
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

int _main() {
	process();
	_getch();
	return 0;

}

// Bai 2 MS WORD

void option() {
	printf("\n----------------THAO TAC--------------------\n");
	printf("\n 1. Delete char");
	printf("\n 2. Delete select words");
	printf("\n 3. Typing char");
	printf("\n 4. Bold");
	printf("\n 5. Italic");
	printf("\n 6. Underline");
	printf("\n--------------------------------------------\n");
}

void action() 
{
	printf("\n----------------ACTION--------------------\n");
	printf("\n 1. Do");
	printf("\n 2. Undo");
	printf("\n 3. Redo");
	printf("\n--------------------------------------------\n");
}


void process() {
	Stack st1, st2;

}

