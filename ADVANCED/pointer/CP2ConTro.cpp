#include<iostream>

using namespace std;



int main()
{
    int n;
    cout<<"Nhap n: "; cin>>n;
    int **p;
    *p = new int[100];
    for(int i=0;i<n;i++){
        cout<<"Nhap so thu "<<i<<" : ";
        cin>>*p[i];
    }
    return 0;
}