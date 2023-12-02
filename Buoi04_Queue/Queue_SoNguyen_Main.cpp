#include "Queue_SoNguyen.h"

void showMenu() {
	printf("\n----------------------MENU----------------------\n");
	printf("\n 0. Thoat chuong trinh");
	printf("\n 1. Tao Queue ");
	printf("\n 2. Xem noi dung hang doi");
	printf("\n 3. Xoa 1 phan tu ra khoi queue");
	printf("\n 4. Them mot nut p vao queue");
	printf("\n 5. Xem gia tri phan tu dau queue");
	printf("\n 6. Xem gia tri phan tu cuoi queue");
	printf("\n 7. Xoa toan bo queue va xem queue da xoa");

	printf("\n------------------------------------------------\n");

}

void process() {
	int luachon;

	ItemType x;
	Queue queue;
	QueueNode* p;
	
	initQueue(queue);


	do {

		showMenu();

		printf("\nNhap lua chon cua ban: ");
		scanf_s("%d", &luachon);

		switch (luachon)
		{
		case 1:
			system("cls");
			createQueue_Auto(queue);
			break;
		case 2:
			system("cls");
			showQueue(queue);
			break;
		case 3:
		{
			system("cls");
			if (remove(queue, x)) {
				printf("Thong tin queue sau khi xoa %d la: ", x);
				showQueue(queue);
			}
			else {
				printf("Khong the xoa %d trong queue !!!");
			}

			break;
			
		}

		case 4:
		{
			system("cls");
			int x;
			printf("\nNhap phan tu x muon them: "); scanf_s("%d", &x);

			p = createQueueNode(x);
			insertHead(queue, p);
			showQueue(queue);
			break;
		}
		case 5:
			system("cls");
			if (showFirstQueue(queue, x)) {
				printf("Phan tu dau cua queue la: %d", x);
			}
			else {
				printf("Khong co phan tu dau");
			}
			break;

		case 6: 
			system("cls");
			if (showLastQueue(queue, x)) {
				printf("Phan tu cuoi cua queue la: %d", x);
			}
			else {
				printf("Khong co phan tu cuoi");
			}
			break;
		case 7:
		{
			system("cls");
			Queue deletedQueue;

			initQueue(deletedQueue);

			if (removeAll(queue, deletedQueue)) {
				printf("Da xoa tat ca phan tu trong queue");
				printf("\nQueue da xoa la: "); showQueue(deletedQueue);

			}

			break;
		}
			break;
		default:
			break;
		}

	} while (luachon != 0);
}
int main() {

	process();

	_getch();
	return 0;
}