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

void inorder(Node *root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// find node
Node *find_node(Node *root, int key){
    while(root!=NULL and root->data!=key){
        if(root->data>key)root = root->left;
        else root = root->right;
    }
    return root;
}

// ceil value
int ceil(Node *root, int key){
    int ans = -1;
    while(root != NULL){
        if(root->data == key)return root->data;
        if(root->data > key){
            ans = root->data;
            root = root->left;
        }
        else root = root->right;
    }
    return ans;
}

// floor value
int floor(Node *root, int key){
    int ans = -1;
    while(root != NULL){
        if(root->data == key)return root->data;
        if(root->data < key){
            ans = root->data;
            root = root->right;
        }
        else root = root->left;
    }
    return ans;
}


// insert node in BST
Node *insertNode(Node *root, int data){
    Node *mover = root;
    Node *node = new Node(data);
    while(mover!=NULL){
        if(mover->data <= data){
            if(mover->right != NULL)mover = mover->right;
            else{
                mover->right = node;
                break;
            }
        }
        else{
            if(mover->left != NULL)mover = mover->left;
            else{
                mover->left = node;
                break;
            }
        }
    }
    return root;
}

// delete node with value x
Node *findMostRight(Node *root){
    if(root->right == NULL)return root;
    return findMostRight(root->right);
}

Node *helper(Node *root){
    if(root->left == NULL)return root->right;
    if(root->right == NULL)return root->left;

    Node *right = root->right;
    Node *lastright = findMostRight(root->left);
    lastright->right = right;
    return root->left;
}

Node *deleteNode(Node *root, int x){
    if(root==NULL)return NULL;
    if(root->data == x){
        return helper(root);
    }

    Node *temp = root;
    while(root!=NULL){
        if(root->data > x){
            if(root->left != NULL and root->left->data == x){
                root->left =  helper(root->left);
                break;
            }
            else root = root->left;
        }
        else{
            if(root->right != NULL and root->right->data == x){
                root->right = helper(root->right);
                break;
            }
            else root = root->right;
        }
    }

    return temp;
}

// print kth smallest element
int cnt = 0;
void kthSmallest(Node *root, int k, int &ans){
    if(root == NULL or k<0)return;
    kthSmallest(root->left,k, ans);
    if(++cnt==k){
        ans = root->data;
        return;
    }
    kthSmallest(root->right,k, ans);
}

// validate BST
bool validate(Node *root, int mx, int mn){
    if(root == NULL)return true;
    if(root->data <= mn or root->data >= mx)return false;
    return validate(root->left, root->data, mn) and validate(root->right, mx, root->data);
}

// lca
Node *lca(Node *root, Node *p, Node *q){
    if(root == NULL) return NULL;
    if(root->data < p->data and root->data < q->data)return(lca(root->right, p, q));
    if(root->data > p->data and root->data > q->data)return(lca(root->left, p, q));
    return root;
}

// 16 13 11 -1 12 -1 -1 14 -1 -1 20 19 18 17 -1 -1 -1 -1 -1

int main(){
    Node *root = NULL;
    root = createTree();
    inorder(root);
    cout<<endl;

    int key = 17;
    Node *found = find_node(root,key);
    if(found == NULL)cout<<"Not found"<<endl;
    else cout<<"found "<<found<<" : "<<found->data<<endl;

    cout<<"floor : "<<floor(root, 15)<<" , ceil : "<<ceil(root,15)<<endl;

    int data = 2;
    root = insertNode(root, data);
    inorder(root);
    cout<<endl;

    root = insertNode(root, 21);
    inorder(root);
    cout<<endl;

    root = insertNode(root, 15);
    inorder(root);
    cout<<endl;

    root = insertNode(root, 15);
    inorder(root);
    cout<<endl;

    root =deleteNode(root, 15);
    inorder(root);
    cout<<endl;

    int k = 12;
    int ans = -1;
    kthSmallest(root, k, ans);
    cout<<k<<"th smallest element : "<<ans<<endl;


    // 16 13 11 -1 12 -1 -1 14 -1 -1 20 19 18 17 -1 -1 -1 -1 23 24 -1 -1 -1  invalid
    bool correct;
    correct = validate(root, INT_MAX, INT_MIN);
    if(correct)cout<<"valid BST"<<endl;
    else cout<<"invalid BST"<<endl;
}