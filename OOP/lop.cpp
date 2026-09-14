#include<iostream>

using namespace std;

class TamGiac{
public:
    TamGiac() : canhA(1), canhB(1), canhC(1) {}
    TamGiac(double a, double b, double c) : canhA(a), canhB(b), canhC(c) {}
private:
    double canhA, canhB, canhC;
};

int main()
{
    return 0;
}
