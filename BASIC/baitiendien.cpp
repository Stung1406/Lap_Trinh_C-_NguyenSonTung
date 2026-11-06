#include<iostream>

using namespace std;

int main()
{
    int dien;
    long long tiendien = 0;

    cout << "Nhap so dien su dung: "; cin >> dien;

    if (dien <= 50) tiendien = dien * 1806;
    else if (dien >= 51 && dien <=100) tiendien = 50*1806 + (dien - 50)*1866;
    else if(dien >= 101 && dien <=200) tiendien = 50*1806 + 50*1866 + (dien - 100)*2167;
    else if(dien >= 201 && dien <=300) tiendien = 50*1806 + 50*1866 + 50*2167 + (dien - 200)*2729;
    else if(dien >= 301 && dien <=400) tiendien = 50*1806 + 50*1866 + 50*2167 + 50*2729 + (dien - 300)*3050;
    else tiendien = 50*1806 + 50*1866 + 50*2167 + 50*2729 + 50*3050 + (dien - 400)*3151;
    cout << "Tien dien phai tra: " << tiendien << " VND" << endl;
    return 0;
}