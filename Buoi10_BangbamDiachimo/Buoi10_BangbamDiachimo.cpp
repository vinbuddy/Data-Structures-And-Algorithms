///*
//	Huỳnh Thế Vinh - 2001210660
//	Ca TH: ST4, tiet 1-5
//	Buổi 10: Bảng băm địa chỉ mở
//*/
//#define _CRT_SECURE_NO_WARNINGS 
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <conio.h>
//
//#define KEYSIZE 27
//#define TRUE 1
//#define FALSE 0
//#define NULLKEY -1
//
//typedef int ItemType;
//typedef int KeyType;
//
//struct HashTable_LinearProbing
//{
//	ItemType* Infor;
//	int size;
//	int MAXSIZE = 0;
//};
//
//
//int HashFunction(KeyType key, int size) {
//	return key % size;
//}
//
//void initHashTable(HashTable_LinearProbing& ht) {
//	for (int i = 0; i < KEYSIZE; i++) {
//		ht.Infor[i] = NULLKEY;
//
//	}
//	ht.size = 0;
//}
//
//void initHashTable(HashTable_LinearProbing& ht, int size) {
//	ht.MAXSIZE = size;
//	ht.Infor = new ItemType[ht.MAXSIZE];
//	for (int i = 0; i < size; i++) {
//		ht.Infor[i] = NULLKEY;
//
//	}
//	ht.size = 0;
//}
//
//int isEmpty(HashTable_LinearProbing ht) {
//	if (ht.size == 0)
//		return TRUE;
//	return FALSE;
//}
//
//
//int isFull(HashTable_LinearProbing ht) {
//	if (ht.size == ht.MAXSIZE)
//		return TRUE;
//	return FALSE;
//}
//
//
//
//void traverseHashTable(HashTable_LinearProbing ht) {
//	for (int i = 0; i < ht.MAXSIZE; i++)
//	{
//		printf("\n Table[%2d]: %4d", i, ht.Infor[i]);
//	}
//}
//
//void clear(HashTable_LinearProbing& ht) {
//	for (int i = 0; i < ht.MAXSIZE; i++) {
//		ht.Infor[i] = NULLKEY;
//	}
//
//	ht.size = 0;
//}
//
//int insert(HashTable_LinearProbing& ht, ItemType x) {
//	if (isFull(ht)) {
//		printf("\n Bang Bam FULL, Khong them vao duoc :<");
//		return ht.MAXSIZE;
//	}
//	int i = HashFunction(x, ht.MAXSIZE);
//
//	while (ht.Infor[i] != NULLKEY)
//	{
//		i++;
//		if (i >= ht.MAXSIZE)
//			i = i - ht.MAXSIZE;
//	}
//
//	ht.Infor[i] = x;
//	ht.size++;
//	return i;
//}
//
//int search(HashTable_LinearProbing ht, KeyType k) {
//	int i = HashFunction(k, ht.MAXSIZE);
//	int pivot = i;
//
//	while (ht.Infor[i] != k)
//	{
//		i++;
//		if (i >= ht.MAXSIZE)
//			i = i - ht.MAXSIZE;
//		if (i == pivot) return ht.MAXSIZE;
//	}
//
//	return i;
//}
//
//int remove(HashTable_LinearProbing& ht, KeyType k) {
//	int i = HashFunction(k, ht.MAXSIZE);
//	int pivot = i;
//
//	while (ht.Infor[i] != k)
//	{
//		i++;
//		if (i >= ht.MAXSIZE)
//			i = i - ht.MAXSIZE;
//		if (i == pivot) return FALSE;
//
//	}
//
//	ht.Infor[i] = NULLKEY;
//	ht.size--;
//	return TRUE;
//}
//
//void createHashTable_Random(HashTable_LinearProbing& ht, int n) {
//	srand(unsigned(time(NULL)));
//
//	for (int i = 0; i < n; i++) {
//		KeyType key = rand() % 1000;
//		insert(ht, key);
//	}
//}
//
//
//void showMenu() {
//	printf("\n----------------------MENU----------------------\n");
//	printf("\n 0. Thoat chuong trinh");
//	printf("\n 1. Thay doi kich thuoc cua bang bam ");
//	printf("\n 2. Them 1 nut vao bang");
//	printf("\n 3. Them ngau nhien nhieu nut vao bang ");
//	printf("\n 4. Xoa 1 nut trong bang ");
//	printf("\n 5. Clear all ");
//	printf("\n 6. Duyet bang bam ");
//	printf("\n 7. Tim kiem ");
//	printf("\n------------------------------------------------\n");
//}
//
//void process() {
//	int pos, i, n, select;
//
//	char c;
//	ItemType key;
//	HashTable_LinearProbing HashTable;
//	int Maxsize = 15;
//	initHashTable(HashTable, Maxsize);
//
//
//	do
//	{
//		showMenu();
//
//		printf("Nhap lua chon: ");
//		scanf_s("%d", &select);
//
//		switch (select)
//		{
//		case 1: {
//			printf("\nNhap kich thuoc toi da cua bang bam: ");
//			scanf("%d", &Maxsize);
//			initHashTable(HashTable, Maxsize);
//
//			break;
//		}
//		case 2: {
//			printf("\nNhap 1 nut vao trong bang bam ");
//			printf("\nNhap gia tri khoa cua nut can them: ");
//			scanf("%d", &key);
//			insert(HashTable, key);
//			break;
//
//		}
//		case 3: {
//			printf("\nThem mot bang ngau nhien");
//			do
//			{
//				printf("\nNhap so nut can them: ");
//				scanf("%d", &n);
//			} while (n <= 0);
//
//			createHashTable_Random(HashTable, n);
//			break;
//
//		}
//		case 4: {
//			printf("\nXoa 1 nut tren bang");
//			printf("\nNhap khoa cua nut can xoa: ");
//			scanf("%d", &key);
//
//			if (remove(HashTable, key) == FALSE)
//				printf("\nKhoa %d khong ton tai", key);
//			else {
//				printf("\nDuyet bang bam sau khi xoa %d: ", key);
//				traverseHashTable(HashTable);
//			}
//
//			break;
//
//		}
//		case 5: clear(HashTable); break;
//		case 6:
//		{
//			if (isEmpty(HashTable))
//				printf("\nBang bam rong");
//			else {
//				printf("\nDuyet bang bam: ");
//				traverseHashTable(HashTable);
//			}
//			break;
//		}
//		case 7:
//		{
//			printf("\nTim kiem 1 khoa tren bang");
//			printf("\nNhap khoa cua nut can tim: ");
//			scanf("%d", &key);
//
//			pos = search(HashTable, key);
//			if (pos == HashTable.MAXSIZE)
//				printf("\nKhong tim thay %d tren bang bam", key);
//			else
//				printf("\nTim thay %d tren bang bam", key);
//
//			break;
//		}
// 
//		default:
//			break;
//		}
//	} while (select != 0);
//}
//
//int main() {
//
//	process();
//}