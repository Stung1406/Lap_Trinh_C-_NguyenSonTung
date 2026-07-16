//cấp phát mảng động 
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cout<<"Nhap so luong phan tu xin cap: "; 
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin>>*(a+i);
    }

    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
    }

    delete[] a;
    return 0;
}