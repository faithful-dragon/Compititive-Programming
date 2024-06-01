// overiding member function
#include <iostream>
using namespace std;


class base{
    public:
    void msg(){
        cout<<"base class"<<endl;
    }
};

class derived:public base{
    public:
    void msg(){
        cout<<"derived class"<<endl;
        base::msg();   // will call base class
    }
};

int main(){
    base b;
    derived d;

    b.msg();
    d.msg();
}

