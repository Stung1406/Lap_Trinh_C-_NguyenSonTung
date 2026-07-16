#include<iostream>

using namespace std;

class Nguoi{
private:
	string hoten;		
public:
	virtual void nhap();
	virtual void xuat();
	virtual bool thuong()=0;
	friend ostream& operator<< (ostream& outputStream,Nguoi& n);
	friend istream& operator>> (istream& inputStream,Nguoi& n);
};

class SinhVien : public Nguoi{
public:
	void nhap();
	void xuat();
	bool thuong();
private:
	double dtb;
};

class GiangVien : public Nguoi{
public:
	void nhap();
	void xuat();  
	bool thuong(); 
private:
	int sobaibao;
}; 

class NhanVien : public Nguoi{
public:
	void nhap();
	void xuat();  
	bool thuong(); 
private:
	int songaynghi;
};

int main ()
{
	Nguoi *ds[100];
	int chon,k=0;
	while(true)
	{
		cout<<"GV/SV/NV/Thoat/(1,2,3,4):"; cin>>chon;
		cin.ignore();
		if(chon == 1) ds[k] = new GiangVien;
		if(chon == 2) ds[k] = new SinhVien;
		if(chon == 3) ds[k] = new NhanVien;
		if(chon == 4) break;
		ds[k]->nhap();
		k++;
	}
	for(int i=0;i<k;i++){
		if(ds[i]->thuong()) ds[i]->xuat();
	}
	return 0;
}

void Nguoi :: nhap(){
	cout<<"Nhap ho ten: "; getline(cin,hoten);
}
void Nguoi :: xuat(){
	cout<<"Ho ten: "<<hoten<<endl; 
}

void SinhVien :: nhap(){
	cout<<"Nhap thong tin sinh vien: "<<endl;
	Nguoi :: nhap();
	cout<<"Nhap diem trung binh cua sinh vien: "; cin>>dtb;
}

void SinhVien :: xuat(){
	cout<<"Thong tin sinh vien duoc khen thuong: "<<endl;
	Nguoi :: xuat();
	cout<<"Diem trung binh cua sinh vien la: "<<dtb<<endl;
}
bool SinhVien :: thuong(){
	return dtb>8;
}
void GiangVien::nhap(){
	cout<<"Nhap thong tin giang vien: "<<endl;
	Nguoi :: nhap();
	cout<<"Nhap so bai bao cua giang vien: "; cin>>sobaibao;
}
void GiangVien :: xuat(){
	cout<<"Thong tin giang vien duoc khen thuong: "<<endl;
	Nguoi :: xuat();
	cout<<"So bai bao cua giang vien: "<<sobaibao<<endl;
}   
bool GiangVien :: thuong(){
	return sobaibao>3;
}
void NhanVien::nhap(){
	cout<<"Nhap thong tin nhan vien: "<<endl;
	Nguoi :: nhap();
	cout<<"Nhap so ngay nghi cua nhan vien: "; cin>>songaynghi;
}
void NhanVien :: xuat(){
	cout<<"Thong tin nhan vien duoc khen thuong: "<<endl;
	Nguoi :: xuat();
	cout<<"So ngay nghi cua giang vien: "<<songaynghi<<endl;
}   
bool NhanVien :: thuong(){
	return songaynghi<5;
}


