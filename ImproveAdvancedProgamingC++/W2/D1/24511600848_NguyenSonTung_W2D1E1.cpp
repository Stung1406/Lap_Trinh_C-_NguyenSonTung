#include<iostream>

using namespace std;

void inputMatrix(int n,int a[][100]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"a["<<i<<"]["<<j<<"] = "; cin>>a[i][j];
        }
    }
}

int minColumK(int n,int a[][100],int k){
    int min = a[0][k];
    for(int i=0;i<n;i++)
        if(a[i][k] < min) min = a[i][k];
    return min;
}

int main()
{
    int n,a[100][100],k;
    cout<<"Nhap n = "; cin>>n;
    inputMatrix(n,a);
    cout<<"Nhap cot k = "; cin>>k;
    cout<<"Phan tu nho nhat trong cot "<<k<<" la: "<<minColumK(n,a,k);
    return 0;
}