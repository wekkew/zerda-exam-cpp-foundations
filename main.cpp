#include <iostream>
#include "aircraft.h"
#include "carrier.h"

using namespace std;

int main() {
    carrier geraldFord(5000);
    geraldFord.enbarkeAmmunition(30);
    geraldFord.addAircraft("f16");
    geraldFord.addAircraft("f16");
    geraldFord.addAircraft("f35");
    geraldFord.addAircraft("f35");
    geraldFord.addAircraft("f35");
    geraldFord.addAircraft("f35");
    geraldFord.addAircraft("f35");
    geraldFord.addAircraft("f35");
    geraldFord.fillAllAircraftsWithAmmo();
    cout << "USS Gerald Ford:" << endl << geraldFord.getStatus() << endl << endl;

    carrier admiralKuznetsov(2000);
    admiralKuznetsov.enbarkeAmmunition(100);
    admiralKuznetsov.addAircraft("f16");
    admiralKuznetsov.addAircraft("f16");
    admiralKuznetsov.addAircraft("f16");
    admiralKuznetsov.fillAllAircraftsWithAmmo();
    cout << "RFS Admiral Kuznetsov: " << endl << admiralKuznetsov.getStatus() << endl << endl;

    geraldFord.fight(admiralKuznetsov);
    cout << "USS Gerald Ford:" << endl << geraldFord.getStatus() << endl << endl;
    cout << "RFS Admiral Kuznetsov: " << endl << admiralKuznetsov.getStatus() << endl;

    return 0;
}
