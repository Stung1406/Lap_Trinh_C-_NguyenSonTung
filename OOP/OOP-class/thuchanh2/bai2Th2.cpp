#include <iostream>
using namespace std;

class SoPhuc {
private:
    double thuc; 
    double ao;   

public:
    SoPhuc();
    
    SoPhuc(double t, double a);
    
    friend istream& operator>>(istream &in, SoPhuc &sp);

    friend ostream& operator<<(ostream &out, const SoPhuc &sp);

    SoPhuc operator + (const SoPhuc &sp);

    SoPhuc operator - (const SoPhuc &sp);

    SoPhuc operator * (const SoPhuc &sp);

    SoPhuc operator / (const SoPhuc &sp);
};

int main() {
    int chon;

    do {
        cout << "Nhap so phuc thu nhat:\n";
        SoPhuc sp1; cin>>sp1;
        cout<<sp1<<endl;
        cout << "Nhap so phuc thu hai:\n";
        SoPhuc sp2; cin>>sp2;
        cout<<sp2<<endl;
        
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
            kq = sp1 + sp2;
            cout << "Ket qua: "<<kq<<endl;
            break;
        case 2:
            kq = sp1 - sp2;
            cout << "Ket qua: "<<kq<<endl;
            break;
        case 3:
            kq = sp1*sp2;
            cout << "Ket qua: "<<kq<<endl;
            break;
        case 4:
            kq = sp1/sp2;
            cout << "Ket qua: "<<kq<<endl;
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

SoPhuc SoPhuc::operator + (const SoPhuc &sp) {return SoPhuc(thuc + sp.thuc, ao + sp.ao);}


SoPhuc SoPhuc::operator -(const SoPhuc &sp) {return SoPhuc(thuc - sp.thuc, ao - sp.ao);}

SoPhuc SoPhuc::operator * (const SoPhuc &sp) {
        double t = thuc * sp.thuc - ao * sp.ao;
        double a = thuc * sp.ao + ao * sp.thuc;
        return SoPhuc(t, a);
}

SoPhuc SoPhuc::operator / (const SoPhuc &sp) {
    double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
    if (mau == 0) {
        cout << "Loi: Khong the chia cho 0!" << endl;
        return SoPhuc(0, 0);
    }
    double t = (thuc * sp.thuc + ao * sp.ao) / mau;
    double a = (ao * sp.thuc - thuc * sp.ao) / mau;
    return SoPhuc(t, a);
    }

istream& operator>>(istream &in, SoPhuc &sp){
    cout << "Nhap phan thuc: ";
    in >> sp.thuc;
    cout << "Nhap phan ao: ";
    in >> sp.ao;
    return in; 
}

ostream& operator<<(ostream &out, const SoPhuc &sp) {
    out << sp.thuc << "+"<<sp.ao<<"i";  
    return out;            
}
