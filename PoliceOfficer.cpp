#include "PoliceOfficer.h"

PoliceOfficer::PoliceOfficer(const std::string& n, const std::string& b)
    : name(n), badge(b) {}

bool PoliceOfficer::isExpired(const ParkedCar& car, const ParkingMeter& meter) const {
    return car.getMinutesParked() > meter.getMinutesPurchased();
}

ParkingTicket PoliceOfficer::issueTicket(const ParkedCar& car, const ParkingMeter& meter) const {
    int over = car.getMinutesParked() - meter.getMinutesPurchased();
    if (over < 0) over = 0;
    ParkingTicket ticket(car, *this, over, meter.getMinutesPurchased(), car.getMinutesParked());
    return ticket;
}
