#include<iostream>
#include<cmath>
using namespace std;

bool isCP(int x){
    int can = sqrt(x);
    return can * can == x;
}

int main()
{
    int a,b;
    cout<<"Nhap a: "; cin>>a;
    do{
        cout<<"Nhap b: "; cin>>b;
    }while(b < a);
    
    cout<<"Cac so chinh phuong trong doan a,b la:";
    for(int i = a; i <= b ; i++){
        if(isCP(i)) cout<<" "<<i;
    }
    return 0;
}