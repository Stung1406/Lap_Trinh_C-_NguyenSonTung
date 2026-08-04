#include <bits/stdc++.h>

using namespace std;

bool isNguyenAm(char c){
    c = tolower(c);
    return c=='u' || c=='e' || c=='a' || c=='o' || c=='i';
}

int demNguyenAm(string s){
    int dem = 0;
    for(int i=0;i<s.size();i++){
        if(isNguyenAm(s[i])) dem++;
    }
    return dem;
}

int demKiTuKhac(string s){
    int dem = 0;
    for(int i=0;i<s.size();i++){
        if(!isalpha(s[i])) dem++;
    }
    return dem;
}

int demPhuAm(string s){
    int dem = 0;
    for(int i=0;i<s.size();i++){
        if(!isNguyenAm(s[i]) && isalpha(s[i])) dem++;
    }
    return dem;
}



int main(){
    string s;
    cout<<"Nhap xau: "; getline(cin,s);
    cout<<"Nguyen am: "<<demNguyenAm(s)<<endl;
    cout<<"Phu am: "<<demPhuAm(s)<<endl;
    cout<<"Ky tu khac: "<<demKiTuKhac(s);
}