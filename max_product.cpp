#include <iostream>

using namespace std;

//Thuat toan tim tich lon nhat vet can
long long FindMaxProduct(int a[], int n)
{
    long long Max_Product = 1;
    for(int i = 0; i < n; i++)
    {
        long long max_term = 1;
        for(int j = i; j < n; j++)
        {
            max_term *= a[j];
            if(max_term > Max_Product)
                Max_Product = max_term;
        }
    }
    return Max_Product;
}

int main()
{
    int n;
    cin >> n;
    int a[] = {4,6,2,7,-6,1,-7,-6,4,6,9};
    cout << FindMaxProduct(a, n);
    return 0;
}


//
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Biến toàn cục để lưu kết quả tốt nhất tìm được
long long tichLonNhat = LLONG_MIN;
vector<int> tapConTotNhat;

// Hàm đệ quy duyệt qua tất cả các tập con
void timTapCon(int viTri, const vector<int>& mangGoc, vector<int>& tapConHienTai, long long tichHienTai, bool daCoPhanTu) {
    // Điều kiện dừng: Khi đã xét hết tất cả phần tử trong mảng gốc
    if (viTri == mangGoc.size()) {
        // Chỉ cập nhật nếu tập con có ít nhất 1 phần tử và tích lớn hơn tích lớn nhất cũ
        if (daCoPhanTu && tichHienTai > tichLonNhat) {
            tichLonNhat = tichHienTai;
            tapConTotNhat = tapConHienTai;
        }
        return;
    }

    // Trường hợp 1: KHÔNG chọn phần tử mangGoc[viTri] vào tập con
    timTapCon(viTri + 1, mangGoc, tapConHienTai, tichHienTai, daCoPhanTu);

    // Trường hợp 2: CHỌN phần tử mangGoc[viTri] vào tập con
    tapConHienTai.push_back(mangGoc[viTri]);
    
    // Nếu đây là phần tử đầu tiên được chọn, tích sẽ bằng chính nó. Nếu không, nhân thêm vào tích cũ.
    long long tichMoi = daCoPhanTu ? tichHienTai * mangGoc[viTri] : mangGoc[viTri];
    
    timTapCon(viTri + 1, mangGoc, tapConHienTai, tichMoi, true);
    
    // Quay lui: Xóa phần tử vừa thêm để thử các trường hợp khác
    tapConHienTai.pop_back();
}

int main() {
    // Mảng dữ liệu đầu vào thử nghiệm
    vector<int> mangGoc = {2, -1, -3, 4};
    vector<int> tapConHienTai;
    
    // Bắt đầu duyệt từ vị trí số 0, tích ban đầu bằng 1, chưa có phần tử nào được chọn (false)
    timTapCon(0, mangGoc, tapConHienTai, 1, false);
    
    // In kết quả ra màn hình
    cout << "Tich lon nhat la: " << tichLonNhat << endl;
    cout << "Cac phan tu trong tap con do la: ";
    for (int x : tapConTotNhat) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}
