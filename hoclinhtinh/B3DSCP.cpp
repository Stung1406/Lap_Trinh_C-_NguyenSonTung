#include<iostream>
#include<cmath>

using namespace std;

void nhap(int &n,int a[]){
	do{
	cout<<"n="; cin>>n;
	}while(n<1 || n>=200);
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]="; cin>>a[i];
	}
}

void xuat(int n,int a[]){
	for(int i=0;i<n;i++){
		if(i!=n-1) cout<<a[i]<<"\t";
	}
	cout<<a[n-1];
}

bool checkCP(int x){
	return (int)sqrt(x) * (int)sqrt(x) == x;
}

int demCP(int n,int a[],int x){
	int dem=0;
	for(int i=0;i<n;i++){
		if(checkCP(a[i]) and a[i]<x){
			dem++;
		} 
	}
	return dem;
}

void inCP(int n,int a[]){
	int x;
	cout<<"Nhap x = "; cin>>x;
	if(demCP(n,a,x)==0) cout<<"Khong co so chinh phuong nao nho hon "<<x<<" !";
	else
	{
		cout<<"Cac so chinh phuong nho hon "<<x<<":"<<endl;
		for(int i=0;i<n;i++){
			if(checkCP(a[i]) and a[i]<x){
				cout<<a[i];
				if(i!=n-1) cout<<"\t";
			} 
		}
	}
}


int main()
{
	int n,a[100];
	nhap(n,a);
	cout<<"Day so vua nhap: "<<endl;
	xuat(n,a);
	cout<<endl;
	inCP(n,a);
	return 0;
}
