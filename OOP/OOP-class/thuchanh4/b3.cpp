#include<iostream>
#include<cmath>
#include<string>

using namespace std;

class Hinh2D{
public:
	Hinh2D();
	Hinh2D(string s);
	string getMauSac();
	void setMauSac(string s);
	virtual void nhap();
	virtual void xuat();
	virtual double tinhdientich() const = 0;
	friend double operator + (Hinh2D& h1,Hinh2D& h2);
	friend bool operator < (Hinh2D& h1,Hinh2D& h2);
	friend ostream& operator<< (ostream& outputStream,Hinh2D& h);
	friend istream& operator>> (istream& inputStream,Hinh2D& h);
private:
	string mausac;
};

class HinhTron : public Hinh2D{
private: 
	double bankinh;
public:
	HinhTron();
	HinhTron(string s,double bk);
	void nhap();
	void xuat();
	double tinhdientich();	
};

class HinhChuNhat : public Hinh2D{
private:
	double chieuDai,chieuRong;
public:
	HinhChuNhat();
	HinhChuNhat(string s,double cd,double cr);
	void nhap();
	void xuat();
	double tinhdientich();
};

class HinhTamGiac : public Hinh2D{
private:
	double a,b,c; 
public:
	HinhTamGiac();
	HinhTamGiac(string s,double x,double y,double z);
	void nhap();
	void xuat();
	double tinhdientich();
};

int main()
{
	Hinh2D *ds[100]; 
	int k = 0,chon;
	while(true)
	{
		cout<<"\n*Hinh tron/Hinh chu nhat/Hinh tam giac/Thoat (1,2,3,4):";
		cin>>chon; cin.ignore();
		if (chon==4) break;
		if (chon==1) ds[k]=new HinhTron();
		if (chon==2) ds[k]=new HinhChuNhat();
		if (chon==3) ds[k]=new HinhTamGiac();
		cin>> *ds[k];
		k++;
	} 
	double sum=0;
	cout<<"Thong tin cac hinh vua nhap: ";
	for(int i=0;i<k;i++){
		cout<<*ds[i];
		cout<<endl;
		sum += ds[i]->tinhdientich();
	} 
	Hinh2D *dienTichLonNhat = ds[0];
	for(int i=0;i<k;i++){
		if(dienTichLonNhat->tinhdientich() < ds[i]->tinhdientich()) dienTichLonNhat = ds[i];
	}
	cout<<"Hinh 2D co dien tich lon nhat la: "<<endl;
	dienTichLonNhat->xuat();
	
	if(*ds[0] < *ds[1]) cout<<"1";
	else cout<<"0";
	
	cout<<"\nDien tich 2 hinh dau tien la: "<<*ds[0] + *ds[1];
	
	cout<<"\nTong dien tich cac hinh vua nhap la: "<<sum;
	return 0;
}
double operator + (Hinh2D& h1,Hinh2D& h2){
	return h1.tinhdientich() + h2.tinhdientich();
}

bool operator < (Hinh2D& h1,Hinh2D& h2){
	return h1.tinhdientich() < h2.tinhdientich();
}

ostream& operator<< (ostream& outputStream,Hinh2D &h){
	h.xuat();
	return outputStream;
}

istream& operator>> (istream& inputStream,Hinh2D &h){
	h.nhap();
	return inputStream;
}

Hinh2D :: Hinh2D() : mausac(""){}
Hinh2D :: Hinh2D(string s) : mausac(s) {}
string Hinh2D :: getMauSac(){
	return mausac;
}
void Hinh2D :: setMauSac(string s){
	mausac = s;
}
void Hinh2D :: nhap(){
	cout<<"Nhap mau sac: "; 
	getline(cin,mausac);
}
void Hinh2D :: xuat(){
	cout<<"Mau sac: "<<mausac<<endl;
}

HinhTron :: HinhTron() : Hinh2D(),bankinh(0) {}
HinhTron :: HinhTron(string s,double bk) : Hinh2D(s),bankinh(bk) {}
void HinhTron::nhap(){
	Hinh2D::nhap();
	cout<<"Nhap ban kinh: "; cin>>bankinh;
}

double HinhTron :: tinhdientich() override{
	return 3.14 * bankinh * bankinh;	
}

void HinhTron::xuat(){
	Hinh2D::xuat();
	cout<<"Ban kinh : "<<bankinh<<endl;
	cout<<"Dien tich hinh tron la : "<<tinhdientich()<<endl;
}

HinhChuNhat::HinhChuNhat() : Hinh2D(),chieuDai(0.0),chieuRong(0.0) {}
HinhChuNhat::HinhChuNhat(string s,double cd,double cr) : Hinh2D(s),chieuDai(cd),chieuRong(cr){}

void HinhChuNhat :: nhap(){
	Hinh2D::nhap();
	cout<<"Nhap chieu dai: "; cin>>chieuDai;
	cout<<"Nhap chieu rong: "; cin>>chieuRong;
}

void HinhChuNhat :: xuat(){
	Hinh2D::xuat();
	cout<<"Chieu dai: "<<chieuDai<<endl;
	cout<<"Chieu rong: "<<chieuRong<<endl;
	cout<<"Dien tich hinh chu nhat: "<<tinhdientich()<<endl;
}

double HinhChuNhat :: tinhdientich(){
	return chieuDai * chieuRong;
}


HinhTamGiac :: HinhTamGiac() : Hinh2D(),a(0.0),b(0.0),c(0.0){}
HinhTamGiac :: HinhTamGiac(string s,double x,double y,double z) : Hinh2D(s),a(x),b(y),c(z){}
void HinhTamGiac :: nhap(){
	Hinh2D::nhap();
	cout<<"Nhap canh thu nhat: "; cin>>a;
	cout<<"Nhap canh thu hai: "; cin>>b;
	cout<<"Nhap canh thu ba: "; cin>>c;
}
void HinhTamGiac :: xuat(){
	Hinh2D::xuat();
	cout<<"Canh thu nhat: "<<a<<endl;
	cout<<"Canh thu hai: "<<b<<endl;
	cout<<"Canh thu ba: "<<c<<endl;
	cout<<"Dien tich hinh tam giac: "<<tinhdientich()<<endl;
}
double HinhTamGiac :: tinhdientich(){
	double p = (a+b+c) / 2;
	return 	sqrt(p*(p-a)*(p-b)*(p-c)); 
}


