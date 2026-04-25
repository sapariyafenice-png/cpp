#include <iostream>
using namespace std;

string logArr[50];
int i = 0;

void addLog(string msg) {
    logArr[i++] = msg;
}

class BankAccount {
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void deposit(double amt) {
        addLog("Enter deposit()");
        if (amt <= 0)
            throw "Invalid deposit amount";

        balance += amt;
        addLog("Deposit done");
    }

    void withdraw(double amt) {
        addLog("Enter withdraw()");
        if (amt > balance)
            throw "Not enough balance";

        balance -= amt;
        addLog("Withdraw done");
    }
};

void func2(BankAccount &acc) {
    addLog("Enter func2()");
    acc.withdraw(5000);
    addLog("Exit func2()");
}

void func1(BankAccount &acc) {
    addLog("Enter func1()");
    func2(acc);
    addLog("Exit func1()");
}

int main() {
    try {
        addLog("Enter main()");

        BankAccount acc(2000);
        acc.deposit(1000);

        func1(acc);

        addLog("Exit main()");
    }
    catch (const char* msg) {
        addLog("Exception caught in main()");
        cout << msg << endl;
    }

    cout << "\nLogs:\n";
    for (int j = 0; j < i; j++) {
        cout << logArr[j] << endl;
    }

    return 0;
}
