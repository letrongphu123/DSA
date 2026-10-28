
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY {
    int Ngay, Thang, Nam;
};
struct SINHVIEN {
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE{
    SINHVIEN key;
    NODE* pNext;
};
struct LIST{
    NODE*pHead, *pTail;
};

void NhapNgay(NGAY &a);
void XuatNgay(NGAY a);
void NhapSinhVien(SINHVIEN &a);
void XuatSinhVien(SINHVIEN a);
NODE* CreateNode(SINHVIEN x);
void CreateEmptyList(LIST &L);
void AddTail(LIST& l, NODE* p);
void XuatDS(LIST L);
void NhapDS(LIST &L, int n);
void ChenGiam(LIST &, SINHVIEN);
void ClearList(LIST &L);

int main() {
    LIST L;
    int n;
    SINHVIEN sv;

    NhapSinhVien(sv);

    cin >> n ;
    NhapDS(L, n);

    ChenGiam(L, sv);

    XuatDS(L);
    ClearList(L);
    return 0;
}
void NhapNgay(NGAY &a){
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a){
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a){
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a){
    cout << a.MASV;         cout << "\t";
    cout << a.HoTen;        cout << "\t";
    XuatNgay(a.NgaySinh);   cout << "\t";
    cout << a.GioiTinh;     cout << "\t";
    cout << a.DiemToan;     cout << "\t";
    cout << a.DiemLy;       cout << "\t";
    cout << a.DiemHoa;      cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}

NODE* CreateNode(SINHVIEN x)
{
    NODE *p = new NODE;
    if(p == nullptr)
        exit(0);
    p->key = x;
    p->pNext = nullptr;
    return p;
}

void CreateEmptyList(LIST &L)
{
    L.pHead = L.pTail = nullptr;
}

void AddTail(LIST& l, NODE* p)
{
    if(l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
        return;
    }
    l.pTail->pNext = p;
    l.pTail = p;
}

void XuatDS(LIST L)
{
    NODE *currentNode = L.pHead;
    while(currentNode != nullptr)
    {
        XuatSinhVien(currentNode->key);
        cout << "\n";
        currentNode = currentNode->pNext;
    }
}

void NhapDS(LIST &L, int n)
{
    CreateEmptyList(L);
    for(int i = 0; i < n; i++)
    {
        SINHVIEN temp;
        NhapSinhVien(temp);
        AddTail(L, CreateNode(temp));
    }
}

void ClearList(LIST &L)
{
    NODE *currentNode = L.pHead;
    while(currentNode != nullptr)
    {
        NODE *temp = currentNode;
        currentNode = currentNode->pNext;
        delete temp;
    }
    L.pHead = L.pTail = nullptr;
}

void ChenGiam(LIST &l, SINHVIEN A)
{
    NODE *newNode = CreateNode(A);
    NODE * currentNode = l.pHead;
    while(currentNode != nullptr)
    {
        if(newNode->key.MASV > currentNode->key.MASV)
        {
            //neu node moi co mssv lon hon node dau tien
            if(currentNode = l.pHead)
            {
                newNode->pNext = currentNode;
                l.pHead = newNode;
                return;
            }
        }

        //chen node moi vao cac vi tri con lai
        if(newNode->key.MASV < currentNode->key.MASV)
        {
            //neu node moi nho hon node cuoi cung
            if(currentNode == l.pTail)
            {
                currentNode->pNext = newNode;
                l.pTail = newNode;
                return;
            }

            newNode->pNext = currentNode->pNext;
            currentNode->pNext = newNode;
            return;
        }
        currentNode = currentNode->pNext;
    }
}

