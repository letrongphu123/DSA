/*
Check If Linked List Is Sorted
Tuan is validating a queue of students stored as a linked list — he needs to confirm whether their IDs are already arranged in non-decreasing order before feeding the list to a sorting algorithm.

Problem
Given a singly linked list of N integers, determine whether the values are sorted in non-decreasing order (i.e., each node's value ≤ the next node's value).

If N ≤ 1, the list is trivially sorted → print YES.
Print YES if sorted non-decreasing, otherwise NO.
Input Format
Line 1: N — number of nodes
Line 2: N space-separated integers (the list values); omitted if N = 0

Output Format
Print YES if the list is sorted in non-decreasing order, otherwise NO.

Constraints
0 ≤ N ≤ 10^4
-10^6 ≤ value ≤ 10^6
*/

#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

Node* CreateNode(int x)
{
    Node* p = new Node;
    if(p == nullptr)
        exit(0);
    p->value = x;
    p->next = nullptr;
    return p;
}

struct List{
    Node* head;
    Node* tail;
};

void CreateEmptyList(List &l)
{
    l.head = l.tail = nullptr;
}

void AddHead(List &l, Node* p)
{
    if(l.head == nullptr)
        l.head = l.tail = p;
    
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

void PopHead(List &l)
{
    if(l.head != nullptr)
    {
        l.head = l.head->next;
    }
}

bool CheckIfLinkedListIsSorted(const List &l)
{
    if(l.head == nullptr || l.head == l.tail)
        return true;

    Node* curNode = l.head;
    Node* pastNode = nullptr;
    while(curNode != nullptr)
    {
        if(pastNode != nullptr)
            if(pastNode->value < curNode->value)
                return false;
        
        pastNode = curNode;
        curNode = curNode->next;
    }
    return true;
}

void ClearList(List &l)
{
    Node* curNode = l.head;
    while(curNode != nullptr)
    {
        Node* temp;
        temp = curNode;
        curNode = curNode->next;
        delete temp;
    }

    l.head = l.tail = nullptr;
}

int main()
{
    int n;
    cin >> n;
    List L;
    CreateEmptyList(L);
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        AddHead(L, CreateNode(temp));
    }
    if(CheckIfLinkedListIsSorted(L))
        cout << "YES";
    else    
        cout << "NO";
    ClearList(L);
    return 0;
}
