#include<iostream>
#include<string>



using namespace std;

class DocGia{
public:
	DocGia();
	DocGia(string ht,int m,string l);
	void nhapDl();
	void hienthi();
	string getTen();
	void setTen(string hoten);
	int getMa();
	void getMa(int madg);
	string getLoai();
	void setLoai(string l);
private:
	string hoten;
	int madg;
	string loai;
};

class Sach{
public:
	
private:
	string tensach;
	
};

int main()
{
	
	
	return 0;
}

DocGia :: DocGia() : hoten("Le Thi B"),madg(1000),loai("Sinh Vien"){}
DocGia :: DocGia(string ht,int m,string l) : hoten(ht),madg(m),loai(l){}
void DocGia :: nhapDl(){
	cout<<"Nhap ten : "; 
	getline(cin,hoten);
	cout<<"Nhap ma doc gia: "; cin>>madg;
	cin.ignore();
	cout<<"Nhap loai : "; cin>>loai;
}
void DocGia ::  hienthi(){
	cout<<"Ho ten: "<<hoten;
	cout<<"Ma doc gia: "<<madg;
	cout<<"Loai : "<<loai;
}
string DocGia ::  getTen(){
	return hoten;
}
void  DocGia :: setTen(string ht){
	hoten = ht;
}
int DocGia :: getMa(){
	return madg;
}
void DocGia :: getMa(int m){
	madg=m;
}
string DocGia :: getLoai(){
	return loai;
}
void DocGia :: setLoai(string l){
	loai = l;
}
