///*
//	Huỳnh Thế Vinh - 2001210660
//	Ca TH: ST4, tiet 1-5
//	Buổi 9: Bảng băm 
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define KEYSIZE 27
//
//typedef int ItemType;
//
//struct HashNode
//{
//	ItemType Key;
//	HashNode* Next;
//};
//
//HashNode* bucket[KEYSIZE];
//
//int HashFunction(int key) {
//	return key % KEYSIZE;
//}
//
//void initBucket() {
//	for (int b = 0; b < KEYSIZE; b++) {
//		bucket[b] = NULL;
//	}
//}
//
//void push(int b, int x) {
//	HashNode* p = new HashNode;
//
//	p->Key = x;
//	p->Next = bucket[b];
//	bucket[b] = p;
//}
//
//
//void insertAfter(HashNode* p, int k) {
//	if (p == NULL)
//		printf("Khong the them Node moi");
//	else {
//		HashNode* q = new HashNode;
//		q->Key = k;
//		q->Next = p->Next;
//		p->Next = q;
//	}
//}
//
//void place(int b, int k) {
//	HashNode* p, * q;
//	q = NULL;
//	for (p = bucket[b]; p != NULL && k > p->Key; p = p->Next) 
//		q = p;
//	if (q == NULL)
//		push(b, k);
//	else
//		insertAfter(q, k);
//}
//
//
//void insert(int k) {
//	int b = HashFunction(k);
//
//	place(b, k);
//}
//
//bool isEmptyBucket(int b) {
//	return bucket[b] == NULL;
//}
//
//int pop(int b) {
//	HashNode* p;
//
//	int k;
//	if (isEmptyBucket(b))
//	{
//		printf("Bucket %d bi rong, khong the xoa", b);
//		return 0;
//	}
//
//	p = bucket[b];
//	k = p->Key;
//	bucket[b] = p->Next;
//	delete p;
//
//	return k;
//}
//
//int deleteAfter(HashNode* p) {
//	HashNode* q;
//	int k;
//
//	if (p == NULL || p->Next == NULL) {
//		printf("\nkhong the xoa");
//		return 0;
//	} 
//
//	q = p->Next;
//	k = q->Key;
//
//	p->Next = q->Next;
//	delete p;
//	return k;
//}
//
//void placeDel(int b, int k) {
//	HashNode* p = bucket[b], * q = NULL;
//
//	while (p != NULL)
//	{
//		if (p->Key == k)
//			break;
//		q = p;
//		p = p->Next;
//	}
//
//	if (q == NULL)
//		pop(b);
//	else
//		deleteAfter(q); //  after is delete value
//
//}
//
//void remove(int k) {
//	int b = HashFunction(k);
//	placeDel(b, k);
//}
//
//
//
//void traverseBucket(int b) {
//	HashNode* p = bucket[b];
//
//	while (p != NULL)
//	{
//		printf("%5d ", p->Key);
//		p = p->Next;
//	}
//}
//
//
//void traverse() {
//	for (int b = 0; b < KEYSIZE; b++) {
//		printf("\nBucket thu %d: ", b);
//		traverseBucket(b);
//	}
//}
//
//void showMenu() {
//	printf("\n----------------------MENU----------------------\n");
//	printf("\n 0. Thoat chuong trinh");
//	printf("\n 1. Tao HashTable random ");
//	printf("\n 2. Xoa node ");
//	printf("\n------------------------------------------------\n");
//}
//
//void process() {
//	int n, numDelete, luachon;
//	ItemType key;
//	initBucket();
//
//	
//
//	do
//	{
//		showMenu();
//
//		printf("Nhap lua chon: ");
//		scanf_s("%d", &luachon);
//
//		switch (luachon)
//		{
//		case 1: {
//			printf("So nut ban muon them: ");
//			scanf_s("%d", &n);
//
//			srand(unsigned(time(NULL)));
//
//			for (int i = 0; i < n; i++) {
//				key = rand() % 100;
//				insert(key);
//			}
//
//			traverse();
//			break;
//		}
//		case 2: {
//			printf("So nut ban muon xoa: ");
//			scanf_s("%d", &numDelete);
//
//			remove(numDelete);
//			traverse();
//		}
//		default:
//			break;
//		}
//	} while (luachon != 0);
//}
//
//int main() {
//
//	process();
//}