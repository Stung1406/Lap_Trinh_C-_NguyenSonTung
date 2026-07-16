#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int x,n; 
    cout<<"Nhap n: "; cin>>n;
    cout<<"Nhap x: "; cin>>x;
    double S = 1;
    int tu=0;
    int mau=1;
    for(int i=1;i<n;i++){
        tu = pow(x,i-1);
        mau = i;
        S += (tu/mau);
    }
    cout<<S;
    return 0;
}