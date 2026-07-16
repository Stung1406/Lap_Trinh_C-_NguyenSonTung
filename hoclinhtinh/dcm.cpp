#include<bits/stdc++.h>

using namespace std;

int main()
{

	int a[100];
	int n;
	cout<<"Nhap so phan tu "; cin>>n; 
	cout<<"Nhap mang a "<<endl;
	for(int i=0;i<n;i++){
		cout<<"Nhap phan tu thu "<<i+1<<": "; cin>>a[i];
	}	
	cout<<endl<<"Mang vua nhap la: "<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	int x; 
	cout<<endl<<"Nhap phan tu can xoa: "; cin>>x;
	int m = 0;
	for(int i=0;i<n;i++){
		if(a[i]!=x){
			a[m]=a[i];	
			m++; 
		}
	}
	cout<<"Mang sau khi xoa: "<<endl; 
	for(int i=0;i<m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
