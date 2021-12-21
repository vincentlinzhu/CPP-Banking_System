//
//  main.cpp
//  BankingSystem
//
//  Created by Vincent Zhu on 9/12/21.
//

#include <iostream>
using namespace std;
#include "Bank.hpp"
#include "Account.hpp"
#include <map>
#include <vector>
#include <fstream>

int main(int argc, const char * argv[]) {
    if(argc!=2){
        cout<<"Usage: BankSystem <File Name>"<<endl;
        return 1;
    }
    Bank b(argv[1]);
    Account a;
    string firstN;
    string lastN;
    double balance;
    long accountNumber;
    double amount;
    int option;

    cout<<"|---- BANKING SYSTEM ----|"<<endl;
    do{
        cout<<" "<<endl;
        cout<<"\tSelect an Option Number from the Bank Menu: "<<endl;
        cout<<"\t1. Open an Account"<<endl;
        cout<<"\t2. Balance Enquiry"<<endl;
        cout<<"\t3. Deposit"<<endl;
        cout<<"\t4. Withdrawal"<<endl;
        cout<<"\t5. Close an Account"<<endl;
        cout<<"\t6. Show All Accounts"<<endl;
        cout<<"\t7. EXIT Bank System"<<endl;
        cout<<" "<<endl;
        
        cout<<"Enter Choice: "<<endl;
        cin>>option;
        
        switch(option){
            case 1:
                cout<<"To open an account, please provide the following information: "<<endl;
                cout<<"First Name: "<<endl;
                cin>>firstN;
                cout<<"Last Name: "<<endl;
                cin>>lastN;
                cout<<"Starting Balance: "<<endl;
                cin>>balance;
                a=b.openAccount(firstN,lastN,balance);
                cout<<endl<<"Congradulations "<<firstN<<"! Your account has been created."<<endl;
                cout<<a<<endl;
                break;
            case 2:
                cout<<"Enter the account number: "<<endl;
                cin>>accountNumber;
                a=b.balanceEnquiry(accountNumber);
                cout<<"Your Account Information: "<<endl;
                cout<<a<<endl;
                break;
            case 3:
                cout<<"Enter the account number: "<<endl;
                cin>>accountNumber;
                cout<<"Enter deposit amount: "<<endl;
                cin>>amount;
                a=b.deposit(accountNumber, amount);
                cout<<"Amount Successfully Deposited"<<endl;
                cout<<a<<endl;
                break;
            case 4:
                cout<<"Enter the account number: "<<endl;
                cin>>accountNumber;
                cout<<"Enter withdrawal amount: "<<endl;
                cin>>amount;
                a=b.withdraw(accountNumber,amount);
                cout<<"Amount Successfully Withdrawn"<<endl;
                cout<<a<<endl;
                break;
            case 5:
                cout<<"Enter the account number"<<endl;
                cin>>accountNumber;
                b.closeAccount(accountNumber);
                cout<<"Account "<<accountNumber<<" Successfully Closed"<<endl;
                break;
            case 6:
                cout<<"All Accounts in System: "<<endl;
                b.showAllAccounts();
                break;
            case 7:
                break;
            default:
                cout<<"Invalid Choice: "<<endl;
                exit(0);
        }
        
    }while (option!=7);
    return 0;
}

