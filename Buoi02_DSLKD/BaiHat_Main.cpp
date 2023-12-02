#include "DSLKD_BaiHat.h"


#define fileName_In "dsBaiHat_In.txt"
#define fileName_Out "dsBaiHat_Out.txt"

void showMenu();
void process();

void main() {

	process();


	_getch();
}

void showMenu() {
	printf("\n----------------------MENU----------------------\n");
	printf("\n 0. Thoat chuong trinh");
	printf("\n 1. Load danh sach bai hat");
	printf("\n 2. xem noi dung danh sach bai hat");
}

void process() {
	int luachon;

	SList slist;
	SNode* p;

	do
	{

		showMenu();

		printf("\nNhap lua chon cua ban: ");
		scanf_s("%d", &luachon);

		switch (luachon)
		{
		case 0:
			return;
		case 1:
			docDuLieu(slist, "d");
			showSlist(slist);
			break;

		}

	} while (luachon != 0);
}