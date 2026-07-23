#include<iostream>

using namespace std;

void printMatrix(int n){
    for(int i=0;i<10;i++){
            for(int j=0;j<n;j++){
                cout<<j+1<<" * "<<i+1<<" = "<<(j+1) * (i+1);
                if(j!= n-1) cout<<"\t";
            }
            if(i!=9) cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Nhap n: "; cin>>n;
    printMatrix(n);
    return 0;
}