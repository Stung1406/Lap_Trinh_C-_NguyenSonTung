#include <iostream>
using namespace std;

struct SoPhuc {
    double thuc;
    double ao;
};

SoPhuc nhap() {
    SoPhuc sp;
    cout << "Nhap phan thuc: ";
    cin >> sp.thuc;
    cout << "Nhap phan ao: ";
    cin >> sp.ao;
    return sp;
}

void xuat(SoPhuc sp) {
    if (sp.ao >= 0)
        cout << sp.thuc << " + " << sp.ao << "i";
    else
        cout << sp.thuc << " - " << -sp.ao << "i";
}

SoPhuc cong(SoPhuc a, SoPhuc b) {
    SoPhuc kq;
    kq.thuc = a.thuc + b.thuc;
    kq.ao = a.ao + b.ao;
    return kq;
}

SoPhuc tru(SoPhuc a, SoPhuc b) {
    SoPhuc kq;
    kq.thuc = a.thuc - b.thuc;
    kq.ao = a.ao - b.ao;
    return kq;
}

SoPhuc nhan(SoPhuc a, SoPhuc b) {
    SoPhuc kq;
    kq.thuc = a.thuc * b.thuc - a.ao * b.ao;
    kq.ao = a.thuc * b.ao + a.ao * b.thuc;
    return kq;
}

SoPhuc chia(SoPhuc a, SoPhuc b) {
    SoPhuc kq;
    double mau = b.thuc * b.thuc + b.ao * b.ao;
    if (mau == 0) {
        cout << "Khong the chia cho 0!\n";
        kq.thuc = kq.ao = 0;
    } else {
        kq.thuc = (a.thuc * b.thuc + a.ao * b.ao) / mau;
        kq.ao = (a.ao * b.thuc - a.thuc * b.ao) / mau;
    }
    return kq;
}

int main() {
    int chon;
    do {
        cout << "Nhap so phuc thu nhat:\n";
        SoPhuc sp1 = nhap();
        cout << "Nhap so phuc thu hai:\n";
        SoPhuc sp2 = nhap();

        cout << "\nChon phep tinh:\n";
        cout << "1. Cong\n";
        cout << "2. Tru\n";
        cout << "3. Nhan\n";
        cout << "4. Chia\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        SoPhuc kq;

        switch (chon) {
        case 1:
            kq = cong(sp1, sp2);
            cout << "Ket qua: ";
            xuat(sp1);
            cout << " + ";
            xuat(sp2);
            cout << " = ";
            xuat(kq);
            cout << endl;
            break;
        case 2:
            kq = tru(sp1, sp2);
            cout << "Ket qua: ";
            xuat(sp1);
            cout << " - ";
            xuat(sp2);
            cout << " = ";
            xuat(kq);
            cout << endl;
            break;
        case 3:
            kq = nhan(sp1, sp2);
            cout << "Ket qua: ";
            xuat(sp1);
            cout << " * ";
            xuat(sp2);
            cout << " = ";
            xuat(kq);
            cout << endl;
            break;
        case 4:
            kq = chia(sp1, sp2);
            cout << "Ket qua: ";
            xuat(sp1);
            cout << " / ";
            xuat(sp2);
            cout << " = ";
            xuat(kq);
            cout << endl;
            break;
        case 0:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);

    return 0;
}

