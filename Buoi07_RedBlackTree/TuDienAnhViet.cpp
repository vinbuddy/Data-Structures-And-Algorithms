﻿/*
	Họ và tên:	Huỳnh Thế Vinh
	MSSV:		2001210660
	Lớp:		12DHTH07
	Kiem tra lan 2: Cay Do Den
*/
#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>


using namespace std;

struct MonHoc
{
	char id[11];
	char name[31];
	int soTC;
	char loaiHP[21];
};

/* Khai báo kiểu dữ liệu của Node */
typedef MonHoc ItemType;

/* Khai báo thuộc tính color */
enum EColor { RED, BLACK };

/* Khai báo cấu trúc node */
struct BRTNode
{
	ItemType Info;
	EColor Color;
	BRTNode* Left, * Right, * Parent;
};

/* Khai báo cấu trúc cây Đỏ-Đen */
struct BRTree
{
	BRTNode* Root;
};

//==================================================
BRTNode* createBRTNode(ItemType x)
{
	BRTNode* p = new BRTNode;
	if (p == NULL)
	{
		printf("\nKhong the cap phat nut moi!");
		_getch();
		return NULL;
	}
	p->Info = x;		// Gán dữ liệu mới cho nút
	p->Color = RED;		// Gán màu đỏ (Red) mặc định
	p->Left = NULL;		// Chưa có nút con trái
	p->Right = NULL;	// Chưa có nút con phải
	p->Parent = NULL;	// Chưa có nút cha
	return p;
}
//==================================================
void set_Color(int colorBackground, int colorText) {
	HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hColor, colorBackground * 16 + colorText);
	/*
	0 = Black       8 = Gray
	1 = Blue        9 = Light Blue
	2 = Green       A = Light Green
	3 = Aqua        B = Light Aqua
	4 = Red         C = Light Red
	5 = Purple      D = Light Purple
	6 = Yellow      E = Light Yellow
	7 = White       F = Bright White
	=> set_Color(X); -> X = a*16 + b, a (background) và b (character)
	*/
}
void showBRTNode(BRTNode* p)
{
	if (p->Color == RED)
		set_Color(15, 12);	//Light Red=12 (C), Bright White=15 (F)
	else if (p->Color == BLACK)
		set_Color(15, 0);	//Black=0, Bright White=15 (F)
	/*printf("%4d", p->Info);*/
	printf("%-30s%-30s%-30s%-30d\n", p->Info.id, p->Info.name, p->Info.loaiHP, p->Info.soTC);
	set_Color(14, 2);		//Light Yellow=14 (E), Green=2
}
//==================================================
/* Initalize BRTree */
void initBRTree(BRTree& brt)
{
	brt.Root = NULL;
}

/* Hoán vị màu (Color) */
void swapColors(EColor& color1, EColor& color2)
{
	EColor temp = color1;
	color1 = color2;
	color2 = temp;
}

/* Hoán vị giá trị */
void swapInfos(ItemType& info1, ItemType& info2)
{
	ItemType temp = info1;
	info1 = info2;
	info2 = temp;
}

/* Một hàm đệ quy để thực hiện việc duyệt thứ tự NLR - PreOrder */
void showBRTree_PreOrder(BRTNode* root)
{
	if (root == NULL) return;

	showBRTNode(root); //printf("%4d", root->Info);
	showBRTree_PreOrder(root->Left);
	showBRTree_PreOrder(root->Right);
}

/* Một hàm đệ quy để thực hiện việc duyệt thứ tự LNR - InOrder */
void showBRTree_InOrder(BRTNode* root)
{
	if (root == NULL) return;

	showBRTree_InOrder(root->Left);
	showBRTNode(root); //printf("%4d", root->Info);
	showBRTree_InOrder(root->Right);
}

/* Một hàm đệ quy để thực hiện việc duyệt thứ tự LRN - PostOrder */
void showBRTree_PostOrder(BRTNode* root)
{
	if (root == NULL) return;

	showBRTree_PostOrder(root->Left);
	showBRTree_PostOrder(root->Right);
	showBRTNode(root); //printf("%4d", root->Info);
}

