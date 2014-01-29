#ifndef HOOK_H
#define HOOK_H

#include <stdint.h>
#include <string>
#include <ctime>
using namespace std;

class Wallet;

class Hook {
  //! Unique
  string name;
 public:
  Hook(string);
  string getName ();
  /**
     @param day Day to be verified
     Verify if this hooks is to be executed at day 'day'
   */
  virtual bool verifyExec(struct tm) = 0;
  /**
     @param wallet Wallet to be edited
     Execute a hook. A hook can do ANYTHING with the wallet.
   */
  virtual void exec (Wallet&) = 0;

  virtual void desc () = 0;
};

#endif /* HOOK_H */
