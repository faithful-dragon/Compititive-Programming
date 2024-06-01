/*
constructor
-> same name as of class
-> no return type
*/



#include <iostream>
using namespace std;

// non-parametrized constructor
// use to give default value to private variable otherwise garbage value will be intialized to them.
class person{
    private:
    string name;
    int age;
    float height;

    public:
    person(){          // no parameters,       
        name = "XYZ";
        age = 0;
        height = 0.0f;
    }

    void getInfo(){
        cout<<"Name   : "<<name<<endl;
        cout<<"Age    : "<<age<<endl;
        cout<<"Height : "<<height<<endl;
    }
};


// parametrized constructor
class student{
    private:
    string name;
    int rollno;

    public:
    student(string s, int x){    // constructor
        name = s;
        rollno = x;
    }

    void get_info(){
        cout<<"Name   : "<<name<<endl;
        cout<<"Rollno : "<<rollno<<endl;
    }
};


// default constructor
// will assign garbage value itself to private variables
class car{
    private:
    string name;
    float milage;

    public:

    void get_info(){
        cout<<"Name   : "<<name<<endl;
        cout<<"Milage : "<<milage<<endl;
    }
};


// copy constructor
// create new object from existing object
class prison{
    private:
    string name;
    int age;
    float height;

    public:
    prison(string n, int a, float h){       // normal constructor       
        name = n;
        age = a;
        height = h;
    }

    prison(prison &p){                      // copy constructor
        name = p.name;
        age = p.age;
        height = p.height;
    }

    void getInfo(){
        cout<<"Name   : "<<name<<endl;
        cout<<"Age    : "<<age<<endl;
        cout<<"Height : "<<height<<endl;
    }
};


// overload constructor
class prison2{
    private:
    string name;
    int age;
    float height;

    public:
    prison2(string n="NULL", int a=0, float h=0.0){       // overload constructor       
        name = n;
        age = a;
        height = h;
    }

    void getInfo(){
        cout<<"Name   : "<<name<<endl;
        cout<<"Age    : "<<age<<endl;
        cout<<"Height : "<<height<<endl;
    }
};


int main(){

    person p1;
    p1.getInfo();
    cout<<endl;

    student s1{"Pawan Kumar", 20095079};
    s1.get_info();
    cout<<endl;


    car c1;
    c1.get_info();
    cout<<endl;

    prison pr1{"Pawan", 24, 5.7};
    prison pr2(pr1);

    pr1.getInfo();
    pr2.getInfo();   // p1 and p2 are same
    cout<<endl;

    prison2 pr3{"Pawan", 24, 5.7},pr4;
    pr3.getInfo();  // print assigned value
    pr4.getInfo();  // print default value

    return 0;
}

