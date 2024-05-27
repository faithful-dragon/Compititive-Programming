#include <iostream>
using namespace std;


class base{
    public:
    base(){
        cout<<"1 base default constructor"<<endl;
    }
    base(int n){
        cout<<"2 base parametrized constructor "<<n<<endl;
    }
};

class derived : public base{
    public:
    derived():base(){
        cout<<"3 derived default constructor"<<endl;
    }

    derived(int n):base(){
        cout<<"4 derived default constructor : "<<n<<endl;
    }
};

int main(){
    base b;
    base b2(10);
    derived d;
    derived d2(20);    // default of base and parametrized constructor of derived class is called.
}

