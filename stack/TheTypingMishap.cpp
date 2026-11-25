/*
The Typing Mishap
Lan is writing notes on a retro text editor that doesn't show a cursor — she types blindly and uses # as the backspace key to delete the last character she typed. After a long session, she wonders: did two different drafts end up producing the same final text?

Problem
You are given two strings s and t, each typed on a text editor where the character # represents a backspace. Your task is to determine whether the two strings produce the same final text after all backspaces are applied.

Note: Pressing backspace on an empty string (or when there are no characters left) does nothing.

Input Format
Line 1: string s
Line 2: string t
Output Format
Print YES if the final texts are equal, otherwise print NO.
Constraints
1 ≤ |s|, |t| ≤ 10^5
Each string consists of lowercase English letters (a–z) and the character #.
*/

#include <iostream>
#include <vector>

using namespace std;

struct STACK{
    vector<char> value;
};

void push(STACK &s, char a)
{
    s.value.push_back(a);
}

void pop(STACK &s)
{
    s.value.pop_back();
}

char top(const STACK &s)
{
    return s.value.back();
}

bool Isempty(const STACK &s)
{
    return s.value.empty();
}

bool IsThemSame(STACK &s1, STACK &s2)
{
    if(s1.value.size() != s2.value.size())
        return false;

    while(!Isempty(s1))
    {
        if(top(s1) != top(s2))
            return false;
        pop(s1);
        pop(s2);
    }
    return true;
}
bool TheTypingMishap(const string &s1, const string &s2)
{
    STACK stk1;
    STACK stk2;
    for(int i = 0; s1[i] != '\0'; i++)
    {
        if(s1[i] != '#')
            push(stk1, s1[i]);
        else 
            if(!Isempty(stk1))
                pop(stk1);
    }

    for(int i = 0; s2[i] != '\0'; i++)
    {
        if(s2[i] != '#')
            push(stk2, s2[i]);
        else 
            if(!Isempty(stk2))
                pop(stk2);
    }

    return IsThemSame(stk1, stk2);
}

int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    if(TheTypingMishap(s1, s2))
        cout << "YES";
    else 
        cout << "NO";
    return 0;
}