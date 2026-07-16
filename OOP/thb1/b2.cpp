#include<iostream>
using namespace std;

struct SoPhuc{
    double thuc,ao;
};
void nhap(SoPhuc &tmp){
    cout<<"Nhap phan thuc: "; cin>>tmp.thuc;
    cout<<"Nhap phan ao: "; cin>>tmp.ao;
}
void xuat(SoPhuc tmp){
    cout<<tmp.thuc<<"+"<<tmp.ao<<"i";
}
SoPhuc cong(SoPhuc a,SoPhuc b){
    SoPhuc sum;
    sum.thuc=a.thuc+b.thuc;
    sum.ao = a.ao+b.ao;
    return sum; 
}
SoPhuc tru(SoPhuc a,SoPhuc b){
    SoPhuc t;
    t.thuc=a.thuc-b.thuc;
    t.ao = a.ao-b.ao;
    return t; 
}
SoPhuc nhan(SoPhuc a,SoPhuc b){
    SoPhuc n;
    n.thuc = a.thuc*b.thuc - a.ao*b.ao;
    n.ao = a.thuc*b.ao +b.thuc*a.ao;
    return n; 
}

SoPhuc chia(SoPhuc a,SoPhuc b){
    SoPhuc res;
    double mau = b.thuc*b.thuc + b.ao*b.ao; // mẫu = c^2 + d^2

    if(mau == 0){
        cout << "Loi: Khong the chia cho 0!\n";
        return {0, 0};
    }

    res.thuc = (a.thuc*b.thuc + a.ao*b.ao) / mau;
    res.ao   = (a.ao*b.thuc - a.thuc*b.ao) / mau;

    return res;
}

int main()
{
    SoPhuc a,b;
    cout<<"Nhap 2 so phuc"<<endl;
    cout<<"Nhap so phuc thu nhat"<<endl;
    nhap(a);
    cout<<"So phuc vua nhap la: "; xuat(a);
    cout<<"\nNhap so phuc thu hai"<<endl;
    nhap(b);
    cout<<"So phuc vua nhap la: "; xuat(b);
    cout<<"\nTong cua 2 so phuc la "; xuat(cong(a,b));
    cout<<"\nHieu cua 2 so phuc la "; xuat(tru(a,b));
    cout<<"\nTich cua 2 so phuc la "; xuat(nhan(a,b));
    cout<<"\nThuong cua 2 so phuc la "; xuat(chia(a,b));
    return 0;
}