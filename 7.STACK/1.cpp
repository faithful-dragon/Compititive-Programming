// implement stack using array/vector
#include <iostream>
#include <vector>
using namespace std;

class Stack{
    private:
    int top;
    int mx_size;
    vector<int>st;

    public:
    Stack(int size){
        st.resize(size,-1); 
        top = -1;
        mx_size = size;
    }

    void push(int n){
        if(top == mx_size-1){
            cout<<"stack is full"<<endl;
        }
        else{
            top++;
            st[top]=n;
            cout<<"element added successfully"<<endl;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"stack is already empty"<<endl;
        }
        else{
            cout<<st[top]<<" removed successfully"<<endl;
            top--;
        }
    }

    int Top(){
        if(top==-1){
            cout<<"stack is already empty"<<endl;
            return -1;
        }
        else{
            return st[top];
        }
    }

    bool isEmpty(){
        if(top == -1)return true;
        return false;
    }

    bool isFull(){
        if(top == mx_size-1)return true;
        return false;
    }

    int size(){
        return top+1;
    }

    void display(){
        cout<<endl;
        int j = top;
        while(j>=0){
            cout<<st[j]<<endl;
            j--;
        }
        cout<<endl;
    }
};

int main(){
    int n;
    cout<<"enter size of stack : ";
    cin>>n;

    Stack st(n);
    int choice;
    int data;
    do{
        cout<<"press 1 to push element"<<endl;
        cout<<"press 2 to pop element"<<endl;
        cout<<"press 3 to get top element"<<endl;
        cout<<"press 4 to check is list is empty"<<endl;
        cout<<"press 5 to check is list is full"<<endl;
        cout<<"press 6 to print size of stack"<<endl;
        cout<<"press 7 to display stack"<<endl;
        cout<<"press 0 to exit"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"enter data : ";
                cin>>data;
                st.push(data);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                cout<<"top element : "<<st.Top()<<endl;
                break;
            case 4:
                if(st.isEmpty())cout<<"stack is empty"<<endl;
                else cout<<"stack is not empty"<<endl;
                break;
            case 5:
                if(st.isFull())cout<<"stack is full"<<endl;
                else cout<<"stack is not full"<<endl;
                break;
            case 6:
                cout<<"size of stack : "<<st.size()<<endl;
                break;
            case 7:
                st.display();
                break;
            default:
                if(choice==0)cout<<"Thank You!"<<endl;
                else cout<<"invalid option"<<endl;
                break;
        }

    }while(choice !=0);

    return 0;
}