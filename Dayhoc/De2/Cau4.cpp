#include<iostream>
#include<string>

using namespace std;

struct Staff{
    string name,id,room;
};

Staff inputStaff(Staff s){
    cout<<"Ten nhan vien: "; getline(cin,s.id);
    cout<<"Ma nhan vien: "; getline(cin,s.name);
    cout<<"Ten phong: "; getline(cin,s.room); 
    return s;
}

void printStaff(Staff &s){
    cout<<s.id<<"\t"<<s.name<<"\t"<<s.room<<endl;
}

struct Node{
    Staff data;
    Node *pNext;
};

Node *createrNode(Staff s){
    Node *p = new Node;
    p->data = s;
    p->pNext = nullptr;
    return p;
}

void insertLast(Node *&l,Staff s){
    Node *p = createrNode(s);
    if(l==nullptr) l = p;
    else
    {
        Node *tmp = l;
        while(tmp->pNext != nullptr) tmp = tmp->pNext;
        tmp->pNext = p;
    }
}

void delLast(Node *&l){
    if(l==nullptr) return;
    else
    {
        
    }
}
void createList(Node *&l){
    l = nullptr;
}

void inputList(Node *&l,int n){
    createList(l);
    for(int i=0;i<n;i++){
        Staff s;
        cout<<"Nhap nhan vien thu "<<i+1<<": "<<endl;
        s = inputStaff(s);
        insertLast(l,s);
    }
}


void printAll(Node *&l){
    Node *tmp = l;
    cout<<"Id\t"<<"Name\t"<<"Phong"<<endl;
    while(tmp != nullptr){
        printStaff(tmp->data);
        tmp = tmp->pNext;
    }
}
int main()
{
    Node *l;
    int n;
    cout<<"Nhap so luong nhan vien: "; cin>>n;
    cin.ignore();
    inputList(l,n);
    printAll(l);
    return 0;
}