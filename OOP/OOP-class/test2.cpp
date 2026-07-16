#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class TaiLieu {
private:
    int MaTL;
    string TenTL;
    int SoTrang;

public:
    TaiLieu() : MaTL(0), TenTL(""), SoTrang(0) {}
    TaiLieu(int ma, string ten, int trang) : MaTL(ma), TenTL(ten), SoTrang(trang) {}
    
    int getMaTL(){ return MaTL; }
    void setMaTL(int ma) { MaTL = ma; }
    
    string getTenTL(){ return TenTL; }
    void setTenTL(string ten) { TenTL = ten; }
    
    int getSoTrang(){return SoTrang; }
    void setSoTrang(int trang) { SoTrang = trang; }

    friend istream& operator>>(istream& is, TaiLieu& tl) {
        cout << "Nhap Ma TL: "; 
		is >> tl.MaTL;
        is.ignore();
        cout << "Nhap Ten TL: "; 
        getline(is, tl.TenTL);
        cout << "Nhap So trang: "; 
        is >> tl.SoTrang;
        return is;
    }
    
    friend ostream& operator<<(ostream& os,TaiLieu& tl) {
        os << "Ma TL: " << tl.MaTL << endl;
        os << "Ten TL: " << tl.TenTL << endl;
        os << "So trang: " << tl.SoTrang << endl;
        return os;
    }
    
    virtual float tinhPhi(){
        return SoTrang * 500;
    }
    
    friend bool operator==(TaiLieu& tl1,TaiLieu& tl2) {
        return tl1.MaTL == tl2.MaTL;
    }
    
};

class Sach : public TaiLieu {
private:
    string TheLoai;

public:
    Sach() : TaiLieu(), TheLoai("") {}
    Sach(int ma, string ten, int trang, string loai) 
        : TaiLieu(ma, ten, trang), TheLoai(loai) {}
    
    string getTheLoai(){ return TheLoai; }
    void setTheLoai(string loai) { TheLoai = loai; }
    
    friend istream& operator>>(istream& is, Sach& s) {
        is >> (TaiLieu&) s;
        is.ignore();
        cout << "Nhap The loai: "; 
        getline(is, s.TheLoai);
        return is;
    }
    
     friend ostream& operator<<(ostream& os,Sach& s){
        os << (TaiLieu&) s;
        os << "The loai: " << s.TheLoai << endl;
        return os;
    }
    
    float tinhPhi(){
        return getSoTrang() * 500 * 0.8f;
    }
};

class TapChi : public TaiLieu {
private:
    string ChuyenNganh;

public:
    TapChi() : TaiLieu(), ChuyenNganh("") {}
    TapChi(int ma, string ten, int trang, string chuyennganh) : TaiLieu(ma, ten, trang), ChuyenNganh(chuyennganh) {}
    
    string getChuyenNganh() { return ChuyenNganh;}
    void setChuyenNganh(string chuyennganh) { ChuyenNganh = chuyennganh; }
    
    friend istream& operator>>(istream& is, TapChi& tc) {
        is >> (TaiLieu&) tc;
        is.ignore();
        cout << "Nhap Chuyen nganh: "; 
        getline(is, tc.ChuyenNganh);
        return is;
    }
    
     friend ostream& operator<<(ostream& os, TapChi& tc) {
        os << (TaiLieu&) tc;
        os << "Chuyen nganh: " << tc.ChuyenNganh << endl;
        return os;
    }
    
    float tinhPhi() {
        return getSoTrang() * 500 * 1.3f;
    }
};

void nhapTL(TaiLieu *tl)
{
    if (typeid(*tl)==typeid(Sach)) {
		cin >> (Sach&) *tl;    // nhap sau khi ep kieu TaiLieu ve Sach  
	}
	else if (typeid(*tl)==typeid(TapChi)){
		cin >> (TapChi&) *tl;     
	}  
	else cin>>*tl;
}
void inTL(TaiLieu *tl)
{
	if (typeid(*tl)==typeid(TapChi))      
    	cout << (TapChi&)*tl;
    else if (typeid(*tl)==typeid(Sach))      
    	cout << (Sach&)*tl;
    else cout <<*tl;
}
int main() {
	TaiLieu *dsTL[100]; 
    int n;
   
    cout << "Nhap so luong tai lieu: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\nChon loai tai lieu (1-TaiLieu,2-Sach,3-TapChi): ";
        cin >> loai;
        
        if (loai == 1) dsTL[i] = new TaiLieu;
        else if (loai == 2) dsTL[i] = new Sach;
        else if (loai == 3) dsTL[i] = new TapChi;
        else {
            cout << "Loai khong hop le! Vui long nhap lai.\n";
            i--;
            continue;
        }       
        cout << "\nNhap thong tin tai lieu thu " << i + 1 << ":\n";
		nhapTL(dsTL[i]);
    }
    
    cout << "\n=== DANH SACH TAI LIEU VA PHI IN AN ===\n";
    
    for (int i=0;i<n;i++) {
    	inTL(dsTL[i]);  
        cout << "Phi in an: " << dsTL[i]->tinhPhi() << " dong\n";
        cout << "------------------------\n";            
    }
      
	if (n!=0) {
        TaiLieu* tlMax = dsTL[0];
        TaiLieu* tlMin = dsTL[0];
        
        for (int i=0;i<n;i++) {
            if (dsTL[i]->tinhPhi() > tlMax->tinhPhi()) {
                tlMax = dsTL[i];
            }
            if (dsTL[i]->tinhPhi() < tlMin->tinhPhi()) {
                tlMin = dsTL[i];
            }
        }
        
        cout << "\n=== TAI LIEU CO PHI IN AN LON NHAT ===\n";
        inTL(tlMax);
        cout << "Phi in an: " << tlMax->tinhPhi() << " dong\n";
        
        cout << "\n=== TAI LIEU CO PHI IN AN NHO NHAT ===\n";
        inTL(tlMin);
        cout << "Phi in an: " << tlMin->tinhPhi() << " dong\n";
    }
    
    float tongPhi = 0;
    bool coTapChi = false;
    for (int i=0;i<n;i++) {
    	if (typeid(*dsTL[i])==typeid(TapChi)) {
        tongPhi += dsTL[i]->tinhPhi();
        coTapChi = true;
    	}
    }
    if (coTapChi==false) {
        cout << "Khong co Tap chi nao trong danh sach!\n";
    } 
	else cout << "\nTong phi in an cua tat ca tap chi: " << tongPhi << " dong\n";
       
    cout << "\n=== KIEM TRA TRUNG MA TAI LIEU ===\n";
    Sach sachMoi(999, "Sach moi khoi tao", 300, "Cong nghe");
    
    bool trungMa = false;
    for (int i=0;i<n;i++) {
        if (*dsTL[i] == sachMoi) {
            trungMa = true;
            cout << "Tim thay tai lieu trung ma voi Sach moi (MaTL = 999):\n";
            inTL(dsTL[i]);
            cout << "------------------------\n";
        }
    }
    
    if (!trungMa) {
        cout << "Khong co tai lieu nao trung ma voi Sach moi (MaTL = 999)\n";
    }
    return 0;
}
