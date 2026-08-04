#include<iostream>

using namespace std;

void input(int &n,int a[]){
	cout<<"Nhap n: "; cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Nhap phan tu thu "<<i+1<<": "; cin>>a[i];
	}
}

int demMang(int n,int a[]){
	int dem=0;
	for(int i=1;i<n-1;i++){
		if(a[i]==a[i-1]+a[i+1]) dem++;
	}
	return dem;
}

void solution(int n,int a[]){
	if(demMang(n,a)!=0){
		cout<<"Mang bo ba la: ";
		for(int i=0;i<n;i++){
			if(a[i]==a[i-1]+a[i+1]) cout<<"("<<a[i-1]<<a[i]<<a[i+1]<<")"<<endl;
		}
	}else{
		cout<<endl<<"Khong co mang bo ba";
	} 
}

void output(int n,int a[]){
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
}

int main()
{
	int n,a[100];
	input(n,a);
	solution(n,a);
	return 0;
}

