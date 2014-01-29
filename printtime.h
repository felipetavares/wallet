#ifndef PRINTTIME_H
#define PRINTTIME_H

#include <ctime>
#include <iostream>
using namespace std;

void printtime (struct tm time) {
  cout << time.tm_mon+1 << "."
       << time.tm_mday << "."
       << time.tm_year+1900;
}

void readtime (struct tm& time) {
  cout << "[y] ";
  cin >> time.tm_year;
  time.tm_year -= 1900;
  cout << "[m] ";
  cin >> time.tm_mon;
  time.tm_mon -= 1;
  cout << "[d] ";
  cin >> time.tm_mday;
}

#endif /* PRINTTIME_H */
