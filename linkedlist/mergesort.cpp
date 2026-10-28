#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
struct LIST{
    Node*pHead, *pTail;
};

Node* CreateNode(int x)
{
    Node *p = new Node;
    if(p == nullptr)
        exit(0);
    p->data = x;
    p->next = nullptr;
    return p;
}

void CreateEmptyList(LIST &L)
{
    L.pHead = L.pTail = nullptr;
}

void AddTail(LIST& l, Node* p)
{
    if(l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
        return;
    }
    l.pTail->next = p;
    l.pTail = p;
}

void ClearList(LIST &L)
{
    Node *currentNode = L.pHead;
    while(currentNode != nullptr)
    {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
    L.pHead = L.pTail = nullptr;
}

// Hàm tìm node ở giữa danh sách (Fast & Slow Pointers)
Node* getMiddle(Node* head) {
    if (head == nullptr) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Hàm trộn hai danh sách liên kết đơn đã được sắp xếp(tang dan)
Node* sortedMerge(Node* a, Node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    Node* result = nullptr;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

// Hàm trộn hai danh sách liên kết đơn đã được sắp xếp(giam dan)
Node* sortedMergeDES(Node* a, Node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    Node* result = nullptr;

    if (a->data >= b->data) {
        result = a;
        result->next = sortedMergeDES(a->next, b);
    } else {
        result = b;
        result->next = sortedMergeDES(a, b->next);
    }
    return result;
}

// Hàm thực hiện Merge Sort cho danh sách liên kết đơn (Chạy dựa trên Node)
void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // Chia danh sách thành 2 nửa: a và b
    Node* middle = getMiddle(head);
    Node* nextOfMiddle = middle->next;

    middle->next = nullptr; // Cắt đôi danh sách

    // Đệ quy sắp xếp từng nửa
    mergeSort(&head);
    mergeSort(&nextOfMiddle);

    // Trộn hai nửa đã sắp xếp
    *headRef = sortedMergeDES(head, nextOfMiddle);
}

void SortList(LIST &L) {
    if (L.pHead == nullptr || L.pHead->next == nullptr) return;

    // 1. Chạy thuật toán mergeSort dựa trên Node cho pHead
    mergeSort(&L.pHead);

    // 2. Tìm lại pTail mới sau khi danh sách đã bị xáo trộn vị trí
    Node* temp = L.pHead;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    L.pTail = temp; // Cập nhật lại pTail chính xác
}

void NhapDS(LIST &L, int n)
{
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        AddTail(L, CreateNode(temp));
    }
}

void PrintList(LIST L) {
    Node* temp = L.pHead;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

long long CalSum(const LIST &A, const LIST &B)
{
    Node *currentnodeB = B.pHead;
    Node *currentnodeA = A.pHead;
    int count = 0;
    long long sum = 0;
    while(currentnodeB != nullptr)
    {
        int index = currentnodeB->data;
        while(currentnodeA != nullptr)
        {
            if(count == index)
            {
                sum += currentnodeA->data;
                break;
            }
            count++;
            currentnodeA = currentnodeA->next;
        }
        currentnodeB = currentnodeB->next;
    }
    return sum;
}

void InSoTrongKhoang(const LIST &A, int a, int b)
{
    Node *currentnode = A.pHead;
    while(currentnode != nullptr)
    {
        if((currentnode->data > a) && (currentnode->data < b))
            cout << currentnode->data << " ";
        currentnode = currentnode->next;
    }
}

long long TinhTongViTriChan(const LIST &A)
{
    int count = 0;
    int sum = 0;
    Node *currentnode = A.pHead;
    while(currentnode != nullptr)
    {
        if(count % 2 == 0)
        {
            sum += currentnode->data;
        }
        count++;
        currentnode = currentnode->next;
    }
    return sum;
}

long long TinhTongLonNhat(const LIST &A)
{
    if(A.pHead == nullptr)
    {
        return 0;
    }
    if(A.pHead == A.pTail)
    {
        return (long long)A.pHead->data;
    }

    return (long long)A.pHead->data + A.pHead->next->data; 
}

int main()
{
    int n;
    
    // Nhập danh sách A
    cin >> n;
    LIST A;
    CreateEmptyList(A);
    NhapDS(A, n);
    SortList(A);
    cout << TinhTongLonNhat(A);
    // Giải phóng bộ nhớ trước khi thoát chương trình
    ClearList(A);
    return 0;
}
