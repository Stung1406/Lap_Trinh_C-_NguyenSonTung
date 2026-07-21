#include <iostream>

using namespace std;

double tinhTong(int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    int mau = 2 * (i + 1);
    sum += (1.0 / mau);
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
