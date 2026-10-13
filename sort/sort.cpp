#include <iostream>
#include <vector>

using namespace std;

void NhapMangVector(vector<int> &a, int n)
{
    for(int i = 0; i < n; i++)
        {
            cin >> a[i];
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


//Cach 1:
//ham sap xep va gop mang (Merge sort)
void Merge(vector<int> &origin, const vector<int> &left, const vector<int> &right)
{
    auto k = origin.begin();
    auto i = left.begin();
    auto j = right.begin();
    for(i, j; i != left.end() && j != right.end();)
    {
        if(*i <= *j)
        {
            *k = *i;
            i++;
            k++;
        }

        else
        {
            *k = *j;
            j++;
            k++;
        }
    }

    //dua cac phan tu con lai cua mang left vao 
    while(i != left.end())
    {
        *k = *i;
        i++;
        k++;
    }

    //dua cac phan tu con lai cua mang right vao
    while(j != right.end())
    {
        *k = *j;
        j++;
        k++;
    }
}

//Merge sort (sắp xếp trộn)
void MergeSort(vector<int> &a, int n)
{
    if(n <= 1)
        return;

    int mid = n / 2;
    vector<int> l;
    vector<int> r;
    // tach mang thanh hai mang con
    int index = 0;

    // gan cac phan tu cho mang ben trai
    for(int i = 0; i < mid; i++)
    {
        l.push_back(a[index]);
        index++;
    }

    //gan cac phan tu cho mang ben phai
    for(int i = 0; i < n - mid; i++)
    {
        r.push_back(a[index]);
        index++;
    }

    //goi de quy chia doi mang
    MergeSort(l, mid);
    MergeSort(r, n - mid);

    //goi ham sap xep va gop mang
    Merge(a, l, r);
}


//Cach 2:
void Merge2(vector<int> &a, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    vector<int> temp;

    while(i <= mid && j <= right)
    {
        if(a[i] <= a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }
    }

    while(i <= mid)
    {
        temp.push_back(a[i]);
        i++;
    }

    while(j <= right)
    {
        temp.push_back(a[j]);
        j++;
    }

    //ghi de cac phan tu duoc sap xep vao lai mang goc
    for(int k = 0; k < temp.size(); k++)
    {
        a[left + k] = temp[k];
    }
}

void MergeSort2(vector<int> &a, int left, int right)
{
    if(left >= right)
        return;

    int mid = (left + right) / 2;

    //goi de quy tach mang
    MergeSort2(a, left, mid); //mang ben trai
    MergeSort2(a, mid + 1, right); //mang ben phai

    //goi ham merge2
    Merge2(a, left, mid, right);

    //in ra cac phan tu sau khi thuc hien merge
    for(int i = 0; i < a.size(); i++)
    {
        if(i == left)
        {
            cout << "[" << " " << a[i] << " ";
        }

        else if(i == right)
        {
            cout << a[i] << " " << "]" << " ";
        }

        else
        {
            cout << a[i] << " ";
        }
    }
    cout << "\n";
}

//Cach 3 (khong dung de quy)
//Ham merge (ascending)
void MergeASC(vector<int> &a, vector<int> left, int n, vector<int> right, int m, int k)
{
    int count = 0;
    int i = 0;
    int j = 0;
    int dieukien = k;
    while(dieukien <= max(n,m))
    {
        while((i < dieukien && i < n) && (j < dieukien && j < m))
        {
            if(left[i] < right[j])
            {
                a[count] = left[i];
                i++;
                count++;
            }

            else 
            {
                a[count] = right[j];
                j++;
                count++;
            }
        }

            while(i < dieukien && i < n)
            {
                a[count] = left[i];
                i++;
                count++;
            }

            while(j < dieukien && j < m)
            {
                a[count] = right[j];
                j++;
                count++;
            }
    
        dieukien += k;
    }
}

// Ham Merge (Descending)
void MergeDES(vector<int> &a, const vector<int> left, int n, const vector<int> right, int m, int k)
{
    int i = 0; 
    int j = 0;
    int count = 0;
    int dieukien = k;
    while(dieukien <= max(n, m))
    {
        while((i < dieukien && i < n) && (j < dieukien && j < m))
        {
            if(left[i] > right[j])
            {
                a[count] = left[i];
                i++;
                count++;
            }

            else
            {
                a[count] = right[j];
                j++;
                count++;
            }
        }

        while(i < dieukien && i < n)
        {
            a[count] = left[i];
            i++;
            count++; 
        }

        while(j < dieukien && j < m)
        {
            a[count] = right[j];
            j++;
            count++;
        }
        dieukien += k;
    }
}

//Ham MergeSort
void MergeSort3(vector<int> &a, int n, int k)
{
    int mid = (n / 2) + 1;
    cout << "Sap xep:\n";
    while(k < n)
    {
        cout << "k = " << k << "\n"; 
        cout << "Mang A (truoc khi chia): ";
        XuatMangVector(a, n);
        cout << "\n";
        // Tach thanh hai mang con
        vector<int> l;
        vector<int> r;
        
        for(int i = 0; i < n; i += 2 * k)
        {
            //gan cho mang ben trai
            for(int step = 0; step < k && (i + step) < n; step++)
                l.push_back(a[i + step]);

            //gan cho mang ben phai
            for(int step = 0; step < k && (i + k + step) < n; step++)
                r.push_back(a[i + k + step]);
        }

        cout << "Mang B: ";
        XuatMangVector(l, l.size());
        cout << "\n";
        cout << "Mang C: ";
        XuatMangVector(r, r.size());
        cout << "\n";

        //goi ham merge
        MergeDES(a, l, l.size(), r, r.size(), k);
        cout << "Mang A (sau khi gop): ";
        XuatMangVector(a, n);
        cout << "\n \n";
        k *= 2;
    }
}

int main()
{
    int n;
    cin >> n;
    //vector<int> a{8,3,4,2,1,9,5,7,6,7,2,4,1};
    vector<int> a(n);
    NhapMangVector(a, n);
    MergeSort2(a, 0, n - 1);
    return 0;
}