//
//  Account.cpp
//  BankingSystem
//
//  Created by Vincent Zhu on 9/12/21.
//

#include "Account.hpp"
#include <iostream>
using namespace std;
#include <fstream>

class InsufficientFunds{};
long Account::nextAccountNumber=0;
Account::Account(){
    
}
Account::Account(string fname, string lname, float bal){
    nextAccountNumber++;
    accountNumber=nextAccountNumber;
    firstName=fname;
    lastName=lname;
    balance=bal;
}
void Account::deposit(float amount){
    balance+=amount;
}
void Account::withdraw(float amount){
    if (balance-amount<0){
        throw InsufficientFunds();
    }
    else{
        balance-=amount;
    }
}
void Account::setLastAccountNumber(long accountNumber){
    nextAccountNumber=accountNumber;
}
long Account::getLastAccountNumber(){
    return nextAccountNumber;
}
ofstream & operator<<(ofstream &ofs, Account &a){
    ofs<<a.getAccountNumber()<<endl;
    ofs<<a.getFirstName()<<endl;
    ofs<<a.getLastName()<<endl;
    ofs<<a.getBalance()<<endl;
    return ofs;
}
ifstream & operator>>(ifstream &ifs, Account &a){
    ifs>>a.accountNumber;
    ifs>>a.firstName;
    ifs>>a.lastName;
    ifs>>a.balance;
    return ifs;
}
ostream & operator<<(ostream &os, Account &a){
    os<<"Account Number: "<<a.getAccountNumber()<<endl;
    os<<"First Name: "<<a.getFirstName()<<endl;
    os<<"Last Name: "<<a.getLastName()<<endl;
    os<<"Balance: "<<a.getBalance()<<endl;
    return os;
}


