#include<iostream>
#include<cmath>
using namespace std;

void inputN(int &n){
    do{
        cout<<"Nhap n = "; cin>>n;
    }while(n<5 || n>20);
}

bool isCP(int x){
    int can = sqrt(x);
    return can * can == x;
}

void inputArray(int n,int a[])
{
    for(int i=0;i<n;i++){
        cout<<"So thu "<<i+1<<": "; cin>>a[i];
    }
}

void outputArray(int n,int a[]){
    for(int i=0;i<n;i++){
        cout<<" "<<a[i];
    }
}

int demCP(int n,int a[]){
    int dem = 0;
    for(int i=0;i<n;i++){
        if(isCP(a[i])) dem++;
    }
    return dem;
}

int demCPChan(int n,int a[]){
    int dem = 0;
    for(int i=0;i<n;i++){
        if(isCP(a[i]) && a[i] %2==0) dem++;
    }
    return dem;
}

int main()
{
    int n,a[100];
    inputN(n);
    inputArray(n,a);
    cout<<endl<<"Hien thi day so:";
    outputArray(n,a);
    cout<<endl;
    cout<<endl<<"Day co "<<demCP(n,a)<<" so chinh phuong, "<<"trong do co "<<demCPChan(n,a)<<" so chinh phuong chan!";
    return 0;
}