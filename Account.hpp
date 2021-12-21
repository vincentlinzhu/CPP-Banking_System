//
//  Account.hpp
//  BankingSystem
//
//  Created by Vincent Zhu on 9/12/21.
//

#ifndef Account_hpp
#define Account_hpp

#include <iostream>
using namespace std;
#include <fstream>

class Account{
private:
    long accountNumber;
    string firstName;
    string lastName;
    float balance;
    static long nextAccountNumber;
public:
    Account();
    Account(string fname, string lname, float bal);
    long getAccountNumber(){return accountNumber;}
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    float getBalance(){return balance;}
    
    void deposit(float amount);
    void withdraw(float amount);
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();
    friend ofstream & operator<<(ofstream &ofs, Account &a);
    friend ifstream & operator>>(ifstream &ifs, Account &a);
    friend ostream & operator<<(ostream &os, Account &a);

};

#endif /* Account_hpp */

