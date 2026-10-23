#include <iostream>
#include <vector>

using namespace std;

//ham binary search
int BinarySearch(const vector<pair<string, int>> &a, int n, string x)
{
    int left = 0;
    int right = n - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(x == a[mid].first)
            return mid;

        if(x < a[mid].first)
        {
            right = mid - 1;
        }

        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

//ham nhap mang vector hai chieu
void NhapMangVectorPair(vector<pair<string, int>> &a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        cin >> a[i].second;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string x;
    cin >> n;
    vector<pair<string, int>> a(n);
    NhapMangVectorPair(a, n);
    cin.ignore();
    getline(cin, x);
    int kq = BinarySearch(a, n, x);
    if(kq != -1)
        cout << a[kq].second;
    else
        cout << "Not Found";
    return 0;
}
