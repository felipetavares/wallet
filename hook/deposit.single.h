#ifndef DEPOSIT_SINGLE_H
#define DEPOSIT_SINGLE_H

#include "../hook.h"
#include "../wallet.h"
#include <ctime>

class DepositSingle: public Hook {
  struct tm time;
  double amount;
 public:
  DepositSingle(string);

  bool verifyExec (struct tm);
  void exec(Wallet&);
  void desc();
};

#endif /* DEPOSIT_SINGLE_H */
