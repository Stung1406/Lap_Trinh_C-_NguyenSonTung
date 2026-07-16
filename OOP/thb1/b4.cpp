#include<iostream>
#include<string>

using namespace std;

class SinhVien{
private:
    string name,classmate,id;
    double mark;
public:
    SinhVien(){
        name = "";
        classmate = "";
        id = "";
        mark = 0;
    }
    void getSinhVien(string n,string c,string i,double m){
        name = n;
        classmate = c;
        id = i;
        mark = m;
    }

    void nhap();
    void xuat() const;
    void diemChu() const;
};


int main()
{
    SinhVien a,b,c;
    cout<<"Nhap sinh vien a"<<endl;
    a.nhap();
    cout<<"Nhap sinh vien b"<<endl;
    b.nhap();
    cout<<"Nhap sinh vien c"<<endl;
    c.nhap();
    cout<<endl; a.xuat(); a.diemChu();
    cout<<endl; b.xuat();
    cout<<endl; c.xuat();
    return 0;
}
//cin.ignore()
void SinhVien::nhap(){
    cout<<"Nhap ten: "; getline(cin,name);
    cout<<"Nhap lop: "; getline(cin,classmate);
    cout<<"Nhap ma sinh vien: "; getline(cin,id);
    cout<<"Nhap diem: "; cin>>mark;
    cin.ignore();
}


void SinhVien::xuat() const{
    cout << "Ten: " << name << endl;
    cout << "Lop: " << classmate << endl;
    cout << "ID: " << id << endl;
    cout << "Diem: " << mark << endl;
}

void SinhVien::diemChu() const{
    if(mark<0 || mark>10) cout<<"Khong hop le";
    else
    {
        if(8.5<=mark<11) cout<<"A";
        else if(7<=mark<8.5) cout<<"B";
        else if(5.5<=mark<=6.9) cout<<"C";
        else if(4.0<=mark<5.5) cout<<"D";
        else cout<<"F";
    }
}
