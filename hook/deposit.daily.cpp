#include "deposit.daily.h"
#include <iostream>
using namespace std;

DepositDaily::DepositDaily(string name):
  Hook(name) {

  cout << "<$ ";
  cin >> amount;
}

bool DepositDaily::verifyExec (struct tm time) {
  return true;
}

void DepositDaily::exec (Wallet& wallet) {
  wallet.deposit (amount); 
}

void DepositDaily::desc () {
  cout << "$" << amount << " every day " << endl;
}
