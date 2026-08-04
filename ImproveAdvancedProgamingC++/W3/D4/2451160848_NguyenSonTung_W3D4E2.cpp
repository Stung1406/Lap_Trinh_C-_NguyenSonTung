#include<iostream>

using namespace std;

int demThuong(string s){
    int dem = 0;
    for(int i=0;i<s.length();i++){
        if(islower(s[i])) dem++;
    }
    return dem;
}

int demHoa(string s){
    int dem = 0;
    for(int i=0;i<s.length();i++){
        if(isupper(s[i])) dem++;
    }
    return dem;
}

int demSo(string s){
    int dem = 0;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])) dem++;
    }
    return dem;
}


bool matKhauManh(string s){
    if(s.length() < 8 || s.length() > 20) return false;
    
    for(int i=0;i<s.length();i++){
        if(isspace(s[i])) return false;
    }
    
    if(demThuong(s) >= 1 && demHoa(s) >= 1 && demSo(s) >= 1) return true;
    return false;
}

int main()
{
    string s;
    cout<<"Nhap mat khau: "; getline(cin,s);
    if(matKhauManh(s)) cout<<"Mat khau hop le"<<endl;
    else cout<<"Mat khau khong hop le"<<endl;
    return 0;
}
