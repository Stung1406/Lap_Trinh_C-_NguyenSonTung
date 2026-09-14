#include<iostream>

using namespace std;

void innputN(int &n){
    do{
        cout<<"Nhap so luong ten:"; cin>>n;
    }while(n<=0 || n>=20000);
}

void inputArr(int n,string name[]){
    for(int i=0;i<n;i++){
        getline(cin,name[i]);
    }
}

void outputArr(int n,string name[]){
    for(int i=0;i<n;i++){
        cout<<name[i]<<endl;
    }
}

void Sort(string name[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(name[j].compare(name[i]) < 0){
                string tmp = name[i];
                name[i] = name[j];
                name[j] = tmp;
            } 
        }
    }
}

int main()
{
    int n;
    string name[1000];
    innputN(n);
    cin.ignore();
    cout<<"Nhap ten (moi ten 1 dong):"<<endl;
    inputArr(n,name);
    cout<<"Danh sach ho ten vua nhap:"<<endl;
    outputArr(n,name);
    Sort(name,n);
    cout<<"Sap xep theo thu tu bang tu dien:"<<endl;
    outputArr(n,name);
    return 0;
}