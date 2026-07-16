#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;


class TaiLieu {
private:
    int MaTL;
    string TenTL;
    int SoTrang;

public:
    TaiLieu() : MaTL(0), TenTL(""), SoTrang(0) {}
    TaiLieu(int ma, string ten, int trang): MaTL(ma), TenTL(ten), SoTrang(trang) {}

    virtual ~TaiLieu() {cout<<"1234";}

    int getMaTL(){ return MaTL; }
    void setMaTL(int ma) { MaTL = ma;}

    string getTenTL() {return TenTL; }
    void setTenTL(string ten) { TenTL = ten; }

    int getSoTrang() { return SoTrang; }
    void setSoTrang(int trang) { SoTrang = trang; }

    virtual void input(){
        cout << "Nhap Ma TL: ";
        cin >> MaTL;
        cin.ignore();
        cout << "Nhap Ten TL: ";
        getline(cin, TenTL);
        cout << "Nhap So trang: ";
        cin >> SoTrang;
    }

    virtual void output(){
        cout << "Ma TL: " << MaTL << endl;
        cout << "Ten TL: " << TenTL << endl;
        cout << "So trang: " << SoTrang << endl;
    }

    virtual double tinhPhi(){
        return SoTrang * 500;
    }
	
	friend ostream& operator<< (ostream& outputStream,TaiLieu& tl){
		tl.output();
		return outputStream; 
	}
	
	friend istream& operator>> (istream& inputStream,TaiLieu& tl){
		tl.input();
		return inputStream; 
	}
	
    friend bool operator==(const TaiLieu& tl1, const TaiLieu& tl2) {
        return tl1.MaTL == tl2.MaTL;
    }
    
    double operator+ (TaiLieu& tl){
    	return this->tinhPhi() + tl.tinhPhi(); 
	}

	 
};


class Sach : public TaiLieu {
private:
    string TheLoai;

public:
    Sach() : TaiLieu(), TheLoai("") {}
    Sach(int ma, string ten, int trang, string loai)
        : TaiLieu(ma, ten, trang), TheLoai(loai) {}

    ~Sach() {}

    void input() {
        TaiLieu::input();
        cin.ignore();
        cout << "Nhap The loai: ";
        getline(cin, TheLoai);
    }

    void output(){
        TaiLieu::output();
        cout << "The loai: " << TheLoai << endl;
    }

    double tinhPhi(){
        return getSoTrang() * 500 * 0.8f;
    }
};


class TapChi : public TaiLieu {
private:
    string ChuyenNganh;

public:
    TapChi() : TaiLieu(), ChuyenNganh("") {}
    TapChi(int ma, string ten, int trang, string chuyennganh): TaiLieu(ma, ten, trang), ChuyenNganh(chuyennganh) {}

    ~TapChi() {}

    void input(){
        TaiLieu::input();
        cin.ignore();
        cout <<"Nhap Chuyen nganh: ";
        getline(cin, ChuyenNganh);
    }

    void output(){
        TaiLieu::output();
        cout <<"Chuyen nganh: " << ChuyenNganh << endl;
    }

    double tinhPhi(){
        return getSoTrang() * 500 * 1.3f;
    }
};

int main() {
    TaiLieu *danhSachTL[100];
    int n;

    cout <<"Nhap so luong tai lieu: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\nChon loai tai lieu (1-TaiLieu, 2-Sach, 3-TapChi): ";
        cin >> loai;
        if (loai == 1) danhSachTL[i] = new TaiLieu();
        else if (loai == 2) danhSachTL[i] = new Sach();
        else if (loai == 3) danhSachTL[i] = new TapChi();
        else {
            cout <<"Loai khong hop le! Nhap lai.\n";
            i--;
            continue;
        }
		cout << "\nNhap thong tin tai lieu thu " << i + 1 << ":\n";
        cin >> *danhSachTL[i];
    }

    cout << "\n=== DANH SACH TAI LIEU VA PHI IN AN ===\n";
    for (int i = 0; i < n; i++){
        cout << *danhSachTL[i];
        cout << "Phi in an: " << danhSachTL[i]->tinhPhi() << " dong\n";
        cout << "------------------------\n";
    }

	cout<<"Tong phi in an cua hai hinh dau tien la: "<<*danhSachTL[0] + *danhSachTL[1];

    TaiLieu* tlMax = danhSachTL[0];
    TaiLieu* tlMin = danhSachTL[0];

    for (int i = 1; i < n; i++) {
        if (danhSachTL[i]->tinhPhi() > tlMax->tinhPhi())
            tlMax = danhSachTL[i];
        if (danhSachTL[i]->tinhPhi() < tlMin->tinhPhi())
            tlMin = danhSachTL[i];
    }

    cout << "\n=== TAI LIEU CO PHI IN AN LON NHAT ===\n";
    cout<<*tlMax; 
    cout << "Phi in an: " << tlMax->tinhPhi() << " dong\n";
    cout << "\n=== TAI LIEU CO PHI IN AN NHO NHAT ===\n";
    cout<<*tlMin;
    cout << "Phi in an: " << tlMin->tinhPhi() << " dong\n";
    float tongPhi = 0;
    bool coTapChi = false;
    for (int i = 0; i < n; i++) {
        if (typeid(*danhSachTL[i]) == typeid(TapChi)){
            tongPhi += danhSachTL[i]->tinhPhi();
            coTapChi = true;
        }
    }

    if (coTapChi) cout << "\nTong phi in an cua tat ca TapChi: " << tongPhi << " dong\n";
    else cout << "Khong co TapChi nao trong danh sach!\n";

    cout << "\n=== KIEM TRA TRUNG MA TAI LIEU ===\n";
    Sach sachMoi(999, "Sach moi khoi tao", 300, "Cong nghe");

    bool trungMa = false;
    for (int i = 0; i < n; i++) {
        if (*danhSachTL[i] == sachMoi) {
            trungMa = true;
            danhSachTL[i]->output();
        }
    }

    if (!trungMa) cout << "Khong co tai lieu nao trung ma voi Sach moi (MaTL = 999)\n";
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(danhSachTL[i]->tinhPhi() > danhSachTL[j]->tinhPhi()){
				TaiLieu *tmp = danhSachTL[i];
				danhSachTL[i] = danhSachTL[j];
				danhSachTL[j] = tmp;
			}
		}
	}
	cout << "\n=== DANH SACH TAI LIEU SAP XEP GIAM DAN ===\n";
    for (int i = 0; i < n; i++){
        cout << *danhSachTL[i];
        cout << "Phi in an: " << danhSachTL[i]->tinhPhi() << " dong\n";
        cout << "------------------------\n";
    }
    
    for (int i = 0; i < n; i++) {
        delete danhSachTL[i];
    }

    return 0;
}

