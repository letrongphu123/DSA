/*
Every Saturday, Coach Minh keeps a running scorecard for the school baseball team. During each round, the scorekeeper calls out one of four things: a number (a new valid score), a + (bonus round — add the last two scores), a D (double the last score), or a C (oops — cancel the last score). At the end of the game, Coach Minh needs the total of all valid scores on the board.

Problem
You are given a list of N operations for a baseball game. Each operation is one of the following:

An integer (possibly negative): Record a new score equal to this integer.
+: Record a score equal to the sum of the previous two scores. (Guaranteed there are at least two valid scores on record.)
D: Record a score equal to double the previous score. (Guaranteed there is at least one valid score on record.)
C: Invalidate the previous score, removing it from the record. (Guaranteed there is at least one valid score on record.)
After all operations, return the sum of all recorded (valid) scores.

Input Format
Line 1: A single integer N — the number of operations.
Lines 2 to N+1: Each line contains one operation (an integer or one of +, D, C).
Output Format
Print a single integer — the total sum of all valid scores after all operations.

Constraints
1 ≤ N ≤ 10^5
−10^6 ≤ score ≤ 10^6 (for integer operations)
+ is always called when there are at least 2 scores on record.
D and C are always called when there is at least 1 score on record.
The answer fits in a 64-bit integer.
*/

#include <iostream>
#include <vector>

using namespace std;

struct STACK{
    vector<long long> value;
};

void push(STACK &s, long long x)
{
    s.value.push_back(x);
}

void pop(STACK &s)
{
    s.value.pop_back();
}

long long top(const STACK &s)
{
    return s.value.back();
}

bool Isempty(const STACK &s)
{
    return s.value.empty();
}

long long BaseballGames(STACK &s, vector<string> &a)
{
    if(a.size() == 0)
        return 0;

    long long sum = 0;
    int n = a.size();
    for(int i = 0; i < n; i++)
    {
        if(a[i] == "D")
        {
            push(s, 2 * top(s));
            sum += top(s);
        }

        else if(a[i] == "C")
        {
            sum -= top(s);
            pop(s);
        }

        else if(a[i] == "+")
        {
            long long curTop = top(s);
            pop(s);
            long long nextTop = top(s);

            push(s, curTop);
            push(s, curTop + nextTop);
            sum += top(s);
        }

        else
        {
            push(s, stoll(a[i]));
            sum += top(s);
        }
    }
    return sum;
}

void Nhap(vector<string> &v, int n)
{
    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    Nhap(v, n);
    STACK s;
    cout << BaseballGames(s, v);
    return 0;
}