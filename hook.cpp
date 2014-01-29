#include "hook.h"

Hook::Hook (string name) {
  this->name = name;
}

string Hook::getName () {
  return name;
}
