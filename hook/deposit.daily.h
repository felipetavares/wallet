#ifndef DEPOSIT_DAILY_H
#define DEPOSIT_DAILY_H

#include "../hook.h"
#include "../wallet.h"

class DepositDaily: public Hook {
  double amount;
 public:
  DepositDaily(string);

  bool verifyExec (struct tm);
  void exec(Wallet&);
  void desc();
};

#endif /* DEPOSIT_DAILY_H */
