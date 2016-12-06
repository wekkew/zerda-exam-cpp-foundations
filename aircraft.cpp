#include "aircraft.h"
#include <sstream>

aircraft::aircraft(string type) {
  this->type = type;
  this->ammo = 0;
  if (type == "f16") {
    this->baseDamage = 30;
  } else if (type == "f35") {
    this->baseDamage = 50;
  }
}

string aircraft::getStatus() {
  string statusMessage;
  statusMessage += "Type ";
  statusMessage += this->type;
  statusMessage += ", Ammo: ";
  stringstream ss;
  ss << this->ammo;
  statusMessage += ss.str();
  statusMessage += ", Base Damage: ";
  ss.str("");
  ss << this->baseDamage;
  statusMessage += ss.str();
  ss.str("");
  statusMessage += ", All Damage: ";
  int allDamage = this->ammo * this->baseDamage;
  ss.str("");
  ss << allDamage;
  statusMessage += ss.str();
  return statusMessage;
}

int aircraft::fight() {
  int allDamage = this->ammo*this->baseDamage;
  this->ammo = 0;
  return allDamage;
}

int aircraft::neededAmmo() {
  if (this->type == "f16") {
    return 8 - this->ammo;
  } else if (this->type == "f35") {
    return 12 - this->ammo;
  }
  return 0;
}

int aircraft::refill() {
  int neededBeforeRefill = this->neededAmmo();
  this->ammo += this->neededAmmo();
  return neededBeforeRefill;
}

string aircraft::getType() {
  return this->type;
}

int aircraft::getTotalDamage() {
  return this->ammo * this->baseDamage;
}

aircraft::~aircraft() {
}
