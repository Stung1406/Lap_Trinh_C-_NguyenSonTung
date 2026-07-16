#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class HocSinh {
private:
    string MaHS;
    string HotenHS;
    string Lop;
    double Diem;
public:
    void nhap();

    void hienthi();
    double getDiem();
    string getMaHS();
    string getLop();
};

void themHocSinh(vector<HocSinh> &ds) {
    HocSinh hs;
    hs.nhap();
    for (size_t i = 0; i < ds.size(); i++) {
        if (ds[i].getMaHS() == hs.getMaHS()) {
            cout << "MaHS bi trung" << endl;
            return;
        }
    }
    ds.push_back(hs);
}

void xoaHocSinh(vector<HocSinh> &ds) {
    string ma;
    cout << "Nhap MaHS can xoa: ";
    cin >> ma;
    for (vector<HocSinh>::iterator it = ds.begin(); it != ds.end(); ++it) {
        if (it->getMaHS() == ma) {
            ds.erase(it);
            cout << "Da xoa" << endl;
            return;
        }
    }
    cout << "Khong tim thay" << endl;
}

void timKiemHocSinh(vector<HocSinh> &ds) {
    string ma;
    cout << "Nhap MaHS can tim: ";
    cin >> ma;
    for (size_t i = 0; i < ds.size(); i++) {
        if (ds[i].getMaHS() == ma) {
            ds[i].hienthi();
            return;
        }
    }
    cout << "Khong tim thay" << endl;
}

void lietKeDiem(vector<HocSinh> &ds) {
    bool found = false;
    for (size_t i = 0; i < ds.size(); i++) {
        if (ds[i].getDiem() > 5.5) {
            ds[i].hienthi();
            found = true;
        }
    }
    if (!found) cout << "Khong co hoc sinh nao" << endl;
}

void lietKeTheoLop(vector<HocSinh> &ds) {
    string lop;
    cout << "Nhap Lop: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, lop);
    bool found = false;
    for (size_t i = 0; i < ds.size(); i++) {
        if (ds[i].getLop() == lop) {
            ds[i].hienthi();
            found = true;
        }
    }
    if (!found) cout << "Khong co hoc sinh nao" << endl;
}

void lietKeTatCa(vector<HocSinh> &ds) {
    if (ds.empty()) {
        cout << "Danh sach rong" << endl;
        return;
    }
    for (size_t i = 0; i < ds.size(); i++) {
        ds[i].hienthi();
    }
}

int main() {
    vector<HocSinh> ds;
    int chon;
    do {
        cout << "\n1. Them moi hoc sinh\n";
        cout << "2. Xoa hoc sinh khoi danh sach\n";
        cout << "3. Tim kiem hoc sinh theo ma\n";
        cout << "4. Liet ke danh sach hoc sinh co diem tren 5.5\n";
        cout << "5. Liet ke danh sach hoc sinh theo lop\n";
        cout << "6. Liet ke danh sach tat ca hoc sinh\n";
        cout << "7. Thoat\n";
        cout << "Ban chon: ";
        cin >> chon;
        switch (chon) {
            case 1: themHocSinh(ds); break;
            case 2: xoaHocSinh(ds); break;
            case 3: timKiemHocSinh(ds); break;
            case 4: lietKeDiem(ds); break;
            case 5: lietKeTheoLop(ds); break;
            case 6: lietKeTatCa(ds); break;
            case 7: cout << "Thoat\n"; break;
            default: cout << "Lua chon khong hop le\n";
        }
    } while (chon != 7);
    return 0;
}

void HocSinh::nhap() {
    cin.ignore();
    cout << "Nhap MaHS: "; cin >> MaHS;
    cout << "Nhap Ho ten: "; getline(cin, HotenHS);
    cout << "Nhap Lop: "; getline(cin, Lop);
    cout << "Nhap Diem: "; cin >> Diem;
    cin.ignore();
}

void HocSinh::hienthi() {
        cout << MaHS << " | " << HotenHS << " | " << Lop << " | " << Diem << endl;
}
double HocSinh::getDiem() { return Diem; }

string HocSinh::getMaHS() { return MaHS; }

string HocSinh::getLop() { return Lop; }
