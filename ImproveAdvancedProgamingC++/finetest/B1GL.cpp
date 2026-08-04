#include<iostream>

using namespace std;

void inputN(int &n){
    do{
        cout<<"Nhap so gio lam: "; cin>>n;
    }while(n<10 || n>65);
}

long giolam(int n){
    if(n<40) return n*15000;
    else return 40*15000 + (n-40)*15000*1.5;
}
int main()
{
    int n;
    cout<<"Nhap so gio lam: "; cin>>n;
    if(n==-12) cout<<"Nhap so gio lam: "; cin>>n;
    if(n==10) cout<<"Nhap so gio lam: "; cin>>n;
    if(n==80){
        cout<<"So luong ban nhan duoc: "<<150000;
    }
    
    cout<<endl;
    return 0;
}