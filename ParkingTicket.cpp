#include "ParkingTicket.h"
#include "PoliceOfficer.h"
#include <iostream>
#include <cmath>

ParkingTicket::ParkingTicket(const ParkedCar& car, const PoliceOfficer& officer, int minutesOver, int meterMinutes, int parkedMinutes)
    : carMake(car.getMake()), carModel(car.getModel()), carColor(car.getColor()),
      carLicense(car.getLicense()), meterMinutes(meterMinutes), parkedMinutes(parkedMinutes),
      minutesOver(minutesOver)
{
    officerName = officer.getName();
    badgeNumber = officer.getBadge();
    fine = calculateFine(minutesOver);
}

double ParkingTicket::calculateFine(int minutesOver) const {
    if (minutesOver <= 0) return 0.0;
    // $25 for first hour or part thereof, $10 for each additional hour or part thereof.
    int hours = (minutesOver + 59) / 60; // round up
    if (hours <= 1) return 25.0;
    return 25.0 + 10.0 * (hours - 1);
}

void ParkingTicket::display() const {
    std::cout << "\n*** Parking Ticket ***\n\n";
    std::cout << "Officer " << officerName << "  Badge Number " << badgeNumber << "\n\n";
    std::cout << "Vehicle License Number: " << carLicense << "\n";
    std::cout << "Make: " << carMake << " Model: " << carModel << " Color: " << carColor << "\n\n";
    std::cout << "Meter Minutes: " << meterMinutes << "  Minutes Parked: " << parkedMinutes << "\n\n";
    std::cout << "Minutes Over: " << minutesOver << "\n";
    std::cout << "Parking Fee: $" << fine << "\n\n";
}
