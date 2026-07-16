#include<iostream>

using namespace std;

class HuuTi{
public:
    HuuTi();
    
    HuuTi(int m);

    HuuTi(int t,int m);

    HuuTi operator + (HuuTi ht);
    
    HuuTi operator - (HuuTi ht);

    HuuTi operator * (HuuTi ht);

    HuuTi operator / (HuuTi ht);

    friend istream& operator>>(istream &in,HuuTi &sp);
    
    friend ostream& operator<<(ostream &in,HuuTi &sp);

    bool operator ==(const HuuTi& ht) const;
    
    bool operator <(const HuuTi& ht) const;

    bool operator <=(const HuuTi& ht) const;

    bool operator >(const HuuTi& ht) const;

    bool operator >=(const HuuTi& ht) const; 
private:
    int tu,mau;
};

int main()
{
    HuuTi ht1,ht2;

    cout<<"Nhap so phuc thu nhat : "<<endl; cin>>ht1;
    cout<<ht1<<endl;
    cout<<"Nhap so phuc thu hai : "<<endl; cin>>ht2;
    cout<<ht2<<endl;


    if(ht1<ht2) cout<<1;

    int chon;
    HuuTi kq;
    

    cin>>chon;

    switch(chon)
    {
        case 1 : 
            kq=ht1+ht2;
            cout<<"Tong cua 2 phan so: "<<kq<<endl;
            break;
        case 2 :
            kq = ht1 - ht2;
            cout<<"Hieu cua 2 phan so: "<<kq<<endl;
            break;
        case 3 : 
            kq = ht1 * ht2;
            cout<<"Tich cua 2 phan so: "<<kq<<endl;
            break;
        case 4 : 
            kq = ht1 * ht2;
            cout<<"Thuong cua 2 phan so: "<<kq<<endl;
            break;
        case 0 :
            cout<<"Tam biet";
            break;
        default:
            cout<<"Chon khong hop le";
    }

    return 0;
}

HuuTi::HuuTi() : tu(0),mau(1){}

HuuTi::HuuTi(int m) : tu(0),mau(1) {};

HuuTi::HuuTi(int t,int m) : tu(t),mau(m) {};

HuuTi HuuTi::operator + (HuuTi ht){
    return HuuTi(tu*ht.mau+mau*ht.tu,mau*ht.mau);
}
    
HuuTi HuuTi::operator - (HuuTi ht){
    return HuuTi(tu*ht.mau-mau*ht.tu,mau*ht.mau);
}

HuuTi HuuTi::operator * (HuuTi ht){
    return HuuTi(tu*ht.tu,mau*ht.mau);
}

HuuTi HuuTi::operator / (HuuTi ht){
    return HuuTi(tu*ht.mau,mau*ht.tu);
}

istream& operator>>(istream &in,HuuTi &ht){
    cout<<"Nhap tu so: "; in>>ht.tu;
    cout<<"Nhap mau so: "; in>>ht.mau;
    return in;
}
    
ostream& operator<<(ostream &out,HuuTi &ht){
    out<<ht.tu<<"/"<<ht.mau;
    return out;
}

bool HuuTi::operator ==(const HuuTi& ht) const{
    return tu*ht.mau==mau*ht.tu;
}
    
bool HuuTi::operator <(const HuuTi& ht) const{
    return tu*ht.mau < ht.tu * mau;
}

bool HuuTi::operator <=(const HuuTi& ht) const{
    return (tu*ht.mau < ht.tu * mau) || (tu*ht.mau == ht.tu * mau) ;
}

bool HuuTi::operator >(const HuuTi& ht) const{
    return (tu*ht.mau > ht.tu * mau);
}

bool HuuTi::operator >=(const HuuTi& ht) const{
    return (tu*ht.mau > ht.tu * mau) || (tu*ht.mau == ht.tu * mau) ;
} 



