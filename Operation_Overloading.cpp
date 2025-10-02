// Trong C++ ta có thể nạp chồng toán tử để có thể thực hiện các toán tử đối với toán hạng là 
// các đối tượng trong một lớp ( thay vì chỉ sử dụng được toán tử đối với các biến đơn thuần )


// Mối liên hệ giữa hàm tạo , hàm hủy - cấp phát động và giải phóng vùng nhớ 
// -> Khi cấp phát động -> hàm tạo được gọi 
// -> Khi giải phóng vùng nhớ -> hàm hủy được gọi
// -> Thông thường hàm tạo cũng thường dùng để cấp phát động giá trị ban đầu 
// -> Còn hàm hủy gần như chỉ dùng để giải phóng vùng nhớ 


// Operation Overloading 
// some basic syntax 
// 1. istream& operator >> (istream &in, SinhVien a) {... return in;}
// 2. ostream& operator << (ostream &out, SinhVien a) {... return out;}
// Remember that with each operator -> the parameter is also fixed 
// For ex: operator + require exactly 2 parameter ( a+b -> need just a and b to execute )

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class SinhVien{
    private:
        string Name;
        int MSV;
        float GPA;
    public:
        SinhVien(){};
        friend istream& operator >> (istream &in, SinhVien &S);
        friend ostream& operator << (ostream &out, SinhVien S);
};

istream& operator >> (istream &in, SinhVien &S)
{
    cout << "Nhap ho ten sinh vien: ";
    getline(in, S.Name);
    cout << "Nhap MSV: ";
    in >> S.MSV;
    cout << "Nhap GPA: ";
    in >> S.GPA;
    cin.ignore();
    return in;
}
ostream& operator << (ostream &out, SinhVien S)
{
    out << "Ten sinh vien la: " << S.Name << endl;
    out << "MSV: " << S.MSV << endl;
    out << "GPA: " << S.GPA << endl;
    return out;

}
int main()
{
    SinhVien S;
    cin >> S;
    cout << S; 
}
