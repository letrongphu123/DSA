/* Remove All Adjacent Duplicates In String
Marina is developing a text simplification engine that compresses repetitive patterns. Her algorithm works by scanning a string and erasing any two identical adjacent characters — then repeating this process until no such pairs remain, yielding a fully simplified result.

Problem
Given a string s of lowercase English letters, repeatedly remove two adjacent equal characters until no more such pairs exist. Return the final string. It is guaranteed that the answer is unique regardless of the order in which pairs are removed.

Input Format
A single line containing the string s.

Output Format
A single line containing the resulting string after all adjacent duplicates have been removed. If the entire string is eliminated, print an empty line.

Constraints
1 ≤ |s| ≤ 10^6
s consists of lowercase English letters only.
Sample Test Cases
Input	Output	    Explanation
abbaca	ca	        Remove bb → aaca; remove aa → ca
azxxzy	ay	        Remove xx → azzy; remove zz → ay
a	a	            Single character — no adjacent pair exists
aa	    (empty)	    Remove the only pair aa → empty string
abcdef	abcdef	    No adjacent duplicates — string is unchanged
*/

#include <iostream>

using namespace std;

struct NODE{
    char value;
    NODE* next;
};

NODE* CreateNode(char a)
{
    NODE* p = new NODE;
    if(p == nullptr)
        exit(0);

    p->value = a;
    p->next = nullptr;
    return p;
}

struct STACK{
    NODE* head = nullptr;
};

bool Isempty(const STACK &s)
{
    if(s.head == nullptr)
        return true;
    return false;
}

void AddHead(STACK &s, NODE* p)
{
    if(!Isempty(s))
    {
        p->next = s.head;
        s.head = p;
        return;
    }
    s.head = p;
}

void PopHead(STACK &s)
{
    if(!Isempty(s))
    {
        s.head = s.head->next;
    }
}

void ClearStack(STACK &s)
{
    while(!Isempty(s))
    {
        PopHead(s);
    }
}

void Reversall_Stack(STACK &s)
{
    if(Isempty(s))
        return;

    STACK temp;
    NODE* currentnode = s.head;
    while(currentnode != nullptr)
    {
        AddHead(temp, CreateNode(currentnode->value));
        currentnode = currentnode->next;
    }
    ClearStack(s);
    s.head = temp.head;
}

void RemoveAdjecentDuplicates(STACK &stk,const string &s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(stk.head == nullptr)
        {
            AddHead(stk, CreateNode(s[i]));
        }

        else if(s[i] == stk.head->value)
        {
            PopHead(stk);
        }

        else
            AddHead(stk, CreateNode(s[i]));
    }
    Reversall_Stack(stk);
}

void PrintStack(const STACK &s)
{
    if(Isempty(s))
    {
        return;
    }

    NODE* currentnode = s.head;
    while(currentnode != nullptr)
    {
        cout << currentnode->value;
        currentnode = currentnode->next;
    }
}
int main()
{
    string s;
    cin >> s;
    STACK kq;
    RemoveAdjecentDuplicates(kq, s);
    PrintStack(kq);
    ClearStack(kq);
    return 0;
}

