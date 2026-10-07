#include <iostream>

#define MAX 10000

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin, x.Hodem);
    getline(cin, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
    cin.ignore();
}

int BSearch(Hocsinh [], int, Hocsinh);

int main()
{
    Hocsinh ds[MAX], hs;
    int n;

    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        ds[i] = hs;
    }
    InputElement(hs);
    cout << BSearch(ds, n, hs) << endl;
    return 0;
}

bool DungTruoc(const Hocsinh & A, const Hocsinh &B)
{
    if(A.Ten != B.Ten)
        return A.Ten < B.Ten;
    if(A.Hodem != B.Hodem)
        return A.Hodem < B.Hodem;
    if(A.Nam != B.Nam)
        return A.Nam > B.Nam;
    if(A.Thang != B.Thang)
        return A.Thang > B.Thang;
    return A.Ngay > B.Ngay;
}

int BSearch(Hocsinh a[], int n, Hocsinh A)
{
    int count = 0;
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        count++;
        int mid = left + (right - left) / 2;
        if(a[mid].Ten == A.Ten && a[mid].Hodem == A.Hodem && a[mid].Nam == A.Nam && a[mid].Thang == A.Thang && a[mid].Ngay == A.Ngay)
            return count;   
        //neu x co quan he < voi voi mid thi tim ben trai cua mid
        if(DungTruoc(A, a[mid]))
        {
        right = mid - 1;
        }
        //neu x khong co quan he < voi mid thi tim ben phai
        else
        {
            left = mid + 1;
        }
    }
    return 0;
}