/* Duyệt theo chiều rộng (Breadth-first search) */
void levelOrder(BRTNode* root) {
	if (root == NULL) return;

	queue <BRTNode*> q;
	q.push(root);

	while (!q.empty()) {
		BRTNode* p;
		p = q.front();
		q.pop();
		showBRTNode(p);
		if (p->Left != NULL)
			q.push(p->Left);
		if (p->Right != NULL)
			q.push(p->Right);
	}
}

/* In theo thứ tự cấp */
void showLevelOrder(BRTNode* root) {
	printf("\nIn theo thu tu cap (Breadth-first traverse): \n");
	if (root == NULL)
		printf("\nCay rong!");
	else
		levelOrder(root);
}

/* Duyệt theo chiều sâu (Depth-first search): Pre-Order */
void iterativePreOrder(BRTNode* root) {
	if (root == NULL) return;

	stack <BRTNode*> s;
	s.push(root);

	while (!s.empty()) {
		BRTNode* p;
		p = s.top();
		s.pop();
		showBRTNode(p);
		//right child is pushed first so that left is processed first
		if (p->Right != NULL)
			s.push(p->Right);
		if (p->Left != NULL)
			s.push(p->Left);
	}
}

/* In theo thứ tự Pre-Order (Depth-first traverse) */
void showPreOrder(BRTNode* root) {
	printf("\nIn theo thu tu Pre-Order (Depth-first traverse): \n");
	if (root == NULL)
		printf("\nCay rong!");
	else
		iterativePreOrder(root);
}

/* Duyệt theo chiều sâu (Depth-first search): In-Order */
void iterativeInOrder(BRTNode* root) {
	if (root == NULL) return;

	stack <BRTNode*> s;

	while (!s.empty() || root) {
		if (root) {
			s.push(root);
			root = root->Left;
		}
		else {
			root = s.top();
			s.pop();
			showBRTNode(root);
			root = root->Right;
		}
	}
}

/* In theo thứ tự In-Order (Depth-first traverse) */
void showInOrder(BRTNode* root) {
	printf("\nIn theo thu tu In-Order (Depth-first traverse): \n");
	if (root == NULL)
		printf("\nCay rong!");
	else
		iterativeInOrder(root);
}

/* Duyệt theo chiều sâu (Depth-first search): Post-Order */
void iterativePostOrder(BRTNode* root) {
	if (root == NULL) return;

	stack <BRTNode*> s;
	BRTNode* pt_lastNodeVisited = NULL;
	BRTNode* p;

	while (!s.empty() || root) {
		if (root) {
			s.push(root);
			root = root->Left;
		}
		else {
			p = s.top();
			// if right child exists and traversing node
			// from left child, then move right
			if (p->Right && p->Right != pt_lastNodeVisited) {
				root = p->Right;
			}
			else {
				showBRTNode(p);
				pt_lastNodeVisited = s.top();
				s.pop();
			}
		}
	}
}

/* In theo thứ tự Post-Order (Depth-first traverse) */
void showPostOrder(BRTNode* root) {
	printf("\nIn theo thu tu Post-Order (Depth-first traverse): \n");
	if (root == NULL)
		printf("\nCay rong!");
	else
		iterativePostOrder(root);
}

int compareChar(char x[], char y[]) {
	int xLength = strlen(x);
	int yLength = strlen(y);
	int n;

	// x = insertNode
	if (xLength < yLength) {
		n = xLength;
	}
	else {
		n = yLength;
	}
	
	for (int i = 0; i < n; i++) {
		if (x[i] < y[i]) return -1; // -1 insert < root

		else if (x[i] > y[i]) return 1; // insert > root
	}

	if (xLength < yLength) return -1;
	else if (xLength > yLength) return 1;

	return 0; // ==
}

