#include<iostream>
#include<map>
using namespace std;

map<int,long long> Fibonanci;

int fibo1(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    if(n%3==0) return fibo1(n/3 * 2);
    if(n%3==1) return fibo1(n/3 * 2) + fibo1(n/3 * 2 + 1);
    if(n%3==2) return fibo1(n/3 * 2) + fibo1(n/3 * 2 + 1) + fibo1(n/3 * 2 + 2);
}

//toi uu
long long fibo(int n){
    if(n<3) return n;
    auto x = Fibonanci.find(n);
    if(x == Fibonanci.end()){ //tính fibo nếu chưa có trong map
        int k = n/3;
        long long v = fibo(2*k);
        if(n%3 > 0) v+=fibo(2*k+1);
        if(n%3 > 1) v+=fibo(2*k+2);
        Fibonanci[n] = v;
    }
    return Fibonanci[n];
}
// f(10)
// ├─ f(6)
// │   └─ f(4)
// │       ├─ f(2) = 2
// │       └─ f(3)
// │           └─ f(2) = 2
// └─ f(7)
//     ├─ f(4) = 4 (memo)
//     └─ f(5)
//         ├─ f(2) = 2
//         ├─ f(3) = 2
//         └─ f(4) = 4
int main()
{
    int n;
    cout<<"Nhap n = "; cin>>n;
    cout<<"f("<<"n"<<") = "<<fibo(n);
    return 0;
}