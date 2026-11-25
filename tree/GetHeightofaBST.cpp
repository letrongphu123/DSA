/*
Get Height of a BST
A forest ranger maintains a record of tree heights by building a classification tree — a Binary Search Tree where each new species is inserted in the order it is discovered. The ranger needs to know the height of this BST to understand how balanced (or unbalanced) the classification has become over time.

Problem
Given a sequence of n distinct integers inserted into a Binary Search Tree (BST) in the given order, compute the height of the BST. The height is defined as the number of edges on the longest path from the root to any leaf. A single-node tree has height 0.

Input Format
Line 1: An integer n — the number of nodes.
Line 2: n space-separated integers representing the values to insert into the BST in order (first value becomes the root).
Output Format
A single integer — the height of the BST.

Constraints
1 ≤ n ≤ 10^4
1 ≤ values ≤ 10^6
All values are distinct (no duplicates).
*/
#include <iostream>
#include <queue>

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

int GetHeightBST(TREE &t)
{
    if(t == nullptr)
        return -1;

    queue<Node*> q;
    int height = -1;
    q.push(t);
    
    while(!q.empty())
    {
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++)
        {
            Node* curNode = q.front();
            q.pop();

            if(curNode->left)
                q.push(curNode->left);
            if(curNode->right)
                q.push(curNode->right);
        }
        height++;
    }
    return height;
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
    cout << GetHeightBST(t);
    return 0;
}