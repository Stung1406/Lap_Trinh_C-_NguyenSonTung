//dịch các phần tử sang trái rồi xóa phần tử cuối 
#include<iostream>
#include<cmath>

using namespace std;

int *nhapArray(int &n){
    cout<<"Nhap so phan tu cua mang: "; cin>>n;
    int *p = new int[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap phan tu thu "<<i+1<<": "; cin>>*(p+i);
    }
    return p;
}

void out(int *&p,int n){
    for(int i=0;i<n;i++){
        cout<<*(p+i)<<" ";
    }
}

void xoa(int *&p,int &n){
    int k;
    cout<<"Nhap vi tri can xoa: "; cin>>k;
    for(int i=k;i<n;i++){
        *(p+i) =  *(p+i+1);
    }
    n--;
}

int main()
{
    int n;
    int *p;
    p=nhapArray(n);
    out(p,n);
    xoa(p,n);
    cout<<"Mang sau khi xoa: ";
    out(p,n);
    delete[] p;
    return 0;
}