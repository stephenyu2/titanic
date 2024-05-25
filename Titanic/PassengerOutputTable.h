//
//  PassengerOutputTable.hpp
//  Titanic
//
//  Created by Stephen Yu on 11/15/23.
//

#ifndef PASSENGEROUTPUTTABLE_H
#define PASSENGEROUTPUTTABLE_H

#include <iostream>
#include <string>
#include "Enums.h"
#include "Passenger.h"
#include "OutputTableRow.h"
#include <vector>

namespace cs32 {

class PassengerOutputTable{
    
public:
    
    PassengerOutputTable(std::vector<Passenger *> passengers);
    void setOutputField(Field f);
    void setDescription(std::string description);
    Field getOutputField();
    std::string getDescription();
    void display();
    size_t rowCount();
    OutputTableRow getRow(int index);
    
private:
    
    std::vector< Passenger * > mPassengerList;
    std::vector< OutputTableRow > mRows;
    Field mField;
    std::string mDescription; 
    
};

}

#endif /* PassengerOutputTable_hpp */
