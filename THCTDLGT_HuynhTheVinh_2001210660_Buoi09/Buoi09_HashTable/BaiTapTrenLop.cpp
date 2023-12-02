/*
	Huỳnh Thế Vinh - 2001210660
	Ca TH: ST4, tiet 1-5
	Buổi 9: Bảng băm, sinh vien
*/
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KEYSIZE 8

struct SinhVien
{
	char mssv[20];
	char name[30];
	int year;
	int score;
};

typedef SinhVien ItemType;

struct HashNode
{
	ItemType Key;
	HashNode* Next;
};

HashNode* bucket[KEYSIZE];

int HashFunction(int key) {
	return key % KEYSIZE;
}

void initBucket() {
	for (int b = 0; b < KEYSIZE; b++) {
		bucket[b] = NULL;
	}
}

void push(int b, ItemType x) {
	HashNode* p = new HashNode;

	p->Key = x;
	p->Next = bucket[b];
	bucket[b] = p;
}


void insertAfter(HashNode* p, ItemType k) {
	if (p == NULL)
		printf("Khong the them Node moi");
	else {
		HashNode* q = new HashNode;
		q->Key = k;
		q->Next = p->Next;
		p->Next = q;
	}
}

void place(int b, ItemType k) {
	HashNode* p, * q;
	q = NULL;
	for (p = bucket[b]; p != NULL ; p = p->Next)
		q = p;
	if (q == NULL)
		push(b, k);
	else
		insertAfter(q, k);
}


void insert(ItemType sv) {
	int b = HashFunction(sv.score);

	place(b, sv);
}

bool isEmptyBucket(int b) {
	return bucket[b] == NULL;
}

int pop(int b) {
	HashNode* p;

	int k;
	if (isEmptyBucket(b))
	{
		printf("Bucket %d bi rong, khong the xoa", b);
		return 0;
	}

	p = bucket[b];
	k = p->Key.score;
	bucket[b] = p->Next;
	delete p;

	return k;
}

int deleteAfter(HashNode* p) {
	HashNode* q;
	int k;

	if (p == NULL || p->Next == NULL) {
		printf("\nkhong the xoa");
		return 0;
	}

	q = p->Next;
	k = q->Key.score;

	p->Next = q->Next;
	delete p;
	return k;
}

void placeDel(int b, int k) {
	HashNode* p = bucket[b], * q = NULL;

	while (p != NULL)
	{
		if (p->Key.score == k)
			break;
		q = p;
		p = p->Next;
	}

	if (q == NULL)
		pop(b);
	else
		deleteAfter(q); //  after is delete value

}

void remove(int k) {
	int b = HashFunction(k);
	placeDel(b, k);
}

void traverseBucket(int b) {
	HashNode* p = bucket[b];

	while (p != NULL)
	{
		printf("\n\t%-30s%-30s%-30d%-30d\n", p->Key.mssv, p->Key.name, p->Key.year, p->Key.score);
		p = p->Next;
	}
}

void traverseBucketXS(int b) {
	HashNode* p = bucket[b];

	while (p != NULL)
	{
		if (p->Key.score >= 90)
		{
			printf("\n\t%-30s%-30s%-30d%-30d\n", p->Key.mssv, p->Key.name, p->Key.year, p->Key.score);
		}

		p = p->Next;
	}
}


void traverse() {
	for (int b = 0; b < KEYSIZE; b++) {
		printf("\nBucket thu %d: ", b);
		traverseBucket(b);
	}
}

void traverseXS() {
	for (int b = 0; b < KEYSIZE; b++) {
		printf("\nBucket thu %d: ", b);
		traverseBucketXS(b);
	}
}

void createHashTableFromFile(char fileName[]) {
	initBucket();
	FILE* fi = fopen(fileName, "rt");


	if (fi == NULL)
	{
		printf("LOI DOC FIle");
	}
	else {
		int n;

		fscanf(fi, "%d\n", &n);

		for (int i = 0; i < n; i++)
		{
			ItemType x;
			fscanf(fi, "%[^\#]#%[^\#]#%d#%d\n", &x.mssv, &x.name, &x.year, &x.score);
			insert(x);
		}
		fclose(fi);
	}
}

void show1SV(ItemType sv) {
	printf("\n\t%-30s%-30s%-30d%-30d\n", sv.mssv, sv.name, sv.year, sv.score);
}

void displaySameScore() {
	HashNode* q, *p;
	for (int b = 0; b < KEYSIZE; b++) {
		q = bucket[b];
		if (q != NULL)
		{
			p = q->Next;
			while (p != NULL)
			{
				if (p->Key.score == q->Key.score)
				{
					if(p->Next != NULL && p->Next->Key.score != p->Key.score)
						show1SV(p->Key);
					if(p->Next == NULL)
						show1SV(p->Key);
					show1SV(q->Key);
				}
				q = p;
				p = p->Next;
			}
		}
	}
}

int checkLevel(int score) {
	if (score >= 90)
		return 1;
	return 0;
}

void xuatSVXuatSac() {
	HashNode* q, * p;
	for (int b = 0; b < KEYSIZE; b++) {
		p = bucket[b];
		if (p != NULL)
		{
			for (p; p->Next != NULL; p = p->Next)
			{
				for (q = p->Next; q != NULL; q = q->Next)
				{
					if (checkLevel(p->Key.score) == 1 && checkLevel(q->Key.score)==1 && p->Key.score > q->Key.score)
					{
						HashNode* temp= p;
						p = q;
						q = temp;
					}
				}
			}
		}
	}
}

void showMenu() {
	printf("\n----------------------MENU----------------------\n");
	printf("\n 0. Thoat chuong trinh");
	printf("\n 1. Load + show dssv ");
	printf("\n 2. Xuat sinh vien co cung diem so ");

	printf("\n------------------------------------------------\n");
}

void process() {
	int n, numDelete, luachon;
	ItemType key;
	initBucket();

	do
	{
		showMenu();

		printf("Nhap lua chon: ");
		scanf_s("%d", &luachon);

		switch (luachon)
		{
		case 1: {
			char fileName[] = "dssv.txt";
			createHashTableFromFile(fileName);

			traverse();
			break;
		}
		case 2: {
			displaySameScore();
			break;
		}
		case 3:
			xuatSVXuatSac();
			traverseXS();
			break;
		default:
			break;
		}
	} while (luachon != 0);
}

int main() {

	process();
}