/* insert BRTNode */
BRTNode* BRTInsert(BRTNode* root, BRTNode* pNew)
{
	/* Nếu cây trống thì trả về một BRTNode mới */
	if (root == NULL) return pNew;


	/* Nếu không thì tiếp tục duyệt xuống dưới cây */
	if (pNew->Info.id < root->Info.id)
	{
		root->Left = BRTInsert(root->Left, pNew);
		root->Left->Parent = root;
	}
	else if (pNew->Info.id > root->Info.id)
	{
		root->Right = BRTInsert(root->Right, pNew);
		root->Right->Parent = root;
	}

	/* Trả về con trỏ BRTNode */
	return root;
}

/* Thuật toán xoay trái */
void rotateLeft(BRTNode*& root, BRTNode*& p)
{
	BRTNode* pRight = p->Right;

	p->Right = pRight->Left;

	if (p->Right != NULL)
		p->Right->Parent = p;

	pRight->Parent = p->Parent;

	if (p->Parent == NULL)
		root = pRight;

	else if (p == p->Parent->Left)
		p->Parent->Left = pRight;

	else
		p->Parent->Right = pRight;

	pRight->Left = p;
	p->Parent = pRight;
}

/* Thuật toán xoay phải */
void rotateRight(BRTNode*& root, BRTNode*& p)
{
	BRTNode* pLeft = p->Left;

	p->Left = pLeft->Right;

	if (p->Left != NULL)
		p->Left->Parent = p;

	pLeft->Parent = p->Parent;

	if (p->Parent == NULL)
		root = pLeft;

	else if (p == p->Parent->Left)
		p->Parent->Left = pLeft;

	else
		p->Parent->Right = pLeft;

	pLeft->Right = p;
	p->Parent = pLeft;
}

/* Sửa lại cấu trúc khi chèn BRTNode vào hoặc xóa node */
void fixViolation(BRTNode*& root, BRTNode*& pt)
{
	BRTNode* pParent = NULL;
	BRTNode* pGrandParent = NULL;

	if (!pt || !pt->Parent) return; //Nút rỗng thì dừng

	while ((pt != root) && (pt->Color != BLACK) && (pt->Parent->Color == RED))
	{
		pParent = pt->Parent;
		pGrandParent = pt->Parent->Parent; //Nút ông

		if (!pGrandParent) break; //Nút ông bị rỗng

		/* Trường hợp A:
		node cha của pt là con trái của node ông của pt */
		if (pParent == pGrandParent->Left)
		{
			BRTNode* pUncle = pGrandParent->Right;

			/* Trường hợp: 1
			node chú của pt là node đỏ khi này chỉ cần đổi màu cho node đó thành đen */
			if (pUncle != NULL && pUncle->Color == RED)
			{
				pGrandParent->Color = RED;
				pParent->Color = BLACK;
				pUncle->Color = BLACK;
				pt = pGrandParent;
			}

			else
			{
				/* Trường hợp: 2
				pt là node con phải của node cha nó ta thực hiện xoay trái */
				if (pt == pParent->Right)
				{
					rotateLeft(root, pParent);
					pt = pParent;
					pParent = pt->Parent;
				}

				/* Trường hợp: 3
				pt là con trái của node cha nó ta thực hiện xoay phải */
				rotateRight(root, pGrandParent);
				swapColors(pParent->Color, pGrandParent->Color);
				pt = pParent;
			}
		}

		/* Trường hợp: B
		node cha của pt là con phải của node cha của pt */
		else
		{
			BRTNode* pUncle = pGrandParent->Left;

			/* Trường hợp: 1
			node chú của pt là node đỏ khi này chỉ cần đổi màu cho node đó thành đen */
			if ((pUncle != NULL) && (pUncle->Color == RED))
			{
				pGrandParent->Color = RED;
				pParent->Color = BLACK;
				pUncle->Color = BLACK;
				pt = pGrandParent;
			}
			else
			{
				/* Trường hợp: 2
				pt là con trái của node cha nó ta thực hiện xoay phải */
				if (pt == pParent->Left)
				{
					rotateRight(root, pParent);
					pt = pParent;
					pParent = pt->Parent;
				}

				/* Trường hợp: 3
				pt là node con phải của node cha nó -> nên thực hiện xoay trái */
				rotateLeft(root, pGrandParent);
				swapColors(pParent->Color, pGrandParent->Color);
				pt = pParent;
			}
		}
	}

	root->Color = BLACK;
}

