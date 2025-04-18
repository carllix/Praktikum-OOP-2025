#include "SpacingGuildShip.hpp"
#include <iostream>
using namespace std;

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip() : maxPassengerCap(50), guildNavigatorCount(3), serialNum(producedShips + 1) {
    this->passengerCount = 0;
    this->operatingGuildNavigator = 3;
    this->spiceStock = 50;
    producedShips ++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(producedShips + 1) {
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = spiceStock;
    producedShips ++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& other) : maxPassengerCap(other.maxPassengerCap), guildNavigatorCount(other.guildNavigatorCount), serialNum(other.producedShips + 1) {
    this->passengerCount = other.passengerCount;
    this->operatingGuildNavigator = other.operatingGuildNavigator;
    this->spiceStock = other.spiceStock;
    this->producedShips ++;
}

SpacingGuildShip::~SpacingGuildShip() {}

int SpacingGuildShip::getShipSerialNum() const {
    return this->serialNum; 
}

int SpacingGuildShip::getPassengerCount() const {
    return this->passengerCount;
}

void SpacingGuildShip::travel(float distance) {
    if (this->operatingGuildNavigator > 0){
        totalGuildTravel += distance / (E * E * this->operatingGuildNavigator);
        this->operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers){
    if (passengerCount + addedPassengers > maxPassengerCap){
        passengerCount = maxPassengerCap;
    }
    else{
        passengerCount += addedPassengers;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers){
    if (passengerCount - droppedPassengers < 0){
        passengerCount = 0;
    }
    else{
        passengerCount -= droppedPassengers;
    }
}

void SpacingGuildShip::refreshNavigator(int n) {
    int addedNav = n * GUILD_NAVIGATOR_SPICE_DOSE;
    int inactive = guildNavigatorCount - operatingGuildNavigator;
    if (addedNav > spiceStock){
        if (n < inactive){
            spiceStock -= addedNav;
            operatingGuildNavigator += n;
        }
        else{
            spiceStock -= addedNav;
            operatingGuildNavigator += inactive;
        }
    }
    else{
        spiceStock -= (spiceStock / GUILD_NAVIGATOR_SPICE_DOSE) * GUILD_NAVIGATOR_SPICE_DOSE;
        operatingGuildNavigator += (spiceStock / GUILD_NAVIGATOR_SPICE_DOSE);
    } 
}

void SpacingGuildShip::transitToArrakis(int addedSpice) {
    spiceStock += addedSpice;
}