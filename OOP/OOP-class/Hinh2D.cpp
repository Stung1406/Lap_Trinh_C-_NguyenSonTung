#include<iostream>
#include<string>

using namespace std;

class Hinh2D{
private:
	string mausac;
public:
	Hinh2D() : mausac("") {}
	Hinh2D(string ms) : mausac(ms) {}
	string getMauSac() const{
		return mausac;
	}
	void setMauSac(string ms){
		mausac = ms;
	}
	virtual void nhap(){
		cout<<"Nhap mau sac: "; getline(cin,mausac);
	}
	virtual void xuat() const{
		cout<<"Mau sac: "<<mausac<<endl;
	}
	virtual double tinhdientich() const = 0;
};

class HinhTron : Hinh2D{
private:
	double bankinh;
public:
	HinhTron() : Hinh2D(),bankinh(0) {}
	HinhTron(string ms,double bk) : Hinh2D(ms),bankinh(bk){}
	void nhap(){
		Hinh2D::nhap();
		cout<<"Nhap ban kinh: "; cin>>bankinh;
	}
	void xuat() const{
		Hinh2D::xuat();
		cout<<"Ban kinh: "<<bankinh;
	}
	double tinhdientich() override{
		
	}
};

int main()
{
	
	return 0;
}
