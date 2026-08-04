#include<iostream>

using namespace std;

void inputN(int &n)
{
    do{
        cout<<"Nhap so nguyen duong n = "; cin>>n;
    }while(n <= 10);
}


bool isDX(int n){
    int a = n,b = 0;
    while(n > 0){
        b = b*10 + n%10;
        n /= 10;
    }
    return a == b;
}

int demDX(int n){
    int dem=0;
    for(int i=1;i<=n;i++){
        if(isDX(i)) dem++;
    }
    return dem;
}

int main()
{
    int n;
    inputN(n);
    if(isDX(n)) cout<<n<<" la so doi xung!"<<endl;
    else cout<<n<<" khong la so doi xung!"<<endl;
    cout<<"Co "<<demDX(n)<<" so doi xung trong khoang tu 1 den "<<n;
    return 0;
}