#include<iostream>
#include<string>

using namespace std;


int main()
{
    string s,del;
    cout<<"Nhap xau: "; getline(cin,s);
    cout<<"Nhap xau can xoa: "; getline(cin,del);
    int pos = s.find(del);
    if(pos == -1) cout<<"Xau can xoa khong co trong xau goc";
    else
    {
        s.erase(pos,del.length());
        cout<<"Xau sau khi xoa: "<<s;
    }
    return 0;
}