// binary tree
#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int x, Node *a=NULL, Node*b=NULL){
        data = x;
        left = a;
        right = b;
    }
};

Node *createTree(){
    int data;
    cin>>data;

    if(data==-1)return NULL;
    Node *node = new Node(data,NULL,NULL);
    node->left = createTree();
    node->right = createTree();
    return node;
}

void preorder(Node *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

Node *find_node(Node *root, int key){
    while(root!=NULL and root->data!=key){
        if(root->data>key)root = root->left;
        else root = root->right;
    }
    return root;
}

int main(){
    Node *root = NULL;
    root = createTree();
    preorder(root);
    cout<<endl;

    int key = 9;
    Node *found = find_node(root,key);
    if(found == NULL)cout<<"Not found"<<endl;
    else cout<<"found "<<found<<" : "<<found->data<<endl;
    
}