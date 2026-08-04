#include<iostream>

using namespace std;

bool isLeapYear(long long year){
    return (year%4==0 && year%100!=0) || year%400==0;
}

void inputN(long long &n){
    do{
        cout<<"Nhap nam:"; cin>>n;
    }while(n<0 || n>20000);
}

int main()
{
    long long n;
    inputN(n);
    if(isLeapYear(n)) cout<<n<<" la nam nhuan";
    else cout<<n<<" khong la nam nhuan";
    cout<<endl;
    return 0;
}