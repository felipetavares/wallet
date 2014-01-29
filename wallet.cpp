#include <ctime>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "wallet.h"
#include "hook/deposit.single.h"
#include "hook/deposit.daily.h"
using namespace std;

Wallet::Wallet () {
}

void Wallet::addHook (Hook* hook) {
  hooks[hook->getName()] = hook;
}

void Wallet::removeHook (string hookName) {
  hooks.erase(hooks.find(hookName));
}

vector <Hook*> Wallet::listHooks () {
  vector <Hook*> vhooks;
  
  for (auto i=hooks.begin();i!=hooks.end();i++) {
    vhooks.push_back(i->second);
  }
  
  return vhooks;
}

void Wallet::run () {
  time_t t = time(0);
  struct tm* now = localtime(&t);
  cout << "time: " << ctime(&t) << endl;;
  for (auto i=hooks.begin();i!=hooks.end();i++) {
    if (i->second->verifyExec(*now)) {
      i->second->exec(*this);
    }
  }
  cout << "balance: $" << balance << endl;
}

Hook* deposit_single (string name) {
  return new DepositSingle(name);
}

Hook* deposit_daily (string name) {
  return new DepositDaily(name);
}

void Wallet::bankEngine (string cmd) {
  vector <Hook*> hooks;
  map <string, function<Hook*(string)> > availableHooks = {
    {"deposit.single",deposit_single},
    {"deposit.daily",deposit_daily}//,
    /*{"deposit.monthly",},
    {"deposit.yearly",},
    {"draw.single",},
    {"draw.daily",},
    {"draw.monthly",},
    {"draw.yearly",}*/
  };

  hooks = listHooks();

  if (cmd == "run")
    run();
  
  if (cmd == "balance")
    for (Hook* h :hooks) {
      cout << h->getName() << " ";
      h->desc();
    }

  if (cmd == "hooks")
    for (pair<string, function<Hook*(string)> > hook :availableHooks) {
      cout << hook.first << endl;
    }

  if (cmd == "addhook") {
    string hookName,localName;
    cout << "< ";
    cin >> hookName;
    cout << "<n ";
    cin >> localName;

    try {
      addHook(availableHooks[hookName](localName));
    } catch (exception e) {
      cout << "No hook " << hookName << " available!" << endl;
    }
  }
    
  if (cmd == "delhook") {
      
  }
}

int main (void) {
  Wallet wallet;
  string cmd;

  wallet.run();

  do {
    cout << "<<< ";
    cin >> cmd;

    wallet.bankEngine(cmd);
  } while(cmd != "quit");

  return 0;
}

double Wallet::draw (double amount) {
  cout << "out: $" << amount << endl;
  return (balance-=amount);
}

double Wallet::deposit (double amount) {
  cout << "in: $" << amount << endl;
  return (balance+=amount);
}
