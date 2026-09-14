#include<iostream>
#include<string>

using namespace std;

struct Product{
    string id,name;
    double price;
};

Product inputPro(Product p){
    cout<<"ID: "; getline(cin,p.id);
    cout<<"Name: "; getline(cin,p.name);
    cout<<"Price: "; cin>>p.price;
    return p;
}

void printPro(Product p){
    cout<<p.id<<"\t"<<p.name<<"\t"<<p.price<<"\n";
}

struct Node{
    Product data;
    Node *pNext;
};

Node *createNode(Product pro){
    Node *p = new Node;
    p->data = pro;
    p->pNext = NULL;
    return p;
}

void insertFirst(Node *&l,Node *&tail,Product pro){
    Node *p = createNode(pro);
    if(l == NULL)
    {
        l = p;
        tail = p;
    }else{
        l->pNext = p;
        l = p;
    }
}

void insertLast(Node *&l,Node *&tail,Product pro){
    Node *p = createNode(pro);
    if(l == NULL)
    {
        l = p;
        tail = p;
    }else{
        tail->pNext = p;
        tail = p;
    }
}

void delLast(Node *&l){
    if(l == NULL) return;
    else
    {
        tail
    }
}

int main()
{
    return 0;
}