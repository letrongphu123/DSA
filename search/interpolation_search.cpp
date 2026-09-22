#include <iostream>
#include <algorithm>

using namespace std;

int InterpolationSearch(int a[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid = left + ((x - a[left])/(a[right] - a[left])) * (right - left);
        if(x == a[mid])
            return mid;
        
        if(x < a[mid])
            right = mid - 1;
        else 
            left = mid + 1;
    }
    return -1;
}

int main()
{
    int n = 9;
    int a[] = {4,6,8,7,1,3,5,4,9};
    sort(a, a + n);
    cout << "Danh sach sau khi sap xep" << endl;
    for(auto i : a)
        cout << i << " ";
    cout << endl;
    cout << "Vi tri cua so can tiem la: ";
    cout << InterpolationSearch(a, n, 8);
    return 0;
}