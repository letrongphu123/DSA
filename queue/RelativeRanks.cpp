/*
Relative Ranks
At the end of the championship, scores are tallied and medals are awarded. The athlete with the highest score earns the Gold Medal, second-highest gets Silver, third-highest gets Bronze, and everyone else gets their numeric rank (4th, 5th, 6th...). You need to report each athlete's reward in their original roster order.

Problem
Given n athletes with distinct scores, assign each a rank label:

Rank 1 → "Gold Medal"
Rank 2 → "Silver Medal"
Rank 3 → "Bronze Medal"
Rank 4+ → their rank number as a string (e.g., "4", "5", ...)
Output the labels in the same order as the original input (not sorted by score).

Input Format
Line 1: integer n
Line 2: n space-separated integers — scores in original athlete order (all distinct)
Output Format
A single line with n space-separated labels in original order.
Constraints
1 ≤ n ≤ 10^5
1 ≤ scores[i] ≤ 10^6
All scores are distinct
Sample Test Cases
Input	Output	Explanation
5
5 4 3 2 1	Gold Medal Silver Medal Bronze Medal 4 5	Already sorted descending; ranks match positions.
3
10 3 8	Gold Medal Bronze Medal Silver Medal	Sorted: 10(rank1), 8(rank2), 3(rank3). Original order: 10→Gold, 3→Bronze, 8→Silver.
1
100	Gold Medal	Only one athlete, gets Gold.
4
7 4 9 1	Silver Medal Bronze Medal Gold Medal 4	Sorted: 9(rank1), 7(rank2), 4(rank3), 1(rank4). Original: 7→Silver, 4→Bronze, 9→Gold, 1→"4".
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void NhapPriorityQueue(priority_queue<pair<int, int>> &q, int n)
{
    for(int i = 0; i < n; i++)
    {
        pair<int, int> temp;
        cin >> temp.first;
        temp.second = i;
        q.push(temp);
    }
}

void RelativeRanks(priority_queue<pair<int, int>> &q, vector<string> &kq)
{
    if(q.size() == 0)
        return;
    
    int n = q.size();
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            kq[q.top().second] = "Gold Medal";
        else  if(i == 1)
            kq[q.top().second] = "Silver Medal";
        else if(i == 2)
            kq[q.top().second] = "Bronze Medal";
        else 
            kq[q.top().second] = to_string(i + 1);
        q.pop();
    }
}

void Print(const vector<string> &v)
{
    int n = v.size();
    for(int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    priority_queue<pair<int, int>> q;
    NhapPriorityQueue(q, n);
    vector<string> kq(n);
    RelativeRanks(q, kq);
    Print(kq);
    return 0;
}