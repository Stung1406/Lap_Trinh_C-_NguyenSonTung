#include<iostream>

using namespace std;

bool isNA(char c){
    c = tolower(c);
    return c == 'u' || c == 'e'  || c == 'a' || c == 'o' || c == 'i';
}

int main()
{
    string s;
    cout<<"Nhap xau goc: "; getline(cin,s);
    for(int i = s.size() - 1; i > 0 ; i--){
        if(isNA(s[i]) && isNA(s[i - 1])) s.insert(i,"-");
    }
    cout<<"Xau sau khi chen: "<<s;
    return 0;
}