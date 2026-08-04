#include<iostream>
#include<string>

using namespace std;

int demKiTuHoa(string s){
    int dem = 0;
    for(int i=0;i<s.length();i++){
        if(isupper(s[i])) dem++;
    }
    return dem;
}

int main()
{
    string s;
    cout<<"Nhap xau goc: "; getline(cin,s);
    if(demKiTuHoa(s) != 0) cout<<"Co "<<demKiTuHoa(s)<<" ki tu la chu cai hoa trong xau.";
    else cout<<"Khong co ki tu nao la chu cai hoa trong xau.";
    return 0;
}