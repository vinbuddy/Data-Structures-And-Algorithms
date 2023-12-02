#include "DSLKD_SoNguyen.h"

void showMenu() {
	printf("\n----------------------MENU----------------------\n");
	printf("\n 0. Thoat chuong trinh");
	printf("\n 1. Tao danh sach ngau nhien");
	printf("\n______________________Bai [3]_____________________________");
	printf("\n 2. Tao danh sach tang dan");
	printf("\n 3. Chen phan tu X vao danh sach ( van giu nguyen tang dan )");
	printf("\n 4. In danh sach theo thu tu giam dan");
}

void process() {
	int luachon;

	SList slist;
	SNode* p;
	initSList(slist);

	do {

		showMenu();

		printf("\nNhap lua chon cua ban: ");
		scanf_s("%d", &luachon);

		switch (luachon)
		{
		case 1:
			createList_Auto(slist);
			showSList(slist);
			break;
		case 2:
			createList_Increase(slist);
			showSList(slist);
			break;
		case 3:
		{
			int x;
			printf("\nNhap phan tu x muon them: "); scanf_s("%d", &x);

			p = createSNode(x);
			insertHead(slist, p);
			sortIncrease(slist);
			showSList(slist);

			break;
		}

		case 4:
			sortDecrease(slist);
			showSList(slist);
			break;

		default:
			break;
		}

	} while (luachon != 0);
}
void main() {

	process();
		
	
	_getch();
}