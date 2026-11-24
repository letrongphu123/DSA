
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


void SwapPointers(LIST &L , NODE* p, NODE* min)
{
    //neu hai node trung nhau thi khong lam gi
    if(p == nullptr || min == nullptr || p == min)
        return;

    //tim node dung truoc p va dung truoc min
    NODE *pastp = nullptr;
    NODE *pastmin = nullptr;
    NODE *currentnode = L.pHead;
    while(currentnode != nullptr && (pastp == nullptr || pastmin == nullptr))
    {
        if(currentnode->pNext == p)
            pastp = currentnode;
        if(currentnode->pNext == min)
            pastmin = currentnode;
        currentnode = currentnode->pNext;
    }

    if(pastp != nullptr)
        pastp->pNext = min;
    else 
        L.pHead = min; //p la phan tu dau tien

    if(pastmin != nullptr)
        pastmin->pNext = p;
    else 
        L.pHead = p;    //min la phan tu dau tien

    NODE* temp = p->pNext;
    p->pNext = min->pNext;
    min->pNext = temp;

    //cap nhat tail
    if(L.pTail == p)
        L.pTail = min;
    else if(L.pTail == min)
        L.pTail = p;
}

void ClearList(LIST &A)
{
    NODE* currentNode = A.pHead;
    while(currentNode != nullptr)
    {
        NODE* temp = currentNode;
        currentNode = currentNode->pNext;
        delete temp;
    }
    A.pHead = A.pHead = nullptr;
}


void SelectionSort(LIST &L){
    NODE* tmp;
    NODE* p = L.pHead;
    NODE* q;
    NODE* node_min;
    while (p != NULL){
        node_min = p;
        for (q = p->pNext; q != NULL; q = q->pNext){
            if (q->info < node_min->info)
                node_min = q;
        }
        SwapPointers(L, p, node_min);
        p = node_min->pNext;
    }
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
    SelectionSort(L);
    PrintList(L);
    ClearList(L);
    return 0;
}
