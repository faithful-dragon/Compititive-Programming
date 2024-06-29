// function of a tree
#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *createTree(){
    int data;
    cout<<" data (-1 for null) : ";
    cin>>data;

    if(data == -1)return NULL;
    Node *root = new Node(data);

    cout<<"for left child of "<<data<<" ";
    root->left = createTree();

    cout<<"for right child of "<<data<<" ";
    root->right = createTree();

    return root;
}

// inorder traversal
void inorder(Node *root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// preorder traversal
void preorder(Node *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// preorder traversal
void postorder(Node *root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


// level order traversal
// bfs : level order traversal
void bfs(Node* root){
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right !=NULL)
            q.push(temp->right);
    }
    cout<<endl;
}

void print_level(Node* root){
    if (root == NULL) return;
    vector<vector<int>>ans;
    vector<int>v;
    Node *x = new Node(-1);
    queue<Node*> q;
    q.push(root);
    q.push(x);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp->data == -1){
            ans.push_back(v);
            v.clear();
            if(q.empty()==false)q.push(x);
        }
        else{
            v.push_back(temp->data);
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right !=NULL) q.push(temp->right);
        }
    }

    for(auto a:ans){
        for(int b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Node *root = createTree();
    cout<<"inorder   : ";
    inorder(root);
    cout<<endl;

    cout<<"preorder  : ";
    preorder(root);
    cout<<endl;

    cout<<"postorder : ";
    postorder(root);
    cout<<endl;

    cout<<"bfs : ";
    bfs(root);

    cout<<"level order "<<endl;
    print_level(root);
}

