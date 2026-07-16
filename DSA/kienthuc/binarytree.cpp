#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isEmpty(Node *root){
    return root == NULL;
}

// Hàm tạo node mới
Node* createNode(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//hàm chèn phần tử 
Node *insert(Node *root,int x){
    if(root==NULL) return createNode(x);
    else if(x<root->data) root->left =  insert(root->left,x);
    else if(x>root->data) root->right =  insert(root->right,x);
    return root;
}

// Hàm duyệt trung thứ (Inorder traversal)
void inorder(Node* root) { //O(log(n))
    if(isEmpty(root)) return; // cây rỗng dừng luôn
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void nhap(Node *&root,int n){ //root chỉ là bản sao con trỏ, nên khi insert tạo node đầu tiên, nó không cập nhật được ra ngoài main.
    for(int i=0;i<n;i++){
        int tmp;
        cout<<"Nhap nut thu "<<i+1<<": ";
        cin>>tmp;
        root = insert(root,tmp);
    }
}

int main() {
    // Tạo các node
    int n;
    cout<<"Nhap so luong phan tu: "; 
    cin>>n;
    Node *root = NULL;
    nhap(root,n);
    cout << "Cay nhi phan vua tao (Inorder): ";
    // Hàm in cây theo thứ tự trung thứ
    inorder(root);
    return 0;
}

