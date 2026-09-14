#include<iostream>
#include<string>

using namespace std;

void inputN(int &n){
    do{
        cout<<"N = "; cin>>n;
    }while(n<=0 || n>=100);
}

void inputArr(int n,string ten[]){
    for(int i=0;i<n;i++){
        cout<<"Ho ten "<<i+1<<": "; getline(cin,ten[i]);
    }
}

string tenNganNhat(int n,string ten[]){
    string ngannhat = ten[0];
    for(int i=0;i<n;i++){
        if(ngannhat.size() > ten[i].size()) ngannhat = ten[i];
    }
    return ngannhat;
}

int main()
{
    int n;
    string ten[100];
    inputN(n);
    cin.ignore();
    inputArr(n,ten);
    cout<<"Ho ten ngan nhat (dau tien) la: "<<tenNganNhat(n,ten);
    return 0;
}