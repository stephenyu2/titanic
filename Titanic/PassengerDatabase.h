//
//  PassengerDatabase.hpp
//  Titanic
//
//  Created by Stephen Yu on 11/13/23.
//

#ifndef PASSENGERDATABASE_H
#define PASSENGERDATABASE_H

#include <iostream>
#include <string>
#include <vector>
#include "Enums.h"
#include "Passenger.h"
#include "DataCollectorCallback.h"
#include "CSVFile.h"

namespace cs32{

class PassengerDatabase : public DataCollectorCallback{
    
public:
    
    PassengerDatabase();
    ~PassengerDatabase();
    int load(std::string filePath);
    void clearAllPassengers();
    bool loaded();
    Passenger * getPassenger_byName(std::string name) const;
    std::vector<Passenger *> getPassengers() const;
    std::vector<Passenger *> getPassengers_byClass(Class paidClass, bool survived, double minimumFare) const;
    std::vector<Passenger *> getPassengers_byEmbarcation(Embarcation embarked, bool Survived, double minimumFare) const;
    virtual void csvData(std::map<std::string, std::string> row);
    
private:
    
    std::vector<Passenger *> passengers;
    bool isLoaded;
    
};

}

#endif /* PassengerDatabase_h */
