#include<iostream>
using namespace std;

class TamGiac{
private:
//sử dụng các biến nội bộ nên viết các hàm đấy vào trong private
    double a,b,c;
    bool isTamGiac() const{
        return a+b>c && a+c>b && b+c>a;
    } 
    bool isDeu() const{
        return a==b && a==c;
    }
    bool isCan() const{
        return (a==b || b==c || c==a);
    }
public:
    TamGiac();
    TamGiac(double x); 
    TamGiac(double x,double y);
    TamGiac(double x,double y,double z);
    void xacDinhTamGiac() const;
};

int main()
{
    TamGiac(3,4,5).xacDinhTamGiac(); 
    return 0;
}

TamGiac::TamGiac(double x,double y,double z) :a(x),b(y),c(z) {}
TamGiac::TamGiac(double x,double y): a(x),b(y),c(0){}
TamGiac::TamGiac(double x) : a(x),b(0),c(0){}
TamGiac::TamGiac() :a(0),b(0),c(0) {}

void TamGiac::xacDinhTamGiac() const{
    if(isTamGiac()){
        if(isDeu()) cout<<"Tam giac deu";
        else if(isCan()) cout<<"Tam giac can";
        else cout<<"Tam giac thuong";         
    }else{
        cout<<"Khong la tam giac";
    }
}

