// function of a tree
#include <iostream>
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
}


// traversal
void inorder(Node *root){
    if(root == NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
