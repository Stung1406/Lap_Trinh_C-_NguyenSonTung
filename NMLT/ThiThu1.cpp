#include<iostream>
#include<string>
#include<typeinfo>

using namespace std;

class DongVat{
public:
	virtual double tinhLuongThucAn() = 0;
	virtual void nhap(){
		cout<<"Nhap ten: "; getline(cin,ten);
	}
	virtual void hienThi(){
		cout<<"Ten: "<<ten<<endl;
	}
	friend ostream& operator<< (ostream& outputStream,DongVat& dv);
	friend istream& operator>> (istream& inputStream,DongVat& dv);
private:
	string ten;
};
ostream& operator<< (ostream& outputStream,DongVat& dv){
	dv.hienThi();
	return outputStream;
}
istream& operator>> (istream& inputStream,DongVat& dv){
	dv.nhap();
	return inputStream;
}
class Thu : public DongVat{
public:
	double tinhLuongThucAn(){
		return canNang * 0.1 + doTuoi * 0.05;
	}
	void nhap(){
		DongVat :: nhap();
		cout<<"Nhap can nang: "; cin>>canNang;
		cout<<"Nhap do tuoi: "; cin>>doTuoi;
	}
	void hienThi(){
		DongVat::hienThi();
		cout<<"Can Nang: "<<canNang<<endl;
		cout<<"Do tuoi: "<<doTuoi<<endl;
	}
private:
	double canNang;
	int doTuoi;
};

class Chim : public DongVat{
	public:
		double tinhLuongThucAn(){
			return doDaiCanh * 0.02 + soNgayDeTrung * 0.1;
		}
		void nhap(){
			DongVat :: nhap();
			cout<<"Nhap do dai canh: "; cin>>doDaiCanh;
			cout<<"Nhap so ngay de trung: "; cin>>soNgayDeTrung;
		}
		void hienThi(){
			DongVat::hienThi();
			cout<<"Do dai canh: "<<doDaiCanh<<endl;
			cout<<"So ngay de trung: "<<soNgayDeTrung<<endl;
		}
	private:
		double doDaiCanh;
		int soNgayDeTrung;
};

int main(){
	DongVat *ds[100]; 
	int chon,k=0;
	while(true)
	{
		cout<<"Thu/Chim/Thoat/(1,2,3): "; cin>>chon;
		cin.ignore();
		if(chon==1) ds[k] = new Thu;
		if(chon==2) ds[k] = new Chim;
		if(chon==3) break;
		cin>> *ds[k];
		k++;
	}
	for(int i=0;i<2;i++){
		cout<< *ds[i];
	}
	int min = ds[0]->tinhLuongThucAn();
	int max = ds[0]->tinhLuongThucAn();
	for(int i=1;i<2;i++){
		if(min > ds[i]->tinhLuongThucAn()) min = ds[i]->tinhLuongThucAn();
		if(max < ds[i]->tinhLuongThucAn()) max = ds[i]->tinhLuongThucAn();
	cout<<"Luong thuc an lon nhat: "<<max<<endl;
	cout<<"Luong thuc an be nhat: "<<min<<endl;
	return 0;
 	}
}
