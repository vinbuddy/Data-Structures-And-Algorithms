#include "Buoi02_DSLKD.h"

void showMenu() {
	printf("\n----------------------MENU----------------------\n");
	printf("\n 0. Thoat chuong trinh");
	printf("\n 1. Tao danh sach ngau nhien");
	printf("\n 2. Xoa node dau danh sach");
	printf("\n 3. Xoa node cuoi danh sach");
	printf("\n 4. Xoa node sau q");
	printf("\n 5. Xoa node x");
	printf("\n 6. Xoa all node");

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
		case 0:
			return;
		case 1:
			createList_Auto(slist);
			showSList(slist);
			break;
		case 2:
		{
			bool result = deleteHead(slist);
			if (!result) {
				printf("\nDanh sach rong");
			} else {
				printf("\nDanh sach sau khi xoa node dau la: ");
			}
			showSList(slist);
			break;
		}
		case 3: 
		{
			bool result = deleteTail(slist);
			if (!result) {
				printf("\nDanh sach rong");
			}
			else {
				printf("\nDanh sach sau khi xoa node cuoi la: ");
			}
			showSList(slist);
			break;
		}
		case 4: 
		{
			int x; 
			printf("\nNhap node q de khoi tao: "); scanf_s("%d", &x);
			SNode* q = createSNode(x);
			insertHead(slist, q);
			printf("\nDanh sach sau khi them node q la: ");

			showSList(slist);

			deleteAfter(slist, q);
			printf("\nDanh sach sau khi xoa node sau q cuoi la: ");
			showSList(slist);
			break;
		}

		case 5: 
		{
			int x;
			printf("\nNhap node x can xoa: "); scanf_s("%d", &x);

			deleteXNode(slist, x);
			printf("\nDanh sach sau khi xoa node %d la: ", x);
			showSList(slist);
			break;
		}

		case 6: 
		{
			deleteAll(slist);
			printf("\nDanh sach khi sau xoa tat ca la: "); 
			showSList(slist);
			break;
		}
		default:
			break;
		}

	} while (luachon != 0);
}
void main() {

	process();


	_getch();
}