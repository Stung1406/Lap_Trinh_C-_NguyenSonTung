#include<iostream>
#include<string>
#include <algorithm>
 
using namespace std;

struct SinhVien{
	int SBD;
	string hoten;
	double diem;
	void nhapDL(){
		cout<<"SBD: "; cin>>SBD;
		cin.ignore(); 
		cout<<"Ho va ten: "; getline(cin,hoten);
		cout<<"Diem: "; cin>>diem;
		cin.ignore();
	}
};


void nhap(int n,SinhVien dssv[]){
	for(int i=0;i<n;i++){
		dssv[i].nhapDL();
	}
}

int partition(SinhVien a[], int left, int right) {
    double pivot = a[(left + right) / 2].diem;
    int i = left;
    int j = right;

    while (i <= j) {
        while (a[i].diem < pivot) i++;
        while (a[j].diem > pivot) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(SinhVien a[], int left, int right) {
    if (left >= right) return;
    int index = partition(a, left, right);
    quickSort(a, left, index - 1);
    quickSort(a, index, right);
}

void output(int n,SinhVien dssv[]){
	for(int i=0;i<n;i++){
		cout<<dssv[i].SBD<<"\t"<<dssv[i].hoten<<"\t"<<dssv[i].diem<<endl;
	}
}

int main()
{
	int n;
	cout<<"Nhap n = "; cin>>n;
	SinhVien dssv[1000];		
	nhap(n,dssv);
	quickSort(dssv,0,n-1); 
	cout<<"Danh sach sap xep tang dan cua diem:"<<endl;
	output(n,dssv);
	return 0;
} 
