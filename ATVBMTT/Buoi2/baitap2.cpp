#include<bits/stdc++.h>

using namespace std;

int kiTuSangSo(char c) { return c-'A'; } //Doi ki tu sang so nguyen

char soSangKiTu(int n) {return 'A'+n; }

int main()
{
    string C,P;
    cout<<"Nhap chuoi CipherText: "; getline(cin,C);
    //Be khoa
    // ================= BE KHOA (BRUTE-FORCE) ===============
    for(int K=1;K<26;K++)
    {
        P="";
        for(int i=0;i<C.size();i++){
            int c=kiTuSangSo(C[i]);
            int p=(c-K+26) % 26;
            P = P + soSangKiTu(p);
        }
        cout<<K<<": "<<P<<endl;
    }
    return 0;
}