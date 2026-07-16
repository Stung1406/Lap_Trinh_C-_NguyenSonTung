#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;      // private, chỉ class này truy cập
    int salary;       // private, che giấu thông tin nhạy cảm

public:
    // Constructor: khởi tạo object
    Employee(string n, int s) {
        name = n;
        salary = s;
    }

    

    // Method public để truy cập private
    void showInfo() {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }

    // Method public để thay đổi private
    void setSalary(int s) {
        if (s > 0) salary = s;
        else cout << "Invalid salary!" << endl;
    }
};

int main() {
    Employee emp1("Tung", 1000);

    emp1.showInfo();       // Name: Tung, Salary: 1000

    emp1.setSalary(1500);  // thay đổi lương
    emp1.showInfo();       // Name: Tung, Salary: 1500

    // emp1.salary = 2000; // ❌ lỗi: salary là private

    return 0;
}
