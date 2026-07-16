#include<iostream>
#include<string>

using namespace std;

class Time{
public:
    Time();
    Time(int h,int m,int s);
    friend istream& operator>>(istream& in,Time &tg);
    friend ostream& operator<<(ostream& out,Time &tg);
    const Time operator + (const Time &tg);
    const Time operator - (const Time &tg);
    const Time operator - (); //mot ngoi
    const Time operator ++ ();
    friend bool operator ==(const Time &tg1,const Time &tg2);
    void standardize();
private:
    int hours,minutes,seconds;
};

int main()
{
    Time tg1,tg2;

    cout<<"Nhap thoi gian thu nhat: "<<endl; 

    cout<<"\nThoi gian vua nhap la: ";
    
    cout<<"\nNhap thoi gian thu hai: "<<endl; 
    
    cout<<"\nThoi gian vua nhap la: ";
    

    Time kq = tg1 + tg2;

    cout<<endl;
    

    return 0;
}

Time::Time() : hours(0),minutes(0),seconds(0){}

Time:: Time(int h,int m,int s) : hours(h),minutes(m),seconds(s){standardize();}

void Time::standardize()
{
    minutes += seconds / 60;
    seconds = seconds % 60; 
    hours += minutes / 60;
    minutes = minutes % 60;
}

istream& operator>>(istream& in,Time &tg)
{
    cout<<"Nhap gio: "; in>>tg.hours;
    cout<<"Nhap phut: "; in>>tg.minutes;
    cout<<"Nhap giay: "; in>>tg.seconds;
    
    return in; //quan trong
}

ostream& operator<<(ostream& out,Time &tg)
{
    out<<tg.hours<<":"<<tg.minutes<<":"<<tg.seconds;
    return out;
}



const Time Time::operator + (const Time &tg){
    return Time(hours+tg.hours,minutes+tg.minutes,seconds+tg.seconds);
}

const Time Time::operator - (const Time &tg){
    return Time(hours-tg.hours,minutes-tg.minutes,seconds-tg.seconds);
}

bool operator ==(const Time &tg1,const Time &tg2){
    return (tg1.hours==tg2.hours && tg1.minutes==tg2.minutes && tg1.seconds == tg2.seconds);
}

const Time Time::operator - (){
    return Time(-hours,-minutes,-seconds);
}

const Time Time::operator++(){
    return Time(hours++,minutes++,seconds++);
}
