#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
};

Node *createNode(int x){
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

bool isEmpty(Node *&head){
    return head == NULL;
}

int size(Node *&head){
    if(isEmpty(head)) return 0;
    int size=1;
    Node *temp=head;
    while(temp->next != NULL){
        temp = temp->next;
        size++;
    }
    return size;
}

void insertFirst(Node *&head,int x){
    Node *newNode = createNode(x);
    if(isEmpty(head)){
        head=newNode;
    }else{
    head->prev=newNode;
    newNode->next = head;
    head=newNode;
    }
}

void insertLast(Node *&head,int x){
    Node *newNode = createNode(x);
    if(isEmpty(head)){
        head=newNode;
    }else{
        Node *temp = head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        newNode->prev=temp;
        temp->next=newNode;
    }
}

void nhap(Node *&head,int &n){
    cout<<"Nhap so luong phan tu "; cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cout<<"Nhap phan tu thu "<<i+1<<": ";
        cin>>tmp;
        insertFirst(head,tmp);
    }
}

void printList(Node* head) {
    cout << "Danh sach hien tai: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data <<" ";
        temp = temp->next;
    }
}


int main()
{
    int n;
    Node *head = NULL;
    nhap(head,n);
    printList(head);
    return 0;
}