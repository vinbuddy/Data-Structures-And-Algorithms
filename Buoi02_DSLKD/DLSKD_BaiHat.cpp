#include "DSLKD_BaiHat.h"

SNode* createSNode(ItemType x)
{
	SNode* p = new SNode;

	if (p == NULL) {
		printf("Khong du bo nho de cap phat");
		_getch();
		return NULL;
	}

	p->Info = x;
	p->Next = NULL;

	return p;

}

void initSList(SList& slist)
{
	slist.Head = NULL;
	slist.Tail = NULL;
}

bool isEmpty(SList slist)
{
	return (slist.Head == NULL);
}

bool insertTail(SList& slist, SNode* p)
{
	if (p == NULL) return false;
	if (isEmpty(slist) == true)
		slist.Head = slist.Tail = p;
	else {
		slist.Tail->Next = p;
		slist.Tail = p;
	}

	return true;
}

void showSNode(SNode* p)
{
	printf("%4d", p->Info);
}

void docTTBaiHat(FILE* fi, ItemType& x) {
	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%d\n", &x.tenBH, &x.tenTG, &x.tenCS, &x.thoiGian);
}

void docDuLieu(SList& slist, char fileName[]) {
	FILE* fi = fopen(fileName, "rt");
	if (!fi) {
		printf("LOI DOC FILE");
		return;
	}

	int n;
	fscanf(fi, "%d\n", &n);

	ItemType x;
	SNode* p;

	initSList(slist);

	for (int i = 0; i <= n; i++) {
		docTTBaiHat(fi, x);
		p = createSNode(x);
		insertTail(slist, p);
	}
	fclose(fi);
}


void luuTTBaiHat(FILE* fo, ItemType x) {
	fprintf(fo, "%-30s%s-30s%-30s%10d", x.tenBH, x.tenTG, x.tenCS, x.thoiGian);
}

void luuDuLieu(SList slist, char fileName[]) {
	FILE* fo = fopen(fileName, "wt");

	if (!fo) {
		printf("Loi ghi file");
		return;

	}

	if(isEmpty(slist)) {
		printf("Danh sach rong");
		return;
	}

	fprintf(fo, "DANH SACH BAI HAT\n");

	fprintf(fo, "%-5s%-30s%-30s%-30s%10s", "STT", "TEN BAI HAT", "TEN TAC GIA", "TEN CA SI", "THOI LUONG");

	int i = 1;

	for (SNode* p = slist.Head; p != NULL; p = p->Next) {
		fprintf(fo, "\n%-5d", i++);
		luuTTBaiHat(fo, p->Info);
	}
}

void showSlist(SList slist) {
	if (isEmpty(slist)) {
		printf("Danh sach rong");
		return;
	}

	printf("SACH SACH BAI HAT\n");
	printf("%-5s%-30s%-30s%-30s%10s", "STT", "TEN BAI HAT", "TEN TAC GIA", "TEN CA SI", "THOI LUONG");

	int i = 1;

	for (SNode* p = slist.Head; p != NULL; p = p->Next) {
		printf("\n%-5d", i++);
		showSNode(p);
	}
}
