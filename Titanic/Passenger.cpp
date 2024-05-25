//
//  Passenger.cpp
//  Titanic
//
//  Created by Stephen Yu on 11/13/23.
//

#include "Passenger.h"

using namespace std;
namespace cs32{

Passenger::Passenger(){
    
    mName = "";
    mSurvived = false;
    mClass = Class::NOTKNOWN;
    mEmbarked = Embarcation::NOTKNOWN;
    mFare = 0; 
    
}

void Passenger::setName(std::string name){
    
    // Name setter
    mName = name;
    
}

std::string Passenger::getName() const{
    
    // Name getter
    return(mName);
    
}

void Passenger::setEmbarcation(std::string embarked){
    
    // Embarcation setter
    if(embarked == "C"){
        
        mEmbarked = Embarcation::CHERBOURG;
        
    }else if(embarked == "Q"){
        
        mEmbarked = Embarcation::QUEENSTOWN;
        
    }else if(embarked == "S"){
        
        mEmbarked = Embarcation::SOUTHHAMPTON;
        
    }else{
        
        mEmbarked = Embarcation::NOTKNOWN;
        
    }
    
}

void Passenger::setClass(std::string classofFare){
    
    // Class setter
    if(classofFare == "1"){
        
        mClass = Class::FIRST;
        
    }else if(classofFare == "2"){
        
        mClass = Class::SECOND;
        
    }else if(classofFare == "3"){
        
        mClass = Class::THIRD;
        
    }else{
        
        mClass = Class::NOTKNOWN;
        
    }
    
}

void Passenger::setSurvived(std::string survived){
    
    // Survived setter
    if(survived == "1"){
        
        mSurvived = true;
        
    }else{
        
        mSurvived = false;
        
    }
    
}

void Passenger::setFare(std::string fare){
    
    // Fare setter
    if(fare == ""){
        
        mFare = 0;
        
    }else{
        
        mFare = std::stof( fare );
        
    }
    
}

Class Passenger::getClass() const{
    
    // Class getter
    return(mClass);
    
}

Embarcation Passenger::getEmbarcation() const{
    
    // Embarcation getter
    return(mEmbarked);
    
}

bool Passenger::getSurvived() const{
    
    // Survived getter
    return(mSurvived);
    
}

double Passenger::getFare() const{
    
    // Fare getter
    return(mFare);
    
}

}

