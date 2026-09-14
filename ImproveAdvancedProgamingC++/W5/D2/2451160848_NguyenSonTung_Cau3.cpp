#include<iostream>
#include<string>

using namespace std;

bool isNA(char c){
    c = tolower(c);
    return c == 'u' || c== 'e' || c=='a' || c=='o' || c == 'i';
}

void hoaNA(char &c){
    if(isNA(c)) c = tolower(c);
    else c = toupper(c);
}

void viet(string &s){
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i]) && s[i] !='9') s[i]++;
        hoaNA(s[i]);
    }
}

int main()
{

    string s;
    cout<<"Nhap xau goc: "; getline(cin,s);
    viet(s);
    cout<<"Xau sau khi thay doi: "<<s;
    return 0;
}