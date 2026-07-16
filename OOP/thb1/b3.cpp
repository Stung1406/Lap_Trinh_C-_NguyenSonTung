/*cài đẳ lớp SoPhuc đặc tả khái niệm số phức với các thao tác:
-Hàm tạo mặc định và hàm tham số
-Xuất nhập
-Tính toán số học(cộng,trừ,nhân,chia)
Viết chương trình cho phép người dùng thực hiện nhiều lần công việc
-Nhập 2 số phức
-Chọn xem kết quả tính toán với 2 số phức đã nhập
*/
#include<iostream>
using namespace std;

class SoPhuc{
private:
    double thuc,ao;
public:
    SoPhuc(){
        thuc = 0;
        ao = 0;
    }

    SoPhuc(double t,double a){
        thuc = t;
        ao = a;
    }
    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> thuc;
        cout << "Nhap phan ao: ";
        cin >> ao;
    }
    // Hàm xuất
    void xuat() const {
        if (ao >= 0)
            cout << thuc << " + " << ao << "i";
        else
            cout << thuc << " - " << -ao << "i";
    }

    // Toán tử cộng
    SoPhuc operator+(const SoPhuc& b) const {
        return SoPhuc(thuc + b.thuc, ao + b.ao);
    }

    // Toán tử trừ
    SoPhuc operator-(const SoPhuc& b) const {
        return SoPhuc(thuc - b.thuc, ao - b.ao);
    }

    // Toán tử nhân
    SoPhuc operator*(const SoPhuc& b) const {
        return SoPhuc(thuc*b.thuc - ao*b.ao, thuc*b.ao + ao*b.thuc);
    }

    // Toán tử chia
    SoPhuc operator/(const SoPhuc& b) const {
        double mau = b.thuc*b.thuc + b.ao*b.ao;
        return SoPhuc(
            (thuc*b.thuc + ao*b.ao) / mau,
            (ao*b.thuc - thuc*b.ao) / mau
        );
    }
};
int main()
{
    SoPhuc a,b;

    cout<<"Nhap so thu nhat: "<<endl;
    a.nhap();
    cout<<"Nhap so thu hai: "<<endl;
    b.nhap();
    
    return 0;
}