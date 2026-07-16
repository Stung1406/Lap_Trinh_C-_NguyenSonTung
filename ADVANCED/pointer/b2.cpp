#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n=5;
    int a[5] = {3,8,4,2,9};
    cout<<"Gia tri cua a : "<<a<<endl;
    cout<<"Duyet mang a kieu con tro : ";
    for(int i=0;i<n;i++){
        cout<< *(a+i) << ' ';
    }
    return 0;
}