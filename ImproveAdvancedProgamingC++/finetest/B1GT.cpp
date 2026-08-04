#include<iostream>
#include<string>
using namespace std;


void inputN(int &n){
    do{
        cout<<"Cho so nguyen n (n<10) = "; cin>>n;
    }while(n<0 || n>=10);
}

long long gt(int n){
    if(n==0) return 1;
    if(n==1) return 1;
    else return n * gt(n-1);
}

int main()
{
    int n;
    char c;
    do{
        inputN(n);
        cout<<n<<"! = "<<gt(n)<<endl;
        cout<<"Ban co tim tiep khong? (C/K) "; cin>>c;
    }while(c=='c' || c=='C');
    cout<<endl;
    return 0;
}