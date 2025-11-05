#ifndef PARKINGMETER_H
#define PARKINGMETER_H

class ParkingMeter {
private:
    int minutesPurchased;
public:
    ParkingMeter(int minutes = 0) : minutesPurchased(minutes) {}
    int getMinutesPurchased() const { return minutesPurchased; }
};

#endif // PARKINGMETER_H
