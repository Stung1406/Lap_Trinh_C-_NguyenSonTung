#include<iostream>

using namespace std;

int demKiTuSo(string s){
    int dem = 0;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])) break;
    }
    return dem;
}

void printKiTuSo(string s){
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])) cout<<" "<<s[i];
    }
}

int main()
{
    string s;
    cout<<"Nhap xau: "; getline(cin,s);
    if(demKiTuSo(s) == 0) cout<<"Khong co ki tu nao la chu so trong xau."<<endl;
    else
    {
        cout<<"Cac ki tu la chu so trong xau la: ";
        printKiTuSo(s);
        cout<<endl;
    }
    return 0;
}