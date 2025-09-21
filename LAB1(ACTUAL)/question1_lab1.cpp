#include <iostream>
using namespace std;

class BankAcc {
private:
    double balance;

public:
    BankAcc() {
        balance = 0;
    }

    BankAcc(double initialB) {
        balance = initialB;
    }

    BankAcc(BankAcc& a) {
        balance = a.balance;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "not enough funds" << endl;
        }
    }

    double getBal() const {
        return balance;
    }
};

int main() {
    BankAcc acc1;
    cout << "Balance of account1: " << acc1.getBal() << endl;

    BankAcc acc2(1000.0);
    cout << "Balance of account2: " << acc2.getBal() << endl;

    BankAcc acc3(acc2);
    acc3.withdraw(200.0);
    cout << "Balance of acc3 after withdrawal: " << acc3.getBal() << endl;

    cout << "Balance of acc2 after acc3 transaction: " << acc2.getBal() << endl;

    return 0;
}

