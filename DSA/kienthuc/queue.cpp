#include<iostream>
#include<queue>

using namespace std;
// enqueue	Thêm phần tử vào cuối hàng	push(x)
// dequeue	Xóa phần tử ở đầu hàng	pop()
// front	Lấy phần tử ở đầu (nhưng không xóa)	front()
// back	Lấy phần tử ở cuối (nhưng không xóa)	back()
// empty	Kiểm tra hàng đợi rỗng không	empty()
// size	Đếm số phần tử trong hàng đợi	size()

class Queue{
public:
    Queue(){
        front=rear=nullptr;
    }
    Queue(int x){
        front = rear = new Node(x);
    }
    bool empty(){
        return front==nullptr && rear == nullptr;
    }
    void enqueue(int x){
        Node *newNode = new Node(x);
        if(empty()){
            front=rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
        }
    }    
    void dequeue(){
        front = front->next;
    }
    int Front(){
        return front->data;
    }
private:
    struct Node{
        int data;
        Node *next;
        Node(int x) : data(x),next(nullptr){}
    };
    Node *front;
    Node *rear;  
};

int main(){
    Queue q;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    while(!q.empty())
    {
        cout<<q.Front()<<" ";
        q.dequeue();
    }
    return 0;
}