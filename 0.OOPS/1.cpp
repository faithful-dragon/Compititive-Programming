// characteristics of oops
// 1 class
// 2 object
/*
Class is a blueprint and Object is instance of class.
-> Class is a user-defined data type, which holds its own data members and member functions.
-> Helps in code reusability
*/


// 3 Encapsulation
/*
Encapsulation wraping up variables and methods in class.
-> It help in data hiding
*/

// 4 Polymorphism
/*
Polymorphism means having many forms
In class method may behave differently, depending on the inputs. function overloading
*/

// 5 Inhertence
/*
Inheritance means property of a child class to inherit characteristic of parent class.
like :-
Dog, Cat, Cow Class Inherit from Animal Class.
*/
// 6 Abstraction
// means hiding complecated things


#include <iostream>
using namespace std;

/*
member function will be shared by each object.
member variable will be created for each object defined!.
private variables can be accessed by class itself only
protected variables can be used within class and by the inheritent class only
public variable can be used anywhere in program
*/
class house{
    private:        // access specifier
    int length;     // member variable
    int breadth;    // member variable

    public:

    int lb=0;

    void setData(int x, int y){      // member function
        length=x;
        breadth=y;
    }

    void area(){                    // member function
        cout<<"area : "<<length*breadth<<endl;
    }
};

int main(){
    house h1;        // memory allocated to object h1
    int x,y;
    cout<<"enter values : ";
    cin>>x>>y;
    h1.setData(x,y);
    h1.area();

    // h1.lenght will show error as length is private and can't be used outside class
    h1.lb = 10;  // lb is public variable and can be used outside the class;

    return 0;
}