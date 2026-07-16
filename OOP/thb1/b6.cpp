#include<iostream>
#include<vector>

using namespace std;

class HocSinh{
private:
    string MaHS,HotenHS,Lop;
    double Diem;
public:
    HocSinh(){
        MaHS="";
        HotenHS="";
        Lop="";
        Diem=0;
    }
    HocSinh(string m,string t,string l,double d){
        MaHS = m;
        HotenHS = t;
        Lop = l;
        Diem = d;
    }
    
};

int main()
{

    return 0;
}