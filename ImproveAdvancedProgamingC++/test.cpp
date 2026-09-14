#include<iostream>
#include<string>

using namespace std;

void chen(string &s,string s1){
    for(int i = s.size() - 1;i > 0; i--){
        if(isspace(s[i-1])) s.insert(i,s1);
    }
}

void xoa(string &s){
    for(int i = s.size() - 1;i >= 0; i--){
        if(isspace(s[i])) s.erase(i,1);
    }
}

int main()
{
    string s,s1;
    cout<<"Nhap xau goc: "; getline(cin,s);
    cout<<"Nhap xau can them: "; getline(cin,s1);
    chen(s,s1);
    xoa(s);
    cout<<"Xau ket qua: "<<s;
    return 0;
}