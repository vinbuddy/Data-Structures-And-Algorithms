	

/*
	Huỳnh Thế Vinh - 2001210660
	Ca TH: ST4, tiet 1-5
	Buổi 10: Bảng băm địa chỉ mở
*/
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

#define KEYSIZE 27
#define TRUE 1
#define FALSE 0
#define NULLKEY -1

struct Book
{
	char id[10];
	char name[51];
	int page;
	float price;
};

typedef Book ItemType;
typedef int KeyType;

struct HashTable_LinearProbing
{
	ItemType* Infor;
	int size;
	int MAXSIZE = 0;
};


int HashFunction(KeyType key, int size) {
	return key % size;
}

void initHashTable(HashTable_LinearProbing& ht) {
	for (int i = 0; i < KEYSIZE; i++) {
		ht.Infor[i].page = NULLKEY;
	}
	ht.size = 0;
}

void initHashTable(HashTable_LinearProbing& ht, int size) {
	ht.MAXSIZE = size;
	ht.Infor = new ItemType[ht.MAXSIZE];

	for (int i = 0; i < size; i++) {
		ht.Infor[i].page = NULLKEY;
		strcpy(ht.Infor[i].id, "X");
		strcpy(ht.Infor[i].name, "X");
		ht.Infor[i].price = NULLKEY;
	}
	ht.size = 0;
}

int isEmpty(HashTable_LinearProbing ht) {
	if (ht.size == 0)
		return TRUE;
	return FALSE;
}


int isFull(HashTable_LinearProbing ht) {
	if (ht.size == ht.MAXSIZE)
		return TRUE;
	return FALSE;
}



void traverseHashTable(HashTable_LinearProbing ht) {
	for (int i = 0; i < ht.MAXSIZE; i++)
	{
		printf("\n Table[%d]: ", i);
		printf("\n\t%-30s%-30s%-30d%-30f\n", ht.Infor[i].id, ht.Infor[i].name, ht.Infor[i].page, ht.Infor[i].price);
	}
}

void clear(HashTable_LinearProbing& ht) {
	for (int i = 0; i < ht.MAXSIZE; i++) {
		ht.Infor[i].page = NULLKEY;
	}

	ht.size = 0;
}

int insert(HashTable_LinearProbing& ht, ItemType x) {
	if (isFull(ht)) {
		printf("\n Bang Bam FULL, Khong them vao duoc :<");
		return ht.MAXSIZE;
	}
	int i = HashFunction(x.page, ht.MAXSIZE);

	while (ht.Infor[i].page != NULLKEY)
	{
		i++;
		if (i >= ht.MAXSIZE)
			i = i - ht.MAXSIZE;
	}

	ht.Infor[i] = x;
	ht.size++;
	return i;
}

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

//void createHashTable_Random(HashTable_LinearProbing& ht, int n) {
//	srand(unsigned(time(NULL)));
//
//	for (int i = 0; i < n; i++) {
//		KeyType key = rand() % 1000;
//		insert(ht, key);
//	}
//}

void createHashTableFromFile(HashTable_LinearProbing &ht ,char fileName[]) {
	
		FILE* fi = fopen(fileName, "rt");
		
		if (fi == NULL) {
			printf("LOI DOC FIle");
		}
		else {
			int n;
			
			fscanf(fi, "%d\n", &n);
			
			for (int i = 0; i < n; i++)
			{
				ItemType x;
				fscanf(fi, "%[^\#]#%[^\#]#%d#%f\n", &x.id, &x.name, &x.page, &x.price);
				insert(ht, x);
			}
			
			fclose(fi);
		}
}


int searchBookId(HashTable_LinearProbing ht, char searchValue[]) {
	for (int i = 0; i < ht.MAXSIZE; i++)
	{
		if (strcmp(ht.Infor[i].id, searchValue) == 0) {
			printf("\n\t%-30s%-30s%-30d%-30f\n", ht.Infor[i].id, ht.Infor[i].name, ht.Infor[i].page, ht.Infor[i].price);
			return 1;
		}

	}
	
	return 0;
}