/* Chèn một node mới với dữ liệu đã cho */
void insert(BRTNode*& root, ItemType Info)
{
	BRTNode* pNew = createBRTNode(Info);

	/* Thực hiện chèn như bình thường */
	root = BRTInsert(root, pNew);

	/* Sửa lại lỗi của quy tắc cây đỏ đen */
	fixViolation(root, pNew);
}

/* Kiểm tra xem node hiện tại có phải là node con trái của node cha không */
bool isOnLeft(BRTNode* p)
{
	return p == p->Parent->Left;
}

/* Trả về con trỏ tới node chú (Uncle) */
BRTNode* findUncle(BRTNode* p) {
	// Nếu không có node cha hoặc node ông, thì không có node chú
	if (p->Parent == NULL || p->Parent->Parent == NULL)
		return NULL;

	if (isOnLeft(p->Parent))
		// node chú bên phải
		return p->Parent->Parent->Right;
	else
		// node chú bên trái
		return p->Parent->Parent->Left;
}

/* Trả về con trỏ cho node anh chị em */
BRTNode* findSibling(BRTNode* p) {
	// node anh rỗng nếu không tồn tại node cha 
	if (p->Parent == NULL)
		return NULL;

	if (isOnLeft(p))
		return p->Parent->Right;
	else
		return p->Parent->Left;
}

/* Tìm nút không có nút con bên trái trong cây con của nút đã cho */
BRTNode* findSuccessor(BRTNode* p) {
	BRTNode* temp = p;

	while (temp->Left != NULL)
		temp = temp->Left;

	return temp;
}

/* Kiểm tra có node hiện tại có node con là nút đỏ hay không */
bool hasRedChild(BRTNode* p) {
	return (p->Left != NULL && p->Left->Color == RED) ||
		(p->Right != NULL && p->Right->Color == RED);
}

/* Tìm nút thay thế nút đã xóa trong BST */
BRTNode* BSTReplace(BRTNode* p) {
	// Khi nút có 2 con
	if (p->Left != NULL && p->Right != NULL)
		return findSuccessor(p->Right);

	// Khi node lá 
	if (p->Left == NULL && p->Right == NULL)
		return NULL;

	// Khi node có một con
	if (p->Left != NULL)
		return p->Left;
	else
		return p->Right;
}


void fixDoubleBlack(BRTNode*& root, BRTNode* p) {
	// p là node gốc thì return
	if (p == root) return;

	BRTNode* pSibling = findSibling(p);
	BRTNode* pParent = p->Parent;
	if (pSibling == NULL) {
		// Không có sibiling, màu đen kép được đẩy lên 
		fixDoubleBlack(root, pParent);
	}
	else {
		if (pSibling->Color == RED) {
			// Anh chị em màu đỏ 
			pParent->Color = RED;
			pSibling->Color = BLACK;
			if (isOnLeft(pSibling)) {
				// trường hợp left 
				rotateRight(root, pParent);
			}
			else {
				// trường hợp right 
				rotateLeft(root, pParent);
			}
			fixDoubleBlack(root, p);
		}
		else {
			// Anh chị em đen 
			if (hasRedChild(pSibling)) {
				// Ist nhất 1 trẻ em màu đỏ 
				if (pSibling->Left != NULL && pSibling->Left->Color == RED) {
					if (isOnLeft(pSibling)) {
						// left left 
						pSibling->Left->Color = pSibling->Color;
						pSibling->Color = pParent->Color;
						rotateRight(root, pParent);
					}
					else {
						// right left 
						pSibling->Left->Color = pParent->Color;
						rotateRight(root, pSibling);
						rotateLeft(root, pParent);
					}
				}
				else {
					if (isOnLeft(pSibling)) {
						// left right 
						pSibling->Right->Color = pParent->Color;
						rotateLeft(root, pSibling);
						rotateRight(root, pParent);
					}
					else {
						// right right 
						pSibling->Right->Color = pSibling->Color;
						pSibling->Color = pParent->Color;
						rotateLeft(root, pParent);
					}
				}
				pParent->Color = BLACK;
			}
			else {
				// Hai con đen 
				pSibling->Color = RED;
				if (pParent->Color == BLACK)
					fixDoubleBlack(root, pParent);
				else
					pParent->Color = BLACK;
			}
		}
	}
}

