#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef char Itemtype;

struct StackNode {
	Itemtype Info;
	StackNode* Next;
};

struct Stack {
	StackNode* top;
};

StackNode* createStackNode(Itemtype Value)
{
	StackNode* p = new StackNode;
	if (p == NULL)
	{
		printf("Khong du bo nho de cap phap!\n");
		return NULL;
	}
	p->Info = Value;
	p->Next = NULL;
	return p;
}

void InitStack(Stack& st)
{
	st.top = NULL;
}

int isEmpty(Stack st)
{
	if (st.top == NULL)
		return 1;
	return 0;
}

int push(Stack& st, StackNode* p)
{
	if (p == NULL)
		return 0;
	if (isEmpty(st) == 1)
		st.top = p;
	else
	{
		p->Next = st.top;
		st.top = p;
	}
	return 1;
}

int pop(Stack& st, Itemtype& X)
{
	StackNode* p;
	if (isEmpty(st) == 1)
		return 0;
	else
	{
		p = st.top;
		st.top = st.top->Next;
		X = p->Info;
		delete p;
	}
	return 1;
}

Itemtype GetTop(Stack st)
{
	Itemtype X;
	if (isEmpty(st) == 1)
		return 0;
	else
		X = st.top->Info;
	return X;
}

int ShowStack(Stack st)
{
	if (isEmpty(st) == 1)
	{
		printf("\nNgan xep rong !\n");
		return 0;
	}
	StackNode* p = st.top;
	while (p != NULL)
	{
		printf("%d\n", p->Info);
		p = p->Next;
	}
}

int DoUuTien(char c)
{
	if (c == '(')
		return 0;
	else if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	return 3;
}

int isaNum(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
		return 0;
	return 1;
}

void InfixtoPostfix(char Infix[], char Postfix[])
{
	Stack st;
	InitStack(st);
	int n = strlen(Infix), j = 0;
	Itemtype X;
	StackNode* p;
	for (int i = 0; i < n; i++)
	{
		if (isaNum(Infix[i]) == 1)
			Postfix[j++] = Infix[i];
		else
		{
			if (Infix[i] == '(')
			{
				p = createStackNode('(');
				push(st, p);
			}
			else
			{
				if (Infix[i] == ')')
				{
					while (GetTop(st) != '(')
					{
						pop(st, X);
						Postfix[j++] = X;
					}
					Itemtype Y;
					pop(st, Y);
				}
				else
				{
					if (DoUuTien(Infix[i]) <= DoUuTien(GetTop(st)) && isEmpty(st) != 1)
					{
						Itemtype Z;
						pop(st, Z);
						Postfix[j++] = Z;
					}
					p = createStackNode(Infix[i]);
					push(st, p);
				}
			}
		}
	}
	if (isEmpty(st) != 1)
	{
		pop(st, X);
		Postfix[j++] = X;
	}

	Postfix[j] = '\0';
}

int main()
{
	char Infix[] = "((3+8/2)+6)*(5-2*)", Postfix[50];
	InfixtoPostfix(Infix, Postfix);
	printf("Postfix: %s", Postfix);
	getch();
	return 0;
}