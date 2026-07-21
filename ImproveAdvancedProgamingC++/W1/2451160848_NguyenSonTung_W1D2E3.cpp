#include<iostream>
#include<cmath>

using namespace std;

bool isNT(int x){
	if(x<2) return false
	for(int i=0;i<sqrt(x);i++) 
		if x%i==0 return false
	return true;
}

void inputN(int &n){
    do{
        cout<<"Nhap n = "; cin>>n;
    }while(n <= 0 || n >= 100);
}

int maxArray(int n,int a[]){
    int max = a[0];
    for(int i = 0;i < n;i++){
        if(max<a[i]) max=a[i];
    }
    return max;
}


void inputArray(int n,int a[]){
    for(int i = 0;i < n;i++){
		cout<<"So thu "<<i+1<<": "; cin>>a[i];
	}
}

void outputArray(int n,int a[]){
    for(int i = 0;i < n;i++){
		cout<<" "<<a[i];
	}
}

int main()
{
	int n,a[100];
	inputN(n);
	inputArray(n,a);
	cout<<endl<<"In day so:";
	outputArray(n,a);
	cout<<endl<<"So max = "<<maxArray(n,a);
	cout<<endl<<"So chinh phuong lon nhat: "<<maxCP(n,a);
	return 0;
}
