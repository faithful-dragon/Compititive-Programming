// constructor and inheritence
// first default constructor of base then of derived is called
// only parametrized constructor of derived class is called.

#include <iostream>
using namespace std;


class base{
    public:
    base(){
        cout<<"base default constructor"<<endl;
    }
    // base(int x=0){
    //     cout<<"parametric constrcutor "<<x<<endl;
    // }
};

class derived:public base{
    public:
    // derived(){
    //     cout<<"derived default constructor "<<endl;
    // }
    derived(int x=1){
        cout<<"parametric constructor "<<x<<endl;
    }
};


int main(){
    //derived d1;
    derived d2(3);
    //base b(10);

    return 0;
}