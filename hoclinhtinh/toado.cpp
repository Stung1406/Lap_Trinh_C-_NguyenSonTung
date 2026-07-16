#include<bits/stdc++.h>

using namespace std;

struct Toado{
    double tung;
    double hoanh;
};

Toado nhapToado(Toado &p){
    cout<<"Tung: "; cin>>p.tung;
    cout<<"Hoanh: "; cin>>p.hoanh;
    return p;
}

double doDai(Toado p){
    return sqrt(p.tung*p.tung +p.hoanh*p.hoanh);
}

void nhapCacToaDo(int &n,double distance[]){
    for(int i=0;i<n;i++){
        char c='A'+ i;
        cout<<"Nhap toa do thu "<<c<<endl;
        Toado b = nhapToado(b);
        distance[i]=doDai(b);
    }
}

double ganNhat(int n,double distance[]){
    double min = distance[0];
    for(int i=0;i<n;i++){
        if(min>distance[i]) min=distance[i];
    }
    return min;
}

int main()
{
    int n;
    cout<<"Nhap so diem: "; cin>>n;
    double d[100];
    nhapCacToaDo(n,d);
    cout<<ganNhat(n,d);
}