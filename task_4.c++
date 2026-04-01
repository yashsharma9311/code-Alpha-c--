#include<iostream>
#include<vector>
using namespace std;

class Transaction {
public:
    string type;
    float amount;
    Transaction(string t, float a){
        type = t;
        amount = a; 
    }
};

class Account {
public:
int accNo;
float balance;
vector<Transaction> history;

Account(int no){
    accNo = no;
    balance = 0;
}
void deposit(float amount){
    balance += amount;
    history.push_back(Transaction("Deposit", amount));
    cout<<"Deposited: "<<amount<<endl;  
}

void withdraw(float amount){
    if(amount > balance){
        cout<<"Insufficient funds! Withdrawal failed.\n";
    }else{
        balance -= amount;
        history.push_back(Transaction("Withdrawal", amount));
        cout<<"Withdrew: "<<amount<<endl;
    }  
}

void showBalance(){
    cout<<"Current Balance: "<<balance<<endl;
}

void showTransactions(){
    cout<<"\nTransaction History:\n";
    for(const auto& t : history){
        cout<<t.type<<": "<<t.amount<<endl;
    }
}
};

class customer {
public:
string name;
Account account;
customer(string n, int accNo) : account(accNo){
    name = n;
}

void showDetails(){
    cout<<"Customer Name: "<<name<<endl;
    cout<<"Account Number: "<<account.accNo<<endl;
    account.showBalance();
}
};
int main(){
    string name;
    int accNo;

    cout<<"Enter customer name: ";
    cin>>name;

    cout<<"Enter account number: ";
    cin>>accNo;

    customer customer(name, accNo);

    int choice;
    float amount;

    do{
        cout<<"\n===MENU===\n";
        cout<<"1. Deposit\n";
        cout<<"2. Withdraw\n";
        cout<<"3. Show Balance\n";
        cout<<"4. Show Transactions\n";
        cout<<"5. Exit\n";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter amount to deposit: ";
                cin>>amount;
                customer.account.deposit(amount);
                break;
            case 2:
                cout<<"Enter amount to withdraw: ";
                cin>>amount;
                customer.account.withdraw(amount);
                break;
            case 3:
                customer.account.showBalance();
                break;
            case 4:
                customer.account.showTransactions();
                break;
            case 5:
                cout<<"Exiting the program. Goodbye!\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    } while(choice != 5);

    return 0;
}