#ifndef CARRIER_H
#define CARRIER_H
#include <vector>
#include "aircraft.h"
#include <string>

class carrier {
  public:
    carrier(int hp);
    void enbarkeAmmunition(int ammo);
    string getStatus();
    void addAircraft(string type);
    void fillAllAircraftsWithAmmo();
    void fight(carrier& enemy);
    void getDamage(int damage);
    virtual ~carrier();
  private:
    int totalDamage;
    int ammunitionStorage;
    int healthPoint;
    vector<aircraft> deck;

    void setTotalDamage();
    bool checkAmmoStatus();
};

#endif
