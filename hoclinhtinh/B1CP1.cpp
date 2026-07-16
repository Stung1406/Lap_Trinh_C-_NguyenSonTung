#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n;
	int sum=0;
	cout<<"Nhap N = "; cin>>n;
	if(n<=10 || n>=1000) cout<<"Khong thoa man yeu cau!";
	else
	{
		cout<<"Cac so chinh phuong duong <"<<n<<":";
		for(int i=1;i*i<n;i++){
			cout<<" "<<i*i;
			sum += i*i;
		}
		cout<<"\nTong so chinh phuong: "<<sum;
	}
	return 0;
}
