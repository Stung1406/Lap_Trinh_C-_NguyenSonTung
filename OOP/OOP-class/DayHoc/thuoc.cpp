
#include<iostream>
#include<string>

using namespace std;

class THUOC {
//private: chỉ truy cập được trong class THUOC
//protected: chỉ truy cập được trong class THUOC và các class kế thừa

private:
    static int dem;  //Mã nhân viên ( tự động tăng)
    int maThuoc;
    string tenThuoc;
    string hangThuoc;
    double gia;

public:
    // nếu mình không khai báo hàm tạo thì trình biên dịch sẽ tự động sinh ra hàm tạo mặc định
    //hàm tạo mặc định
    THUOC() {
        dem++;
        this->maThuoc = dem;
        this->tenThuoc = "";
        this->hangThuoc = "";
        this->gia = 0;
    }

    //hàm tạo có tham số | hàm tạo có tham số | hàm tạo tường minh
    THUOC(int mt, string tt, string ht, double g) {
        dem++;

        // Neu ma thuoc khong hop le thi tu dong tang
        if (mt <= 0) {
            this->maThuoc = dem;
        } else {
            this->maThuoc = mt;

            if (mt > dem) {
                dem = mt;
            }
        }

        this->tenThuoc = tt;
        this->hangThuoc = ht;
        this->gia = g;
    }

    // Ham huy ao
    virtual ~THUOC() {}

    int getMa() {
        return this->maThuoc;
    }

    void setMaThuoc(int mt) {
        this->maThuoc = mt;
    }

    string getTenThuoc() {
        return this->tenThuoc;
    }

    string getHangThuoc() {
        return this->hangThuoc;
    }

    double getGia() {
        return this->gia;
    }

    void setMaThuoc(int mt) {
        this->maThuoc = mt;
    }

    void setTenThuoc(string tt) {
        this->tenThuoc = tt;
    }

    void setHangThuoc(string ht) {
        this->hangThuoc = ht;
    }

    void setGiaThuoc(double g) {
        this->gia = g;
    }
// 3 hàm nhập,xuât,hủy luôn luôn viêt hàm ảo để có thể gọi được hàm nhập,xuất của lớp con
    virtual void nhap() {
        cout << "Nhap ten thuoc: ";
        getline(cin, this->tenThuoc);

        cout << "Nhap hang thuoc: ";
        getline(cin, this->hangThuoc);

        cout << "Nhap gia thuoc: ";
        cin >> this->gia;
        cin.ignore(1000, '\n');
    }

    virtual void xuat() {
        cout << "Ma thuoc: " << this->maThuoc << endl;
        cout << "Ten thuoc: " << this->tenThuoc << endl;
        cout << "Hang thuoc: " << this->hangThuoc << endl;
        cout << "Gia: " << this->gia << endl;
    }

    // Nap chong toan tu so sanh
    friend bool operator==(THUOC& t1, THUOC& t2) {
        return t1.maThuoc == t2.maThuoc;
    }
};

// Dinh nghia bien static
int THUOC::dem = 0;


// Lop thuoc bo
class THUOCBO : public THUOC {
private:
    string congdung;

public:
    THUOCBO() : THUOC() {
        this->congdung = "";
    }

    THUOCBO(int mt, string tt, string ht, double g, string cd)
        : THUOC(mt, tt, ht, g) {
        this->congdung = cd;
    }

    string getCongDung() {
        return this->congdung;
    }

    void setCongDung(string cd) {
        this->congdung = cd;
    }

    //hàm ảo có 2 loại : hàm ảo bình thường và hàm ảo thuần túy
    virtual void nhap() {
        THUOC::nhap();

        cout << "Nhap cong dung: ";
        getline(cin, this->congdung);
    }

    virtual void xuat() {
        THUOC::xuat();
        cout << "Cong dung: " << this->congdung << endl;
    }

    ~THUOCBO() {}
};


// Lop khang sinh
class KHANGSINH : public THUOC {
private:
    string hamluongsd;

public:
    KHANGSINH() : THUOC() {
        this->hamluongsd = "";
    }

    KHANGSINH(int mt, string tt, string ht, double g, string hl)
        : THUOC(mt, tt, ht, g) {
        this->hamluongsd = hl;
    }

    string getHangLuong() {
        return this->hamluongsd;
    }

    void setHangLuong(string hl) {
        this->hamluongsd = hl;
    }

    virtual void nhap() {
        THUOC::nhap();

        cout << "Nhap ham luong: ";
        getline(cin, this->hamluongsd);
    }

    virtual void xuat() {
        THUOC::xuat();
        cout << "Ham luong: " << this->hamluongsd << endl;
    }

    ~KHANGSINH() {}
};


int main() {
    int n;
    THUOC t1,t2;
    if(t1 == t2) cout<<"Hai thuoc giong nhau"<<endl;
    do {
        cout << "Nhap so luong thuoc (1-9): ";
        cin >> n;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            n = 0;
        } else {
            cin.ignore(1000, '\n');
        }

    } while (n <= 0 || n >= 10);

    THUOC* ds[10] = {nullptr};

    for (int i = 0; i < n; i++) {
        int loai;

        cout << "\nNHAP THUOC THU " << i + 1 << endl;
        cout << "1. Thuoc bo" << endl;
        cout << "2. Khang sinh" << endl;

        do {
            cout << "Nhap loai thuoc: ";
            cin >> loai;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                loai = 0;
            } else {
                cin.ignore(1000, '\n');
            }

        } while (loai != 1 && loai != 2);

        if (loai == 1) {
            ds[i] = new THUOCBO();
        } else {
            ds[i] = new KHANGSINH();
        }

        ds[i]->nhap();
    }

    cout << "\n========== DANH SACH THUOC ==========" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nTHUOC THU " << i + 1 << endl;
        ds[i]->xuat();
    }

    // Giai phong bo nho
    for (int i = 0; i < n; i++) {
        delete ds[i];
        ds[i] = nullptr;
    }

    return 0;
}
