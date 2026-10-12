#include <iostream>
#include <vector>

using namespace std;

class Point{
    private: 
        int x, y;
    public:
        void Nhap()
        {
            cin >> x >> y;
        }

        void Xuat() const
        {
            cout << x << " " << y;
        }

        friend bool SoSanh(const Point &A, const Point &B);
};

void NhapDSPoint(vector<Point> &a, int n)
{
    for(int i = 0; i < n; i++)
    {
        Point temp;
        temp.Nhap();
        a.push_back(temp);
    }
}

void XuatDSPoint(const vector<Point> &a, int n)
{
    for(int i = 0; i < n; i++)
    {
        a[i].Xuat();
        cout << "\n";
    }
}

bool SoSanh(const Point &A, const Point &B)
{
    if(A.x != B.x)
        return A.x < B.x; 
    return B.y < A.y;
} 

//ham sap xep
void Merge(vector<Point> &origin, const vector<Point> &left, const vector<Point> &right)
{
    auto k = origin.begin();
    auto i = left.begin();
    auto j = right.begin();
    for(i, j; i != left.end() && j != right.end();)
    {
        if(SoSanh(*i, *j))
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
void MergeSort(vector<Point> &a, int n)
{
    if(n <= 1)
        return;

    int mid = n / 2;
    vector<Point> l;
    vector<Point> r;
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

void SortPoint(vector<Point> &a, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(SoSanh(a[j], a[j + 1]))
                swap(a[j], a[j + 1]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> A;
    NhapDSPoint(A, n);
    MergeSort(A, n);
    XuatDSPoint(A, n);
    return 0;
}
