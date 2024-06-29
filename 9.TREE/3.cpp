// function of a tree
#include <iostream>
#include <queue>
#include <stack>
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

// preorder traversal
void preorder(Node *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// inorder traversal
void inorder(Node *root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// preordered using stack
vector<int> st_preorder(Node *root){
    vector<int>preorder;
    if(root==NULL)return preorder;
    stack<Node*>st;
    st.push(root);

    while(st.empty()==false){
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right)st.push(root->right);
        if(root->left)st.push(root->left);
    }
    return preorder;
}

// inordered using stack
vector<int> st_inorder(Node *root){
    vector<int>inorder;
    Node *node = root;
    stack<Node*>st;

    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()==true)break;
            node=st.top();
            inorder.push_back(node->data);
            st.pop();
            node=node->right;
        }
    }
    return inorder;
}

// post order using 2 stack
vector<int> st_postorder(Node *root){
    vector<int>postorder;
    if(root==NULL)return postorder;
    stack<Node*>st1,st2;
    st1.push(root);

    while(st1.empty()==false){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left)st1.push(root->left);
        if(root->right)st1.push(root->right);
    }

    while(st2.empty()==false){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}


int main(){
    Node *root = createTree();
    cout<<endl;
    cout<<"preorder   : ";
    preorder(root);
    cout<<endl;

    vector<int>po = st_preorder(root);
    for(int x:po)cout<<x<<" ";
    cout<<endl;

    cout<<"inorder   : ";
    inorder(root);
    cout<<endl;

    vector<int>io = st_inorder(root);
    for(int x:io)cout<<x<<" ";
    cout<<endl;

    vector<int>pto = st_postorder(root);
    for(int x:pto)cout<<x<<" ";
    cout<<endl;

}