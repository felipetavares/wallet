#include "../printtime.h"
#include "deposit.single.h"
#include <iostream>
using namespace std;

DepositSingle::DepositSingle(string name):
  Hook(name) {

  cout << "<$ ";
  cin >> amount;
  readtime(time);
}

bool DepositSingle::verifyExec (struct tm time) {
  cout << mktime(&time) << " " << mktime(&this->time) << endl;
  if (mktime(&time) == mktime(&this->time))
    return true;
}

void DepositSingle::exec (Wallet& wallet) {
  wallet.deposit (amount); 
}

void DepositSingle::desc () {
  cout << "$" << amount << " at day ";
  printtime(time);
  cout << endl;
}
