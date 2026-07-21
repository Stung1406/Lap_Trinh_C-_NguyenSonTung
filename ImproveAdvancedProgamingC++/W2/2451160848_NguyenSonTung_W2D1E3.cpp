#include<iostream>

using namespace std;

void printMatrix(int n){
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) cout<<"0";
                else cout<<"1";
            }
            if(i!=n-1) cout<<endl;
    }
}

int main(){
    int n,a[100][100];
    cout<<"Nhap n: "; cin>>n;
    printMatrix(n);
    return 0;
}