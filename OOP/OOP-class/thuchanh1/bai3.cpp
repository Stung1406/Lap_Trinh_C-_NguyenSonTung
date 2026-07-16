#include <iostream>
using namespace std;

class SoPhuc {
private:
    double thuc; 
    double ao;   

public:
    SoPhuc();
    SoPhuc(double t, double a);
    void nhap();
    void xuat();

    SoPhuc cong(const SoPhuc &sp);

    SoPhuc tru(const SoPhuc &sp);

    SoPhuc nhan(const SoPhuc &sp);

    SoPhuc chia(const SoPhuc &sp);
};

int main() {
    int chon;
    do {
        cout << "Nhap so phuc thu nhat:\n";
        SoPhuc sp1;
        sp1.nhap();

        cout << "Nhap so phuc thu hai:\n";
        SoPhuc sp2;
        sp2.nhap();

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
            kq = sp1.cong(sp2);
            cout << "Ket qua: ";
            sp1.xuat(); cout << " + "; sp2.xuat(); cout << " = ";
            kq.xuat(); cout << endl;
            break;
            
        case 2:
            kq = sp1.tru(sp2);
            cout << "Ket qua: ";
            sp1.xuat(); cout << " - "; sp2.xuat(); cout << " = ";
            kq.xuat(); cout << endl;
            break;
        case 3:
            kq = sp1.nhan(sp2);
            cout << "Ket qua: ";
            sp1.xuat(); cout << " * "; sp2.xuat(); cout << " = ";
            kq.xuat(); cout << endl;
            break;
        case 4:
            kq = sp1.chia(sp2);
            cout << "Ket qua: ";
            sp1.xuat(); cout << " / "; sp2.xuat(); cout << " = ";
            kq.xuat(); cout << endl;
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

SoPhuc::SoPhuc(double t, double a) : thuc(t),ao(a){}


SoPhuc::SoPhuc() : thuc(0),ao(0) {}

void SoPhuc::nhap() {
    cout << "Nhap phan thuc: ";
    cin >> thuc;
    cout << "Nhap phan ao: ";
    cin >> ao;
}

void SoPhuc::xuat() {
    if (ao >= 0)
        cout << thuc << " + " << ao << "i";
    else
        cout << thuc << " - " << -ao << "i";
}

SoPhuc SoPhuc::cong(const SoPhuc &sp) {return SoPhuc(thuc + sp.thuc, ao + sp.ao);}


SoPhuc SoPhuc::tru(const SoPhuc &sp) {return SoPhuc(thuc - sp.thuc, ao - sp.ao);}

SoPhuc SoPhuc::nhan(const SoPhuc &sp) {
        double t = thuc * sp.thuc - ao * sp.ao;
        double a = thuc * sp.ao + ao * sp.thuc;
        return SoPhuc(t, a);
}

SoPhuc SoPhuc::chia(const SoPhuc &sp) {
    double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
    if (mau == 0) {
        cout << "Loi: Khong the chia cho 0!" << endl;
        return SoPhuc(0, 0);
    }
    double t = (thuc * sp.thuc + ao * sp.ao) / mau;
    double a = (ao * sp.thuc - thuc * sp.ao) / mau;
    return SoPhuc(t, a);
    }