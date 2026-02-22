#include <iostream>
using namespace std;

class Wallet
{
private:
    int id;
    string username;
    int balance;
public:
    void setValues(int n, string name, int bal);
    int loadMoney(int amt);
    int transferMoney(Wallet &receiver, int amt);
    void display();
};

void Wallet :: setValues(int n, string name, int bal)
    {
        id=n;
        username=name;
        balance= bal;
    }

int Wallet :: loadMoney(int amt)
    {
        balance+=amt;
        return balance;
    }
int Wallet :: transferMoney( Wallet &receiver, int amt)
    {
       if (amt <= 0)
        {
            cout << "Invalid amount.\n";
            return 0;
        }
        else if (amt > balance)
        {
            cout << "Insufficient balance.\n";
            return 0;
        }
        else
        {
            balance -= amt;
            receiver.balance += amt;
            cout << "Transfer successful.\n";
            return 0;
        }
    }
void Wallet :: display()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"USERNAME: "<<username<<endl;
        cout<<"BALANCE: "<<balance<<endl;
    }

int main()
{
    Wallet w1,w2;
    int ch;
    int id,balance;
    string username;
    cout<<"Enter details for wallet 1:"<<endl;
    cout<<"ID: ";
    cin>>id;
    cout<<"Username: ";
    cin.ignore();
    getline(cin,username);
    cout<<"Balance: ";
    cin>>balance;
    cout<<endl;

    w1.setValues(id,username,balance);


    cout<<"Enter details for wallet 2:"<<endl;
    cout<<"ID: ";
    cin>>id;
    cout<<"Username: ";
    cin.ignore();
    getline(cin,username);
    cout<<"Balance: ";
    cin>>balance;
    cout<<endl;

    w2.setValues(id,username,balance);

    r: cout<<"1) Load money"<<endl;
    cout<<"2) Transfer money"<<endl;
    cout<<"3) Display details"<<endl;
    cout<<"4) Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
    case 1:
        {
            int amt,n;
            cout<<"In which wallet you want to add money: ";
            cin>>n;
            cout<<"Enter the amount you want to load: ";
            cin>>amt;
            if(n==1)
            {
                cout<<"Current balance is: "<<w1.loadMoney(amt)<<endl;
            }
            else if(n==2)
            {
                cout<<"Current balance is: "<<w2.loadMoney(amt)<<endl;
            }
            else
            {
                cout<<"Wallet does not exist"<<endl;
            }

            goto r;
        }
    case 2:
        {
            int n,amt;
            cout<<"From which wallet you want to transfer money: ";
            cin>>n;
            cout<<"Enter the amount you want to transfer: ";
            cin>>amt;
            if(n==1)
            {
                w1.transferMoney(w2, amt);
            }
            else if(n==2)
            {
                w2.transferMoney(w1, amt);
            }
            else
            {
                cout<<"wallet does not exist.";
            }

            goto r;
        }
    case 3:
        {
            w1.display();
            w2.display();
            goto r;
        }
    case 4:
        {
            cout<<"THANK YOU!";
            break;
        }
    default:
        {
            cout<<"Invalid choice entered";
        }
    }

}
