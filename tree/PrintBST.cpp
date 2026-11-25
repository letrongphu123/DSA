#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
};

Node* CreateNode(int x)
{
    Node* p = new Node;
    if(p == nullptr)
        exit(0);

    p->value = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

typedef Node* TREE;

void CreateTree(TREE &t)
{
    t = nullptr;
}

int Insert(TREE &t, Node* p)
{
    if(t != nullptr)
    {
        if(t->value == p->value)
            return 0;
        
        if(t->value > p->value)
            return Insert(t->left, p);
        return Insert(t->right, p);
    }
    t = p;
    return 1;
}

void PrintNLR(const TREE &t)
{
    if(t != nullptr)
    {
        cout << t->value << " ";
        PrintNLR(t->left);
        PrintNLR(t->right);
    }
}

void PrintLNR(const TREE &t)
{
    if(t != nullptr)
    {
        PrintLNR(t->left);
        cout << t->value << " ";
        PrintLNR(t->right);
    }
}

void PrintLRN(const TREE &t)
{
    if(t != nullptr)
    {
        PrintLRN(t->left);
        PrintLRN(t->right);
        cout << t->value << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    TREE t;
    CreateTree(t);
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        Insert(t, CreateNode(temp));
    }
    PrintLRN(t);
    return 0;
}