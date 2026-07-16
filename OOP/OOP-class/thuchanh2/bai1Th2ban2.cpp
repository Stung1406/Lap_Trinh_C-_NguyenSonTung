#include <iostream>

using namespace std;
// Lop Thoigian bieu dien dai luong thoi gian theo gio, phut, giay

class Time{
public:
    Time();// Ham tao khong tham so
    Time(int h, int m, int s);// Ham tao co tham so, co goi standardize()
    int getHours() const;// Lay so gio
    int getMinutes() const;// Lay so phut
    int getSeconds() const;// Lay so giay
    void setHours(int h);// Dat so gio
    void setMinutes(int m);// Dat so phut
    void setSeconds(int s);// Dat so giay
    void standardize();// Chuan hoa: minutes va seconds phai tu 0-59
    void output() const;// In ra man hinh cac thong so gio, phut, giay
    void input();// Nhap du lieu tu ban phim, co goi standardize()
private:
    int hours;// gio
    int minutes;// phut
    int seconds;// giay
};
// Ham nap chong toan tu + cho lop Time
const Time operator+(const Time& t1, const Time& t2);
// -----------------------------------------------------------------------------
// Ham main
int main(){
    Time timeVar1(3, 70, 67);
    cout << "Bien Time thu nhat: ";
    timeVar1.output();
    cout << endl;
    cout << "Bien Time thu hai: ";
    Time timeVar2(0, 108, 53);
    timeVar2.output();
    cout << endl;
    cout << "Tong cua 2 bien Time: ";
    (timeVar1 + timeVar2).output();
    cout << endl;
    cout << "Nhap cac thong so cho bien Time thu ba:\n";
    Time timeVar3;
    timeVar3.input();
    cout << "Bien Time thu ba: ";
    timeVar3.output();
    cout << endl;
    system("pause");
    return 0;
}
// -----------------------------------------------------------------------------
// Dinh nghia cac ham
// Ham tao khong tham so
Time::Time(): hours(0), minutes(0), seconds(0){ }
// Ham tao co tham so, co goi standardize()
Time::Time(int h, int m, int s): hours(h), minutes(m), seconds(s){standardize();}
// Chuan hoa: minutes va seconds phai tu 0-59
void Time::standardize(){
    int s = seconds;
    int m = minutes;
    int h = hours;
    seconds = s % 60;
    m += s / 60;
    minutes = m % 60;
    hours = h + m / 60;
}
// Lay so gio
int Time::getHours()const{
    return hours;
}
// Lay so phut
int Time::getMinutes()const{
    return minutes;
}
// Lay so giay
int Time::getSeconds ()const{
    return seconds;
}
// Dat so gio
void Time::setHours(int h){
    hours = h;
}
// Dat so phut
void Time::setMinutes(int m){
    minutes = m;
}
// Dat so giay
void Time::setSeconds(int s){
    seconds = s;
}
// In ra man hinh cac thong so gio, phut, giay
void Time::output() const{
    cout << hours << " gio, " << minutes << " phut, " << seconds << " giay";
}
// Nhap du lieu tu ban phim, co goi standardize()
void Time::input(){
    cout << "Nhap so gio: ";
    cin >> hours;
    cout << "Nhap so phut: ";
    cin >> minutes;
    cout << "Nhap so giay: ";
    cin >> seconds;
    standardize();
}

// Ham nap chong toan tu + cho lop Time
const Time operator+(const Time& t1, const Time& t2){
    int h = t1.getHours() + t2.getHours();
    int m = t1.getMinutes() + t2.getMinutes();
    int s = t1.getSeconds() + t2.getSeconds();
    return Time(h, m, s);
}