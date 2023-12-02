//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<iostream>
//#include<fstream>
//#include<iomanip>
//#include<conio.h>
//
//int MAXSIZE = 10;
//int* hashTable;//khai hashtable là một mảng động
//#define RONG 0
//#define DAXOA -1
//#define THESHOLD 0.6
//
//int maxCount = MAXSIZE * THESHOLD;
//int count;
//void initHashTable()
//{
//	hashTable = new int[MAXSIZE];
//	for (int i = 0; i < MAXSIZE; i++)
//		hashTable[i] = RONG;
//	//count = 0;
//}
//int hashFuction(int key)
//{
//	return key % MAXSIZE;
//}
//
//void menu()
//{
//	printf("MENU CHUONG TRINH \n");
//	printf("1. Them phan tu: \n");
//	printf("2. TIm phan tu: \n");
//	printf("3. Xoa phan tu: \n");
//	printf("4. Xuat bang bam \n");
//	printf("5. Tang kich thuoc \n");
//	printf("0. THoat chuong trinh \n");
//}
//
//void xuat();
//int deleteKey(int Key);
//int search(int Key);
//void resize();
//int insert(int key);
//
//void main()
//{
//	int chon;
//	initHashTable();
//	do {
//		system("cls");
//		xuat();
//		menu();
//		printf("Ban chon chuc nang nao: ");
//		scanf("%d", &chon);
//		switch (chon)
//		{
//		case 1:
//		{
//			printf("BAN CHON CHUC NANG THEM PHAN TU VAO BANG BAM\n");
//			int x;
//			printf("nhap phan tu muon them: ");
//			scanf("%d", &x);
//			int kq = insert(x);
//			if (kq == 0)
//				printf("Them that bai \n");
//			else
//				printf("Them thanh cong \n");
//			break;
//		}
//		case 2:
//		{
//			printf("BAN CHON CHUC NANG TIM PHAN TU VAO BANG BAM\n");
//			int x;
//			printf("nhap phan tu muon tim: ");
//			scanf("%d", &x);
//			int kq = search(x);
//			if (kq == -1)
//				printf("khong co %d trong bang bam \n", x);
//			else
//				printf("Phan tu can tim dang luu o vi tri %d trong bang bam \n", kq);
//			break;
//		}
//		case 3:
//		{
//			printf("BAN CHON CHUC NANG XOA PHAN TU VAO BANG BAM\n");
//			int x;
//			printf("nhap phan tu muon xoa: ");
//			scanf("%d", &x);
//			int kq = deleteKey(x);
//
//			if (kq == 0)
//				printf("khong co %d trong bang bam. Xoa that bai! \n", x);
//			else
//				printf("Da xoa\n", kq);
//
//			break;
//		}
//		case 4:
//		{
//			printf("BAN CHON CHUC NANG XUAT PHAN TU VAO BANG BAM\n");
//			xuat();
//			break;
//		}
//		case 5:
//		{
//			printf("Tang Kich thuoc bang bam\n");
//			resize();
//			break;
//		}
//		default: printf("Nhap sai, yeu cau nhap lai!!");
//			break;
//		}	system("pause");
//	} while (chon != 0);
//}
//
//int deleteKey(int Key)
//{
//	int index = search(Key);
//	if (index != -1)
//	{
//		hashTable[index] = DAXOA;
//		return 1;
//	}
//	else
//		return 0;
//}
//void xuat()
//{
//	for (int i = 0; i < MAXSIZE; i++)
//		printf("vi tri %d --- key: %d \n", i, hashTable[i]);
//}
//int search(int Key)
//{
//	int index = hashFuction(Key);
//	int dt = index;
//	int i = 1;
//	while (hashTable[index] != RONG && hashTable[index] != Key)
//	{
//		index = (dt + 1) % MAXSIZE;
//		i++;
//	}
//	if (hashTable[index] == RONG)
//		return -1;
//	else
//		return index;
//}
//void resize()
//{
//	int OldMaxSize = MAXSIZE;
//	MAXSIZE = MAXSIZE * 2;
//
//	maxCount = THESHOLD * MAXSIZE;
//
//	int* mang = new int[MAXSIZE];
//	for (int i = 0; i < MAXSIZE; i++)
//		mang[i] = RONG;
//	count = 0;
//	for (int i = 0; i < OldMaxSize; i++)
//	{
//		if (hashTable[i] != RONG)
//		{
//			int x = hashTable[i];
//			//chen x vao mang
//			int index = hashFuction(x);//làn băm đầu tiên
//			int dt = index;
//			int i = 1;
//			while (mang[index] != RONG)
//			{
//				//bam lại => tìm index moi;
//				index = (dt + i) % MAXSIZE;
//				i++;
//			}
//			mang[index] = x;
//			count++;
//		}
//	}
//	delete hashTable;
//	hashTable = mang;
//}
//int insert(int key)
//{
//	if (count > maxCount)
//		resize();
//
//	int index = hashFuction(key);//làn băm đầu tiên
//	if (hashTable[index] == key)
//		return 0;
//	int dt = index;
//	int i = 1;
//	while (hashTable[index] != 0)
//	{
//		//bam lại => tìm index moi;
//		index = (dt + i) % MAXSIZE;
//		if (hashTable[index] == key)
//			return 0;
//		i++;
//	}
//	hashTable[index] = key;
//	count++;
//	return 1;
//}