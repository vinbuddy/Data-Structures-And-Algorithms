#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

typedef int ItemType;

struct BTNode
{
    ItemType Infor;
    BTNode* Left;
    BTNode* Right;
};

struct BTree
{
    BTNode* root;
};

void initBtree(BTree& bt);
BTNode* createBTNode(ItemType x);

void showBTNode(BTNode* p);
void showBTree_NLR(BTNode* root);

bool isEmpty(BTree bt);

void createBTree_Auto(BTree& bt);
bool insertBTNodeLeft(BTNode*& T, BTNode* p);
bool insertBTNodeRight(BTNode*& T, BTNode* p);
bool insertBTNode(BTNode*& root, BTNode* p);

void process();
void showMenu();

int main() {
    process();

    _getch();
    return 0;
}

void showMenu() {
    printf("\n----------------------MENU----------------------\n");
    printf("\n 0. Thoat chuong trinh");
    printf("\n 1. Tao Btree auto ");
    printf("\n------------------------------------------------\n");
}


void process() {
	int luachon;

	ItemType x;
	BTree bt;
	BTNode* p;

	initBtree(bt);


	do {

		showMenu();

		printf("\nNhap lua chon cua ban: ");
		scanf_s("%d", &luachon);

		switch (luachon)
		{
		case 1:
			system("cls");
			createBTree_Auto(bt);
            printf("\nCac Element BTree (NLR) la: \n");
            showBTree_NLR(bt.root);
            break;
		default:
			break;
		}

	} while (luachon != 0);
}

void initBtree(BTree& bt) {
    bt.root = NULL;
}
BTNode* createBTNode(ItemType x) {
    BTNode* p = new BTNode;

    if (!p)
        return NULL;

    p->Infor = x;
    p->Left = NULL;
    p->Right = NULL;

    return p;
}
bool isEmpty(BTree bt)
{
    return (bt.root == NULL);
}

void createBTree_Auto(BTree& bt) {
    int n;
    ItemType x;
    BTNode* p;
    bool isShowFirstRoot = true;

    initBtree(bt);

    printf("\nNhap so node can tao: ");
    scanf_s("%d", &n);

    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++) {
        x = rand() % 100;
        p = createBTNode(x);
        insertBTNode(bt.root, p);

        if (isShowFirstRoot) {
            printf("\nROOT: %d\n", p->Infor);
            isShowFirstRoot = false;
        }

    }
}

void showBTNode(BTNode* p) {
    printf("%4d", p->Infor);
}
void showBTree_NLR(BTNode* root) {
    if (root == NULL) return;

    showBTNode(root);
    showBTree_NLR(root->Left);
    showBTree_NLR(root->Right);
}

bool insertBTNodeLeft(BTNode*& T, BTNode *p) {
    if (T == NULL)
        return false;
    if (T->Left != NULL)
        return false;

    T->Left = p;

    return true;
}
bool insertBTNodeRight(BTNode*& T, BTNode* p) {
    if (T == NULL)
        return false;
    if (T->Right != NULL)
        return false;

    T->Right = p;

    return true;
}
bool insertBTNode(BTNode*& root, BTNode* p) {
    if (!p) return false;

    if (!root) {
        root = p;
        return true;
    }

    if (!root->Left) {
        insertBTNode(root->Left, p);
        printf("\nThem %d vao ben trai cua %d", p->Infor, root->Infor);
    }
    else if (!root->Right) {
        insertBTNode(root->Right, p);
        printf("\nThem %d vao ben phai cua %d", p->Infor, root->Infor);
    }
    else {
        int randomNum = rand() % 2 + 1; // 1 left, 2 right
        if (randomNum == 1)
            insertBTNode(root->Left, p);
        else
            insertBTNode(root->Right, p);
    }

    return true;
}