
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

void NhapNgay(NGAY &);
void XuatNgay(NGAY );
void NhapSinhVien(SINHVIEN &);
void XuatSinhVien(SINHVIEN );
NODE* CreateNode(SINHVIEN );
void CreateEmptyList(LIST &);
void AddTail(LIST&, NODE* );
void XuatDS(LIST );
void NhapDS(LIST &, int n);
void ClearList(LIST &l);
bool Xoa_TheoHoTen(LIST &, string);

int main() {
    LIST L;
    int n;
    string hoten;

    getline(cin, hoten);
    cin >> n ;

    NhapDS(L, n);

    Xoa_TheoHoTen(L, hoten);

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

void CreateEmptyList(LIST &l)
{
    l.pHead = l.pTail = nullptr;
}

NODE* CreateNode(SINHVIEN A)
{
    NODE *p = new NODE;
    if(p == nullptr)
        exit(0);
    p->key = A;
    p->pNext = nullptr;
    return p;
}

void AddTail(LIST &l, NODE* p)
{
    if(l.pHead == nullptr)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void XuatDS(LIST l)
{
    NODE *currentNode = l.pHead;
    while(currentNode != nullptr)
    {
        XuatSinhVien(currentNode->key);
        cout << "\n";
        currentNode = currentNode->pNext;
    }
}

bool Xoa_TheoHoTen(LIST &l, string hoten)
{
    NODE *pastNode = nullptr;
    NODE *currentNode = l.pHead;
    while(currentNode != nullptr)
    {
        if(currentNode->key.HoTen == hoten)
        {
            NODE *nextNode = currentNode->pNext;
            if(currentNode == l.pHead)
                l.pHead = l.pHead->pNext;

            else
            {
                pastNode->pNext = currentNode->pNext;
                if(currentNode == l.pTail)
                {
                    pastNode->pNext = nullptr;
                    l.pTail = pastNode;
                }
            }

            delete currentNode;
            currentNode = nextNode;
        }
        else
        {
            pastNode = currentNode;
            currentNode = currentNode->pNext;
        }
    }
    return true;
}

void ClearList(LIST &l)
{
    NODE* currentNode = l.pHead;
    while(currentNode != nullptr)
    {
        NODE *temp = currentNode;
        currentNode = currentNode->pNext;
        delete temp;
    }
    l.pHead = l.pTail = nullptr;
}

void NhapDS(LIST &l, int n)
{
    CreateEmptyList(l);
    for(int i = 0; i < n; i++)
    {
        SINHVIEN A;
        NhapSinhVien(A);
        AddTail(l, CreateNode(A));
    }
}