/* Xóa nút đã cho */
void deleteNode(BRTNode*& root, BRTNode* pDelete) {
	BRTNode* pReplace = BSTReplace(pDelete);

	// Đúng khi pReplace và pDelete đều đen
	bool flagDoubleBlack = ((pReplace == NULL || pReplace->Color == BLACK) && (pDelete->Color == BLACK));
	BRTNode* pParent = pDelete->Parent;

	if (pReplace == NULL) {
		// pReplace là NULL do đó pDelete là lá 
		if (pDelete == root) {
			// pDelete là root, làm cho root là NULL 
			root = NULL;
		}
		else {
			if (flagDoubleBlack) {
				// pReplace và pDelete đều đen
				// pDelete là lá, sửa màu đen kép tại pDelete 
				fixDoubleBlack(root, pDelete);
			}
			else {
				// pReplace hoặc pDelete là đỏ
				if (findSibling(pDelete) != NULL)
					// node anh chị em không rỗng, làm cho nó màu đỏ 
					findSibling(pDelete)->Color = RED;
			}

			// Xóa pDelete khỏi cây 
			if (isOnLeft(pDelete)) {
				pParent->Left = NULL;
			}
			else {
				pParent->Right = NULL;
			}
		}
		delete pDelete;
		return;
	}

	if (pDelete->Left == NULL || pDelete->Right == NULL) {
		// pDelete có 1 node con
		if (pDelete == root) {
			// pDelete là gốc, gán giá trị của pReplace cho pDelete và xóa pReplace 
			pDelete->Info = pReplace->Info;
			pDelete->Left = pDelete->Right = NULL;
			delete pReplace;
		}
		else {
			// Tách node pDelete khỏi cây và di chuyển node pReplace lên
			if (isOnLeft(pDelete)) {
				pParent->Left = pReplace;
			}
			else {
				pParent->Right = pReplace;
			}
			delete pDelete;
			pReplace->Parent = pParent;
			if (flagDoubleBlack) {
				// pReplace và pDelete đều đen, sửa hai màu đen ở pReplace 
				fixDoubleBlack(root, pReplace);
			}
			else {
				// pReplace hoặc pDelete đỏ, màu pReplace đen 
				pReplace->Color = BLACK;
			}
		}
		return;
	}

	// pDelete có 2 con, hoán đổi giá trị với nút kế nhiệm (thế mạng) và đệ quy 
	swapInfos(pReplace->Info, pDelete->Info);
	deleteNode(root, pReplace);
}


/* Tìm kiếm một giá trị trên cây */
//BRTNode* search(BRTNode* root, ItemType x) {
//	BRTNode* temp = root;
//	while (temp != NULL) {
//		if (x == temp->Info) {
//			return temp;
//		}
//		else if (x < temp->Info) {
//			temp = temp->Left;
//		}
//		else {
//			temp = temp->Right;
//		}
//	}
//
//	return NULL; //Không tìm thấy x trong cây
//}
//
///* chức năng tiện ích xóa nút có giá trị nhất định */
//void deleteByInfo(BRTNode*& root, ItemType x) {
//	// BRTree là rỗng 
//	if (root == NULL) return;
//
//	BRTNode* delete_pt = search(root, x.soTC);
//
//	if (delete_pt == NULL) {
//		printf("\nKhong tim thay nut nao de xoa voi gia tri: %d", x);
//		return;
//	}
//
//	deleteNode(root, delete_pt);
//}
//==================================================
void createBRTreeFromArray(BRTree& brt, ItemType a[], int na)
{//Ham tao cay Black-Red Tree tu mang a
	initBRTree(brt);
	for (int i = 0; i < na; i++)
	{
		insert(brt.Root, a[i]);
		set_Color(14, 2);
		printf("\nOutput: sau khi them %d\n", a[i]);
		showBRTree_InOrder(brt.Root);
		_getch();
	}

}
void createBRTreeFromFile(BRTree& brt, char fileName[]) {
	initBRTree(brt);
	FILE* fi = fopen(fileName, "rt");


	if (fi == NULL)
	{
		printf("LOI DOC FIle");
	}
	else {
		ItemType x;
		int n;

		fscanf(fi, "%d", &n);

		for (int i = 0; i < n; i++)
		{
			fscanf(fi, "%[^\#]#%[^\#]#%[^\#]#%d\n", &x.id, &x.name, &x.loaiHP, &x.soTC);
			insert(brt.Root, x);
		}
		fclose(fi);
	}
}

