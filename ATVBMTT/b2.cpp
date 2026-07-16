#include<bits/stdc++.h>

using namespace std;


int main()
{
    int k;
    string s;
    cout<<"Nhap s: "; getline(cin,s);

    cout<<"Nhap k: "; cin>>k;

    for(int i=0;i<s.size();i++) s[i] += k;
    cout<<"Chuoi moi: "<<s;

    for(int i=0;i<s.size();i++) s[i] -= k;
    cout<<"\nChuoi ma hoa: "<<s; 
    
    return 0;
}