void addBook(HashTable_LinearProbing &ht) {
	ItemType newBook;

	printf("\nNhap ma sach: "); rewind(stdin); gets_s(newBook.id);
	printf("\nNhap ten sach: "); rewind(stdin); gets_s(newBook.name);
	printf("\nNhap so trang: "); scanf("%d", &newBook.page);
	printf("\nNhap gia sach: "); scanf("%f", &newBook.price);

	insert(ht, newBook);
}


// remove book
int handleRemoveBook(HashTable_LinearProbing& ht, ItemType k) {
	int i = HashFunction(k.page, ht.MAXSIZE);
	int pivot = i;
	
		while (ht.Infor[i].page != k.page)
		{
			i++;

			if (i >= ht.MAXSIZE)
				i = i - ht.MAXSIZE;

			if (i == pivot) return FALSE;
	
		}
	
		ht.Infor[i].page = NULLKEY;
		strcpy(ht.Infor[i].id, "Deleted");
		strcpy(ht.Infor[i].name, "Deleted");
		ht.Infor[i].price = NULLKEY;
		ht.size--;

		return TRUE;
}

int removeBook(HashTable_LinearProbing& ht, char id[]) {
	for (int i = 0; i < ht.MAXSIZE; i++)
	{
		if (strcmp(ht.Infor[i].id, id) == 0) {
			if (handleRemoveBook(ht, ht.Infor[i]) == TRUE) return 1;
		}

	}

	return 0;
}


void showMenu() {
	printf("\n----------------------MENU----------------------\n");
	printf("\n 0. Thoat chuong trinh");
	printf("\n 1. Thay doi kich thuoc cua bang bam ");
	printf("\n 2. Tai danh sach BOOKS");
	printf("\n 3. Tim sach khi biet ma ");
	printf("\n 4. Them 1 cuon sach");
	printf("\n 5. Xoa 1 cuon sach theo ma");
	printf("\n 6. Xuat tat ca thong tin cuon sach ra man hinhx	 ");
	printf("\n------------------------------------------------\n");
}


void process() {
	int pos, i, n, select;

	char c;
	ItemType key;
	HashTable_LinearProbing HashTable;
	int Maxsize = 15;

	initHashTable(HashTable, Maxsize);


	do
	{
		showMenu();

		printf("Nhap lua chon: ");
		scanf_s("%d", &select);

		switch (select)
		{
		case 1: {
			printf("\nNhap kich thuoc toi da cua bang bam: ");
			scanf("%d", &Maxsize);
			initHashTable(HashTable, Maxsize);

			break;
		}
		case 2: {
			char fileName[] = "book.txt";
			createHashTableFromFile(HashTable, fileName);

			traverseHashTable(HashTable);
			break;
		}
		case 3: {
			char searchValue[10];

			printf("\nNhap ma sach de tim kiem: ");
			rewind(stdin);
			gets_s(searchValue);

			int result = searchBookId(HashTable, searchValue);

			if(result == 0) printf("\nKhong tim thay");

			break;
		}
		
		case 4: {
			addBook(HashTable);
			traverseHashTable(HashTable);
			break;

		}
		case 5: {
			char id[10];
			printf("\nNhap ma can xoa: "); rewind(stdin); gets_s(id);

			if (removeBook(HashTable, id) == TRUE) printf("\nXoa thanh cong !");
			else printf("\nXoa khong thanh cong !");

			traverseHashTable(HashTable);

			break;
		}
		case 6:
		{
			if (isEmpty(HashTable))
				printf("\nBang bam rong");
			else {
				printf("\nDuyet bang bam: ");
				traverseHashTable(HashTable);
			}
			break;
		}
		/*case 7:
		{
			printf("\nTim kiem 1 khoa tren bang");
			printf("\nNhap khoa cua nut can tim: ");
			scanf("%d", &key);

			pos = search(HashTable, key);
			if (pos == HashTable.MAXSIZE)
				printf("\nKhong tim thay %d tren bang bam", key);
			else
				printf("\nTim thay %d tren bang bam", key);

			break;
		}*/

		default:
			break;
		}
	} while (select != 0);
}

int main() {

	process();
}