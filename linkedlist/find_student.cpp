/*Dùng danh sách liên kết thay cho mảng, vector, hãy viết chương trình chọn một danh sách học sinh có điểm trung bình các môn lớn hơn hoặc bằng 9.0 và in ra danh sách đó theo thứ tự được nhập vào. Trong đó, điểm trung bình bằng tổng của 6 điểm gồm; Toan, Van, Ly, Hoa, Anh, Sinh; chia cho 6.
Đầu vào:
- Số nguyên dương n, cho biết có n thông tin học sinh.
- n khối kế tiếp, mỗi khối là toàn bộ thông tin của một học sinh, được đọc bằng hàm InputElement(Hocsinh &) đã được cài đặt sẵn.
Đầu ra: Dùng hàm Output(List) đã được viết sẵn.
Lưu ý:
1) Cần cài đặt các hàm phù hợp để sử dụng kiểu DSLK đơn List.
2) Cần cài đặt hàm main để thực hiện chương trình.
3) Đầu vào (hàm InputElement) và đầu ra (hàm Output) đã được xử lý sẵn và phù hợp với định dạng nhập/xuất.

Input	                                    Output
3                                           
Le Phu
Quy
1 22 10 2006 10 10 9.5 6.5 7.5 8
Bui Minh
Quan
1 13 9 2006 10 9.5 8 10 10 9
Bui Duy
Quy
1 29 9 2005 10 8.5 10 8 10 0.5	           Bui Minh Quan 1 13/9/2006 10 9.5 8 10 10 9
                                            //Chỉ có Bui Minh Quan có điểm trung bình là 9.42 lớn hơn 9.0 nên được chọn */

#include <iostream>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

struct Node {
    Hocsinh data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

void Output(List ds) {
    Node *p = ds.head;
    if (p == NULL) {
        cout << "EMPTY";
    }
    while(p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

void CreateList(List &l)
{
    l.head = l.tail = nullptr;
}

Node* CreateNode(Hocsinh A)
{
    Node *p = new Node;
    if(p == nullptr)
        exit(0);
    p->data = A;
    p->next = nullptr;
    return p;
}

void AddTail(List &l, Hocsinh A)
{
    Node *p = CreateNode(A);
    if(l.head == nullptr)
        l.head = l.tail = p;
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void ClearList(List &l)
{
    Node *currentNode = l.head;
    while(currentNode != nullptr)
    {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
    l.head = l.tail = nullptr;
}

//ham tim hoc sinh co diem trung binh tren 9.0
void Find_Student(const List &l, List &kq)
{
    Node *currentNode = l.head;
    while(currentNode != nullptr)
    {
        double DTB;
        DTB = (currentNode->data.Anh + currentNode->data.Hoa +
                currentNode->data.Ly + currentNode->data.Sinh +
                currentNode->data.Toan + currentNode->data.Van) / 6;
        if(DTB >= 9.0)
        {
            AddTail(kq, currentNode->data);
        }
        currentNode = currentNode->next;
    }
}

int main()
{
    int n;
    cin >> n;
    List l;
    List kq;
    CreateList(l);
    CreateList(kq);
    for(int i = 0; i < n; i++)
    {
        Hocsinh temp;
        InputElement(temp);
        AddTail(l, temp);
    }
    Find_Student(l, kq);
    Output(kq);
    ClearList(l);
    ClearList(kq);
    return 0;
}


                                           
