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

// symmetric
bool sym(Node *a){
    if(a==NULL)return true;
    if(a->left == NULL or a->right == NULL) return a->left == a->right;
    if(a->left->data!=a->right->data)return false;
    return (a->left) and (a->right);
}

// path tp node x
bool find_path(Node *root, int x, vector<int>&path){
    if(root==NULL)return false;

    path.push_back(root->data);
    if(root->data ==x)return true;
    if(find_path(root->left,x,path)==true or find_path(root->right,x,path)==true)return true;
    path.pop_back();
    return false;
}

// lca
Node *lca(Node *root, int x, int y){
    if(root ==NULL or root->data == x or root->data == y)return root;
    Node *lt = lca(root->left,x,y);
    Node *rt = lca(root->right,x,y);
    if(lt==NULL)return rt;
    else if(rt==NULL)return lt;
    else return root; 
}

// width
int width(Node *root){
    int ans = 0;
    if(root==NULL)return ans;
    queue<pair<Node*, int>>q;
    q.push({root, 0});

    while(q.empty()==false){
        int size = q.size();
        int mini = q.front().second;
        int first, last;
        for(int i=0;i<size;i++){
            int pos = q.front().second-mini;
            Node *temp = q.front().first;
            q.pop();
            if(i==0)first = pos;
            if(i==size-1)last = pos;
            if(temp->left)q.push({temp->left,2*pos+1});
            if(temp->right)q.push({temp->right,2*pos+2});
        }

        ans = max(ans,last-first+1);
    }
    return ans;
}

// children sum property
void rearrange(Node *root){
    if(root == NULL)return;
    int child = 0;
    if(root->left)child+=root->left->data;
    if(root->right)child+=root->right->data;

    if(child < root->data){
        if(root->left)root->left->data = root->data;
        if(root->right)root->right->data = root->data;
    }

    rearrange(root->left);
    rearrange(root->right);

    int x = 0;
    if(root->left)x+=root->left->data;
    if(root->right)x+=root->right->data;
    if(root->left or root->right)root->data = x;
}

int main(){
    Node *root=NULL;
    root = createTree();
    preorder(root);
    cout<<endl;

    bool s = sym(root);
    if(s)cout<<"symmetric"<<endl;
    else cout<<"not symmetric"<<endl;

    int x = 9;
    vector<int>path;
    bool found;
    found = find_path(root,x,path);
    if(found){
        cout<<"path to "<<x<<" : ";
        for(int p:path)cout<<p<<" ";
        cout<<endl;
    }
    else cout<<"Not found"<<endl;

    int y = 2;
    Node *lc = lca(root,x,y);
    if(lc == NULL){
        cout<<"no lca found"<<endl;
    }
    else{
        cout<<"lowest lca : "<<lc->data<<endl;
    }

    int w;
    w= width(root);
    cout<<"width : "<<w<<endl;
}