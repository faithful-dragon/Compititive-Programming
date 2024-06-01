// inheritence

/*

public : child or grand child can use protected and public members only without losing its type
protected : protected will be protected and public will also be protected


*/

#include <iostream>
using namespace std;

class rectangle{
    public:
    int lenght;
    int breadth;

    rectangle(int l=0, int b=0){
        lenght = l;
        breadth = b;
    }

    void area(){
        cout<<"area = "<<lenght*breadth<<endl;
    }
};

class cuboid:public rectangle{
    public:
    int height;
    cuboid(int l=0, int b=0, int h=0){
        lenght=l;
        breadth=b;
        height=h;
    }

    void volume(){
        cout<<"volume : "<<lenght*breadth*height<<endl;
    }
};

int main(){
    
    rectangle r{4,5};
    r.area();
    cuboid c(2,3,4);
    c.volume();

    return 0;
}