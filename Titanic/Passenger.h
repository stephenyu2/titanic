//
//  Passenger.hpp
//  Titanic
//
//  Created by Stephen Yu on 11/13/23.
//

#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include "Enums.h"

namespace cs32{

class Passenger{
    
public:
    
    Passenger(); 
    void setName(std::string name);
    std::string getName() const;
    void setEmbarcation(std::string embarked);
    void setClass(std::string classofFare);
    void setSurvived(std::string survived);
    void setFare(std::string fare);
    Embarcation getEmbarcation() const;
    Class getClass() const;
    bool getSurvived() const;
    double getFare() const;
    
private:
    
    Class mClass;
    Embarcation mEmbarked;
    std::string mName;
    bool mSurvived;
    double mFare; 
    
};

}

#endif
