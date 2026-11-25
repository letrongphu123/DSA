/*
Remove Outermost Parentheses
Leo is studying formal language theory and encounters an interesting property of valid parentheses strings. He learns that any valid parentheses string can be uniquely decomposed into "primitive" parts — pieces that cannot be split further. His task is to clean up strings by stripping the outermost layer from each primitive piece.

Problem
A valid parentheses string (VPS) is defined recursively as:

The empty string ""
"(" + A + ")" where A is a valid parentheses string
A + B where A and B are both valid parentheses strings
A VPS s is called primitive if it is non-empty and cannot be split into two non-empty valid parentheses strings.

Given a valid parentheses string s, find its primitive decomposition s = P1 + P2 + ... + Pk, then remove the outermost parentheses of each primitive part Pi. Return the resulting concatenated string.

Input Format
A single line containing the valid parentheses string s.

Output Format
A single line containing the resulting string after removing the outermost parentheses of every primitive in the decomposition of s.

If the result is empty, print an empty line.

Constraints
1 ≤ |s| ≤ 10^5
s consists of ( and ) only
s is a valid parentheses string
|s| is always even (every ( is matched)
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

char top(STACK &s)
{
    return s.value.back();
}

bool Isempty(STACK &s)
{
    return s.value.empty();
}

void Print(const vector<char> a)
{
    for(auto x : a)
        cout << x;
}
void RemoveOutermostParentheses(string s)
{
    if(s.size() == 0)
        return;

    STACK stk;
    vector<char> ans;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '(')
        {
            if(!Isempty(stk))
                ans.push_back(s[i]);
            push(stk, s[i]);
        }

        else
        {
            pop(stk);
            if(!Isempty(stk))
                ans.push_back(s[i]);
        }
    }

Print(ans);
}

int main()
{
    string s;
    cin >> s;
    RemoveOutermostParentheses(s);
    return 0;
}