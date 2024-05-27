#include <iostream>
using namespace std;


class base{
    private:
    int a;

    protected:
    int b;
    
    public:
    int c;
};

class derived1:private base{
    private:
    int a1;

    protected:
    int b1;
    
    public:
    int c1;
};

class derived2:protected base{
    private:
    int a2;

    protected:
    int b2;
    
    public:
    int c2;
};
class derived3:public base{
    private:
    int a3;

    protected:
    int b3;
    
    public:
    int c3;
};

int main(){
    base b;
    // b.a=2;
    // b.b=2;
    b.c = 10;

    derived1 d1;  
    // d1.a=1;
    // d1.b =2;
    // d1.c=1;
    // d1.a1 = 1;
    // d1.b1 = 1;
    d1.c1 = 1;

    derived2 d2;
    // d2.a=1;
    // d2.b =2;
    // d2.c=1;
    // d2.a2 = 1;
    // d2.b2 = 1;
    d2.c2 = 1;

    derived3 d3;
    // d3.a=1;
    // d3.b =2;
    d3.c=1;
    // d3.a3 = 1;
    // d3.b3 = 1;
    d3.c3 = 1;
}

