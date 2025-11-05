#include "ParkedCar.h"
#include <iostream>

ParkedCar::ParkedCar(const std::string& mk, const std::string& mdl, const std::string& clr,
                     const std::string& lic, int mins)
    : make(mk), model(mdl), color(clr), license(lic), minutesParked(mins) {}

std::string ParkedCar::getMake() const { return make; }
std::string ParkedCar::getModel() const { return model; }
std::string ParkedCar::getColor() const { return color; }
std::string ParkedCar::getLicense() const { return license; }
int ParkedCar::getMinutesParked() const { return minutesParked; }

void ParkedCar::display() const {
    std::cout << "Vehicle License Number: " << license << "\n"
              << "Make: " << make << " Model: " << model << " Color: " << color << "\n"
              << "Minutes Parked: " << minutesParked << "\n";
}
