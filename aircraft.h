#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include <string>

using namespace std;

class aircraft {
  public:
    aircraft(string type);
    int fight();
    int neededAmmo();
    int refill();
    string getType();
    string getStatus();
    int getTotalDamage();
    virtual ~aircraft();
  private:
    int ammo;
    int baseDamage;
    string type;
};

#endif
