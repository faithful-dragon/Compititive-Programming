// operator overloading
#include <iostream>
using namespace std;

class A{
    private:
    int w;

    public:
    A(int x=0){
        w=x;
    }

    void get_sum(){
        cout<<"sum = "<<w<<endl;
    }

    // operator overloading
    A operator+(A a){
        A temp;
        temp.w = w + a.w;
        return temp;
    }

    void operator++(){    // pre increment
        ++w;
    }

    void operator++(int){    // post increment  , use int in bracket
        w++;
    }

};

int main(){
    int a, b, c;
    a=12;
    b=45;
    c = a+b;

    cout<<"sum = "<<c<<endl;
    A a1{12},a2{45},a3;

    // a3 = a1 + a2;     will show error if we add without creating operator+ function

    a3 = a1 + a2;
    a3.get_sum();
    cout<<endl;

    a1.get_sum();
    a1++;
    a1.get_sum();
    ++a1;
    a1.get_sum();


}