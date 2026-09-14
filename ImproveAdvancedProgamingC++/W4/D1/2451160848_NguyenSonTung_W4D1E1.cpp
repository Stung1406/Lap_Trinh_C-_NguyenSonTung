#include<iostream>
#include<string>

using namespace std;

struct SanPham{
    string maSp;
    int namSx;
};

SanPham inputSanPham(SanPham sp){
    cout<<"Ma: "; cin>>sp.maSp;
    cout<<"Nam: "; cin>>sp.namSx;
    return sp;
}

void inputArr(int n,SanPham sp[]){
    for(int i=0;i<n;i++){
        sp[i] = inputSanPham(sp[i]);
    }
}

bool coNam(int n,SanPham sp[],int year){
    for(int i=0;i<n;i++){
        if(sp[i].namSx == year) return true;
    }
    return false;
}

void inSP(int n,SanPham sp[],int year){
    for(int i=0;i<n;i++){
        if(sp[i].namSx == year) cout<<sp[i].maSp<<"\t"<<sp[i].namSx<<endl;
    }
}

int main()
{
    int n,y;
    SanPham sp[100];
    cout<<"N = "; cin>>n;
    inputArr(n,sp);
    cout<<"Nam can tim: "; cin>>y;
    if(coNam(n,sp,y))
    {
        cout<<"Ket qua:"<<endl;
        inSP(n,sp,y);
    }else cout<<"Khong tim thay.";
    return 0;
}