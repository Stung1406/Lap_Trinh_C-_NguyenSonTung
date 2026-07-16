#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *createNode(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(Node *&head,int x)
{
    Node *newNode = createNode(x);
    if(head == NULL){
        head = newNode;
        newNode->next=head;
    }else{
        Node *tmp = new Node;
        while(tmp!=head){
            tmp=tmp->next;
        }
        tmp->next=newNode;
        newNode->next=head;
        head=newNode;
    }
}

int main()
{


    return 0;
}
