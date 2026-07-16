#include<iostream>

using namespace std;

class HoaDon{
public:
    HoaDon();
    HoaDon(int sl,double gc);
    double tongTien();
    void setGiaCa(double gc);
    void inHoaDon();
private:
    int soLuong;
    double giaCa;
};

class HoaDonKm : public HoaDon{
public:
    HoaDonKm();
    HoaDonKm(int sl,double gc,double gg);
    double thanhToan();
    void inHoaDon();
private:
    double giamGia;
};

int main()
{
	HoaDon hd1(18,38);
	hd1.inHoaDon(); cout<<endl;
	HoaDonKm km1(3,10,5),km2;
	km1.inHoaDon(); cout<<endl;
	km2.inHoaDon(); 
    return 0;
}
HoaDon::HoaDon() : soLuong(1),giaCa(10){}
HoaDon::HoaDon(int sl,double gc) : soLuong(sl),giaCa(gc){}
double HoaDon::tongTien() {return soLuong*giaCa;}
void HoaDon::setGiaCa(double gc)  {giaCa = gc;}
void HoaDon::inHoaDon() 
{
    cout<<"So luong: "<<soLuong<<endl;
    cout<<"Gia ca : "<<giaCa<<endl;
    cout<<"So tien phai thanh toan: "<<tongTien()<<endl;
}
HoaDonKm::HoaDonKm() : HoaDon(),giamGia(2) {} 
HoaDonKm::HoaDonKm(int sl,double gc,double gg) : HoaDon(sl,gc),giamGia(gg) {}
double HoaDonKm::thanhToan(){
	return tongTien() - giamGia;
}
void HoaDonKm::inHoaDon(){
	HoaDon::inHoaDon(); // tan dung toan bo ma da co cua lop cha  
	cout<<"Giam gia: "<<giamGia<<endl;
	cout<<"Hoa don thanh toan: "<<thanhToan();
}
