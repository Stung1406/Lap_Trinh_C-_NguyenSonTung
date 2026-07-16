#include<iostream>
#include<cmath>

using namespace std;

bool mark[100]={false};

void nhap(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"] = "; cin>>a[i];
    }
}

void xuat(int a[],int n){
    for(int i=0;i<n-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1];
}

int demPhanTuKhac(int a[],int n){
    for(int i=0;i<n;i++){
        mark[a[i]] = true;
    }

    int dem=0;

    for(int i=0;i<=100;i++){
        if(mark[i]==true) dem++;
    }
    return dem;
}
int dem[100];
//đếm số lần xuất hiện của từng phần tử trong mảng
void soLanxh(int a[],int n){
    for(int i=0;i<n;i++){ //duyệt mảng a đánh dấu số lần xh vào mảng dem
        dem[a[i]]++;
    }
    for(int i=0;i<=100;i++){
        if(dem[i]>0) cout<<"So lan xuat hien cua "<<i<<" la: "<<dem[i]<<endl;  
    }
}
//in phan tu xuat hien 2 lan trong mang
void xh2lan(int a[],int n){
    for(int i=0;i<=100;i++){
        if(dem[i]==2) cout<<i<<endl;  
    }
}

//xoa phan tu xuat hien 2 lan
//ham xoa
void xoa(int a[],int &n,int k){
    for(int i=k;i<n;i++){
        a[i] = a[i+1];
    }
    n--;
} 

void xoaXH2lan(int a[],int &n){
    int j = 0; // chỉ số cho mảng mới
    for(int i = 0; i < n; i++){
        if(dem[a[i]] != 2){
            a[j] = a[i];  // giữ lại phần tử khác x
            j++;
        }
    }
    n = j;
}
// nhập x xóa các phần tử x khỏi array
void xoaPhanTuX(int a[], int &n, int x){
    int m = 0; // chỉ số cho mảng mới
    for(int i = 0; i < n; i++){
        if(a[i] != x){
            a[m] = a[i];  // giữ lại phần tử khác x
            m++;
        }
    }
    n = m; // cập nhật lại số lượng phần tử
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    nhap(a,n);   
    xuat(a,n);
    cout<<endl;
    cout<<"So luong phan tu khac nhau: "<<demPhanTuKhac(a,n);
    cout<<endl;
    soLanxh(a,n);
    xh2lan(a,n);
    xoaXH2lan(a,n);
}

