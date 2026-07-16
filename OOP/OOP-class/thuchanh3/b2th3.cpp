#include<iostream>
#include<string>

using namespace std; 

class Employee{
public:
	Employee();
	Employee(string name1,int age1,double sal1);
	string getName();
	int getAge();
	double getSalary();
	void setName(string name1);
	void setAge(int age1);
	void setSalary(double sal1);
	void selfIntroduce();
	void output();
private:
	string name;
	int age;
	double salary;
};

class Doctor : public Employee{
private:
	double fee;
	string speciality;
public:
	Doctor();
	Doctor(string name1,int age1,double sal1,double fee1,string spec1);
	void setFee(double fee1);
	double getFee();
	void setSpeciality(string spec1);
	string getSpeciality(); 
	void selfIntroduce();
	void output();		
};

int main()
{
	Employee emp1;
	emp1.selfIntroduce(); cout<<endl;
	emp1.output();
	Doctor doctor1("Nguyen Son Tung",19,10000,10,"Pro");
	doctor1.selfIntroduce(); cout<<endl;
	doctor1.output(); 
	return 0;
}

Employee::Employee() : name("Nguyen Van A"),age(20),salary(1000){}
Employee::Employee(string name1,int age1,double sal1) : name(name1),age(age1),salary(sal1) {}
string Employee::getName(){return name;}
int Employee::getAge() {return age;}
double Employee::getSalary() {return salary;}
void Employee::setName(string name1) {name=name1;} 
void Employee::setAge(int age1)  {age=age1;}
void Employee::setSalary(double sal1) {salary=sal1;} 
void Employee::selfIntroduce(){
	cout<<"I am an Employee";
}

void Employee::output(){
	cout<<"Ten: "<<name<<endl;
	cout<<"Tuoi: "<<age<<endl;
	cout<<"Luong: "<<salary<<endl;
}

Doctor::Doctor() : Employee(),fee(0),speciality("") {}
Doctor::Doctor(string name1,int age1,double sal1,double fee1,string spec1) : Employee(name1,age1,sal1),fee(fee1),speciality(spec1) {}
void Doctor::setFee(double fee1)  {fee=fee1;}
double Doctor::getFee() {return fee;}
void Doctor::setSpeciality(string spec1) {speciality=spec1;}
string Doctor::getSpeciality() {return speciality;} 
void Doctor::selfIntroduce(){
	cout<<"I am a doctor"; 
}
void Doctor::output(){
	Employee::output(); 
	cout<<"Phi: "<<fee<<endl;
	cout<<"Chuyen mon "<<speciality<<endl; 
} 
