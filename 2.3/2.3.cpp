#include <iostream>
using namespace std;

class Account
{
private:
    string name;
    int id;
    float balance;
public:

    //default constructor
    Account()
    {
        name="siya";
        id=11;
        balance = 0.0;
    }
    //parameterized constructor
    Account(string n,int i,float bal)
    {
        name=n;
        id=i;
        balance=bal;
    }
    void createAcc();
    void deposit();
    void withdraw();
    void display();
    int getID();
};

void Account :: createAcc()
{
        cout<<"Enter details:\n";
        cout<<"Enter name: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter id: ";
        cin>>id;
        cout<<"Enter balance: ";
        cin>>balance;
}

void Account :: deposit()
{
    float amt;
    cout << "Enter amount to deposit: ";
    cin >> amt;

    if (amt > 0)
        balance += amt;
    else
        cout << "Invalid amount!\n";
}

void Account :: withdraw()
{
    float amt;
    cout << "Enter amount to withdraw: ";
    cin >> amt;

    if (amt > balance)
        cout << "Insufficient balance!\n";
    else
        balance -= amt;
}

void Account :: display()
{
    cout << "\nName: " << name;
    cout << "\nID: " << id;
    cout << "\nBalance: " << balance << endl;
}

int Account :: getID()
{
    return id;
}


int main()
{
    Account a;
    cout<<"Account with default balance is created.\n";
    a.display();


    Account acc[10];
    int ch,n=0;
    x: cout<<"1) Create new account.\n";
    cout<<"2) Deposit money.\n";
    cout<<"3) Withdraw money.\n";
    cout<<"4) Display.\n";
    cout<<"5) Exit.\n";
    cout<<"Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
    case 1:
        {
            if (n<10)
            {
                acc[n].createAcc();
                n++;
            }

            goto x;
        }
    case 2:
        {
            int idd;
            cout << "Enter account ID: ";
            cin >> idd;

            for (int i = 0; i < n; i++)
            {
                if (acc[i].getID() == idd)
                {
                    acc[i].deposit();
                    break;
                }
            }
            goto x;
        }
    case 3:
        {
            int idd;
            cout << "Enter account ID: ";
            cin >> idd;

            for (int i = 0; i < n; i++)
            {
                if (acc[i].getID() == idd)
                {
                    acc[i].withdraw();
                    break;
                }
            }
            goto x;
        }
    case 4:
        {
             for (int i = 0; i < n; i++)
             {
                 acc[i].display();
             }
              goto x;
        }
    case 5:
        {
            cout<<"ThankYou";
            return 0;
        }
    default:
        {
            cout<<"Invalid choice.";
        }
    }
    return 0;
}
