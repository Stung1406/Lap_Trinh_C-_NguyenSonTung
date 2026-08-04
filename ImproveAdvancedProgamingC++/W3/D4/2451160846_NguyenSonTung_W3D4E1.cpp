#include<iostream>
#include<string>

using namespace std;

bool isNguyenAm(char c){
    c = tolower(c);
    return c=='u' || c=='e' || c=='a' || c=='o' || c=='i';
}

string ChuoiNguyenAm(string &s){
    string nguyenam = "";
    for(int i=0;i<s.length();i++){
        if(isNguyenAm(s[i]))
        {
            nguyenam += " ";
            nguyenam += s[i];
        }
    }
    return nguyenam;
}

int main()
{
    string s;
    cout<<"Nhap xau: "; getline(cin,s);
    if(ChuoiNguyenAm(s) != "") cout<<"Cac chu cai nguyen am trong xau la:"<<ChuoiNguyenAm(s)<<endl;
    else cout<<"Khong co chu cai nguyen am nao trong xau"<<endl;
    return 0;
}