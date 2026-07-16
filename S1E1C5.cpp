#include<iostream>
#include<cmath>

using namespace std;

double tinhTong(int n,int x){
  double sum = 0;
  double mau=1;
  int d=1;
  for (int i = 0; i < n; i++){
  	d=-d;
	double tu = pow(x,(i+1));
    double mau  = mau*(i+1);
    sum += d*(tu/mau);
  }
  return sum;
}

int main() {
  int n,x;
  cout << "Nhap n = "; cin >> n;
  cout <<"Nhap x = "; cin>>x;
  cout << "Ket qua: " << tinhTong(n,x);
  return 0;
}
