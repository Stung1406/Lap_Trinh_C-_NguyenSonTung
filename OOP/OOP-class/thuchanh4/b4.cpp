#include <iostream>
#include <string>

using namespace std;

class Nguoi {
private:
    string hoten;

public:
    virtual ~Nguoi() {}

    virtual void nhap();
    virtual void xuat();
    virtual bool thuong() = 0;

    friend ostream& operator<<(ostream& outputStream, Nguoi& n);
    friend istream& operator>>(istream& inputStream, Nguoi& n);
};

class SinhVien : public Nguoi {
private:
    double dtb;

public:
    void nhap();
    void xuat();
    bool thuong();
};

class GiangVien : public Nguoi {
private:
    int sobaibao;

public:
    void nhap();
    void xuat();
    bool thuong();
};

class NhanVien : public Nguoi {
private:
    int songaynghi;

public:
    void nhap();
    void xuat();
    bool thuong();
};

//====================== MAIN ======================

int main() {
    int n;

    cout << "Nhap so luong nguoi: ";
    cin >> n;

    // Cấp phát động mảng con trỏ
    Nguoi **ds = new Nguoi*[n];

    for (int i = 0; i < n; i++) {
        int chon;

        cout << "\n===== Nguoi thu " << i + 1 << " =====\n";
        cout << "1. Giang vien\n";
        cout << "2. Sinh vien\n";
        cout << "3. Nhan vien\n";
        cout << "Chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
        case 1:
            ds[i] = new GiangVien();
            break;
        case 2:
            ds[i] = new SinhVien();
            break;
        case 3:
            ds[i] = new NhanVien();
            break;
        default:
            cout << "Lua chon khong hop le! Mac dinh tao SinhVien.\n";
            ds[i] = new SinhVien();
        }

        ds[i]->nhap();
    }

    cout << "\n========== DANH SACH DUOC KHEN THUONG ==========\n";

    for (int i = 0; i < n; i++) {
        if (ds[i]->thuong())
            ds[i]->xuat();
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++)
        delete ds[i];

    delete[] ds;

    return 0;
}

//====================== NGUOI ======================

void Nguoi::nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
}

void Nguoi::xuat() {
    cout << "Ho ten: " << hoten << endl;
}

ostream& operator<<(ostream& outputStream, Nguoi& n) {
    n.xuat();
    return outputStream;
}

istream& operator>>(istream& inputStream, Nguoi& n) {
    n.nhap();
    return inputStream;
}

//====================== SINH VIEN ======================

void SinhVien::nhap() {
    cout << "\nNhap thong tin Sinh Vien\n";
    Nguoi::nhap();
    cout << "Nhap diem trung binh: ";
    cin >> dtb;
    cin.ignore();
}

void SinhVien::xuat() {
    cout << "\n*** Sinh Vien duoc khen thuong ***\n";
    Nguoi::xuat();
    cout << "Diem TB: " << dtb << endl;
}

bool SinhVien::thuong() {
    return dtb > 8;
}

//====================== GIANG VIEN ======================

void GiangVien::nhap() {
    cout << "\nNhap thong tin Giang Vien\n";
    Nguoi::nhap();
    cout << "Nhap so bai bao: ";
    cin >> sobaibao;
    cin.ignore();
}

void GiangVien::xuat() {
    cout << "\n*** Giang Vien duoc khen thuong ***\n";
    Nguoi::xuat();
    cout << "So bai bao: " << sobaibao << endl;
}

bool GiangVien::thuong() {
    return sobaibao > 3;
}

//====================== NHAN VIEN ======================

void NhanVien::nhap() {
    cout << "\nNhap thong tin Nhan Vien\n";
    Nguoi::nhap();
    cout << "Nhap so ngay nghi: ";
    cin >> songaynghi;
    cin.ignore();
}

void NhanVien::xuat() {
    cout << "\n*** Nhan Vien duoc khen thuong ***\n";
    Nguoi::xuat();
    cout << "So ngay nghi: " << songaynghi << endl;
}

bool NhanVien::thuong() {
    return songaynghi < 5;
}