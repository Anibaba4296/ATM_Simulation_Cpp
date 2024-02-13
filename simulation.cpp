#include<bits/stdc++.h>
using namespace std;

class ATM {
private:
    int balance;
    vector<pair<string,int> > history;

public:
    ATM(int balance=0){
        this->balance = balance;
    }
        
    void deposit(int amount){
        balance += amount;
        history.push_back(make_pair("Deposit", amount));
        cout << "Deposit successfully" << endl;
    }

    int getBalance(){
        return balance;
    }

    bool withdraw(int amount){
        if(balance < amount){
            return false;
        } else {
            balance -= amount;
            history.push_back(make_pair("Withdraw", amount));
            return true;
        }
    }

    void showHistory(){
        for(int i = 0; i < history.size(); i++){
            cout << history[i].first << " : " << history[i].second << endl;
        }
        cout << "Current balance : " << getBalance() << endl;
    }

    bool transfer(ATM &receiver, int amount) {
        if (balance < amount) {
            return false;
        } else {
            balance -= amount;
            receiver.deposit(amount);
            history.push_back(make_pair("Transfer to", amount));
            return true;
        }
    }
};

int main(){
    ATM user1;
    ATM user2;
    ATM *activeUser = &user1; // Pointer to track the active user
    int choice;
    cout << "---------- Welcome to ATM ----------" << endl;
    cout << "--------------- Menu --------------- " << endl;
    do {
        cout << "------------------------------------ " << endl;
        cout << "1. Show Balance" << endl;
        cout << "2. Withdraw Amount" << endl;
        cout << "3. Deposit Amount" << endl;
        cout << "4. Transaction History" << endl;
        cout << "5. Switch User" << endl; 
        cout << "6. Transfer Money"<<endl;
        cout << "7. Exit" << endl;
        cout << "------------------------------------ " << endl;
        cout << "choose an option" << endl;
        cin >> choice;
        string receiver;
        switch (choice) {
            case 1:
                // checking the balance
                cout << "Available Balance : " << activeUser->getBalance() << endl;
                break;
            case 2:
                // withdraw money
                int Wamount;
                cout << "Enter Amount : ";
                cin >> Wamount;
                if(activeUser->withdraw(Wamount)){
                    cout << "Please Collect Your Cash" << endl;
                } else {
                    cout << "Insufficient Balance" << endl;
                }
                break;
            case 3:
                // deposit money
                int Damount;
                cout << "Enter Amount : ";
                cin >> Damount;
                activeUser->deposit(Damount);
                break;
            case 4:
                // show history
                activeUser->showHistory();
                break;
            case 5:
                // Switching users
                activeUser = (activeUser == &user1) ? &user2 : &user1;
                cout << "User switched successfully !! "<< endl;
                break;
            case 6:
                // Transfer money
                cout << "Enter name of receiver (user1 or user2): ";
                cin >> receiver;
                if (receiver == "user1" || receiver == "user2") {
                    ATM* receiverATM = (receiver == "user1") ? &user1 : &user2;
                    int amount;
                    cout << "Enter the amount : ";
                    cin >> amount;
                    if (activeUser->transfer(*receiverATM, amount)) {
                        cout << "Transfer successful!!" << endl;
                    } else {
                        cout << "ERROR :(" << endl;
                    }
                } else {
                    cout << "Invalid receiver name" << endl;
                }
                break;
            case 7:
                cout << "Thank You !! Do Visit Again :)" << endl;
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    } while(choice != 7);
    return 0;
}
