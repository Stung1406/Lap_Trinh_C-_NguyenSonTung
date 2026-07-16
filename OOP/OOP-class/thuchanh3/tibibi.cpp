#include<iostream>
#include<string>

using namespace std;

class DichVu{
private:
	int MaDV;
	string TenDV;
	double KhoiLuong;
public:
	DichVu() : MaDV(0),TenDV(""),KhoiLuong(0.0) {}
	DichVu(int ma,string ten,double kl) : MaDV(ma),TenDV(ten),KhoiLuong(kl) {}
	int getMaDV(){
		return MaDV; 
	}
	void setMaDV(int ma){
		MaDV = ma;
	}
	string getTenDV(){
		return TenDV;
	}
	void setTenDV(string ten){
		TenDV = ten;
	}
	double getKhoiLuong(){
		return KhoiLuong;
	}
	void setKhoiLuong(double kl){
		KhoiLuong = kl;
	}
	virtual void input(){
		cout<<"Nhap ma dich vu: "; cin>>MaDV;
		cin.ignore();
		cout<<"Nhap ten dich vu: "; getline(cin,TenDV);
		cout<<"Nhap khoi luong: "; cin>>KhoiLuong;
	}
	virtual void output(){
		cout<<"Ma dich vu: "<<MaDV<<endl;
		cout<<"Ten dich vu: "<<TenDV<<endl;
		cout<<"Khoi luong: "<<KhoiLuong<<endl;
	}
	virtual void tinhCuoc(){
		return KhoiLuong * 10000;
	}
};

class ChuyenNhanh : public DichVu{
private:
	int ThoiGianGiao;
public:
	ChuyenNhanh() : DichVu(),ThoiGianGiao(0){}
	ChuyenNhanh(int ma,string ten,double kl,int tg) : DichVu(ma,ten,kl),ThoiGianGiao(tg) {}
	int getThoiGianGiao(){
		return ThoiGianGiao;
	}
	void setThoiGianGiao(int tg){
		ThoiGianGiao = tg;
	}
	void input(){
		DichVu :: input();
		cout<<"Nhap thoi gian giao: "; cin>>ThoiGianGiao;
	}
	void output(){
		DichVu :: output();
		cout<<"Thoi gian giao: "<<ThoiGianGiao<<endl;
	}
};

class ChuyenTietKiem{
private:
	int SoNgayGiao;
public:
	ChuyenTietKiem() : DichVu(),SoNgayGiao(0){}
	ChuyenTietKiem(int ma,string ten,double kl,int tg,int songay) : {}
	void input(){
		DichVu::input();
		cout<<""
	}
};

int main()
{
	
	return 0;
}
