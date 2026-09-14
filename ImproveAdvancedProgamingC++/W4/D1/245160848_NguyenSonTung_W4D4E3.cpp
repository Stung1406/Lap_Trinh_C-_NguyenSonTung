#include<iostream>
#include<string>

using namespace std;

struct SinhVien{
    string maSv;
    string hoTen;
    string lop;
    double diem;
    double diemTongKet;
};

void inputSinhVien(SinhVien &sinhvien){
    cout<<"Ma sinh vien: "; getline(cin,sinhvien.maSv);
    if(sinhvien.maSv == ".") return;
    cout<<"Ho ten: "; getline(cin,sinhvien.hoTen);
    cout<<"Lop: "; getline(cin,sinhvien.lop);
    cout<<"Diem: "; cin>>sinhvien.diem;
    cout<<"Diem tong ket: "; cin>>sinhvien.diemTongKet;
    cin.ignore();
}

void outputSinhVien(SinhVien sv){
    cout<<sv.maSv<<"\t"<<sv.hoTen<<"\t"<<sv.lop<<"\t"<<sv.diem<<"\t"<<sv.diemTongKet;
}

void inputArr(SinhVien *&sv, int &n){
    sv = new SinhVien[100];
    n = 0;
    while(true){
        inputSinhVien(*(sv + n));
        if((sv + n)->maSv == ".") break;
        n++;
    }
}

void outputArr(int n,SinhVien *sv){
    cout<<"MaSv"<<"\t"<<"Ten Sv"<<"\t"<<"Lop"<<"\t"<<"Diem"<<"\t"<<"Diem tong ket"<<endl;
    for(int i=0;i<n;i++){
        outputSinhVien(*(sv + i));
        if(i!=n-1) cout<<endl;
    }
}

void dsTheoLop(SinhVien *sv, int n, string lop){
    for(int i=0;i<n;i++){
        if((sv + i)->lop == lop) outputSinhVien(*(sv+i));
    }

}

double diemCaoNhat(SinhVien *sv,int n){
    double max = (sv + 0)->diemTongKet;
    for(int i=1;i<n;i++){
        if((sv + i)->diemTongKet > max) max = (sv + i)->diemTongKet;
    }
    return max;
}

void dsDiemCaoNhat(SinhVien *sv, int n){
    cout<<"Danh sach sinh vien co diem cao nhat"<<endl;
    for(int i=0;i<n;i++){
        if((sv + i)->diemTongKet == diemCaoNhat(sv,n)){
            outputSinhVien(*(sv + i));
            cout<<endl;
        }
    }
}

double diemCaoNhatLop(SinhVien *sv,int n,string lop){
    double max = -1e9;
    bool found = false;
    for(int i=0;i<n;i++){
        if((sv + i)->lop == lop){
            if(!found || (sv + i)->diemTongKet > max){
                max = (sv + i)->diemTongKet;
                found = true;
            }
        }
    }
    return max;
}

void dsDiemCaoNhatLop(SinhVien *sv, int n, string lop){
    string processed[100];
    int processedCount = 0;
    for(int i = 0; i < n; i++){
        string currentLop = (sv + i)->lop;
        bool seen = false;
        for(int j = 0; j < processedCount; j++){
            if(processed[j] == currentLop){
                seen = true;
                break;
            }
        }
        if(seen) continue;
        processed[processedCount++] = currentLop;

        double max = diemCaoNhatLop(sv,n,currentLop);
        for(int j = 0; j < n; j++){
            if((sv + j)->lop == currentLop && (sv + j)->diemTongKet == max){
                outputSinhVien(*(sv + j));
                cout<<endl;
            }
        }
    }
}


int main()
{
    SinhVien *sv;
    int n = 0;
    cout<<"Nhap danh sach sinh vien: "<<endl;
    inputArr(sv,n);

    cout<<"\nDanh sach sinh vien vua nhap: "<<endl;
    outputArr(n,sv);

    string lop;
    cout<<"\nNhap lop can in: ";
    cin.ignore();
    getline(cin,lop);
    cout<<"Danh sach sinh vien lop "<<lop<<"la:"<<endl;
    dsTheoLop(sv,n,lop);

    cout<<"Danh sach sinh vien co diem cao nhat cac lop:"<<endl;
    dsDiemCaoNhat(sv,n);

    cout<<"Danh sach sinh vien co diem cao nhat moi lop:"<<endl;
    dsDiemCaoNhatLop(sv,n,lop);

    delete [] sv;
    return 0;
}