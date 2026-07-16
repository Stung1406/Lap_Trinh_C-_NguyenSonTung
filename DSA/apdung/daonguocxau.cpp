#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
    string s;
    cout<<"S : "; 
    getline(cin,s);
    stack<char> daonguoc;
    for(int i=0;i<s.size();i++){
        daonguoc.push(s[i]);
    }
    cout<<"Xau sau khi dao nguoc: ";
    while (!daonguoc.empty()) {
        cout << daonguoc.top();
        daonguoc.pop(); // xoá phần tử trên cùng
    }
}