//Các toán tử có thể được overload
// + - * / % ^ & | 
// ~	!	=	<	>	+=	-=	*=
// /=	%=	^=	&=	|=	<<	>>	>>=
// <<=	==	!=	<=	>=	&&	||	++
// —	->*	,	->	[]	()	new	delete

#include<bits/stdc++.h>

using namespace std;

class PhanSo{
public:
    PhanSo();
    PhanSo(int m);
    PhanSo(int t, int m);
    PhanSo operator + (const PhanSo tmp);
    
    PhanSo operator - (const PhanSo tmp);

    PhanSo operator * (const PhanSo tmp);

    PhanSo operator / (const PhanSo tmp);

    PhanSo operator++();

    PhanSo operator++(int);

	PhanSo operator--();
	
    PhanSo operator--(int);

    friend istream& operator>>(istream& in, PhanSo& ps);
    
    friend ostream& operator<<(ostream& outputStream, const PhanSo& ps);
private:
    int tu,mau;
};

 

int main()
{
    PhanSo ps1,ps2;
    cout<<"Nhap phan so thu nhat: "<<endl; cin>>ps1;
    cout<<"Nhap phan so thu hai: "<<endl; cin>>ps2;
    cout << ps1 + ps2;
    return 0;
}

PhanSo::PhanSo() : tu(0),mau(1) {}
PhanSo::PhanSo(int t) : tu(t),mau(1) {};
PhanSo::PhanSo(int t, int m) : tu(t),mau(m) {};

//nạp chồng +
PhanSo PhanSo :: operator + (const PhanSo tmp)
{
    return PhanSo(tu*tmp.mau + mau * tmp.tu , mau*tmp.mau);
}

PhanSo PhanSo :: operator - (const PhanSo tmp)
{
    return PhanSo(tu*tmp.mau - mau * tmp.tu , mau*tmp.mau);
}

PhanSo PhanSo :: operator * (const PhanSo tmp)
{
    return PhanSo(tu*tmp.tu, mau*tmp.mau);
}

PhanSo PhanSo::operator / (const PhanSo tmp)
{
    return PhanSo(tu*tmp.mau, mau*tmp.tu);
}

istream& operator>> (istream& in, PhanSo& ps) 
{
    in >> ps.tu >> ps.mau;
    return in;
}

ostream& operator<<(ostream& outputStream, const PhanSo& ps)
{
    outputStream << ps.tu << "/" << ps.mau;
    return outputStream;
}

PhanSo PhanSo::operator++() {
    tu += mau;
    return PhanSo(tu, mau);
}

// ++ hậu tố (tăng sau, trả bản sao)
PhanSo PhanSo::operator++(int)
{
    PhanSo tmp(tu, mau);
    tu += mau;
    return tmp;
}
// int là tham số giả
// Chỉ để phân biệt hậu tố với tiền tố
// Không dùng trong hàm

PhanSo PhanSo::operator--()
{
    tu -= mau;
    return PhanSo(tu,mau);
}

PhanSo PhanSo::operator--(int)
{
    PhanSo tmp(tu, mau);
    tu -= mau;
    return tmp;
}


   
