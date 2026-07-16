#include <iostream>
#include <string>
using namespace std;

class Month {
private:
    int month;
    static string names[12];
    static string vietTat[12];
public:
    Month();
    Month(int m);
    Month(string s);
    void input();
    void output();
    Month nextMonth();
};

string Month::names[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

string Month::vietTat[12]  = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

int main() {
    Month m1;
    cout << "Thang mac dinh: ";
    m1.output();

    Month m2(5);
    cout << "Thang voi so 5: ";
    m2.output();

    Month m3("Oct");
    cout << "Thang voi chu Oct: ";
    m3.output();

    Month m4;
    m4.input();
    cout << "Thang vua nhap: ";
    m4.output();

    Month m5 = m4.nextMonth();
    cout << "Thang tiep theo: ";
    m5.output();

    return 0;
}

Month::Month() : month(1){}

Month::Month(int m) {
    if (m >= 1 && m <= 12) month = m;
    else month = 1;
}

Month::Month(string s) {
    month = 1;
    for (int i = 0; i < 12; i++) {
        if (s == abbr[i]) {
            month = i+1;
            break;
        }
    }
}
void Month::input() {
    int m;
    do {
        cout << "Nhap thang (1-12): ";
        cin >> m;
    } while (m < 1 || m > 12);
        month = m;
}

void Month::output() {
    cout << names[month-1] << endl;
}
    
Month Month::nextMonth() {
    int m = month % 12 + 1;
    return Month(m);
}






