#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cout<<"Nhap x: "; cin >> x;
    int tu = x*x*x + x + 1;
    int mau = x*x + 2;
    double f = (double)tu / mau;
    cout<<fixed<<setprecision(4);
	cout<<"f("<<x<<") = "<<f;
    cout<<endl;
}
