#include<iostream>
#include<string>
using namespace std;

long long Fibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    else return Fibo(n-1) + Fibo(n-2);
}

int main()
{
    int n;
    char c;
    do{
        cout<<"Cho so nguyen n = "; cin>>n;
        if(n<0) cout<<"Nhap sai! So n phai khong am."<<endl;
        else cout<<"So Fibonacci thu "<<n<<" la: "<<Fibo(n)<<endl;
        cout<<"Ban co muon tim tiep khong?(C/c: Tim tiep) "; cin>>c;
    }while(c=='c' || c=='C');
    cout<<endl;
    return 0;
}