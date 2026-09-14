#include<iostream>
#include<string>

using namespace std;

struct Student{
    string id,name;
    double mark;
};

Student inputStu(Student s){
    cout<<"ID: "; getline(cin,s.id);
    cout<<"Name: "; getline(cin,s.name);
    cout<<"Mark: "; cin>>s.mark;
    return s;
}

void printStu(Student s){
    cout<<s.id<<"\t"<<s.name<<"\t"<<s.mark<<endl;
}

struct Node{
    Student data;
    Node *pNext;
};

Node *createNode(Student s){
    Node *p = new Node;
    p->data = s;
    p->pNext = NULL;
    return p;
}

void createList(Node *&l){
    l = NULL;
}

void insertFirst(Node *&l,Student s){
    Node *p = createNode(s);
    if(l == NULL) l = p;
    else{
        p->pNext = l;
        l = p;
    }
}

void insertLast(Node *&l,Student s){
    Node *p = createNode(s);
    if(l==NULL) l = p;
    else
    {
        Node *tmp = l;
        while(tmp->pNext != NULL) tmp = tmp->pNext;
        tmp->pNext = p;
    }
}

void inputN(int &n){
    do{
        cout<<"Nhap so hoc vien n = "; cin>>n;
    }while(n <= 0);
}

void inputList(Node *&l,int n){
    for(int i = 0;i < n; i++ ){
        cout<<"\nNhap thong tin hoc vien thu "<<i+1<<":"<<endl;
        cin.ignore(1000,'\n');
        Student s;
        s = inputStu(s);
        insertLast(l,s);
    }
}

void printALL(Node *&l){
    Node *tmp = l;
    cout<<"ID\t"<<"Name\t"<<"Mark\n";
    while(tmp != NULL){
        printStu(tmp->data);
        tmp = tmp->pNext;
    }
}

int main()
{
    int n;
    Node *l;
    Student s;
    createList(l);
    inputN(n);
    inputList(l,n);
    cout<<"\nDanh sach hoc vien:"<<endl;
    printALL(l);

    cout<<"\nNhap hoc vien moi:"<<endl;
    cin.ignore(1000,'\n');
    s=inputStu(s);
    insertFirst(l,s);

    cout<<"\nDanh sach hoc vien sau khi them vao dau:"<<endl;
    printALL(l);
    return 0;
}