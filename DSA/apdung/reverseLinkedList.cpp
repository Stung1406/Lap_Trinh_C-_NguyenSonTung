#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void insertHead(Node* &head, int x) {
    Node* newNode = createNode(x);
    newNode->next = head;  // trỏ nút mới vào đầu cũ
    head = newNode;        // cập nhật head
}
class Solution{
public:
    Node* reverse(Node* head) {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL) {
            next = curr->next;   // lưu next
            curr->next = prev;   // đảo chiều
            prev = curr;         // tiến prev
            curr = next;         // tiến curr
        }

        return prev; // prev là head mới
    }
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    Node *head=NULL;
    insertHead(head,1);
    insertHead(head,2);
    insertHead(head,3);
    printList(head);
    cout<<endl;
    Solution s;
    head = s.reverse(head);
    printList(head);
}