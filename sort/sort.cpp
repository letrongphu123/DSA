#include <iostream>
#include <vector>

using namespace std;

void NhapMangVector(vector<int> &a, int n)
{
    for(int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            a.push_back(value);
        }
}

void XuatMangVector(vector<int> a, int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}

//Sap xep chon
void SelectionSort(vector<int> &a, int n)
{
    for(int i = 0; i < n; i++)
    {
        int min_pos = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[min_pos])
                min_pos = j;        //Tim vi tri min trong doan hien tai
        }

        if(a[min_pos] < a[i])
        {
            swap(a[min_pos], a[i]); //swap neu gia tri min nho hon gia tri hien tai
            XuatMangVector(a, n);
            cout << endl;
        }
    }
}

//Sap xep noi bot
void BubbleSort(vector<int> &a, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                XuatMangVector(a, n);
                cout << endl;
            }
        }
    }
}

//Sap xep chen
void InsertionSort(vector<int> &a, int n)
{
    for(int i = 1; i < n; i++)
    {
        int temp = a[i];
        int count = i;
        for(int j = i; j > 0; j--)
        {
            if(temp < a[j - 1])
            {
                a[j] = a[j - 1];
                count--;
                XuatMangVector(a, n);
                cout << endl;
            }
        }
        a[count] = temp;
        XuatMangVector(a, n);
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    NhapMangVector(a, n);
    InsertionSort(a, n);
    return 0;
}