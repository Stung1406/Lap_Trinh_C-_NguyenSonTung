#include<iostream>
#include<cmath>

using namespace std;

bool isCP(int n){
	int x = sqrt(n);
	return x*x==n;
}

int demCP(int n,int a[]){
    int dem=0;
    for(int i=0;i < n;i++)
        if(isCP(a[i])) dem++;
    
    return dem;
}

int demChiaHetCho3(int n,int a[]){
    int dem=0;
    for(int i = 0;i < n;i++)
        if(a[i] % 3 == 0 ) dem++;
    
    return dem;
}

void inputArray(int n,int a[]){
    for(int i = 0;i < n;i++){
		cout<<"So thu "<<i<<": "; cin>>a[i];
	}
}

void outputArray(int n,int a[]){
    for(int i = 0;i < n;i++) cout<<" "<<a[i];
}

int main()
{
	int n,a[100];
	cout<<"Nhap n = "; cin>>n;
	inputArray(n,a);
	cout<<endl<<"Day so:";
	outputArray(n,a);
	cout<<endl<<endl;
	cout<<"Dao nguoc day so:";
	for(int i = n-1;i >= 0;i--){
		cout<<" "<<a[i];
	}
	cout<<endl<<"Day co "<<demChiaHetCho3(n,a)<<" so chia het cho 3."<<endl;
	cout<<"Day co "<<demCP(n,a)<<" so chinh phuong.";
	return 0;
}
