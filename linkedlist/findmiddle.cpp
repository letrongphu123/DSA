/*Hãy viết một chương trình nhập vào n số nguyên sau đó in ra số ở vị trí chính giữa của dãy số chẵn theo đúng thứ tự nhập vào. Nếu không vị trí chính giữa, thì lấy số ở vị trí lệch bên trái gần vị trí chính giữa nhất. Biết rằng, trong bài này, không được sử dụng mảng và không được include thêm thư viện.
Đầu vào của bài toán gồm:
- Dòng đầu tiên là số n.
- n số kế tiếp là các số nguyên dương.
Đầu ra của bài toán là một số duy nhất, chính là số ở vị trí chính giữa

Input	                Output
10
1 2 3 4 5 6 7 8 9 11	4
10
1 2 3 4 5 6 7 8 9 10	6
*/
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void CreateList(List &l)
{
    l.head = l.tail = nullptr;
}

Node* CreateNode(int value)
{
    Node *p = new Node;
    if(p == nullptr)
        exit(0);
    p->data = value;
    p->next = nullptr;
    return p;
}

void AddTail(List &l, int value)
{
    Node *p = CreateNode(value);
    if(l.head == nullptr)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void ClearList(List &l)
{
    Node *currentNode = l.head;
    while(currentNode != nullptr)
    {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
    l.head = l.tail = nullptr;
}

//Ham tim so o giua danh sach so chan
int FindMiddle(const List &l, int sl_sochan)
{
    int index;
    (sl_sochan % 2 == 0)? index = sl_sochan / 2 : index = sl_sochan / 2 + 1;
    int count = 1;
    Node *currentNode = l.head;
    while(currentNode != nullptr)
    {
        if(currentNode->data % 2 == 0)
        {
            if(count == index)
                return currentNode->data;
            count++;
        }
        currentNode = currentNode->next;
    }
    return -1;
}


int main()
{
    int n;
    cin >> n;
    int SL_sochan = 0;
    List l;
    CreateList(l);
    for(int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        if(value % 2 == 0)
            SL_sochan++;
        AddTail(l, value);
    }
    cout << FindMiddle(l, SL_sochan);
    ClearList(l);
    return 0;
}