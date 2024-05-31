// double linked list
#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};

// length of list
int length_LL(Node *head){
    Node *mover = head;
    int len = 0;
    while(mover!=NULL){
        len++;
        mover = mover->next;
    }

    return len;
}

// insert at beginning
Node *InsertAtBeg(int data, Node *head){
    Node *temp = new Node(data);
    if(head == NULL)return temp;
    head->prev = temp;
    temp->next = head;
    head = temp;
    return head;
}

// insert node at end
Node *InsertAtEnd(int data, Node *head){
    Node *temp = new Node(data);
    Node *mover = head;
    if(head == NULL)return temp;
    while(mover->next!=NULL){
        mover = mover->next;
    }
    mover->next = temp;
    temp->prev = mover;
    return head;
}

// insert node at any poistion
Node *InsertAtPos(int data, int pos, Node *head){
    if(pos==1) return InsertAtBeg(data,head);
    if(pos>length_LL(head)){
        cout<<"position is more than linked list size"<<endl;
        return head;
    }
    Node *temp = new Node(data);
    Node *mover = head;
    while(pos>2){
        pos--;
        mover = mover->next;
    }
    temp->next = mover->next;
    temp->prev = mover;
    mover->next->prev = temp;
    mover->next = temp;
    return head;
}

// delete node from beginning
Node *DeleteAtBeg(Node *head){
    Node *temp = head->next;
    delete head;
    temp->prev = NULL;
    head = temp;
    return head;
}

// delete node at end
Node *DeleteAtEnd(Node *head){
    Node *temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    Node *del = temp->next;
    delete del;
    temp->next = NULL;
    return head;
}

// detete node at any position
Node *DeleteAtPos(int pos, Node *head){
    if(pos==1)return DeleteAtBeg(head);
    if(pos>length_LL(head)){
        cout<<"position is more than linked list size"<<endl;
        return head;
    }
    if(pos == length_LL(head))return DeleteAtEnd(head);
    Node *mover = head;
    while(pos>2){
        mover = mover->next;
        pos--;
    }   
    Node *del = mover->next;
    mover->next = mover->next->next;
    mover->next->prev = mover;
    delete del;
    return head;
}

// reverse linked list
Node *reverse(Node *head){

    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
}

// find middle element
Node *middleEle(Node *head){
    if(head == NULL)return NULL;
    else if(head->next == NULL)return head;
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// display double linked list
void display(Node *head){
    Node *mover = head;
    while(mover != NULL){
        cout<<mover->data<<" ";
        mover = mover->next;
    }
    cout<<endl;
}

// find tail pointer
Node *find_tail(Node *head){
    Node *tail = head;
    while(tail->next!=NULL)
        tail = tail->next;
    return tail;
}
// reverse display
void reverse_display(Node *head){
    Node *tail = find_tail(head);
    while(tail != NULL){
        cout<<tail->data<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}

int main(){
    Node *head = NULL;
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
            head = InsertAtBeg(data,head);
            break;
        case 2:
            cout<<"data : ";
            cin>>data;
            head = InsertAtEnd(data,head);
            break;
        case 3:
            cout<<"data : ";
            cin>>data;
            cout<<"pos : ";
            cin>>pos;
            head = InsertAtPos(data,pos,head);
            break;
        case 4:
            head = DeleteAtBeg(head);
            break;
        case 5:
            head = DeleteAtEnd(head);
            break;
        case 6:
            int pos;
            cout<<"pos : ";
            cin>>pos;
            head = DeleteAtPos(pos,head);
            break;
        case 7:
            head = reverse(head);
            break;
        case 8:
            mid = middleEle(head);
            cout<<"middle element : "<<mid->data<<endl;
            break;
        case 9:
            cout<<"display   : ";
            display(head);
            break;
        case 10:
            cout<<"r.display : ";
            reverse_display(head);
            break;
        default:
            if(choice == 0)cout<<"Thank You!"<<endl;
            else cout<<"please select correct option"<<endl;
            break;
        }

    }while(choice != 0);
    
    return 0;
}