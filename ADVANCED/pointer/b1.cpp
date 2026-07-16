#include<iostream>
#include<cmath>

using namespace std;

int *pointer(int n){
    int *p=&n;
    return p;
}

int main()
{
    int n=10;
    double m = 1.3;
    cout<<"Dia chi cua n : "<<&n<<endl;
    cout<<"Dia chi cua m: "<<&m<<endl;
    int *p1=&n;
    double *p2=&m;
    //p1,p2 lưu trữ địa chỉ của biến
    //*p1,*p2 lưu trữ giá trị của biến 
    cout<<"Gia tri cua n là: "<<*p1<<endl;
    cout<<"Gia tri cua m là: "<<*p2<<endl;
    cout<<pointer(n);
    return 0;
}
