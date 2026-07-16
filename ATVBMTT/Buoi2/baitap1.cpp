#include<bits/stdc++.h>

using namespace std;

int kiTuSangSo(char c) { return c-'A'; } //Doi ki tu sang so nguyen

char soSangKiTu(int n) {return 'A'+n; }

int main()
{
    string P,C;
    cout<<"Nhap chuoi PlainText: ";  getline(cin,P);
    int k;
    cout<<"Nhap khoa K: "; cin>>k;
    //Ma Hoa
    for(int i=0;i<P.size();i++)
    {
        int p = kiTuSangSo(P[i]);
        int c = (p+k) % 26;
        C += soSangKiTu(c);
    }
    cout<<"Chuoi ma hoa: "<<C;

    //giai ma
    for(int i=0;i<C.size();i++)
    {
        int c = kiTuSangSo(C[i]);
        int p = (c-k+26)%26;
        P[i] = soSangKiTu(p);
    }
    cout<<"\nChuoi giai ma: "<<P;
    return 0;
}