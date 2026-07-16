#include<iostream>
// #include<stack>
// st.push(x)	Thêm phần tử x vào đỉnh stack	st.push(10);
// st.pop()	Xóa phần tử ở đỉnh stack	st.pop();
// st.top()	Trả về phần tử ở đỉnh stack (không xóa)	cout << st.top();
// st.empty()	Kiểm tra stack có rỗng không (trả về true/false)	if(st.empty()) cout << "rong";
// st.size()	Trả về số lượng phần tử trong stack	cout << st.size();
// st.swap(st2)	Hoán đổi nội dung giữa 2 stack cùng kiểu dữ liệu	st.swap(st2);
// st.emplace(x)	Tạo và thêm phần tử mới hiệu quả hơn push()	st.emplace(42);
 
using namespace std;

class Stack{
private:
    struct Node{
        Node(int n){
            data = n;
            next = nullptr;
        }
        int data;
        Node * next;  
    };
    Node *top;
public:
    Stack(){
        top = nullptr;
    }
    Stack(int n){
        top = new Node(n);
    }
    void push(int n){
        Node *tmp = new Node(n);
        tmp->next = top;
        top = tmp;
    }
    void pop(){
        if (empty()) return;
        Node *old = top;
        top = top->next;
        delete old;
    }

    int getTop(){
        if (empty()) return -1; // hoặc throw exception
        return top->data;
    }

    int size(){
        if(empty()){
            return 0;
        }else{
            Node *tmp = top;
            int s=0;
            while (tmp != nullptr) {
                s++;
                tmp = tmp->next;
            }
            return s;
        }
    }
    bool empty(){
        return top==nullptr;
    }
};



int main()
{
    Stack st;
    st.push(3);
    st.push(4);
    st.push(5);

    
    while (!st.empty()) {
         cout << st.getTop() << " ";
         st.pop();
    }


    // cout<<st.getTop();
    return 0;
}
