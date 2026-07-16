#include <bits/stdc++.h>

using namespace std;

// Cấu trúc một nút trong danh sách liên kết đơn
struct Node {
    int data;
    Node* next;
    Node() : data(0),next(nullptr){}
    Node(int n) : data(n),next(nullptr){}
};

// Hàm tạo một nút mới
Node* createNode(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

//kiểm tra ds rỗng
bool isEmpty(Node *&head){
    return head == NULL;
}

int size(Node *&head){
    if(isEmpty(head)) return 0;
    int size=1;
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        size++;
    }    
    return size;
}

// Hàm thêm phần tử vào đầu danh sách
void insertHead(Node* &head, int x) {
    Node* newNode = new Node(x);
    if(isEmpty(head)){
        head = newNode;
    }
    newNode->next = head;  // trỏ nút mới vào đầu cũ
    head = newNode;        // cập nhật head
}

// Hàm in danh sách
void printList(Node* head) {
    cout << "Danh sach hien tai: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

// thêm phần tử vào cuối danh sách
void insertLast(Node* &head,int x){
    Node* newNode = new Node(x);
    if(isEmpty(head)){
        head=newNode;
    }else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next=newNode;
    }
}

void nhapPhantu(int n,int x,Node *&head)
{
    for (int i = 1; i <= n; i++) {
        cout << "Nhap gia tri thu " << i << ": ";
        cin >> x;
        insertLast(head, x);
    }

}

//xóa đầu
void delFirst(Node *&head){
    if(isEmpty(head)) return;
    head = head->next;
}

//xóa cuối
void delLast(Node *&head){
    if(isEmpty(head)) return;
    if(size(head)==1){
        Node *old = head;
        head=NULL;
        delete old;
        
    }else{
        Node *temp = head;
        while(temp->next->next != NULL){ // duyệt đến nút gần cuối
            temp=temp->next;
        }
        Node *old = temp->next;
        temp->next=NULL;
        delete old;
    }
}

// Hàm chính
int main() {
    Node* head = NULL;
    int n, x;

    cout << "Nhap so phan tu: ";
    cin >> n;

    nhapPhantu(n,x,head);

    printList(head);

    cout<<"\nkich thuoc cua ds lien ket : "<<size(head);
}
