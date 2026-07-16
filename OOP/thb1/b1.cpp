//viết chương trình tạo ra một lớp tên là TamGiac 
//đại diện cho độ dài 3 cạnh của nó
//Lớp bao gồm các hàm tạo và hàm thành viên để xác định
//xem tam giác đều,cân hay tam giác thường
//Viết hàm main để kiểm tra sự thực thi của lớp
#include<iostream>

using namespace std;

class TamGiac{
public:
   TamGiac(){
        a=b=c=0;
   }
   TamGiac(int x,int y,int z){
        a = x;
        b = y;
        c = z; 
   }
   bool isTamGiac(){
        return (a+b>c && a+c>b && b+c>a);
   }
   bool isDeu(){
        return isTamGiac() && (a==b && b==c);
   }
   bool isCan(){
        return isTamGiac() && (a==b || b==c || c==a);
   }
   void inra(){
        if(!isTamGiac()){
            cout<<"Khong phai la tam giac";
        }else if(isDeu()){
            cout<<"Tam giac deu";
        }else if(isCan()){
            cout<<"Tam giac can";
        }else{
            cout<<"Tam giac thuong";
        }
   }
private:
    int a,b,c;
};

int main()
{
    TamGiac tamgiac(3,4,5); //tạo đối tượng
    tamgiac.inra();
    return 0;
}
