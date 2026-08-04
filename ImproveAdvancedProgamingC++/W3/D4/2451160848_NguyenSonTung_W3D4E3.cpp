#include<iostream>
#include<string>

using namespace std;

void xoaChan(string &s){
    for(int i=s.length() - 1;i>=0;i--){
        if(i%2==0){
            s.erase(i,1);
        }
    }
}

int main()
{
    string s;
    cout<<"Nhap xau S: "; getline(cin,s);
    xoaChan(s);
    cout<<"Xau sau khi xoa: "<<s;
    return 0;
}