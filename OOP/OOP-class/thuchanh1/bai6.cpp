#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct HocSinh {
    string MaHS;
    string HotenHS;
    string Lop;
    double Diem;
};

void themHocSinh(vector<HocSinh> &ds) {
    HocSinh hs;
    cout << "Nhap MaHS: ";
    cin >> hs.MaHS;
    for (size_t i = 0; i < ds.size(); ++i) {
        if (ds[i].MaHS == hs.MaHS) {
            cout << "MaHS bi trung!" << endl;
            return;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nhap Ho ten: ";
    getline(cin, hs.HotenHS);
    cout << "Nhap Lop: ";
    getline(cin, hs.Lop);
    cout << "Nhap Diem: ";
    cin >> hs.Diem;
    ds.push_back(hs);
}

void xoaHocSinh(vector<HocSinh> &ds) {
    string ma;
    cout << "Nhap MaHS can xoa: ";
    cin >> ma;
    for (vector<HocSinh>::iterator it = ds.begin(); it != ds.end(); ++it) {
        if (it->MaHS == ma) {
            ds.erase(it);
            cout << "Da xoa hoc sinh." << endl;
            return;
        }
    }
    cout << "Khong tim thay hoc sinh." << endl;
}

void timKiemHocSinh(const vector<HocSinh> &ds) {
    string ma;
    cout << "Nhap MaHS can tim: ";
    cin >> ma;
    for (size_t i = 0; i < ds.size(); ++i) {
        if (ds[i].MaHS == ma) {
            cout << ds[i].MaHS << " | " << ds[i].HotenHS << " | " << ds[i].Lop << " | " << ds[i].Diem << endl;
            return;
        }
    }
    cout << "Khong tim thay hoc sinh." << endl;
}

void lietKeTheoLop(const vector<HocSinh> &ds) {
    string lop;
    cout << "Nhap Lop: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, lop);
    bool found = false;
    for (size_t i = 0; i < ds.size(); ++i) {
        if (ds[i].Lop == lop) {
            cout << ds[i].MaHS << " | " << ds[i].HotenHS << " | " << ds[i].Lop << " | " << ds[i].Diem << endl;
            found = true;
        }
    }
    if (!found) cout << "Khong co hoc sinh nao trong lop nay." << endl;
}

void lietKeTatCa(const vector<HocSinh> &ds) {
    if (ds.empty()) {
        cout << "Danh sach rong." << endl;
        return;
    }
    for (size_t i = 0; i < ds.size(); ++i) {
        cout << ds[i].MaHS << " | " << ds[i].HotenHS << " | " << ds[i].Lop << " | " << ds[i].Diem << endl;
    }
}

int main() {
    vector<HocSinh> ds;
    int chon;
    do {
        cout << "\n1. Them moi hoc sinh\n";
        cout << "2. Xoa hoc sinh khoi danh sach\n";
        cout << "3. Tim kiem hoc sinh theo ma\n";
        cout << "4. Liet ke danh sach hoc sinh theo lop\n";
        cout << "5. Liet ke danh sach tat ca hoc sinh\n";
        cout << "6. Thoat\n";
        cout << "Ban chon: ";
        cin >> chon;
        switch (chon) {
            case 1: themHocSinh(ds); break;
            case 2: xoaHocSinh(ds); break;
            case 3: timKiemHocSinh(ds); break;
            case 4: lietKeTheoLop(ds); break;
            case 5: lietKeTatCa(ds); break;
            case 6: cout << "Thoat chuong trinh.\n"; break;
            default: cout << "Lua chon khong hop le.\n";
        }
    } while (chon != 6);
    return 0;
}

