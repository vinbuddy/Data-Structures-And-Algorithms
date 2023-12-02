/*
    Họ tên: Huỳnh Thế Vinh - 2001210660
    Buoi TH: ST4 / Tiet 1 - 5
    Kiem tra lan 1  
*/

#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
//=========================================================
struct DienThoai
{
	char seri[13];
	char ten[26];
	char tenHang[11];
	double gia;
	int namSX;
};
typedef DienThoai ItemType;

struct SNode
{
	ItemType Info;
	SNode* Next;
};
//=========================================================
//Node
//=========================================================
struct SList
{
	SNode* Head;
	SNode* Tail;
};

SNode* createSNode(ItemType x);
void showSNode(SNode *p);
//=========================================================
//Single Link List

//=========================================================
//=========================================================
void nhapTTBaiHat(ItemType &x);
void xuatTTBaiHat(ItemType x);
void docTTBaiHat(FILE *fi, ItemType &x);
void luuTTBaiHat(FILE *fo, ItemType x);
void docdulieu(SList &sl, char filename[]);
void luuDuLieu(SList sl, char filename[]);

void initSList(SList &sl);
bool isEmpty(SList sl);
bool insertHead(SList &sl, SNode *p);
void showSList(SList sl);
void createSList_Auto(SList &sl);
bool insertTail(SList &SL, SNode *p);
bool insertBefore(SList &sl, SNode *q, SNode *p);
bool insertAfter(SList &sl, SNode *q, SNode *p);
SNode* findSNode(SList sl, ItemType x);
void process();
bool deleteHead(SList &sl, ItemType &x);
bool deleteTail(SList &sl, ItemType &x);
bool deleteBefore(SList &sl, SNode *q, ItemType &x);
bool deleteAfter(SList &sl, SNode *q, ItemType &x);
bool deleteX(SList &sl, ItemType x);

//=========================================================
void timDienThoaiTheoHang(SList sl, char tenHang[]);

int main()
{
	process();
	_getch();
    return 0;
}
void menu()
{
	printf("\n***********************************");
	printf("\n              MENU                 ");
	printf("\n0.Thoat chuong trinh               ");
	printf("\n1.Load va xe, danh sach dien thoai ");
	printf("\n2.Tim nhung dien thoai theo ten hang");
	printf("\n***********************************");
}
void process()
{
	int chon;
	bool kq;
	SList SL;
	initSList(SL);
	ItemType X, Y;
	SNode*P, *Q;

    char filename_In[] = "dsDienThoai.txt";
    /*char filename_Out[] = "dsDienThoai_Out.txt";*/

	do
	{
		menu();
		printf("\nHay chon chuc nang: ");
		scanf_s("%d", &chon);
		switch (chon)
		{
		case 0:
			return;
		case 1:
			docdulieu(SL, filename_In);
			printf("\ndanh sach bai hat la: ");
			showSList(SL);
			break;
		case 2:
		{
			printf("\nNhap ten hang dien thoai muon tim");

			break;
		}
		}
	} while (chon != 0);
}





//Node
//=========================================================
SNode* createSNode(ItemType x)
{
	SNode *p = new SNode;
	if (p == NULL)
	{
		printf("Loi khong cap phat duoc");
		_getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
//=========================================================
void showSNode(SNode *p)
{
	xuatTTBaiHat(p->Info);
}
//=========================================================
void showSList(SList sl)
{
	if (isEmpty(sl))
	{
		printf("Danh sach rong");
		return;
	}
	printf("Danh sach bai hat\n");
	printf("%-5s%-30s%-30s%-30s%10s", "STT", "SERI", "TEN SP", "TEN HANG", "GIA", "NAM SX");
	int i = 1;
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
	{
		printf("\n%-5d", i++);
		showSNode(p);
	}

}
//=========================================================
bool isEmpty(SList sl)
{
	return(sl.Head == NULL);
}
//=========================================================
void initSList(SList &sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}
//=========================================================
bool insertHead(SList &sl, SNode*p)
{
	p->Next = sl.Head;
	sl.Head = p;
	return true;
}
//=========================================================
bool insertTail(SList &sl, SNode *p)
{
	if (p == NULL)
		return false;
	if (isEmpty(sl) == true)
		sl.Head = sl.Tail = p;
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
}

//=========================================================
bool insertBefore(SList &sl, SNode *q, SNode *p)
{
	if (p == NULL || q == NULL)
		return false;
	if (q == sl.Head)
	{
		insertHead(sl, p);
		return true;
	}
	SNode*r = sl.Head;
	while (r->Next != q)
	{
		r = r->Next;
	}
	p->Next = q;
	r->Next = p;
	return true;
}
//=========================================================
bool insertAfter(SList &sl, SNode *q, SNode *p)
{
	if (p == NULL || q == NULL)
		return false;
	if (q == sl.Tail)
	{
		insertTail(sl, p);
		return true;
	}
	SNode*r = sl.Tail;
	while (r->Next != q)
	{
		r = r->Next;
	}

	r->Next = p->Next;
	p->Next = r;
}
//=========================================================
bool deleteHead(SList &sl, ItemType &x)
{
	if (isEmpty(sl))
		return false;
	SNode *p = sl.Head;
	sl.Head = sl.Head->Next;
	if (sl.Head == NULL)
		sl.Tail = NULL;
	x = p->Info;
	delete p;
	return true;
}
//=========================================================
bool deleteTail(SList &sl, ItemType &x)
{
	if (sl.Tail == NULL)
		return false;
	SNode *q = sl.Head;
	SNode *p = sl.Tail;
	if (p == q)
	{
		sl.Head = sl.Tail = NULL;
		return true;
	}
	else
	{
		while (q->Next != sl.Tail)
		{
			q = q->Next;
		}
		sl.Tail = q;
		sl.Tail->Next = NULL;
	}
	x = p->Info;
	delete p;
	return true;
}
//=========================================================
void nhapTTBaiHat(ItemType &x)
{
	printf("tutulam");
}
//=========================================================
void xuatTTBaiHat(ItemType x)
{
	printf("%-30s%-30s%-30s%10f%10d", x.seri, x.ten, x.tenHang, x.gia, x.namSX);
}
//=========================================================
void luuTTBaiHat(FILE *fo, ItemType x)
{
	fprintf(fo, "%-30s%-30s%-30s%-10f%-10d", x.seri, x.ten, x.tenHang, x.gia, x.namSX);
}
//=========================================================
void docTTBaiHat(FILE *fi, ItemType &x)
{
	fscanf(fi, "\n%[^\#]#%[^\#]#%[^\#]#%lf#%d", &x.seri, &x.ten, &x.tenHang, &x.gia, &x.namSX);
}
//=========================================================
void docdulieu(SList &sl, char filename[])
{
	FILE *fi = fopen(filename, "rt");
	if (!fi)
	{
		printf("Loi doc file");
		return;
	}
	int n;
	fscanf(fi, "%d\n", &n);

	ItemType x;
	SNode *p;
	initSList(sl);
	for (int i = 0; i <= n; i++)
	{
		docTTBaiHat(fi, x);
		p = createSNode(x);
		insertTail(sl, p);
	}
	fclose(fi);
}
//===========================================================

void timDienThoaiTheoHang(SList sl, char tenHang[]) {

}