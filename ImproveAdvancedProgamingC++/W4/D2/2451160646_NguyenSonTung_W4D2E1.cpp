#include<iostream>
#include<string>
#include<stack>;

using namespace std;

struct Student
{
    string ID;
    string name;
    string major;
    double mark;
};

struct Node
{
    Student data;
    Node *pNext;
};

Node *createNewNode(Student s){
    Node *p =  new Node;
    p->data = s;
    p->pNext = nullptr;
    return p;
}

void Taodanhsach(Node *&L){
    L = nullptr;
}

void insertFirst(Node *&L,Student s){
    Node * p = createNewNode(s);
    if(L == nullptr) L = p;
    else
    {
        p->pNext = L;
        L = p;
    }
}

void insertLast(Node *&L,Student s){
    Node *p = createNewNode(s);

    if(L == nullptr) L = p;
    else
    {
        Node *tmp = L;
        while(tmp->pNext != nullptr) tmp = tmp->pNext;
        tmp->pNext = p;
    }
}

void printAll(Node *L){
    Node *p = L;
    cout<<"ID"<<"\t"<<"Name"<<"\t"<<"Major"<<"\t"<<"Mark"<<endl;
    while(p != nullptr){
        cout<<p->data.ID<<"\t"<<p->data.name<<"\t"<<p->data.major<<"\t"<<p->data.mark<<endl;
        p = p->pNext;
    }
}

void printMonHoc(Node *L,string monhoc){
    Node *p = L;
    cout<<"ID"<<"\t"<<"Name"<<"\t"<<"Major"<<"\t"<<"Mark"<<endl;
    while(p != nullptr){
        if(p->data.major==monhoc) cout<<p->data.ID<<"\t"<<p->data.name<<"\t"<<p->data.major<<"\t"<<p->data.mark<<endl;
        p = p->pNext;
    }
}

double diemCaoNhat(Node *L){
    double max;
    Node *p = L;
    while(p != nullptr){
        if(max < p->data.mark) max = p->data.mark;
        p = p->pNext;
    }
    return max;
}

void printMax(Node *L,double max){
    Node *p = L;
    cout<<"ID"<<"\t"<<"Name"<<"\t"<<"Major"<<"\t"<<"Mark"<<endl;
    while(p != nullptr){
        if(p->data.mark==max) cout<<p->data.ID<<"\t"<<p->data.name<<"\t"<<p->data.major<<"\t"<<p->data.mark<<endl;
        p = p->pNext;
    }
}

void print2MonHoc(Node *L,string monhoc1,string monhoc2){
    Node *p = L;
    cout<<"ID"<<"\t"<<"Name"<<"\t"<<"Major"<<"\t"<<"Mark"<<endl;
    while(p != nullptr){
        if(p->data.major==monhoc1 || p->data.major==monhoc2) cout<<p->data.ID<<"\t"<<p->data.name<<"\t"<<p->data.major<<"\t"<<p->data.mark<<endl;
        p = p->pNext;
    }
}

Student inputStudent(Student s){
    cin.ignore(1000,'\n'); //fflush(stdin)
    cout<<"ID: "; getline(cin,s.ID);
    cout<<"Name: "; getline(cin,s.name);
    cout<<"Major: "; getline(cin,s.major);
    cout<<"Mark: "; cin>>s.mark;
    return s;
}
Node *inputStudents(Node *L,int &n,Student s){
    cout<<"Nhap so Node cua DS n = "; cin>>n;
    //cin.ignore(1000,'\n'); //fflush(stdin);
    for(int i = 1;i <= n;i++){
        s = inputStudent(s);
        insertFirst(L,s);
    }
    return L;
}

void daoNguoc(Node *&l){
    stack<Student> s;
    Node *tmp = l;
    
    while(tmp != nullptr){
        s.push(tmp->data);
        tmp = tmp->pNext;
    }

    while(!s.empty()){
        s.top();
    }
}

int main()
{
    Node *L;
    Student s;
    int n;
    string monhoc;
    string monhoc1;
    string monhoc2;
    Taodanhsach(L);
    cout<<"Tao danh sach lien ket"<<endl;
    L = inputStudents(L,n,s);
    cout<<"Danh sach sinh vien"<<endl;
    printAll(L);
    
    cin.ignore();
    cout<<"Nhap mon hoc: "; getline(cin,monhoc);
    cout<<"Danh sach sinh vien hoc mon hoc "<<monhoc<<"la: "<<endl;
    printMonHoc(L,monhoc);

    double max = diemCaoNhat(L);
    cout<<"Danh sach sinh vien co diem cao nhat la: "<<endl;
    printMax(L,max);


    cout<<"Nhap mon hoc thu nhat: "; cin>>monhoc1;
    cout<<"Nhap mon hoc thu 2: "; cin>>monhoc2;
    print2MonHoc(L,monhoc1,monhoc2);

    cout<<"Nhap mot sinh vien moi: "<<endl;
    s = inputStudent(s);
    insertFirst(L,s);
    n++;
    cout<<"Danh sach sinh vien sau khi them moi la: "<<endl;
    printAll(L);

    cout<<"Dao nguoc dslk"<<endl;
}