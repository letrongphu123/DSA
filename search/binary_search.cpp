#include <iostream>
#include <algorithm>

using namespace std;

int Binary_Search(int a[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    int mid = n / 2;
    while(left <= right)
    {
        if(a[mid] == x)
            return mid;
        
        //neu x co quan he < voi voi mid thi tim ben trai cua mid
        if(x < a[mid])
        {
        right = mid - 1;
        mid = right / 2;
        }
        //neu x khong co quan he < voi mid thi tim ben phai
        else
        {
            left = mid + 1;
            mid = (n + left) / 2;
        }
    }
    return -1;
}

int main()
{
    int a[] = {5,9,1,2,8,1,66,9,4,9,1,3,54,6,64,6,4,3};
    int n = 18;
    sort(a, a + n);
    cout << "Danh sach sau khi sap xep:" << endl;
    for(auto i : a)
        cout << i << " ";
    cout << endl;
    cout << Binary_Search(a, n, 1);
    return 0;
}