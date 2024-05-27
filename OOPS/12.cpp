// ATM

#include <iostream>
using namespace std;


class ATM{
    private:
    int pin;
    int balance;
    int mob_no;
    string user_name;

    public:
    ATM(int p, int b, int m, string n){
        pin=p;
        balance=b;
        mob_no=m;
        user_name=n;
    }

    bool check_pin(int p){
        if(p==pin)return true;
        else return false;
    }

    void check_balance(){
        cout<<"Current Balance : ₹"<<balance<<endl;
    }

    void cash_withdraw(int amount){
        if(amount<=0){
            cout<<"enter valid amount"<<endl;
        }
        else if(amount>balance){
            cout<<"insufficient balance"<<endl;
        }
        else{
            balance = balance - amount;
            cout<<"Collect your amount."<<endl;
            cout<<"Available balance : ₹"<<balance<<endl;
        }
    }

    void get_user_details(){
        cout<<"User Details :"<<endl;
        cout<<"Name :"<<user_name<<endl;
        cout<<"Mobile No : "<<mob_no<<endl;
    }

    void update_mob_no(int num){
        if(num == mob_no){
            cout<<"previou number, kindly enter differnt number"<<endl;
        }
        else{
            mob_no = num;
            cout<<"mobile number successfully updated."<<endl;
        }
    }

    void change_pin(int p){
       if(p == pin){
            cout<<"previou pin, kindly enter differnt pin"<<endl;
        }
        else{
            pin = p;
            cout<<"pin successfully updated."<<endl;
        }
    }
};

int main(){
    ATM user1{000,10000,12345,"Pawan"};
    int pin;
    cout<<"Enter pin :";
    cin>>pin;

    if(user1.check_pin(pin)==false){
        cout<<"incorrect pin...!"<<endl;
    }
    else{
        cout<<"Welcome to IDBI bank"<<endl;
        int option=-1;
        do{
            cout<<"Press 1 to check balance"<<endl;
            cout<<"Press 2 to withdraw cash"<<endl;
            cout<<"Press 3 to get user details"<<endl;
            cout<<"Press 4 to update mobile number"<<endl;
            cout<<"Press 5 to change pin"<<endl;
            cout<<"Press 0 to exit"<<endl;

            cin>>option;
            switch(option){
                case 1:
                    user1.check_balance();
                    break;
                case 2:
                    int amount;
                    cout<<"enter amount : ";
                    cin>>amount;
                    user1.cash_withdraw(amount);
                    break;
                case 3:
                    user1.get_user_details();
                    break;
                case 4:
                    int number;
                    cout<<"enter new mobile number : ";
                    cin>>number;
                    user1.update_mob_no(number);
                    break;
                case 5:
                    int pin;
                    cout<<"enter new pin"<<endl;
                    cin>>pin;
                    user1.change_pin(pin);
                    break;
                default:
                    cout<<"enter valid option"<<endl;
                    break;
            }
        }while(option!=0);
        cout<<"Thanking for using IDBI ATM"<<endl;
    }

    return 0;
}


