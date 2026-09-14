#include<iostream>
#include<string>

using namespace std;

string InHoaXau(string s){
    s[0] = toupper(s[0]);
    for(int i=0;i<s.length() - 1;i++){
        if(isspace(s[i])) s[i+1] = toupper(s[i+1]); // lưu ý
    }
    return s;
}

int main()
{
    string s;
    cout<<"Nhap xau: "; getline(cin,s);
    cout<<"Xau sau khi in hoa la: "<<InHoaXau(s);
    return 0;
}