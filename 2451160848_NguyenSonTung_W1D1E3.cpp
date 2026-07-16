#include<iostream>
#include<cmath>

using namespace std;

double tinhTong(int n,double x){
	double sum=0;
	for(int i=0;i<n;i++){
		double tu = pow(x,i+1);
		double mau = 2*(i+1);
		sum += (tu/mau);
	}
	return sum;
}

int main(){
	int n;
	double x;
	cout<<"Nhap n = "; cin>>n;
	cout<<"Nhap x = "; cin>>x;
	cout<<"Ket qua: "<<tinhTong(n,x);
	return 0;	
}
