#include<iostream>

using namespace std;

int main()
{
    string s; char H = 0;
    cout<<"Nhap chuoi ki tu: "; getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        H = H^s[i];
    }
    cout<<"Ma Hash: "<<H;
    return 0;
}