//
//  OutputTableRow.cpp
//  Titanic
//
//  Created by Stephen Yu on 11/23/23.
//

#include "OutputTableRow.h"

namespace cs32{

OutputTableRow::OutputTableRow(){
    
    
    
}

void OutputTableRow::setDescription(std::string description){
    
    mDescription = description;
    
}

void OutputTableRow::setSurvived(int survived){
    
    mSurvived = survived;
    
}

void OutputTableRow::setTotal(int total){
    
    mTotal = total;
    
}

std::string OutputTableRow::getDescription(){
    
    return(mDescription);
    
}

int OutputTableRow::getSurvived(){
    
    return(mSurvived);
    
}

int OutputTableRow::getTotal(){
    
    return(mTotal);
    
}

double OutputTableRow::getPercentage(){
    
    if(mSurvived == 0){
        
        return(0);
        
    }else{
        
        return((double)mSurvived / mTotal);
        
    }
    
    
}

void OutputTableRow::display(){
    
    std::cout << getDescription() << "-      " << getSurvived() << " / " << getTotal() << "         " << (getPercentage() * 100) << std::endl;
    
}

}
