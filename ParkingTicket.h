#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include <string>
#include "ParkedCar.h"

class PoliceOfficer; // forward

class ParkingTicket {
private:
    std::string officerName;
    std::string badgeNumber;
    std::string carMake;
    std::string carModel;
    std::string carColor;
    std::string carLicense;
    int meterMinutes;
    int parkedMinutes;
    int minutesOver;
    double fine;
public:
    ParkingTicket(const ParkedCar& car, const PoliceOfficer& officer, int minutesOver, int meterMinutes, int parkedMinutes);

    double calculateFine(int minutesOver) const;
    void display() const;
};

#endif // PARKINGTICKET_H
