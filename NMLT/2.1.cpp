#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    do{
    	cout<<"Nhap n: ";
    	cin>>n;
	}while(n<1 || n>100);
	double S = 1;
    for (int i = 1; i <= n; i++){
    	int mau = i*(i+1); 
        S += 1.0/mau;
    }
    cout << fixed << setprecision(5);
    cout<<"S = "<<S;
    return 0;
}
