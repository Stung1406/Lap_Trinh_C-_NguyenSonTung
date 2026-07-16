#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

bool isSquareNum(int x){
    return sqrt(x)*sqrt(x)==x;
}

int main()
{
    vector<int> a = {1,2,3,4,5};
    cout<<find_if(begin(a),end(a),isSquareNum) - begin(a); 
    // trả về vị trí của x = 5
    //
}