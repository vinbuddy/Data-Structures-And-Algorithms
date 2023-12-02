/*
	Họ và tên:	Huỳnh Thế Vinh
	MSSV:		2001210660
	Lớp:		12DHTH07
	Tiết/Buổi:	1-5 / ST4 / Buổi 6_BSTree
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include <queue>
#include <stack>
#include <Windows.h>

using namespace std;

typedef int ItemType;

struct BSTNode
{
    ItemType Infor;
    BSTNode* Left;
    BSTNode* Right;
};

struct BSTree
{
    BSTNode* root;
};

void initBtree(BSTree& bt);
BSTNode* createBSTNode(ItemType x);

void showBSTNode(BSTNode* p);
void showBSTree_NLR(BSTNode* root);

bool isEmpty(BSTree bt);

void createBSTree_Input(BSTree& bt);
void createBSTree_Auto(BSTree& bt);
void createBSTree_FromArr(BSTree& bt, ItemType a[], int n);

bool insertBSTNodeLeft(BSTNode*& T, BSTNode* p);
bool insertBSTNodeRight(BSTNode*& T, BSTNode* p);
bool insertBSTNode(BSTNode*& root, BSTNode* p);

bool isLeaf(BSTNode* root);
int countLeaf(BSTNode* root);

BSTNode* findBSTreeNode(BSTNode* root, ItemType x);

// Delete nut
BSTNode* findNodeReplace(BSTree*& p);
bool deleteNodeX(BSTNode* &root, ItemType x);

// Duyet cay rong - sau
void traverseBreadthNLR(BSTNode* root);
void traverseDepthNLR(BSTNode* root);


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
    printf("\n 1. Tao BStree auto ");
    printf("\n 2. Tao BStree from Arr ");
    printf("\n 3. Show BSTree ");
    printf("\n 4. Dem nut la tren cay ");
    printf("\n 5. Tim gia tri x co ton tai tren cay khong ");
    printf("\n 6. Xoa gia tri x tren cay ");
    printf("\n 7. Duyet cay chieu rong ");
    printf("\n 8. Duyet cay chieu sau ");
    printf("\n------------------------------------------------\n");
}


void process() {
    int luachon;

    ItemType x;
    BSTree bt;
    BSTNode* p;

    ItemType A[] = { 45, 20, 35, 84, 21, 10, 67, 89, 72, 98, 16, 38, 30, 5, 63};
    int N = 15;

    initBtree(bt);


    do {

        showMenu();

        printf("\nNhap lua chon cua ban: ");
        scanf_s("%d", &luachon);

        switch (luachon)
        {
        case 1:
            system("cls");
            createBSTree_Auto(bt);
            printf("\nCac Element BSTree (NLR) la: \n");
            showBSTree_NLR(bt.root);
            break;
        case 2: 
            system("cls");
            createBSTree_FromArr(bt, A, N);
            break;
        case 3: 
            system("cls");
            printf("\nCac Element BSTree (NLR) la: ");
            showBSTree_NLR(bt.root);
            break;
        case 4:
            system("cls");
            printf("\nSo nut la tren cay la: %d", countLeaf(bt.root));
            break;
        case 5:
        {
            system("cls");
            printf("\nNhap gia tri muon tim: "); scanf("%d", &x);
            p = findBSTreeNode(bt.root, x);

            if (p)
                printf("\nGia tri %d co ton tai tren cay", x);
            else
                printf("\nGia tri %d khong ton tai tren cay", x);

            break;
        }

        case 6:
        {
            system("cls");
            printf("\nNhap gia tri muon xoa: "); scanf("%d", &x);
            bool isDeleted = deleteNodeX(bt.root, x);

            if (isDeleted)
                printf("\Da xoa gia %d tren cay", x);
            else
                printf("\nXoa %d khong thanh cong", x);
            break;
        }

        case 7:
            system("cls");
            printf("\nDuyet theo chieu rong NLR: ");
            traverseBreadthNLR(bt.root);
            break;
        case 8:
            system("cls");
            printf("\nDuyet theo chieu sau NLR: ");
            traverseDepthNLR(bt.root);
            break;
        default:
            break;
        }

    } while (luachon != 0);
}

void initBtree(BSTree& bt) {
    bt.root = NULL;
}
BSTNode* createBSTNode(ItemType x) {
    BSTNode* p = new BSTNode;

    if (!p)
        return NULL;

    p->Infor = x;
    p->Left = NULL;
    p->Right = NULL;

    return p;
}
bool isEmpty(BSTree bt)
{
    return (bt.root == NULL);
}

void createBSTree_Auto(BSTree& bt) {
    int n;
    ItemType x;
    BSTNode* p;
    bool isShowFirstRoot = true;

    initBtree(bt);

    printf("\nNhap so node can tao: ");
    scanf_s("%d", &n);

    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++) {
        x = rand() % 100;
        p = createBSTNode(x);
        insertBSTNode(bt.root, p);

        if (isShowFirstRoot) {
            printf("\nROOT: %d\n", p->Infor);
            isShowFirstRoot = false;
        }

    }
}
void createBSTree_FromArr(BSTree& bt, ItemType a[], int n) {
    ItemType x;
    BSTNode* p;
    bool isShowFirstRoot = true;

    initBtree(bt);

    srand((unsigned)time(NULL));

    /*for (int i = 0; i < n; i++) {
        x = rand() % 100;
        p = createBSTNode(x);
        insertBSTNode(bt.root, p);

        if (isShowFirstRoot) {
            printf("\nROOT: %d\n", p->Infor);
            isShowFirstRoot = false;
        }

    }*/

    int i = 0;

    while (i < n)
    {
        x = a[i];
        p = createBSTNode(x);
        insertBSTNode(bt.root, p);
        i++;

        if (isShowFirstRoot) {
            printf("\nROOT: %d\n", p->Infor);
            isShowFirstRoot = false;
        }
    }
}

