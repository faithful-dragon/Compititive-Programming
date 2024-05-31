// single linked list
#include <iostream>
#include <vector>
using namespace std;

int len = 0;

class Node{
    public:
    int data;
    Node *next;

    Node(int d, Node *ptr){
        data = d;
        next = ptr;
    }
};

// length of linked list
int length_LL(Node *head){
    Node *mover = head;
    int len = 0;
    while(mover!=NULL){
        len++;
        mover = mover->next;
    }

    return len;
}

// insert node at beginning
Node *InsertAtBeg(int data, Node *head){
    Node *temp = new Node(data,NULL);
    if(head == NULL)return temp;
    temp->next = head;
    head = temp;
    return head;
}

// insert node at end
Node *InsertAtEnd(int data, Node *head){
    Node *temp = new Node(data,NULL);
    Node *mover = head;
    if(head == NULL)return temp;
    while(mover->next!=NULL){
        mover = mover->next;
    }
    mover->next = temp;
    return head;
}

// insert node at any poistion
Node *InsertAtPos(int data, int pos, Node *head){
    if(pos==1) return InsertAtBeg(data,head);
    if(pos>length_LL(head)){
        cout<<"position is more than linked list size"<<endl;
        return head;
    }
    Node *temp = new Node(data,NULL);
    Node *mover = head;
    while(pos>2){
        pos--;
        mover = mover->next;
    }
    temp->next = mover->next;
    mover->next = temp;
    return head;
}

// delete node from beginning
Node *deleteAtBeg(Node *head){
    Node *temp = head->next;
    delete head;
    head = temp;
    return head;
}

// delete node at end
Node *deleteAtEnd(Node *head){
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
Node *deleteAtPos(int pos, Node *head){
    if(pos==1)return deleteAtBeg(head);
    if(pos>length_LL(head)){
        cout<<"position is more than linked list size"<<endl;
        return head;
    }
    Node *mover = head;
    while(pos>2){
        mover = mover->next;
        pos--;
    }   
    Node *del = mover->next;
    mover->next = mover->next->next;
    delete del;
    return head;
}

// array to linked list
Node *Array2LL(vector<int>arr){
    Node *mover = NULL;
    Node *head = mover;
    for(int x:arr){
        Node *temp = new Node(x,NULL);
        if(mover == NULL){
            mover = temp;
            head = temp;
        }
        else{
            mover->next = temp;
            mover = temp;
        }
    }
    return head;
}

//search element in link list O(N)
bool search(int n, Node *head){
    Node *mover = head;
    while(mover != NULL){
        if(mover->data == n)
            return true;
        mover = mover->next;
    }
    return false;
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
        prev = curr;
        curr = next;
    }
    return prev;
}


//Function to check whether two linked lists are identical or not. 
bool areIdentical(Node *head1,Node *head2){
    Node *a = head1;
    Node *b = head2;
    
    while(a!=NULL){
        if(a->data != b->data)return false;
        a=a->next;
        b=b->next;
        if(b==NULL)break;
    }
    if(a!=NULL)return false;
    if(b!=NULL)return false;
    return true;
}


// middle element
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

// display linked list
void display(Node *head){
    Node *mover = head;
    if(head == NULL)return;
    cout<<"linked list : ";
    while(mover != NULL){
        cout<<mover->data<<" ";
        mover = mover->next;
    }
    cout<<endl;
}


int main(){
    Node *head1 = new Node(1,NULL);
    cout<<head1->data<<" "<<head1->next<<endl;

    vector<int>arr{1,2,3,4,5,6,7,8,9,10};
    Node *head=NULL;

    head = Array2LL(arr);
    display(head);

    head = InsertAtBeg(0,head);
    display(head);

    head = InsertAtEnd(11,head);
    display(head);

    head = InsertAtPos(-1,1,head);
    display(head);

    head = InsertAtPos(4,6,head);
    display(head);

    head = InsertAtPos(11,14,head);
    display(head);
    cout<<"len : "<<length_LL(head)<<endl;

    head = deleteAtBeg(head);
    display(head);

    head = deleteAtEnd(head);
    display(head);

    head = deleteAtPos(1,head);
    display(head);

    head = deleteAtPos(6,head);
    display(head);

    head = deleteAtPos(11,head);
    display(head);

    if(search(2,head))cout<<"found"<<endl;
    else cout<<"not found"<<endl;

    if(search(5,head))cout<<"found"<<endl;
    else cout<<"not found"<<endl;

    display(head);
    head = reverse(head);
    display(head);

    Node *mid_elm = middleEle(head);
    cout<<mid_elm->data<<endl;

    Node *a = new Node(10,NULL);
    mid_elm = middleEle(a);
    cout<<mid_elm->data<<endl;

    Node *b = NULL;
    mid_elm = middleEle(b);
    if(mid_elm==NULL)cout<<"NULL"<<endl;
    else cout<<mid_elm->data<<endl;

    head = deleteAtBeg(head);
    display(head);

    mid_elm = middleEle(head);
    cout<<mid_elm->data<<endl;

    head = deleteAtPos(5,head);
    display(head);

    mid_elm = middleEle(head);
    cout<<mid_elm->data<<endl;

}

