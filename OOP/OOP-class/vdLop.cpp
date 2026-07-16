#include<iostream>
using namespace std;
class DayOfYear
{
    public:
        void output();//khai báo hàm thành viên
        int day;
        int month;


};

int main()
{
    DayOfYear today,birthday;
    cout<<"Nhap ngay hom nay: \n";
    cout<<"Nhap ngay: "; cin>>today.day;
    cout<<"Nhap thang "; cin>>today.month;
    cout<<"Nhap ngay sinh cua ban: "<<endl;
    cout<<"Nhap ngay: "; cin>>birthday.day;
    cout<<"Nhap thang: "; cin>>birthday.month;
    
}