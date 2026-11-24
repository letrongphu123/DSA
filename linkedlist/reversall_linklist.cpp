
#include <bits/stdc++.h>
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

void ReverseLL(LIST &);

void InsertHead(LIST &L, NODE* p)
{
    if(L.pHead == nullptr)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
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

void ReverseLL(LIST &L)
{
    if(L.pHead == L.pTail)
        return;

    LIST temp;
    CreateEmptyList(temp);
    NODE *currentnode = L.pHead;
    while(currentnode != nullptr)
    {
        NODE* newnode = CreateNode(currentnode->info);
        InsertHead(temp, newnode);
        currentnode = currentnode->pNext;
    }
    ClearList(L);
    L.pHead = temp.pHead;
}


int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L, CreateNode(x));
    }
    ReverseLL(L);
    PrintList(L);
    ClearList(L);
    return 0;
}
