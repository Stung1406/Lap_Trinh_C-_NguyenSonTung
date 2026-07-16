#include<iostream>

using namespace std;

struct SinhVien{
	string id;
	string ten;
	double diem;
};

struct ListNode{
	SinhVien data;
	ListNode *next;
};

ListNode *createNode(SinhVien tmp){
	ListNode *newNode = new ListNode;
	newNode->data.id = tmp.id;
	newNode->data.ten =  tmp.ten;
	newNode->data.diem = tmp.diem;
	newNode->next = nullptr;
	return newNode;
}

void insertFirst(ListNode *&l,SinhVien tmp){
	ListNode *newNode = createNode(tmp);
	if(l == nullptr) l=newNode;
	else
	{
		newNode->next = l;
		l = newNode;
	}
}

void insertLast(ListNode *&l,SinhVien tmp){
	ListNode *newNode = createNode(tmp);
	if(l == nullptr) l=newNode;
	else
	{
		ListNode *tmp = l;
		while(tmp->next != nullptr){
			tmp=tmp->next;
		}
		tmp->next=newNode;
	}
}

void output(ListNode *l){
	ListNode *tmp = l;
	cout<<"ID"<<"\t"<<"Name"<<"\t"<<"Mark"<<endl;
	while(tmp != nullptr){
		cout<<tmp->data.id<<"\t"<<tmp->data.ten<<"\t"<<tmp->data.diem<<endl;
		tmp=tmp->next;
	}
}

int main()
{
	ListNode *l = nullptr;
	int n;
	do{
		cout<<"Nhap so hoc vien n = "; cin>>n;
		cin.ignore();
	}while(n<=1);
	
	for(int i=0;i<n;i++){
		SinhVien tmp;
		cout<<"Nhap tong tin hoc vien thu "<<i+1<<endl;
		cout<<"ID: "; getline(cin,tmp.id);
		cout<<"Name: "; getline(cin,tmp.ten);
		cout<<"Mark: "; cin>>tmp.diem;
		cin.ignore();
		insertLast(l,tmp);
		cout<<endl;
	}
	
	cout<<"Danh sach hoc vien: "<<endl;
	output(l);
	
	SinhVien tmp2;
	cout<<"\nNhap hoc vien moi: "<<endl;
	cout<<"ID: "; getline(cin,tmp2.id);
	cout<<"Name: "; getline(cin,tmp2.ten);
	cout<<"Mark: "; cin>>tmp2.diem;
	cin.ignore();
	
	insertFirst(l,tmp2);
	
	cout<<"\nDanh sach hoc vien sau khi them vao dau: "<<endl;
	output(l);
	
	return 0;
}
