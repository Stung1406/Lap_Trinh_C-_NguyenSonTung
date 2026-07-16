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
    int toNum(Node *head){
        int result = 0;
        Node *tmp = head;
        while(tmp!=NULL){
            result = result*10 + tmp->data;
            tmp=tmp->next;
        }
        return result;
    }
};

int main()
{
    Node *head=NULL;
    insertHead(head,3);
    insertHead(head,2);
    insertHead(head,1);
    cout<<endl<<Solution().toNum(head);
    return 0;
}