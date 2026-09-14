#include<iostream>

using namespace std;

class HoaDon{
public:
    HoaDon() : soLuong(1), giaCa(10) {}
    HoaDon(int sl, double gc) : soLuong(sl), giaCa(gc) {}

    double tongTien() {
        return this->soLuong * this->giaCa;
    }

    void setGiaCa(double gc) {
        this->giaCa = gc;
    }

    void inHoaDon() {
        cout << "So luong: " << this->soLuong << endl;
        cout << "Gia ca : " << this->giaCa << endl;
        cout << "So tien phai thanh toan: " << this->tongTien() << endl;
    }

private:
    int soLuong;
    double giaCa;
};

class HoaDonKm : public HoaDon{
public:
    HoaDonKm() : HoaDon(), giamGia(2) {}
    HoaDonKm(int sl, double gc, double gg) : HoaDon(sl, gc), giamGia(gg) {}

    double thanhToan() {
        return this->tongTien() - this->giamGia;
    }

    void inHoaDon() {
        HoaDon::inHoaDon();
        cout << "Giam gia: " << this->giamGia << endl;
        cout << "Hoa don thanh toan: " << this->thanhToan();
    }

private:
    double giamGia;
};

int main()
{
    HoaDon hd1(18, 38);
    hd1.inHoaDon(); cout << endl;
    HoaDonKm km1(3, 10, 5), km2;
    km1.inHoaDon(); cout << endl;
    km2.inHoaDon();
    return 0;
}
