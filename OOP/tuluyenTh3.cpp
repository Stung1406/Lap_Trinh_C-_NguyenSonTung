#include<iostream>
#include<string>

using namespace std;

class NhanVien{
public:
	NhanVien();
	NhanVien(string ht,int m,string cv);
	void nhapDL();
	void hienThi();
	string getHoTen();
	void setHoTen(string ht);
	int getMa();
	void setMa(int m);
	string getChucVu();
	void setChucVu(string cv);
private:
	string hoten;
	int manv;
	string chucvu;
};

class DuAn{
public:
	DuAn();
	DuAn(string t,int th,string md);
	void nhapDL();
	void hienThi();
	string getTenDa();
	void setTenDa(string t);
	int getThoiHan();
	void setThoiHan(int th);
	string getMucDo();
	void setMucDo(string md);
private:
	string tenduan;
	int thoihan;
	string mucdo;
};

class Thuong : public NhanVien,public DuAn{
public:
	Thuong();
	Thuong(string ht,int m,string cv,string t,int th,string md,double st);
	void nhapDL();
	void hienthi();
	double getSoTien();
	void setSoTien(double st);
private:
	double sotien;
};

int main()
{
	Thuong thuong1;
	thuong1.nhapDL();
	thuong1.hienthi();
	return 0;
}
NhanVien::NhanVien() : hoten("Tran Thi B"),manv(101),chucvu("Nhan Vien") {}
NhanVien::NhanVien(string ht,int m,string cv) : hoten(ht),manv(m),chucvu(cv){}
void NhanVien::nhapDL(){
	cout<<"Nhap ten: "; 
	cin.ignore();
	getline(cin,hoten);
	cout<<"Nhap ma nv: "; cin>>manv;
	cout<<"Nhap chuc vu : "; 
	cin.ignore();
	getline(cin,chucvu);
}
void NhanVien :: hienThi(){
	cout<<"Ten: "<<hoten<<endl;
	cout<<"Ma NV: "<<manv<<endl;
	cout<<"Chuc vu: "<<chucvu<<endl;
}
string NhanVien :: getHoTen(){
	return hoten;
}
void NhanVien :: setHoTen(string ht){
	hoten=ht;
}
int NhanVien :: getMa(){
	return manv;
}
void NhanVien :: setMa(int m){
	manv=m;
}
string NhanVien :: getChucVu(){
	return chucvu;
}
void NhanVien :: setChucVu(string cv){
	chucvu=cv;
}


DuAn :: DuAn() : tenduan("He thong quan ly nhan su"),thoihan(6),mucdo("Cao"){}
DuAn :: DuAn(string t,int th,string md) : tenduan(t),thoihan(th),mucdo(md){}
void DuAn :: nhapDL(){
	cout<<"Nhap ten du an : ";
	cin.ignore();
	getline(cin,tenduan);
	cout<<"Nhap thoi han du an: "; cin>>thoihan;
	cout<<"Nhap thoi muc do an : ";
	cin.ignore();
	getline(cin,mucdo);
}
void DuAn :: hienThi(){
	cout<<"Ten du an : "<<tenduan<<endl;
	cout<<"Thoi han du an : "<<thoihan<<endl;
	cout<<"Muc do du an: "<<mucdo<<endl;
}
string DuAn :: getTenDa(){
	return tenduan;
}
void DuAn :: setTenDa(string t){
	tenduan=t;
}
int DuAn :: getThoiHan(){
	return thoihan;
}
void DuAn :: setThoiHan(int th){
	thoihan=th;
}
string DuAn :: getMucDo(){
	return mucdo;
}
void DuAn :: setMucDo(string md){
	mucdo=md;
}

Thuong :: Thuong() : NhanVien(),DuAn(),sotien(15000000){}
Thuong :: Thuong(string ht,int m,string cv,string t,int th,string md,double st) : NhanVien(ht,m,cv),DuAn(t,th,md),sotien(st) {}
void Thuong :: nhapDL(){
	NhanVien::nhapDL();
	DuAn::nhapDL();
	cout<<"Nhap luong thuong: "; cin>>sotien;
}
void Thuong :: hienthi(){
	NhanVien::hienThi();
	DuAn::hienThi();
	cout<<"Luong thuong cua nhan vien la: "<<sotien<<endl;
}
double Thuong :: getSoTien(){
	return sotien;
}
void Thuong :: setSoTien(double st){
	sotien = st;
}
