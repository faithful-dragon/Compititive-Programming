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


// zig zig traversal
vector<vector<int>>zz_traversal(Node *root){
    vector<vector<int>>ans;
    queue<Node *>q;
    q.push(root);

    bool lr = true;
    while(q.empty()==false){
        int size = q.size();
        vector<int>v(size,0);

        for(int i=0;i<size;i++){
            Node *temp = q.front();
            q.pop();

            int idx = (lr)?i:(size-1-i);
            v[idx] = temp->data;

            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }

        lr = !lr;
        ans.push_back(v);
    }
    return ans;
}

// leaf node
bool isleaf(Node *root){
    if(root==NULL)return false;
    else if(root->left == NULL and root->right == NULL)return true;
    else return false;
}


// left_traversal
void left_traversal(Node *root, vector<int> &res){
    Node * curr = root->left;
    while(curr){
        if(isleaf(curr)==false)res.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else curr=curr->right;
    }
}


// addLeaves
void addleaf(Node *root, vector<int> &res){
    if(isleaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addleaf(root->left,res);
    if(root->right) addleaf(root->right,res);
}


// right_traversal
void right_traversal(Node *root, vector<int> &res){
    stack<int>st;
    Node * curr = root->right;
    while(curr){
        if(isleaf(curr)==false)st.push(curr->data);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
    }
    while(st.empty()==false){
        res.push_back(st.top());
        st.pop();
    }
}



// boundary traversal
vector<int> boundary(Node *root){
    vector<int>res;
    if(root==NULL)return res;
    if(isleaf(root)==false)res.push_back(root->data);
    left_traversal(root,res);
    addleaf(root,res);
    right_traversal(root,res);
    return res;
}


// vertical order traversal
vector<vector<int>> ver_order(Node *root){

    vector<vector<int>>res;
    if(root==NULL)return res;
    map<int,multiset<int>>mp;
    queue<pair<Node*,pair<int,int>>>q;
    pair<Node*,pair<int,int>>x,y;
    x.first = root;
    x.second.first=0;
    x.second.second=1;
    q.push(x);

    while(q.empty()==false){
        y = q.front();
        q.pop();

        mp[y.second.first].insert(y.first->data);
        if(y.first->left){
            x.first = y.first->left;
            x.second.first = y.second.first-1;
            x.second.second = y.second.second+1;
            q.push(x);
        }
        if(y.first->right){
            x.first = y.first->right;
            x.second.first = y.second.first+1;
            x.second.second = y.second.second+1;
            q.push(x);
        }
    }

    vector<int>v;
    for(auto a:mp){
        for(int x:a.second)v.push_back(x);
        res.push_back(v);
        v.clear();
    }

    return res;
}

// top veiw
vector<int> top_view(Node *root){
    vector<int>res;
    if(root==NULL)return res;
    map<int,int>mp;
    queue<pair<Node*, int>>q;
    q.push({root,0});
    while(q.empty()==false){
        Node *node = q.front().first;;
        int line = q.front().second;
        q.pop();
        if(mp.find(line)== mp.end())mp[line]=node->data;
        if(node->left != NULL)q.push({node->left,line-1});
        if(node->right != NULL)q.push({node->right,line+1});
    }

    for(auto a:mp){
        res.push_back(a.second);
    }
    return res;
}


// bottom veiw
vector<int> bottom_view(Node *root){
    vector<int>res;
    if(root==NULL)return res;
    map<int,int>mp;
    queue<pair<Node*, int>>q;
    q.push({root,0});
    while(q.empty()==false){
        Node *node = q.front().first;;
        int line = q.front().second;
        q.pop();
        mp[line]=node->data;
        if(node->left != NULL)q.push({node->left,line-1});
        if(node->right != NULL)q.push({node->right,line+1});
    }

    for(auto a:mp){
        res.push_back(a.second);
    }
    return res;
}

// left view
void left_view(Node *root, int lvl, vector<int>&res){
    if(root==NULL)return;
    if(lvl == res.size())res.push_back(root->data);
    if(root->left)left_view(root->left,lvl+1,res);
    if(root->right)left_view(root->right,lvl+1,res);
}

// right view
void right_view(Node *root, int lvl, vector<int>&res){
    if(root==NULL)return;
    if(lvl == res.size())res.push_back(root->data);
    if(root->right)right_view(root->right,lvl+1,res);
    if(root->left)right_view(root->left,lvl+1,res);
}

int main(){
    Node *root=NULL;
    root = createTree();
    preorder(root);
    cout<<endl;

    vector<vector<int>>ans;
    ans = zz_traversal(root);

    for(auto a:ans){
        for(int b:a)cout<<b<<" ";
        cout<<endl;
    }

    vector<int>b;
    cout<<"boundary : ";
    b = boundary(root);
    for(int c:b)cout<<c<<" ";
    cout<<endl;


    vector<vector<int>>res = ver_order(root);
    cout<<"vertical order : ";
    for(auto a:res){
        for(int b:a)cout<<b<<" ";
        cout<<endl;
    }

    vector<int>tv;
    cout<<"top_view : ";
    tv = top_view(root);
    for(int c:tv)cout<<c<<" ";
    cout<<endl;

    vector<int>bv;
    cout<<"bottom_view : ";
    bv = bottom_view(root);
    for(int c:bv)cout<<c<<" ";
    cout<<endl;

    vector<int>lv;
    cout<<"left_view : ";
    left_view(root,0,lv);
    for(int c:lv)cout<<c<<" ";
    cout<<endl;

    vector<int>rv;
    cout<<"right_view : ";
    right_view(root,0,rv);
    for(int c:rv)cout<<c<<" ";
    cout<<endl;
}
