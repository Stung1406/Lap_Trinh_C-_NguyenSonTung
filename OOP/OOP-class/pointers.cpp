#include <iostream>
#include <string>
using namespace std;

struct Sinhvien {
    string tensv;
    int masv;
    int diem[3];
};

void khoitaoSv(Sinhvien* ptr);
void hienthiSv(Sinhvien* ptr);

int main() {
    Sinhvien sv;
    Sinhvien* svPtr = &sv;

    khoitaoSv(svPtr);
    hienthiSv(svPtr);

    return 0;
}

void khoitaoSv(Sinhvien* ptr) {
    cout << "Nhap ten sinh vien: ";
    cin >> ptr->tensv;

    cout << "Nhap ma sinh vien: ";
    cin >> ptr->masv;

    for (int i = 0; i < 3; i++) {
        do {
            cout << "Nhap mot diem: ";
            cin >> ptr->diem[i];
        } while (ptr->diem[i] < 0 || ptr->diem[i] > 10);
    }
}

void hienthiSv(Sinhvien* ptr) {
    cout << "Thong tin sinh vien:\n";
    cout << "Ten: " << ptr->tensv << endl;
    cout << "Ma: " << ptr->masv << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Diem " << i << ": " << ptr->diem[i] << endl;
    }
}
