#include<iostream>

using namespace std;

class CPU{
private:
	double tocDo;	
public:
	CPU(double s);
	virtual double sucManh();
	void xepHang();
};

class Core2Dual : public CPU {
public:
	Core2Dual(double s);
	double sucManh();
}; 

int main()
{
    Core2Dual aChip(2);
	aChip.xepHang();
	return 0;
}

/* ket luan  : a . neu khong co virtual thi ket qua in ra la 2 và chip binh thuong : khi ghi de se bi che khuat 
               b. co virtual ket qua in ra la 4 va chip nay rat manh : duoc ghi de thuc su */

CPU :: CPU(double s) : tocDo(s) {}

double CPU :: sucManh(){
	return tocDo;
}

void CPU :: xepHang(){
	if(sucManh() > 3) cout<<"Chip nay rat manh";	
}

Core2Dual :: Core2Dual(double s) : CPU(s) {}

double Core2Dual :: sucManh(){
	return 2 * CPU::sucManh();
}

