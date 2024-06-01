// static member
// will allocate only one memory
// that memory is shared by each object
// belong to a class

#include <iostream>
using namespace std;

class number{
    private:
    int x;

    public:
    
    number(){
        x=1;
        y++;
    }

    static int y;
};

int number :: y = 0;

class number1{
    private:
    int x;

    public:
    
    number1(){
        x=1;
    }

    static int y;

    static int getstat(){
        y++;
        return y;
    }
};

int number1 :: y = 0;


int main(){
    
    cout<<number::y<<endl;
    number n1;
    number n2; 
    cout<<n1.y<<endl;
    cout<<n2.y<<endl;

    cout<<endl;

    cout<<number1::getstat()<<endl;
    number1 n11;
    number1 n22;
    cout<<number1::getstat()<<endl;
    cout<<n11.getstat()<<endl;
    cout<<n22.getstat()<<endl;

}