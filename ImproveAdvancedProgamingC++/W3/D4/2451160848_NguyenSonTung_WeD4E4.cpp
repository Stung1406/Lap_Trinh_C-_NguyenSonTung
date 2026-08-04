#include<iostream>
#include<string>

using namespace std;

int demSpace(string s){
    int dem = 0;
    for(int i=0;i<s.length();i++){
        if(isspace(s[i])) dem++;
    }
    return dem;
}

void xoaSpace(string &s){
    for(int i=s.length()-1;i>=0;i--){
        if(isspace(s[i])) s.erase(i,1);
    }
}

bool isSDT(string s){
    if(s.length() != 10) return false;
    if(s[0] != '0') return false;
    for(int i=0;i<s.length();i++){
        if(!isdigit(s[i])) return false;
    }
    return true;
}

void thaySobangDola(string &s){
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])) s[i] = '$';
    }
}

bool isNguyenAmHoa(char c){
    return c=='U' || c=='E' || c=='A' || c=='O' || c=='I';
}

void chenNgang(string &s){
    for(int i=1;i<s.length();i++){
        if(isNguyenAmHoa(s[i]) && isNguyenAmHoa(s[i-1])){
            s.insert(i,"-");
            i++;
        }
    }
}

void themSVaoDauMoiTu(string &s,string x){
    s = x + " " + s;
    for(int i=0;i<s.length()-1;i++){
        if(isspace(s[i])){
            s.insert(i+1,x+" ");
            i += x.length()+1;
        }
    }
}

int main()
{
    string s,x;

    cout<<"Nhap xau: ";
    getline(cin,s);
    cout<<"So khoang trang: "<<demSpace(s)<<endl;
    xoaSpace(s);
    cout<<"Xau sau khi xoa khoang trang la: "<<s<<endl;

    cout<<"\nNhap vao so dien thoai: ";
    getline(cin,s);
    if(isSDT(s))cout<<"So dien thoai hop le"<<endl;
    else cout<<"SDT khong hop le"<<endl;
    
    cout<<"\nNhap xau: ";getline(cin,s);
    thaySobangDola(s);
    cout<<"Xau sau khi thay so bang $: "<<s<<endl;
    
    cout<<"\nNhap xau: ";getline(cin,s);
    chenNgang(s);
    cout<<"Xau sau khi chen - : "<<s<<endl;
    cout<<"\nNhap xau goc: ";getline(cin,s);
    cout<<"Nhap xau S: ";
    getline(cin,x);
    themSVaoDauMoiTu(s,x);
    cout<<"Xau sau khi them S vao dau moi tu: "<<s;

    return 0;
}