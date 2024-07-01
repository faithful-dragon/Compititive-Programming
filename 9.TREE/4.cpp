#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

Node *createTree(){
    int data;
    cin>>data;
    if(data==-1)return NULL;
    Node *nd = new Node(data);
    nd->left=createTree();
    nd->right=createTree();
    return nd;
}

void preorder(Node *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


// height
int height(Node *root){
    if(root == NULL)return 0;
    else return 1+ max(height(root->left),height(root->right));
}

// balanced
int balance(Node *root){
    if(root == NULL)return 0;
    int lf = balance(root->left);
    int rt = balance(root->right);

    if(lf==-1 or rt == -1)return -1;
    if(abs(lf-rt)>1)return -1;
    return 1+max(lf,rt);
}

// diameter
int diameter(Node *root, int &dia){
    if(root == NULL)return 0;
    int lt = diameter(root->left,dia);
    int rt = diameter(root->right,dia);
    dia = max(dia,(lt+rt));
    return 1 + max(lt,rt);
}

// maxsum
int maxsum(Node *root, int &s){
    if(root == NULL)return 0;
    int lt = max(0,maxsum(root->left,s));
    int rt = max(0,maxsum(root->right,s));
    s = max(s,(lt+rt+root->data));
    return root->data + max(lt,rt);
}


//identical tree
bool identical(Node *root1, Node *root2){
    if(root1 == NULL or root2 == NULL){
        return root1==root2;
    }
    else{
        bool ans = true;
        ans &= (root1->data == root2->data);
        ans &= identical(root1->left, root2->left);
        ans &= identical(root1->left, root2->left);
        return ans;
    }
}

int main(){
    Node *root=NULL;
    root = createTree();
    preorder(root);
    cout<<endl;

    cout<<"height : "<<height(root)<<endl;
    cout<<"balanced : "<<balance(root)<<endl;   // if -1 then not balanced
    int d=0,ms=INT_MIN;
    diameter(root,d);
    cout<<"diameter : "<<d<<endl;
    maxsum(root,ms);
    cout<<"max sum path : "<<ms<<endl;
}

// 1 2 -1 -1 3 4 5 9 -1 -1 -1 -1 6 -1 7 -1 8 -1 -1