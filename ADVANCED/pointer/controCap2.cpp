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
    DongVat **ds = nullptr;  // con trỏ cấp 2
    int chon;
    int k = 0;

    while (true) {
        cout << "Thu / Chim / Thoat (1/2/3): ";
        cin >> chon;
        cin.ignore();

        if (chon == 3) break;

        // cấp phát mảng mới (k+1 phần tử)
        DongVat **tmp = new DongVat*[k + 1];

        // sao chép con trỏ cũ
        for (int i = 0; i < k; i++)
            tmp[i] = ds[i];

        // tạo đối tượng mới
        if (chon == 1) tmp[k] = new Thu;
        else if (chon == 2) tmp[k] = new Chim;
        else {
            delete[] tmp;
            continue;
        }

        cin >> *tmp[k];

        // giải phóng mảng cũ
        delete[] ds;

        // trỏ sang mảng mới
        ds = tmp;
        k++;
    }

    // hiển thị
    for (int i = 0; i < k; i++)
        cout << *ds[i];

    // tìm min max
    double min = ds[0]->tinhLuongThucAn();
    double max = min;

    for (int i = 1; i < k; i++) {
        double t = ds[i]->tinhLuongThucAn();
        if (t < min) min = t;
        if (t > max) max = t;
    }

    cout << "Luong thuc an lon nhat: " << max << endl;
    cout << "Luong thuc an be nhat: " << min << endl;

    // giải phóng bộ nhớ
    for (int i = 0; i < k; i++)
        delete ds[i];
    delete[] ds;

    return 0;
}
