#include "carrier.h"
#include <sstream>

carrier::carrier(int hp) {
  this->healthPoint = hp;
  this->totalDamage = 0;
}

void carrier::setTotalDamage() {
  this->totalDamage = 0;
  for (unsigned int i = 0; i < this->deck.size(); i++) {
    this->totalDamage += this->deck[i].getTotalDamage();
  }
}

void carrier::enbarkeAmmunition(int ammo) {
  this->ammunitionStorage = ammo;
}

string carrier::getStatus() {
  if (this->healthPoint < 0) {
    return "It's dead Jim :(";
  }
  string statusMessage;
  statusMessage += "Aircraft count: ";
  stringstream ss;
  ss << this->deck.size();
  statusMessage += ss.str();
  statusMessage += ", Ammo Storage: ";
  ss.str("");
  ss << this->ammunitionStorage;
  statusMessage += ss.str();
  ss.str("");
  statusMessage += ", Total Damage: ";
  setTotalDamage();
  ss << this->totalDamage;
  statusMessage += ss.str();
  ss.str("");
  statusMessage += ", HP: ";
  ss << this->healthPoint;
  statusMessage += ss.str();
  statusMessage += "\nAircrafts:";
  for (unsigned int i = 0; i < this->deck.size(); i++) {
    statusMessage += "\n";
    statusMessage += this->deck[i].getStatus();
  }
  return statusMessage;
}

void carrier::addAircraft(string type) {
  aircraft newPlane(type);
  this->deck.push_back(newPlane);
}

bool carrier::checkAmmoStatus() {
  int neededAmmo = 0;
  for (unsigned int i = 0; i < this->deck.size(); i++) {
    neededAmmo += this->deck[i].neededAmmo();
  }
  if (neededAmmo < this->ammunitionStorage) {
    return true;
  }
  return false;
}

void carrier::fillAllAircraftsWithAmmo() {
  if (checkAmmoStatus()) {
    unsigned int i = 0;
    while (this->ammunitionStorage > 0 && i < this->deck.size()) {
      if (this->ammunitionStorage < this->deck[i].neededAmmo()) {
        break;
      }
      this->ammunitionStorage -= this->deck[i].refill();
      i++;
    }
  } else {
    unsigned int i = 0;
    while (this->ammunitionStorage > 0 && i < this->deck.size()) {
      if (this->deck[i].getType() == "f35") {
        if (this->ammunitionStorage < this->deck[i].neededAmmo()) {
          break;
        }
        this->ammunitionStorage -= this->deck[i].refill();
      }
      i++;
    }
  }
  setTotalDamage();
}

void carrier::getDamage(int damage) {
  this->healthPoint -= damage;
}

void carrier::fight(carrier& enemy) {
  for (unsigned int i = 0; i < this->deck.size(); i++) {
    this->deck[i].fight();
  }
  enemy.getDamage(this->totalDamage);
  setTotalDamage();
}

carrier::~carrier() {
  //dtor
}
