#include <bits/stdc++.h>
using namespace std;

int ucln(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

bool checkCP(int n){
    if(n<0) return false;
    else{
        int x=sqrt(n);
        if(x*x==n) return true;
        else return false;
    }
}

bool checkNT(int n){
    if(n<2) return false; // nhỏ hơn 2 thì không phải SNT
    else{
        int dem=0;
        for(int i=0;i<n;i++){
            if(n%i==0) dem++;
        }
        if(dem==2) return true;
        else return false;
    }
}

int main() {
    int m,n;
    cout<<"Nhap m: "; cin>>m;
    cout<<"Nhap n: "; cin>>n;
    cout<<"Uoc chung lon nhat cua "<<n<<","<<m<<" la: "<<ucln(m,n)<<endl;
    cout<<"Boi chung nho nhat cua "<<n<<","<<m<<" la: "<< abs(m*n)/ucln(m,n);
    return 0;
}
