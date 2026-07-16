#include<bits/stdc++.h>

using namespace std;

char kiTuSangSo(char c){return c - 'A';}

int soSangKiTu(int n){ return 'A'+n; }

bool checkVanh26(int n){
    for(int i=0;i<n;i++){
        return((n*i)%26==1);
    }
}

int main()
{
    string P,C;
    int a,b;
    cout<<"Nhap so a: "; cin>>a;
    cout<<"Nhap so b: "; cin>>b;
    cin.ignore();
    cout<<"Nhap chuoi ki tu: "; getline(cin,P);
    for(int i=0;i<P.size();i++){
        if(checkVanh26(a))
        {
            char p = soSangKiTu()
        }
    }
    return 0;
}