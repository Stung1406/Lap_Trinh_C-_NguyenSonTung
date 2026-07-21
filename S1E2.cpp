#include<iostream>
#include<cmath>

using namespace std;

bool isCP(int n)
{
    int x = sqrt(n);
    
}

void inputArr(int n,int a[])
{
    for(int i = 0;i < n;i++){
        cout<<"Nhap phan tu thu "<<i+1<<": ";
        cin>>a[i];
    }
}

void outputArr(int n,int a[])
{
    for(int i = 0;i < n;i++)
    {
        cout<<" "<<a[i];
    }
}

int sumArr(int n,int a[]){
    int sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    return sum;
}

int demSoAm(int n,int a[])
{
    int dem=0;
    for(int i=0;i<n;i++){
        if(a[i] < 0) dem++;
    }
    return dem;
}



int main()
{
    int n,a[100];

    return 0;
}