#include<iostream>
#include<string>

using namespace std;

class SinhVien{
public:
	SinhVien();
	SinhVien(string t,int m,char gt);
	void nhapDL();
	void hienThi();
	string getTen(); 
	int getMa();
	char getGioiTinh();
	void setTen(string t);
	void setMa(int m);
	void setGioiTinh(char gt);
private:
	string tensv;
	int masv;
	char gioitinh;
};

class KhoaHoc{
public:
	KhoaHoc();
	KhoaHoc(string t,int hk,string md);
	void nhapDl();
	void hienThi();
	string getTen();
	void setTen(string t);
	int getHocKy();
	void setHocKy(int hk);
	string getMucDo();
	void setMucDo(string md);
private:
	string tenkh;
	int hocky;
	string mucdo;
};

class HocBong : public SinhVien,public KhoaHoc{
public:
	HocBong();
	HocBong(string t1,int m,char gt,string t2,int hk,string md,double gtr);
	double getGiaTri();
	void setGiaTri(double gt);
	void nhapDL();
	void hienthi();
private:
	double giatri;
};

int main()
{
	HocBong hocbong;
	hocbong.nhapDL();
	hocbong.hienthi();
	cout<<endl;
	hocbong.SinhVien::setTen("Nguyen Son Bach");
	hocbong.hienthi();
	return 0;
}

SinhVien::SinhVien() : tensv("Nguyen Van A"),masv(1),gioitinh('M') {}
SinhVien::SinhVien(string t,int m,char gt) : tensv(t),masv(m),gioitinh(gt){}
void SinhVien::nhapDL(){
	cout<<"Nhap ten: "; 
	getline(cin,tensv);
	cout<<"Nhap ma sinh vien: "; cin>>masv;
	cin.ignore();
	cout<<"Nhap gioi tinh: "; cin>>gioitinh;
}
void SinhVien::hienThi(){
	cout<<"Ten: "<<tensv<<endl;
	cout<<"MaSv: "<<masv<<endl;
	cout<<"Gioi tinh : "<<gioitinh<<endl;
}
string SinhVien::getTen(){
	return tensv;
}
int SinhVien::getMa(){
	return masv;
}
char SinhVien::getGioiTinh(){
	return gioitinh;
}
void SinhVien::setTen(string t){
	tensv=t;
}
void SinhVien::setMa(int m){
	masv=m;
}
void SinhVien::setGioiTinh(char gt){
	gioitinh=gt;
}

KhoaHoc :: KhoaHoc() : tenkh("Ky su Cong Nghe thong tin"),hocky(1),mucdo("Trung binh"){}
KhoaHoc :: KhoaHoc(string t,int hk,string md) : tenkh(t),hocky(hk),mucdo(md) {}
void KhoaHoc::nhapDl(){
	cin.ignore();
	cout<<"Nhap ten khoa hoc: "; getline(cin,tenkh);
	cout<<"Nhap hoc ky: "; cin>>hocky;
	cin.ignore();
	cout<<"Nhap muc do: "; getline(cin,mucdo);
}
void KhoaHoc :: hienThi(){
	cout<<"Ten khoa hoc: "<<tenkh<<endl;
	cout<<"Hoc ky: "<<hocky<<endl;
	cout<<"Muc do: "<<mucdo<<endl;
}
string KhoaHoc :: getTen(){
	return tenkh;
}
void KhoaHoc :: setTen(string t){
	tenkh=t;
}
int KhoaHoc::getHocKy(){
	return hocky;
}
void KhoaHoc::setHocKy(int hk){
	hocky=hk;
}
string KhoaHoc ::  getMucDo(){
	return mucdo;
}
void KhoaHoc::setMucDo(string md){
	mucdo=md;
}
HocBong :: HocBong() : SinhVien(),KhoaHoc(),giatri(30000000){}
HocBong :: HocBong(string t1,int m,char gt,string t2,int hk,string md,double gtr) : SinhVien(t1,m,gt),KhoaHoc(t2,hk,md),giatri(gtr) {}
double HocBong :: getGiaTri(){
	return giatri;
}
void HocBong :: setGiaTri(double gtr){
	giatri=gtr;
}
void HocBong::nhapDL(){
	SinhVien::nhapDL();
	KhoaHoc::nhapDl();
	cout<<"Nhap gia tri hoc bong: "; cin>>giatri;
}
void HocBong::hienthi(){
	SinhVien::hienThi();
	KhoaHoc::hienThi();
	cout<<"Gia tri hoc bong: "<<giatri;
}
