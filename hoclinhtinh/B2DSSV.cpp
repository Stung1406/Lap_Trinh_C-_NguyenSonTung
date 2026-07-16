#include<iostream>
#include<string>

using namespace std;

void nhap(int &n,string dssv[]){
	do{
		cout<<"N = "; cin>>n;
		cin.ignore();
	}while(n<=0 || n>=100);
	for(int i=0;i<n;i++){
		cout<<"Ho ten "<<i+1<<": "; 
		getline(cin,dssv[i]);
	}
}

string tenNganNhat(int &n,string dssv[]){
	string minXau = dssv[0];
	for(int i=0;i<n;i++){
		if(minXau.size()>dssv[i].size()) minXau=dssv[i];  
	}
	return minXau;
}

int main()
{
	int n; string dssv[100];
	nhap(n,dssv);
	cout<<"Ho ten ngan nhat (dau tien) la: "<<tenNganNhat(n,dssv);
	return 0;
}
