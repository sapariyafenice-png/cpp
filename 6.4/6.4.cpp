#include <iostream>
using namespace std;


class Account {
protected:
    int accNo;
    float balance;
    float lastTransaction;

public:
    Account(int a = 0, float b = 0) {
        accNo = a;
        balance = b;
        lastTransaction = 0;
    }

    void deposit(float amount) {
        balance += amount;
        lastTransaction = amount;
    }

    virtual void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            lastTransaction = -amount;
        } else {
            cout << "Insufficient balance\n";
        }
    }

    void undo() {
        balance -= lastTransaction;
        cout << "Last transaction undone\n";
    }

    virtual void display() {
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
};


class Savings : public Account {
    float interest;

public:
    Savings(int a, float b, float r) : Account(a, b) {
        interest = r;
    }

    void addInterest() {
        float i = balance * interest / 100;
        balance += i;
        lastTransaction = i;
    }

    void display() {
        Account::display();
        cout << "Interest Rate: " << interest << "%" << endl;
    }
};

class Current : public Account {
    float overdraft;

public:
    Current(int a, float b, float o) : Account(a, b) {
        overdraft = o;
    }

    void withdraw(float amount) {
        if (amount <= balance + overdraft) {
            balance -= amount;
            lastTransaction = -amount;
        } else {
            cout << "Overdraft limit exceeded\n";
        }
    }

    void display() {
        Account::display();
        cout << "Overdraft Limit: " << overdraft << endl;
    }
};

int main() {
    Savings s(101, 1000, 5);
    Current c(201, 500, 2000);

    cout << "\nSavings Account\n";
    s.deposit(500);
    s.addInterest();
    s.withdraw(200);
    s.display();

    s.undo();
    s.display();

    cout << "\nCurrent Account\n";
    c.deposit(300);
    c.withdraw(2000);
    c.display();

    c.undo();
    c.display();

    return 0;
}
