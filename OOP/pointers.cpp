#include <iostream>
#include <string>
using namespace std;

struct Sinhvien
{
    string tensv;
    int masv;
    int* diem;
    int n;

    ~Sinhvien() {
        delete[] diem;
    }
};

void khoitaoSv(Sinhvien* ptr);
void hienthiSv(Sinhvien* ptr);

//*********************** Ham main ************************//
int main()
{
    int m;
    cout << "Nhap so luong sinh vien: ";
    cin >> m;
    cin.ignore();
    Sinhvien* ds = new Sinhvien[m];
    for (int i = 0; i < m; i++)
    {
        cout << "\n-----Sinh vien thu " << i + 1 << "-----\n";
        cout << "Co tat ca bao nhieu diem? ";
        cin >> ds[i].n;
        cin.ignore();

        khoitaoSv(&ds[i]);
    }

    for (int i = 0; i < m; i++)
    {
        cout << "\nThong tin sinh vien thu " << i + 1 << ":\n";
        hienthiSv(&ds[i]);
    }

    delete[] ds; // goi ~Sinhvien cho tung phan tu
    return 0;
}

//----------------- Dinh nghia cac ham --------------------//
void khoitaoSv(Sinhvien* ptr)
{
    cout << "Nhap ten sinh vien: ";
    getline(cin, ptr->tensv);

    cout << "Nhap ma sinh vien: ";
    cin >> ptr->masv;

    ptr->diem = new int[ptr->n];

    for (int i = 0; i < ptr->n; i++)
    {
        do {
            cout << "Nhap mot diem: ";
            cin >> ptr->diem[i];
        } while (ptr->diem[i] < 0 || ptr->diem[i] > 10);
    }
}

void hienthiSv(Sinhvien* ptr)
{
    cout << "Ten: " << ptr->tensv << endl;
    cout << "Ma: " << ptr->masv << endl;

    for (int i = 0; i < ptr->n; i++)
        cout << "Diem " << i << ": " << ptr->diem[i] << endl;
}


