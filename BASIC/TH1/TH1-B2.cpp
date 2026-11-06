#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int x,y;
    double Fx,Gx;
    cout<<"Nhap x = "; cin>>x;
    Fx = pow(x,5) + 5 * pow(x,5/3) -6;
    cout<<"Nhap y = "; cin>>y;
    Gx = x*y - pow(x,2) + x*pow(y,2) - pow(y,3);
    cout<<"F(x) = "<<Fx<<endl;
    cout<<"G(y) = "<<Gx<<endl;
    return 0;
}