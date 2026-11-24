/*
Last Stone Weight
In the ancient Stone Arena, warriors compete by smashing stones together. Each round, the two heaviest stones are chosen and smashed. If they are equal, both are destroyed. If not, the smaller one is destroyed and the larger one is reduced by the weight of the smaller. The game ends when at most one stone remains.

Problem
You are given n stones, each with a positive integer weight. Each round, pick the two heaviest stones (call them x and y where x ≤ y):

If x == y, both stones are destroyed.
If x != y, stone of weight x is destroyed and the stone of weight y becomes y - x.
Repeat until at most one stone remains. Output the weight of the last stone, or 0 if no stones remain.

Input Format
Line 1: integer n — number of stones
Line 2: n space-separated integers — the weight of each stone
Output Format
A single integer: the weight of the last remaining stone, or 0 if none remain.
Constraints
1 ≤ n ≤ 10^5
1 ≤ stones[i] ≤ 10^6
Sample Test Cases
Input	Output	Explanation
1
7	7	Only one stone, it remains as-is.
2
5 5	0	Both equal, both destroyed.
5
2 7 4 1 8	0	Smash 8,7→1; heap [4,2,1,1]. Smash 4,2→2; heap [2,1,1]. Smash 2,1→1; heap [1,1]. Smash 1,1→both gone.
3
3 3 3	3	Smash 3,3→0; one 3 left.
4
10 4 2 10	2	Smash 10,10→0; smash 4,2→2; result 2.
*/

#include <iostream>
#include <queue>

using namespace std;

int FindLastStoneWeight(priority_queue<int> &q)
{
    if(q.size() == 0)
        return -1;

    while(q.size() > 1)
    {
        int curTop = q.top();
        q.pop();
        int nextTop = q.top();
        q.pop();
        if(curTop != nextTop)
            q.push(curTop - nextTop);
    }

    if(q.size() == 0)
        return 0;
        
    return q.top();
}

void NhapPriorityQueue(priority_queue<int> &q, int n)
{
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        q.push(temp);
    }
}

int main()
{
    int n;
    cin >> n;
    priority_queue<int> q;
    NhapPriorityQueue(q, n);
    cout << FindLastStoneWeight(q);
    return 0;
}
