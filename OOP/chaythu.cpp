#include <iostream>
using namespace std;
class Point{
private: int xVal, yVal;
public: void Print(){
cout<<"("<<xVal<<","<<yVal<<")";
}
Point(int x=0, int y=0):xVal(x),yVal(y){}
Point(int x){
Point::xVal = Point::yVal = x;
}
friend Point operator + (Point, Point);
};
Point operator + (Point p1, Point p2)
{
return Point(p1.xVal+p2.xVal, p1.yVal+p2.yVal);
}
int  main(){
Point p1(3,4);
Point p = p1 + 3;
p.Print();
return 0; 
}

