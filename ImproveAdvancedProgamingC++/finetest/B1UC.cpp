#include<iostream>
#include<cmath>
using namespace std;

int ucln(int a,int b){
    if(a%b==0) return abs(b);
    return ucln(b,a%b);
}

int main()
{
    int a,b;
    char c;
    do{
        cout<<"Cho so nguyen a = "; cin>>a;
        cout<<"Cho so nguyen b = "; cin>>b;
        cout<<"Ket qua UCLN (a,b) = "<<ucln(a,b)<<endl;
        cout<<"Ban co muon tim tiep khong(C/K)? "; cin>>c;
    }while(c=='C' || c=='c');
    cout<<endl;
    return 0;
}