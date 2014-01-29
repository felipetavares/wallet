#ifndef WALLET_H
#define WALLET_H

#include <stdint.h>
#include <string>
#include <map>
#include <vector>
#include "hook.h"

class Wallet {
  //! Current balance
  double balance = 0.0;
  //! Current day
  uint32_t day = 0;
  //! Map of hooks that need to be executed
  map <string,Hook*> hooks;

 public:
  Wallet ();
  void addHook(Hook*);
  void removeHook(string);
  vector<Hook*> listHooks();

  void run ();
  void bankEngine(string);
  double deposit(double);
  double draw (double);
};

#endif /* WALLET_H */
