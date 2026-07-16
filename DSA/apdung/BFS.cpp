#include<bits/stdc++.h>

using namespace std;


class Tree{
private:
    struct Node{
        int data;
        Node *left;
        Node *right;
        Node() : data(0),left(nullptr),right(nullptr) {}
        Node(int x) : data(x),left(nullptr),right(nullptr) {}
    };
    Node *root;
public:
    Tree() : root(nullptr) {}
    
    Tree(int x) : root(new Node(x)) {}
    
    void insert(){
        
    }
};
int main()
{

    return 0;
}