#include<iostream>
#include<cmath>

using namespace std;

void inputN(int &n){
    do{
        cout<<"Nhap n = "; cin>>n;
    }while(n<=5 || n>=20);
}

bool isCP(int x){
    int can = sqrt(x);
    return can * can == x;
}

void inputArray(int n,int a[])
{
    for(int i=0;i<n;i++){
        cout<<"So thu "<<i+1<<": "; cin>>a[i];
    }
}

void outputArray(int n,int a[]){
    for(int i=0;i<n;i++){
        cout<<" "<<a[i];
    }
}

int demCP(int n,int a[]){
    int dem = 0;
    for(int i=0;i<n;i++){
        if(isCP(a[i])) dem++;
    }
    return dem;
}

int maxArray(int n,int a[]){
    int max = a[0];
    for(int i=0;i<n;i++){
        if(max < a[i]) max = a[i];
    }
    return max;
}

int maxCP(int n,int a[]){
    int max = 0;
    for(int i=0;i<n;i++){
        if(max < a[i] && isCP(a[i])) max = a[i];
    }
    return max;
}

int main()
{
    int n,a[100];
    inputN(n);
    inputArray(n,a);
    cout<<endl<<"Day so:";
    outputArray(n,a);
    cout<<endl<<endl;
    cout<<"So max = "<<maxArray(n,a)<<endl;
    if(demCP(n,a) == 0) cout<<"Day khong co so chinh phuong"<<endl;
    else cout<<"So chinh phuong lon nhat: "<<maxArray(n,a);
    return 0;
}
