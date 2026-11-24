
#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};


struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void InsertTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pTail = p;
        L.pHead = L.pTail;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void Noi(LIST &, LIST);

//ham noi hai danh sach lien ket
void Noi(LIST &L, LIST R)
{
    if(R.pHead == nullptr)
        return;
    if(L.pHead == nullptr)
    {
        L.pHead = R.pHead;
        return;
    }
    L.pTail->pNext = R.pHead;
}

//ham tron hai danh sach lien ket
void TronDSLK(const LIST &L1, const LIST &L2, LIST &L3)
{
    if(L1.pHead == nullptr && L2.pHead == nullptr)
        return;

    CreateEmptyList(L3);
    NODE* curentnodeL1 = L1.pHead;
    NODE* currentnodeL2 = L2.pHead;
    while(curentnodeL1 != nullptr && currentnodeL2 != nullptr)
    {
        if(curentnodeL1->info < currentnodeL2->info)
        {
            InsertTail(L3, curentnodeL1);
            curentnodeL1 = curentnodeL1->pNext;
        }

        else
        {
            InsertTail(L3, currentnodeL2);
            currentnodeL2 = currentnodeL2->pNext;
        }
    }

    while(curentnodeL1 != nullptr)
    {
        InsertTail(L3, curentnodeL1);
        curentnodeL1 = curentnodeL1->pNext;
    }

    while (currentnodeL2 != nullptr)
    {
        InsertTail(L3, currentnodeL2);
        currentnodeL2 = currentnodeL2->pNext;
    }
}

void ClearList(LIST &L)
{
    NODE* currentnode = L.pHead;
    while(currentnode != nullptr)
    {
        NODE *temp = currentnode;
        currentnode = currentnode->pNext;
        delete temp;
    }
    L.pHead = L.pTail = nullptr;
}


int main()
{
    int t; cin >> t;
    LIST L1;
    LIST L2;
    LIST L3;
    for (int pid = 0; pid < t; pid++){
        CreateEmptyList(L1);
        int n, m; cin >> n >> m;
        int x;
        for (int i = 0; i < n; i++){
            cin >> x;
            InsertTail(L1, CreateNode(x));
        }
        CreateEmptyList(L2);
        for (int i = 0; i < m; i++){
            cin >> x;
            InsertTail(L2, CreateNode(x));
        }
        TronDSLK(L1, L2, L3);
        PrintList(L3);
        ClearList(L1);
        ClearList(L2);
        ClearList(L3);
        cout << "\n";
    }
    return 0;
}
