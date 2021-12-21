//
//  Bank.hpp
//  BankingSystem
//
//  Created by Vincent Zhu on 9/12/21.
//

#ifndef Bank_hpp
#define Bank_hpp

#include <iostream>
using namespace std;
#include "Account.hpp"
#include <fstream>
#include <map>

class Bank{
private:
    map<long, Account> allAcc;
    string fileName;
public:
    Bank(string fileName);
    Account openAccount(string fn, string ln, float bal);
    Account balanceEnquiry(long accountNum);
    Account deposit(long accountNum,float amount);
    Account withdraw(long accountNum,float amount);
    void closeAccount(long accountNum);
    void showAllAccounts();

};

#endif /* Bank_hpp */

