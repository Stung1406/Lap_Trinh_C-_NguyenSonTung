//dịch các phần tử sang phải  
#include<iostream>
#include<cmath>

using namespace std;

int *nhapArray(int &n){
    cout<<"Nhap so phan tu cua mang: "; cin>>n;
    int *p = new int[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap phan tu thu "<<i+1<<": "; cin>>*(p+i);
    }
    return p;
}

void out(int *&p,int n){
    for(int i=0;i<n;i++){
        cout<<*(p+i)<<" ";
    }
}

void chen(int *&p, int &n) {
    int k, m;
    cout << "\nNhap vi tri can chen (0.." << n << "): ";
    cin >> k;
    cout << "Nhap phan tu can chen: ";
    cin >> m;

    // cấp phát mảng mới lớn hơn 1 phần tử
    int *newArr = new int[n + 1];

    // copy các phần tử trước vị trí k
    for (int i = 0; i < k; i++) {
        newArr[i] = p[i];
    }

    // gán phần tử mới vào vị trí k
    newArr[k] = m;

    // copy các phần tử còn lại
    for (int i = k; i < n; i++) {
        newArr[i + 1] = p[i];
    }

    // giải phóng mảng cũ
    delete[] p;

    // trỏ p sang mảng mới
    p = newArr;
    n++;
}

int main()
{
    int n;
    int *p;
    p=nhapArray(n);
    out(p,n);
    chen(p,n);
    cout<<"Mang sau khi chen: ";
    out(p,n);
    delete[] p;
    return 0;
}