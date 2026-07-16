#include <iostream>
#include <string>

using namespace std;

// =======================
// L?P CO S? (TR?U TU?NG)
// =======================
class SanPham {
protected:
    string tenSp, nhaSx;

public:
    SanPham() : tenSp(""), nhaSx("") {}
    SanPham(string t, string n) : tenSp(t), nhaSx(n) {}

    virtual ~SanPham() {}   

    virtual void nhap() {
        cout << "Nhap ten san pham: ";
        getline(cin, tenSp);
        cout << "Nhap nha san xuat: ";
        getline(cin, nhaSx);
    }

    virtual void hienThi() {
        cout << "Ten san pham: " << tenSp << endl;
        cout << "Nha san xuat: " << nhaSx << endl;
    }

    virtual double thanhToan() = 0; // h�m thu?n ?o
};


class SPBanLe : public SanPham {
private:
    double giaBanLe;
    int soLuong;

    bool checkSL() {
        return soLuong < 10;   // b�n l? >= 10
    }

public:
    SPBanLe() : SanPham(), giaBanLe(0), soLuong(10) {}
    SPBanLe(string t, string n, double g, int s)
        : SanPham(t, n), giaBanLe(g), soLuong(s) {}

    void nhap() override {
        SanPham::nhap();
        cout << "Nhap gia ban le: ";
        cin >> giaBanLe;

        do {
            cout << "Nhap so luong (>=10): ";
            cin >> soLuong;
        } while (checkSL());

        cin.ignore();
    }

    void hienThi() override {
        SanPham::hienThi();
        cout << "Gia ban le: " << giaBanLe << endl;
        cout << "So luong: " << soLuong << endl;
        cout << "Thanh tien: " << thanhToan() << endl;
    }

    double thanhToan() override {
        return giaBanLe * soLuong;
    }
};


class SPBanSi : public SanPham {
private:
    double giaSi;
    int soLuong;

    bool checkSL() {
        return soLuong < 100;   // b�n s? >= 100
    }

public:
    SPBanSi() : SanPham(), giaSi(0), soLuong(100) {}
    SPBanSi(string t, string n, double g, int s)
        : SanPham(t, n), giaSi(g), soLuong(s) {}

    void nhap() override {
        SanPham::nhap();
        cout << "Nhap gia ban si: ";
        cin >> giaSi;

        do {
            cout << "Nhap so luong (>=100): ";
            cin >> soLuong;
        } while (checkSL());

        cin.ignore();
    }

    void hienThi() override {
        SanPham::hienThi();
        cout << "Gia ban si: " << giaSi << endl;
        cout << "So luong: " << soLuong << endl;
        cout << "Thanh tien: " << thanhToan() << endl;
    }

    double thanhToan() override {
        return giaSi * soLuong;
    }
};

int main() {
    int n;
    cout << "Nhap so luong san pham: ";
    cin >> n;
    cin.ignore();

    SanPham* ds[100];
    int m = 0;

    for (int i = 0; i < n; i++) {
        int choice;
        cout << "\nChon loai san pham (1: Ban le | 2: Ban si | 3: Thoat): ";
        cin >> choice;
        cin.ignore();

        if (choice == 3) break;

        if (choice == 1)
            ds[m] = new SPBanLe;
        else if (choice == 2)
            ds[m] = new SPBanSi;
        else {
            cout << "Lua chon khong hop le!\n";
            i--;
            continue;
        }

        ds[m]->nhap();
        m++;
    }

    cout << "\n===== DANH SACH SAN PHAM =====\n";
    for (int i = 0; i < m; i++) {
        cout << "\n--- San pham " << i + 1 << " ---\n";
        ds[i]->hienThi();
    }

    for (int i = 0; i < m; i++) {
        delete ds[i];
    }

    return 0;
}

