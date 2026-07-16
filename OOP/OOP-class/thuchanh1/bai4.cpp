#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string ten;
    string lop;
    string maSV;
    double diemTB;

public:
    SinhVien();

    SinhVien(string t, string l, string m, double d);

    void nhap();

    void xuat();

    string diemChu();
};

int main() {
    SinhVien sv;
    sv.nhap();
    cout << "\nThong tin sinh vien:\n";
    sv.xuat();
    return 0;
}

SinhVien::SinhVien() : ten(""),lop(""),maSV(""),diemTB(0.0){}

SinhVien::SinhVien(string t, string l, string m, double d) : ten(t),lop(l),maSV(m),diemTB(d){}
    
void SinhVien::nhap() {
    cout << "Nhap ten: "; getline(cin, ten);
    cout << "Nhap lop: "; getline(cin, lop);
    cout << "Nhap ma sinh vien: "; getline(cin, maSV);
    cout << "Nhap diem trung binh: ";
    cin >> diemTB; cin.ignore();
}

void SinhVien::xuat() {
    cout << "Ten: " << ten << endl;
    cout << "Lop: " << lop << endl;
    cout << "Ma SV: " << maSV << endl;
    cout << "Diem TB: " << diemTB << endl;
    cout << "Diem chu: " << diemChu() << endl;
}

string SinhVien::diemChu() {
    if (diemTB >= 8.5 && diemTB <= 10.0) return "A";
    else if (diemTB >= 7.0) return "B";
    else if (diemTB >= 5.5) return "C";
    else if (diemTB >= 4.0) return "D";
    else return "F";
}