#include<iostream>
#include<cmath>
using namespace std;

bool isNT(int x){
    if(x < 2) return false;
    for(int i=2;i <= sqrt(x);i++){
        if(x % i == 0) return false;
    }
    return true;
}

void nhapMatran(int n,int a[][50]){
    cout<<"Nhap ma tran: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"a["<<i<<"]["<<j<<"] = "; cin>>a[i][j];
        }
    }
}

void inMatran(int n,int a[][50]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j != 0) cout<<" ";
            cout<<a[i][j];
        }
        if(i != n-1) cout<<endl;
    }
}

int demNT(int n,int a[][50],int k){
    int dem = 0;
    for(int i=0;i<n;i++){
        if(isNT(a[i][k])) dem++;
    }
    return dem;
}

int main()
{
    int n,k;
    int a[50][50];
    cout<<"Nhap N: "; cin>>n;
    nhapMatran(n,a);
    cout<<"Ma tran vua nhap la: "<<endl;
    inMatran(n,a);
    cout<<"\nNhap cot k: ";  cin>>k;
    cout<<"Co "<<demNT(n,a,k-1)<<" so nguyen to trong cot "<<k<<"";
    return 0;
}