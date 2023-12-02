#include "Stack_DoiCoSo.h"

void showMenu() {
	printf("\n----------------------MENU----------------------\n");
	printf("\n 0. Thoat chuong trinh");
	printf("\n 1. Tao stack");
	printf("\n 2. Xem stack");
	printf("\n 3. Them mot nut p vao stack");
	printf("\n 4. Xoa mot nut p khoi stack");
	printf("\n 5. Xem noi dung node dau stack");
	printf("\n 6. Doi co so");
	printf("\n----------------------END----------------------\n");




}

void process() {
	int luachon;
	int n, a;

	Stack st;
	StackNode* p;
	initStack(st);


	do {

		showMenu();

		printf("\nNhap lua chon cua ban: ");
		scanf_s("%d", &luachon);

		switch (luachon)
		{
		case 1:
			createStack_auto(st);
			showStackNode(st);
			break;
		case 2:
			break;
		case 6:
		{
			printf("\nHay cho biet gia tri n =  "); scanf_s("%d", &n);
			printf("\nHay cho biet co so a =  "); scanf_s("%d", &a);

			stack_DoiCoSo(n, a);
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