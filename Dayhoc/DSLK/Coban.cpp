#include<iostream>

using namespace std;


struct SinhVien{
    int id;
    string ten;
    double dieml;
};

SinhVien inputSinhVien(){
    return 
}


struct Node{
    int data;
    Node *pNext;
};

Node *createNode(int x){
    Node *p = new Node; //quan trong
    p->data = x;
    p->pNext = nullptr;
    return p;
}

void insertFirst(Node *&l,int x){
    Node *p = createNode(x); //luc nao cung phai co
    if(l == nullptr) l = p;
    else
    {
        p->pNext = l;
        l = p;
    }
}

void insertLast(Node *&l,int x){
    Node *p = createNode(x); //luc nao cung phai co
    if(l == nullptr) l = p;
    else
    {
        Node *tmp = l;
        while(tmp->pNext != nullptr) tmp = tmp->pNext; 
        tmp->pNext = p;
    }
}

void delFirst(Node *&l){
    if(l==nullptr) return;
    l = l->pNext;
}

void delLast(Node *&l){
    //lay nut gan cuoi
    // cho tro den null
    if(l==nullptr) return;
    Node *tmp = l;
    while(tmp->pNext->pNext != nullptr) tmp = tmp->pNext;
    tmp->pNext = nullptr;
}


void createList(Node *&l){
    l = nullptr;
}

void inputList(Node *&l,int n){
    for(int i=0;i<n;i++){
        int x;
        cout<<"Nhap phan tu thu "<<i<<": "; cin>>x;
        insertFirst(l,x);
    }
}

void printAll(Node *&l){
    Node *tmp = l;
    while(tmp != nullptr){
        cout<<" "<<tmp->data;
        tmp = tmp->pNext;
    }
}

int main()

{
    Node *l;
    int n;
    cout<<"Nhap so phan tu: "; cin>>n;
    createList(l);
    inputList(l,n);
    printAll(l);
    return 0;
}


