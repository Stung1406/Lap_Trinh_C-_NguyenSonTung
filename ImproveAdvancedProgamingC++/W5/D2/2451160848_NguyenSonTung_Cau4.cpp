#include<iostream>
#include<string>

using namespace std;

struct Product{
    string id,name,brand;
    double cost;
    int qty;
};

Product inputPro(Product p){
    cin.ignore(100,'\n');
    cout<<"ma san pham: "; getline(cin,p.id);
    cout<<"ten san pham: "; getline(cin,p.name);
    cout<<"hang san xuat: "; getline(cin,p.brand);
    cout<<"don gia: "; cin>>p.cost;
    cout<<"so luong: "; cin>>p.qty;
    return p;
}

void outputPro(Product p){
    cout<<p.id<<"\t"<<p.name<<"\t"<<p.brand<<"\t"<<p.cost<<"\t"<<p.qty;
}

struct Node{
    Product data;
    Node *pNext;
};

Node *createNode(Node *newNode,Product s){
    newNode = new Node;
    newNode->data = s;
    newNode->pNext = NULL;
    return newNode;
}

void createList(Node *&l){
    l = NULL;
}

void insertFirst(Node *&l,Product s){
    Node *p = createNode(p,s);
    if(l==NULL) l = p;
    else
    {
        p->pNext = l;
        l = p;
    }
}

void insertLast(Node *&l,Product s){
    Node *p = createNode(p,s);
    if(l == NULL) l = p;
    else
    {
        Node *tmp = l;
        while(tmp->pNext != NULL){
            tmp = tmp->pNext;
        }
        tmp->pNext = p;
    }
}

void inputPros(int n,Node *&l){
    for(int i=0;i<n;i++){
        Product s;
        cout<<"Nhap san pham thu "<<i + 1<<": "<<endl;
        s = inputPro(s);
        insertLast(l,s);
    }
}

void printAll(Node *&l){
    cout<<"Ma"<<"\t"<<"Ten"<<"\t"<<"Hang"<<"\t"<<"Don gia"<<"\t"<<"So luong"<<endl;
    Node *tmp = l;
        while(tmp != NULL){
            outputPro(tmp->data); cout<<endl;
            tmp = tmp->pNext;
        }
}

int main()
{
    int n;
    Node *l;
    Product s;
    cout<<"Nhap so luopng san pham: "; cin>>n;
    createList(l);
    cout<<"\nNhap danh sach san pham:"<<endl;
    inputPros(n,l);
    cout<<"\nDanh sach san pham vua nhap la: "<<endl;
    printAll(l);

    cout<<"\nNhap mot san pham moi: "<<endl;
    s = inputPro(s);
    insertFirst(l,s);

    cout<<"\nDanh sach sau khi them la: "<<endl;
    printAll(l);
    return 0;
}