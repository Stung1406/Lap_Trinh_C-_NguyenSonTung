#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cout<<"Nhap chuoi: ";
    getline(cin,s);
    for(int i=0;i<s.size();i+=1) s[i] += 3;
    cout<<"Chuoi moi: "<<s; 
    //in ra chuỗi vô nghĩa
    // bước đầu của mã hóa dữ liệu

    // giải mã chuỗi đã được mã hóa
    for(int i=0;i<s.size();i+=1) s[i] -= 3;
    cout<<"\nChuoi giai ma: "<<s; 
    return 0;
}