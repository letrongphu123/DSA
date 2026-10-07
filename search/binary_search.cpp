#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Binary_Search(int a[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(a[mid] == x)
            return mid;   
        //neu x co quan he < voi voi mid thi tim ben trai cua mid
        if(x < a[mid])
        {
        right = mid - 1;
        }
        //neu x khong co quan he < voi mid thi tim ben phai
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int Binary_Search(const vector<string> &a, int n, string x)
{
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(a[mid] == x)
        {
            return mid + 1;
            break; 
        }  
        //neu x co quan he < voi voi mid thi tim ben trai cua mid
        if(x < a[mid])
        {
        right = mid - 1;
        }
        //neu x khong co quan he < voi mid thi tim ben phai
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

void NhapMangString(vector<string> &a, int n)
{
    cin.ignore();
    for(int i = 0; i < n; i++)
        cin >> a[i];
}
// int main()
// {
//     int a[] = {5,9,1,2,8,1,66,9,4,9,1,3,54,6,64,6,4,3};
//     int n = 18;
//     sort(a, a + n);
//     cout << "Danh sach sau khi sap xep:" << endl;
//     for(auto i : a)
//         cout << i << " ";
//     cout << endl;
//     cout << Binary_Search(a, n, 1);
//     return 0;
// }

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    NhapMangString(a, n);
    string x;
    cin >> x;
    cout << Binary_Search(a, n, x);
    return 0;
}



