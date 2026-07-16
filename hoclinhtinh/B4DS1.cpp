#include<iostream>
#include<vector>

using namespace std;

int main()
{	
	vector<int> v;
	int n;
	cout<<"Cho n = "; cin>>n;
	for(int i=0;i<n;i++){
		int tmp;
		cout<<"Phan tu "<<i+1<<": ";
		cin>>tmp;
		v.push_back(tmp);
	} 
	cout<<"\nIn danh sach: ";
	for(int i=0;i<v.size();i++){
		cout<<v[i];
		if(i!=v.size()-1) cout<<" ";
	}
	int x;
	cout<<"\nCho x = "; cin>>x;
	cout<<"Them x vao dau va cuoi danh sach!"<<endl;
	v.push_back(x);
	v.insert(v.begin()+0,x);
	cout<<"In danh sach: ";
	for(int i=0;i<v.size();i++){
		cout<<v[i];
		if(i!=v.size()-1) cout<<" ";
	}
	cout<<endl
}





//struct Node{
//	int data;
//	Node *next;
//};
//
//Node *createNode(Node *&head,int x){
//	Node *tmp = new Node;
//	tmp->data=x;
//	tmp->next=nullptr;
//	return tmp;
//}
//
//void insertFirst(Node *&head,int x){
//	Node *newNode = createNode(head,x);
//	if(head==nullptr) head=newNode;
//	else
//	{
//		newNode->next=head;
//		head = newNode;
//	}	
//}
//
//void insertLast(Node *&head,int x){
//	Node *newNode = createNode(head,x);
//	if(head==nullptr) head=newNode;
//	else
//	{
//		Node *tmp = head;
//		while(tmp->next!=nullptr){
//			tmp=tmp->next;
//		}
//		tmp->next=newNode;
//	}
//}
//
//void output(Node *head){
//	Node *tmp=head;
//	while(tmp!=nullptr){
//		cout<<tmp->data;
//		if(tmp->next!=nullptr) cout<<" ";
//		tmp=tmp->next;
//	}
//}
//
//int main()
//{
//	Node *head=nullptr;
//	int n;
//	cout<<"Cho n = "; 
//	cin>>n;
//	for(int i=0;i<n;i++){
//		int tmp;
//		cout<<"Phan tu "<<i+1<<": "; 
//		cin>>tmp;
//		insertLast(head,tmp);
//	}
//	cout<<endl;
//	cout<<"In danh sach: ";
//	output(head);
//	int x;
//	cout<<"\nCho x = "; cin>>x;
//	insertFirst(head,x);
//	insertLast(head,x);
//	cout<<"Them x vao dau va cuoi danh sach!"<<endl;
//	cout<<"In danh sach: ";
//	output(head);
//	cout<<endl;
//	return 0;
//}
