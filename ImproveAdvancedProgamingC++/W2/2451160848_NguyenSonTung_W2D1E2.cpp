#include<iostream>
#include<cmath>

using namespace std;

bool isCP(int x){
    int can = sqrt(x);
    return can*can == x;
}

void inputMatrix(int n,int a[][100]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"a["<<i<<"]["<<j<<"] = "; cin>>a[i][j];
        }
    }
}

int sumCP(int n,int a[][100]){
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isCP(a[i][j])) sum+= a[i][j];
        }
    }
    return sum;
}

int demCP(int n,int a[][100]){
    int dem=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isCP(a[i][j])) dem++;
        }
    }
    return dem;
}

int main()
{
    int n,a[100][100],k;
    cout<<"Nhap n = "; cin>>n;
    inputMatrix(n,a);
    if(demCP(n,a)==0) cout<<"Khong co so chinh phuong nao trong ma tran.";
    else cout<<"Tong cac so chinh phuong trong ma tran la: "<<sumCP(n,a);
    return 0;
}