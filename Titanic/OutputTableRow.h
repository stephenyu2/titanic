//
//  OutputTableRow.hpp
//  Titanic
//
//  Created by Stephen Yu on 11/23/23.
//

#ifndef OUTPUTTABLEROW_H
#define OUTPUTTABLEROW_H

#include <iostream>
#include <string>

namespace cs32{

class OutputTableRow{
    
public:
    
    OutputTableRow(); 
    void setDescription(std::string description);
    void setSurvived(int survived);
    void setTotal(int total);
    std::string getDescription();
    int getSurvived();
    int getTotal();
    double getPercentage();
    void display();
    
private:
    
    std::string mDescription;
    int mSurvived;
    int mTotal;
    
};

}

#endif /* OutputTableRow_hpp */
