#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <string>
#include <iostream>

class ParkedCar {
private:
    std::string make;
    std::string model;
    std::string color;
    std::string license;
    int minutesParked;
public:
    ParkedCar() : make(""), model(""), color(""), license(""), minutesParked(0) {}
    ParkedCar(const std::string& mk, const std::string& mdl, const std::string& clr,
              const std::string& lic, int mins);

    std::string getMake() const;
    std::string getModel() const;
    std::string getColor() const;
    std::string getLicense() const;
    int getMinutesParked() const;

    void display() const;
};

#endif // PARKEDCAR_H
