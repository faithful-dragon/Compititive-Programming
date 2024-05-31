// circular linked list;

#include <iostream>
#include <vector>
using namespace std;

int len = 0;

class Node{
    public:
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

// length of linked list
int length_LL(Node *last){
    Node *mover = last;
    int len = 0;
    while(mover!=NULL){
        len++;
        mover = mover->next;
    }

    return len;
}

// insert node at beginning
Node *InsertAtBeg(int data, Node *last){
    Node *temp = new Node(data);
    if(last == NULL){
        temp->next = temp;
        return temp;
    }
    temp->next = last->next;
    last->next = temp;
    return last;
}

// insert node at end
Node *InsertAtEnd(int data, Node *last){
    Node *temp = new Node(data);
    if(last == NULL){
        temp->next = temp;
        return temp;
    }
    
    temp->next = last->next;
    last->next = temp;
    last = temp;
    return last;
}

// insert node at any poistion
Node *InsertAfter(int data, int item, Node *last){
    if(last->data == item) return InsertAtEnd(data,last);
    Node *temp = new Node(data);
    Node *mover = last->next;
    do{
        if(mover->data == item){
            cout<<mover->data<<endl;
            temp->next = mover->next;
            mover->next = temp;
            break;
        }
        else mover = mover->next;

    }while(mover != last->next);
    return last;
}

// delete node from beginning
Node *DeleteAtBeg(Node *last){
    if(last->next==last)return NULL;
    Node *del = last->next;
    last->next = del->next;
    delete del;
    return last;
}

// delete node at end
Node *DeleteAtEnd(Node *last){
    if(last->next==last)return NULL;
    Node *mover = last->next;
    while(mover->next->next!=last->next){
        mover = mover->next;
    }
    Node *del = last;
    mover->next = last->next;
    delete del;
    last = mover;
    return last;
}

// detete node at any position
Node *DeleteAtPos(int pos, Node *last){
    if(last->next==last)return NULL;
    if(pos==1)return DeleteAtBeg(last);
    if(pos>length_LL(last)){
        cout<<"position is more than linked list size"<<endl;
        return last;
    }
    Node *mover = last;
    while(pos>2){
        mover = mover->next;
        pos--;
    }   
    Node *del = mover->next;
    mover->next = mover->next->next;
    delete del;
    return last;
}

// array to linked list
Node *Array2LL(vector<int>arr){
    Node *mover = NULL;
    Node *last = mover;
    for(int x:arr){
        Node *temp = new Node(x);
        if(mover == NULL){
            mover = temp;
            last = temp;
        }
        else{
            mover->next = temp;
            mover = temp;
        }
    }
    return last;
}

//search element in link list O(N)
bool search(int n, Node *last){
    Node *mover = last;
    while(mover != NULL){
        if(mover->data == n)
            return true;
        mover = mover->next;
    }
    return false;
}

// reverse linked list
Node *reverse(Node *last){

    if (last == NULL || last->next == NULL)
        return last;

    Node *prev = NULL;
    Node *curr = last;
    Node *next = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// middle element
Node *middleEle(Node *last){
    Node *head = last->next;
    if(head == NULL)return NULL;
    else if(head->next == last)return last;
    Node *slow = head;
    Node *fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast != head and fast->next != head);
    return slow;
}

// display linked list
void display(Node *last){
    if(last == NULL){
        cout<<"empty cicular linked list"<<endl;
        return;
    }
    Node *mover = last->next;
    cout<<"linked list : ";
    do{
        cout<<mover->data<<" ";
        mover = mover->next;
    }while(mover != last->next);
    cout<<endl;
}

int main(){
    Node *last = NULL;
    Node *mid = NULL;
    int choice=-1;
    int data,pos;
    cout<<"enter choice : "<<endl;
    do{
        cout<<"press 1 to insert at beginning:"<<endl;
        cout<<"press 2 to insert at end:"<<endl;
        cout<<"press 3 to insert at any pos:"<<endl;
        cout<<"press 4 to delete at beginning:"<<endl;
        cout<<"press 5 to delete at end:"<<endl;
        cout<<"press 6 to delete at any pos:"<<endl;
        cout<<"press 7 to reverse list:"<<endl;
        cout<<"press 8 to find middle element:"<<endl;
        cout<<"press 9 to display:"<<endl;
        cout<<"press 10 to displar reverse:"<<endl;
        cout<<"press 0 to exit:"<<endl;
        cin>>choice;

        switch (choice){
        case 1:
            cout<<"data : ";
            cin>>data;
            last = InsertAtBeg(data,last);
            break;
        case 2:
            cout<<"data : ";
            cin>>data;
            last = InsertAtEnd(data,last);
            break;
        case 3:
            cout<<"data : ";
            cin>>data;
            cout<<"after which data : ";
            cin>>pos;
            last = InsertAfter(data,pos,last);
            break;
        case 4:
            last = DeleteAtBeg(last);
            break;
        case 5:
            last = DeleteAtEnd(last);
            break;
        case 6:
            int pos;
            cout<<"pos : ";
            cin>>pos;
            last = DeleteAtPos(pos,last);
            break;
        case 7:
            last = reverse(last);
            break;
        case 8:
            mid = middleEle(last);
            cout<<"middle element : "<<mid->data<<endl;
            break;
        case 9:
            cout<<"display   : ";
            display(last);
            break;
        case 10:
            cout<<"r.display : ";
            //reverse_display(last);
            break;
        default:
            if(choice == 0)cout<<"Thank You!"<<endl;
            else cout<<"please select correct option"<<endl;
            break;
        }

    }while(choice != 0);
    
    return 0;
}