void createBSTree_Input(BSTree& bt) {
    ItemType x;
    int n;
    BSTNode* p;
    bool isShowFirstRoot = true;

    initBtree(bt);

    printf("\nNhap so luong phan tu tren cay: "); scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nNhap gia phan tu: "); scanf("%d", &x);

        p = createBSTNode(x);
        insertBSTNode(bt.root, p);

        if (isShowFirstRoot) {
            printf("\nROOT: %d\n", p->Infor);
            isShowFirstRoot = false;
        }

    }

    
}

void showBSTNode(BSTNode* p) {
    printf("%4d", p->Infor);
}
void showBSTree_NLR(BSTNode* root) {
    if (root == NULL) return;

    showBSTNode(root);
    showBSTree_NLR(root->Left);
    showBSTree_NLR(root->Right);
}

bool insertBSTNodeLeft(BSTNode*& T, BSTNode* p) {
    if (T == NULL)
        return false;
    if (T->Left != NULL)
        return false;

    T->Left = p;

    return true;
}
bool insertBSTNodeRight(BSTNode*& T, BSTNode* p) {
    if (T == NULL)
        return false;
    if (T->Right != NULL)
        return false;

    T->Right = p;

    return true;
}
bool insertBSTNode(BSTNode*& root, BSTNode* p) {
    if (!p) return false;

    if (!root) {
        root = p;
        return true;
    }

    if (root->Infor == p->Infor) {
        return false; // Existed 
    }
    else if (root->Infor > p->Infor) { // value < root 
        insertBSTNode(root->Left, p);
        printf("\nThem %d vao ben trai cua %d", p->Infor, root->Infor);
    } 
    else {
        insertBSTNode(root->Right, p);
        printf("\nThem %d vao ben phai cua %d", p->Infor, root->Infor);
    }
    
    return true;
}

bool isLeaf(BSTNode* p) {
    return !p->Left && !p->Right;
}
int countLeaf(BSTNode* root) {
    if (!root) return 0;

    int countLeft = countLeaf(root->Left);
    int countRight = countLeaf(root->Right);

    if (isLeaf(root))
        return 1 + countLeft + countRight;

    return countLeft + countRight;
}

BSTNode* findBSTreeNode(BSTNode* root, ItemType x) {
    if (!root) return NULL;

    if (root->Infor == x)
        return root;
    else if (x < root->Infor)
        return findBSTreeNode(root->Left, x);
    else 
        return findBSTreeNode(root->Right, x);
}


// Delete nut
BSTNode* findNodeReplace(BSTNode*& p) {

    BSTNode* f = p; // f là nút cha của nút rp
    BSTNode* rp = p->Right; // Tìm nút rp nhỏ nhất trên cây con phải để thế cho p

    while (rp->Left) {
        f = rp; // lưu nút cha của rp
        rp = rp->Left;
    }

    p->Infor = rp->Infor;

    // Neu rp là cha nút p
    if (rp == p)
        f->Right = rp->Right;
    else 
        f->Left = rp->Right;

    return rp;
}

bool deleteNodeX(BSTNode* &root, ItemType x) {
    if (!root) return false;

    if (root->Infor > x)
        return deleteNodeX(root->Left, x);
    else if (root->Infor < x)
        return deleteNodeX(root->Right, x);
    else
    {
        BSTNode* p = root;

        if (!root->Left)
            root = root->Right;
        else if (!root->Right)
            root = root->Left;
        else {
            // Khi có cả 2 nhánh thì chọn Min của nhánh phải
            BSTNode* q = findNodeReplace(p);
            delete q;
        }
    }

    return true;
}

void traverseBreadthNLR(BSTNode* root) {
    if (!root) return;

    queue <BSTNode*> q;
    q.push(root);

    while (!q.empty())
    {
        BSTNode* p;
        p = q.front();
        q.pop();

        showBSTNode(p);

        if (p->Left != NULL) {
            q.push(p->Left);
        } 

        if (p->Right != NULL) {
            q.push(p->Right);
        }
    }
}
void traverseDepthNLR(BSTNode* root) {
    if (!root) return;

    stack <BSTNode*> st;

    st.push(root);

    while (!st.empty()) {
        BSTNode* p;
        p = st.top();
        st.pop();

        showBSTNode(p);

        if (p->Right != NULL) {
            st.push(p->Right);
        }

        if (p->Left != NULL) {
            st.push(p->Left);
        }

        
    }
}