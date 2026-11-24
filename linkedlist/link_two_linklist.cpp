
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
    LIST L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L1, CreateNode(x));
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++){
        cin >> x;
        InsertTail(L2, CreateNode(x));
    }
    Noi(L1, L2);
    PrintList(L1);
    cout << "\n";
    PrintList(L2);
    ClearList(L1);
    ClearList(L2);
    return 0;
}
