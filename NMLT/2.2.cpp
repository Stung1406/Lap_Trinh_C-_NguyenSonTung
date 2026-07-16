#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    double x;
    cout<<"Nhap n: ";
	cin>>n;
	cout<<"Nhap x: ";
	cin>> x;
    double S = 0;
    for (int i = 1; i <= n; i++) {
        double tu = pow(x,i);
        double mau = i;
        S += tu/mau;
    }
	cout<<"S = "<<S;
    return 0;
}

