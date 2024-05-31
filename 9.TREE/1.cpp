// binary tree 
#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

// create tree
node *create_tree(){
    int data;
    cout<<"enter data (or -1 for no node) : ";
    cin>>data;
    if(data == -1)return NULL;
    node * newnode = new node(data);

    cout<<"left child of "<<data<<" : ";
    newnode->left = create_tree();

    cout<<"right child of "<<data<<" : ";
    newnode->right = create_tree();
    return newnode;
}


// insertNode node
node *insertNode(int data, node *root){
    node *newnode = new node(data);
    if(root == NULL)return newnode;

    queue<node *>q;
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        if (temp->left == NULL) {
            temp->left = new node(data);
            break;
        }
        else q.push(temp->left);
        if (temp->right == NULL) {
            temp->right = new node(data);
            break;
        }
        else q.push(temp->right);
    }

    return root;
}

/* function to delete the given deepest node
(d_node) in binary tree */
void deletDeepest(node* root, node* d_node)
{
    queue<node*> q;
    q.push(root);
    // Do level order traversal until last node
    node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

// delete node with value
node *deleteNode(node *root, int key){
    if(root == NULL)return NULL;
    queue<node *>q;
    q.push(root);
    
    node *keynode = NULL;
    node *front = NULL;
    while(q.empty()==false){
        front = q.front();
        q.pop();
        if(front->data == key)keynode = front;
        if(front->left)q.push(front->left);
        if(front->right)q.push(front->right);
    }

    if(keynode != NULL){
        int x = front->data;
        keynode->data = x;
        deletDeepest(root, front);
    }
    return root;
}


// dfs1 : inorder traversal
void inorder(node *root){
    if(root == NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// dfs2 : preorder traversal
void preorder(node *root){
    if(root == NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// dfs3 : postorder traversal
void postorder(node *root){
    if(root == NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// bfs : level order traversal
void levelorderTraversal(node* root){
    if (root == NULL) return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right !=NULL)
            q.push(temp->right);
    }
    cout<<endl;
}


int main(){
    node *root = NULL;
    root = create_tree();

    cout<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorderTraversal(root);
}

// 1 2 -1 -1 3 4 -1 -1 5 -1 -1