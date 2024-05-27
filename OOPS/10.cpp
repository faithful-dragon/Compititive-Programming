// base class pointer and derived class object can access only base members/functoins



#include <iostream>
using namespace std;


class base{
    public:
    void fun(){
        cout<<"base class"<<endl;
    }

    ~base(){
        cout<<"base class destructed "<<endl;
    }
};

class derived1:public base{
    public:
    void fun(){
        cout<<"derived class 1"<<endl;
    }
};

class derived2:public base{
    public:
    void fun(){
        cout<<"derived class 2"<<endl;
    }
    ~derived2(){
        cout<<"derived1 class destructed "<<endl;
    }

};

class base1{
    public:
    virtual void fun(){
        cout<<"base class"<<endl;
    }

    virtual ~base1(){
        cout<<"virtual base class destructed "<<endl;
    }
};

class derived11:public base1{
    public:
    void fun(){
        cout<<"derived class 1"<<endl;
    }
};

class derived22:public base1{
    public:
    void fun(){
        cout<<"derived class 2"<<endl;
    }

    ~derived22(){
        cout<<"derived1 class destructed "<<endl;
    }
};

int main(){
    
    base *ptr;
    ptr = new derived1;
    ptr->fun();
    ptr = new derived2;
    ptr->fun();

    cout<<endl;

    base1 *ptr1;
    ptr1 = new derived11;
    ptr1->fun();
    ptr1 = new derived22;
    ptr1->fun();


    // to delete whole object we need to make virtual destructor
    delete ptr;
    cout<<endl;
    delete ptr1;

}


