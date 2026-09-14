#include<iostream>
#include<string>

using namespace std;

void thayThe(string &str,string s1,string s2){
    int pos = str.find(s1);
    if(pos == -1) cout<<"Khong tim thay xau can thay the trong xau ban dau.";
    else
    {
        str.replace(pos,s1.length(),s2);
        cout<<"Xau sau khi thay the la: "<<str;
    }
}

void chen(string &str,string s1,string s2){
    int pos = str.find(s2);
    if(pos == -1) cout<<"Khong tim thay xau can thay the trong xau ban dau.";
    else
    {
        str.insert(pos,s1 + " ");
        cout<<"Xau sau khi thay the la: "<<str;
    }
}

int main()
{
    string str,s1,s2;
    cout<<"Nhap xau goc: "; getline(cin,str);
    cout<<"Nhap xau can thay the S1: "; getline(cin,s1);
    cout<<"Nhap xau thay the S2: "; getline(cin,s2);

    thayThe(str,s1,s2);
    return 0;
}