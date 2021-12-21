//
//  Bank.cpp
//  BankingSystem
//
//  Created by Vincent Zhu on 9/12/21.
//

#include "Bank.hpp"
#include "Account.hpp"
#include <iostream>
using namespace std;
#include <fstream>
#include <map>

Bank::Bank(string fileName){
    fileName=fileName;
    Account account;
    ifstream ifs(fileName);
    if(!ifs.is_open()){
        cout<<"File does not exist!"<<endl;
        return;
    }
    while(!ifs.eof()){
        ifs>>account;
        allAcc.insert(pair<long,Account>(account.getAccountNumber(),account));
    }
    Account::setLastAccountNumber(account.getAccountNumber());
    ifs.close();
}
Account Bank::openAccount(string fn, string ln, float bal){
    Account account(fn,ln,bal);
    allAcc.insert(pair<long,Account>(account.getAccountNumber(),account));
    ofstream ofs;
    ofs.open(fileName,ios::trunc);
    map<long,Account>::iterator i;
    for(i=allAcc.begin(); i!=allAcc.end(); i++){
        ofs<<i->second;
    }
    ofs.close();
    return account;
}
Account Bank::balanceEnquiry(long accountNum){
    map<long,Account>::iterator itr;
    itr=allAcc.find(accountNum);
    return itr->second;
}
Account Bank::deposit(long accountNum,float amount){
    ofstream ofs;
    ofs.open(fileName,ios::trunc);
    map<long,Account>::iterator itr;
    itr=allAcc.find(accountNum);
    itr->second.deposit(amount);
    map<long,Account>::iterator i;
    for(i=allAcc.begin(); i!=allAcc.end(); i++){
        ofs<<i->second;
    }
    ofs.close();
    return itr->second;
}
Account Bank::withdraw(long accountNum,float amount){
    ofstream ofs;
    ofs.open(fileName,ios::trunc);
    map<long,Account>::iterator itr;
    itr=allAcc.find(accountNum);
    itr->second.withdraw(amount);
    map<long,Account>::iterator i;
    for(i=allAcc.begin(); i!=allAcc.end(); i++){
        ofs<<i->second;
    }
    ofs.close();
    return itr->second;
}
void Bank::closeAccount(long accountNum){
    ofstream ofs;
    ofs.open(fileName,ios::trunc);
    //map<long,Account>::iterator itr;
    //itr=allAcc.find(accountNum);
    allAcc.erase(accountNum);
    map<long,Account>::iterator i;
    for(i=allAcc.begin(); i!=allAcc.end(); i++){
        ofs<<i->second;
    }
    ofs.close();
}
void Bank::showAllAccounts(){
    map<long,Account>::iterator i;
    for(i=allAcc.begin(); i!=allAcc.end(); i++){
        cout<<i->second<<endl;
    }
}

