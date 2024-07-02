#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
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

// min time to burn tree;

Node *find_node(Node *root, int start){
    queue<Node *>q;
    q.push(root);

    while(q.empty()==false){
        Node *x = q.front();
        q.pop();
        if(x->data == start)return x;
        if(x->left)q.push(x->left);
        if(x->right)q.push(x->right);
    }
    return NULL;
}

void store_parent(Node *root, map<Node*,Node*> &par){
    queue<Node *>q;
    Node * temp = NULL;
    par[root] = NULL;
    q.push(root);

    while(q.empty()==false){
        Node *x = q.front();
        q.pop();
        if(x->left){
            q.push(x->left);
            par[x->left]=x;
        }
        if(x->right){
            q.push(x->right);
            par[x->right]=x;
        }
    }
}

int bfs(Node *root, Node *target){
    if(root == NULL)return 0;
    int time = 1;
    map<Node*, bool>vis;
    map<Node*,Node*> par;
    store_parent(root,par);

    queue<Node *>q;
    q.push(target);
    vis[target]=true;

    while(q.empty()==false){
        int size = q.size();
        bool flag = false;
        for(int i=0;i<size;i++){
            root = q.front();
            q.pop();
            if(root->left != NULL and vis[root->left]==false){
                q.push(root->left);
                vis[root->left]=true;
                flag = true;
            }

            if(root->right != NULL and vis[root->right]==false){
                q.push(root->right);
                vis[root->right]=true;
                flag = true;
            }

            if(par[root]!=NULL and vis[par[root]]==false){
                q.push(par[root]);
                vis[par[root]]=true;
                flag = true;
            }
        }
        
        if(flag)time++;
    }
    return time;
}


int main(){
    Node *root=NULL;
    root = createTree();
    preorder(root);
    cout<<endl;

    int start = 3;
    Node *idx=NULL;
    idx = find_node(root,3);
    if(idx == NULL)cout<<"Node not found"<<endl;
    else{
        int burn = 0;
        burn = bfs(root,idx);
        cout<<"burn time "<<burn<<endl;
    }       
}