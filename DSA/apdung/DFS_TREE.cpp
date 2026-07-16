#include <iostream>
#include<stack>
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
void DFS(Node* root) {
    if (root == NULL) return;

    stack<Node*> OPEN;     // OPEN = danh sách các node chờ duyệt
    OPEN.push(root);

    while (!OPEN.empty()) {
        Node* cur = OPEN.top();
        OPEN.pop();

        cout << cur->data << " ";   // xử lý node (visit)

        // push phải trước, trái sau
        if (cur->right != NULL)
            OPEN.push(cur->right);

        if (cur->left != NULL)
            OPEN.push(cur->left);
    }
}

// Hàm tìm giá trị nhỏ nhất trong cây (dùng cho xoá)
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Hàm xoá một nút có giá trị x trong cây nhị phân tìm kiếm
Node* deleteNode(Node* root, int x) {
    if (root == NULL) return root;

    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    } else {
        // tìm thấy nút cần xoá
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // cả hai con đều tồn tại: lấy successor nhỏ nhất bên phải
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int main() {
    int n;
    cout << "Nhap so luong phan tu: "; 
    cin >> n;
    Node *root = NULL;
    nhap(root, n);

    cout << "Cay sau khi nhap (inorder): ";
    inorder(root);
    cout << "\n";

    int m;
    cout << "Nhap so luong nut can xoa: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        int val;
        cout << "Nhap gia tri can xoa thu " << i+1 << ": ";
        cin >> val;
        root = deleteNode(root, val);
        cout << "Cay sau khi xoa " << val << " (inorder): ";
        inorder(root);
        cout << "\n";
    }

    cout << "Cay duoi dang DFS (preorder): ";
    DFS(root);
    cout << "\n";

    return 0;
}