void hienThiMonHocThucHanh(BRTNode* root) {
	fflush(stdin);
	char searchValue[] = "Thuc hanh";

	if (root == NULL) return;

	hienThiMonHocThucHanh(root->Left);
	hienThiMonHocThucHanh(root->Right);

	
	if (strstr(root->Info.name, searchValue) != NULL) {
		showBRTNode(root);
	}
}

void inThongTinMonCoMaX(BRTNode* root, char idMonHoc[]) {
	if (root == NULL) return;

	inThongTinMonCoMaX(root->Left, idMonHoc);
	inThongTinMonCoMaX(root->Right, idMonHoc);

	if (strcmp(root->Info.id, idMonHoc) == 0) {
		showBRTNode(root);
	}
}

void xoaTatCaMonTinChiLa1(BRTNode* root) {
	if (root == NULL) return;

	xoaTatCaMonTinChiLa1(root->Left);
	xoaTatCaMonTinChiLa1(root->Right);

	if (root->Info.soTC == 1) {
		/*deleteByInfo(root, root->Info);*/
	}

}

void menu() {
	printf("\n----------------------MENU----------------------\n");
	printf("\n 0. Thoat chuong trinh");
	printf("\n 1. Load danh sach mon hoc ");
	printf("\n 2. In ra man hinh cac mon <thuc hanh>");
	printf("\n 3. In ra man hinh cac mon co ma x");
	printf("\n 4. Xoa tat ca cac mon co tin chi la 1");
	printf("\n---------------------[END]----------------------\n");

	
}

void process() {
	int luachon;
	BRTree brtree;
	initBRTree(brtree);

	ItemType a[] = { 4, 7, 12, 15, 3, 5, 14, 18, 16, 17 };

	char fileName[] = "dsMonHoc.txt";


	do
	{
		menu();
		printf("\nHay chon chuc nang: ");
		scanf("%d", &luachon);

		switch (luachon)
		{
		case 0: return;
		case 1: 
			createBRTreeFromFile(brtree, fileName);
			printf("\nOutput: NLR\n");

			showBRTree_InOrder(brtree.Root);

			printf("\nOutput: Duyet theo chieu rong (Breadth-first traverse) \n");
			showLevelOrder(brtree.Root);

			printf("\nOutput: Duyet theo chieu sau Pre-Order (Depth-first traverse) \n");
			showPreOrder(brtree.Root);

			break;
		case 2: 
		{	
			system("cls");
			printf("\nCac mon hoc thuc hanh la: \n");
			hienThiMonHocThucHanh(brtree.Root);
			break;
		}
		case 3: {
			char idMonHoc[31];
			printf("Nhap ma mon hoc: "); 
			rewind(stdin);
			gets_s(idMonHoc);

			inThongTinMonCoMaX(brtree.Root, idMonHoc);
			break;
		}
		case 4: {
			/*xoaTatCaMonTinChiLa1(brtree.Root);
			printf("\nDanh Sach Mon Hoc Sau Khi Xoa La (NLR): \n");

			showBRTree_InOrder(brtree.Root);*/
			
			break;
		}
		case 5: {
			break;
		}
		default:
			break;
		}
		
	} while (luachon != 0);
}

void main()
{

	process();
	_getch();
}
