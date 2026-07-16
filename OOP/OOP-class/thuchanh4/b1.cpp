#include<iostream>

using namespace std;

class DongVat{
public:
	DongVat(double w);
	virtual void inDL();
private:
	double canNang;
};

class SuTu : public DongVat{
public:
	SuTu(double w,double s);
	void inDL();
private:
	double tocDo;
};

class TranNuoc : public DongVat{
public:
	TranNuoc(double w,double t);
	void inDL();
private:
	double chieuDai;
};

int main()
{
	SuTu s1(300,100);
	TranNuoc tl(400,3);
	s1.inDL();
	tl.inDL();
	DongVat *dv1;
	dv1 = &s1;
	dv1->inDL();
	dv1 = &tl;
	dv1->inDL();
	return 0;
}

DongVat :: DongVat (double w) : canNang(w) {}
void DongVat :: inDL(){
	cout<<"Can Nang: "<<canNang<<endl;
} 

SuTu :: SuTu(double w,double s) : DongVat(w),tocDo(s) {}

void SuTu :: inDL(){
	DongVat::inDL();
	cout<<"Toc do: "<<tocDo<<endl;
}

TranNuoc :: TranNuoc(double w,double t) : DongVat(w),chieuDai(t) {}

void TranNuoc :: inDL(){
	DongVat::inDL();
	cout<<"chieu dai : "<<chieuDai<<endl;
}


