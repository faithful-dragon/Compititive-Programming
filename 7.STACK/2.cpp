// implement stack using array/vector
#include <iostream>
#include <vector>
using namespace std;

class StackNode{
    public:
    int data;
    StackNode *next;

    StackNode(int x){
        data = x;
        next = NULL;
    }
};

StackNode *push(int num, StackNode *top){
    StackNode *temp = new StackNode(num);
    if(top == NULL) return temp;
    temp->next = top;
    top = temp;
    return top;
}

StackNode *pop(StackNode *top){
    if(top == NULL){
        cout<<"stack is already empty"<<endl;
        return NULL;
    }
    StackNode *temp = top->next;
    delete top;
    top = temp;
    return top;
}

StackNode *Top(StackNode *top){
    return top;
}

void Display(StackNode *top){
    if(top == NULL){
        cout<<"stack is empty"<<endl;
        return;
    }
    StackNode *mover = top;
    cout<<endl<<"stack : "<<endl;
    while(mover!=NULL){
        cout<<mover->data<<endl;
        mover=mover->next;
    }
    cout<<endl<<endl;
}

bool isEmpty(StackNode *top){
    if(top == NULL)return true;
    else return false;
}

int Size(StackNode *top){
    int cnt=0;
    StackNode *mover = top;
    while(mover!=NULL){
        cnt++;
        mover=mover->next;
    }
    return cnt;
}

int main(){
    StackNode *st=NULL;
    int choice;
    int data;
    do{
        cout<<"press 1 to push element"<<endl;
        cout<<"press 2 to pop element"<<endl;
        cout<<"press 3 to get top element"<<endl;
        cout<<"press 4 to check is list is empty"<<endl;
        cout<<"press 5 to print size of stack"<<endl;
        cout<<"press 6 to display stack"<<endl;
        cout<<"press 0 to exit"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"enter data : ";
                cin>>data;
                st = push(data,st);
                break;
            case 2:
                st = pop(st);
                break;
            case 3:
                cout<<"top element : "<<Top(st)->data<<endl;
                break;
            case 4:
                if(isEmpty(st))cout<<"stack is empty"<<endl;
                else cout<<"stack is not empty"<<endl;
                break;
            case 5:
                cout<<"size of stack : "<<Size(st)<<endl;
                break;
            case 6:
                Display(st);
                break;
            default:
                if(choice==0)cout<<"Thank You!"<<endl;
                else cout<<"invalid option"<<endl;
                break;
        }

    }while(choice !=0);

    return 0;
}