#include <iostream>
using namespace std;


class Phone{
    private:
    string Name,Processor;
    int RAM,Battery;

    public:
    Phone(string n, string p, int r, int b){
        Name=n;
        RAM=r;
        Processor=p;
        Battery = b;
    }

    void getInfo(){
        cout<<"Provided phone details are : "<<endl;
        cout<<"Name      : "<<Name<<endl;
        cout<<"RAM       : "<<RAM<<" GB"<<endl;
        cout<<"Processor : "<<Processor<<endl;
        cout<<"Battery   : "<<Battery<<" mAh"<<endl;
    }

};

int main(){
    string Name,Processor;
    int RAM,Battery;
    cout<<"Enter Phone Details : "<<endl;
    cout<<"Name : ";getline(cin, Name);
    cout<<"Processor : ";getline(cin, Processor);
    cout<<"RAM : ";cin>>RAM;
    cout<<"Battery : ";cin>>Battery;

    Phone p1{Name, Processor, RAM, Battery};
    cout<<endl;
    p1.getInfo();
    cout<<endl;

}

/*

Provided phone details are : 
Name      : Iphone 11 Pro
RAM       : 4 GB
Processor : hexa-core Apple A13 Bionic
Battery   : 3046 mAh

*/