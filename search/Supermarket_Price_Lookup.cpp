#include <iostream>
#include <vector>

using namespace std;

void NhapMangVector(vector<pair<int,int>> &a, int n)
{
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
}

int BinarySearch(const vector<pair<int, int>> &a, int n, int x)
{
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(x == a[mid].first)
            return mid;
        if(x < a[mid].first)
            right = mid - 1;
        else 
            left = mid + 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n;
    vector<pair<int, int>> a(n);
    NhapMangVector(a, n);
    cin >> x;
    int kq = BinarySearch(a, n, x);
    if(kq != -1)
        cout << a[kq].second;
    else
        cout << "Not Found";
    return 0;
}

