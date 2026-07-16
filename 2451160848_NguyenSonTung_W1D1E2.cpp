#include <iostream>

using namespace std;

double tinhTong(int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    double tu = (i + 1);
    double mau = (i + 1) * (i + 1);
    sum += (tu / mau);
  }
  return sum;
}

int main() {
  int n;
  cout << "Nhap n = ";
  cin >> n;
  cout << "Ket qua: " << tinhTong(n);
  return 0;
}
