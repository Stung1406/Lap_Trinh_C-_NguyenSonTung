#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PhuongTien {
protected:
    string ten;

public:
    PhuongTien(string t) {
        ten = t;
    }

    virtual double mucTieuThuNhienLieu() = 0; //hàm ảo thuần túy
    // từng phương tiện thì sẽ có cách tính mức tiêu thụ nhiên liệu khác nhau,
    // nên hàm này sẽ được triển khai ở các lớp con
    //bản chất là chỉ để cho lớp con để kế thừa và triển khai
    virtual void hienThi() {
        cout << "Ten phuong tien: " << ten << endl;
    }
};

class Oto : public PhuongTien {
private:
    int dungTichDongCo;

public:
    Oto(string t, int dt) : PhuongTien(t) {
        dungTichDongCo = dt;
    }

    double mucTieuThuNhienLieu() {
        return dungTichDongCo * 8;
    }

    void hienThi() {
        PhuongTien::hienThi();
        cout << "Dung tich dong co: " << dungTichDongCo << endl;
        cout << "Muc tieu thu nhien lieu: "<< mucTieuThuNhienLieu() << " lit/100km" << endl;
    }
};

class XeMay : public PhuongTien {
private:
    int dungTichXiLanh;

public:
    XeMay(string t, int dt) : PhuongTien(t) {
        dungTichXiLanh = dt;
    }

    double mucTieuThuNhienLieu() {
        return dungTichXiLanh / 200.0;
    }

    void hienThi() {
        PhuongTien::hienThi();
        cout << "Dung tich xi lanh: " << dungTichXiLanh << endl;
        cout << "Muc tieu thu nhien lieu: "<< mucTieuThuNhienLieu() << " lit/100km" << endl;
    }
};

int main() {
    vector<PhuongTien*> ds = {
        new Oto("Toyota", 2),
        new Oto("Honda", 3),
        new XeMay("Honda Wave", 110),
        new XeMay("Yamaha", 150)
    };

    double tong = 0;

    for (int i = 0; i < ds.size(); i++) {
        ds[i]->hienThi();
        cout << endl;
        tong += ds[i]->mucTieuThuNhienLieu();
    }

    cout << "Muc tieu thu nhien lieu trung binh: "<< tong / ds.size() << " lit/100km" << endl;

    return 0;
}