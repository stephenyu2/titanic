//
//  PassengerDatabase.cpp
//  Titanic
//
//  Created by Stephen Yu on 11/13/23.
//

#include "PassengerDatabase.h"

using namespace std;
namespace cs32{

PassengerDatabase::PassengerDatabase(){
    
    // isLoaded initializes as false
    isLoaded = false;
    
}

PassengerDatabase::~PassengerDatabase(){
    
    clearAllPassengers();
    
}

int PassengerDatabase::load( std::string filePath )
{
    
    CSVFile file( this );
    int recordCount = file.readFile( filePath );
    // Sets isLoaded to true only if at least 1 passenger has been loaded
    if(!passengers.empty()){
        
        isLoaded = true;
        
    }
    
    return( recordCount );
    
}

void PassengerDatabase::clearAllPassengers(){
    
    // Will be called by destructor
    while(!passengers.empty()){
        
        delete passengers.back();
        passengers.pop_back();
        
    }
    
}

bool PassengerDatabase::loaded(){
    
    return(isLoaded);
    
}

Passenger * PassengerDatabase::getPassenger_byName(std::string name) const{
    
    // Iterates through only returning when name matches parameter
    std::vector<Passenger*>::const_iterator iter = passengers.begin();
    while(iter != passengers.end()){
        
        if(name == (*iter)->getName()){
            
            return(*iter);
            
        }
        
        iter++;
        
    }
    
    return(nullptr); 
    
}

std::vector<Passenger *> PassengerDatabase::getPassengers() const{
    
    return(passengers);
    
}

std::vector<Passenger *> PassengerDatabase::getPassengers_byClass(Class paidClass, bool survived, double minimumFare) const{
    
    // Ensure all parameters are met and returns vector
    std::vector<Passenger *> result;
    std::vector<Passenger*>::const_iterator iter = passengers.begin();
    while(iter != passengers.end()){
        
        if((*iter)->getClass() == paidClass && (*iter)->getSurvived() == survived && (*iter)->getFare() > minimumFare){
            
            result.push_back(*iter);
            
        }
        
        iter++; 
        
    }
    
    return(result); 
    
}

std::vector<Passenger *> PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool Survived, double minimumFare) const{
    
    // Ensure all parameters are met and returns vector
    std::vector<Passenger *> result;
    std::vector<Passenger*>::const_iterator iter = passengers.begin();
    while(iter != passengers.end()){
        
        if((*iter)->getEmbarcation() == embarked && (*iter)->getSurvived() == Survived && (*iter)->getFare() > minimumFare){
            
            result.push_back(*iter);
            
        }
        
        iter++;
        
    }
    
    return(result);
    
}

void PassengerDatabase::csvData( std::map< std::string, std::string > row )
{
    // News a Passenger and throws them into dynamic vector
    Passenger* p = new Passenger;
    p->setName(row.find("name")->second);
    p->setClass(row.find("pclass")->second);
    p->setEmbarcation(row.find("embarked")->second);
    p->setSurvived(row.find("survived")->second);
    p->setFare(row.find("fare")->second);
    passengers.push_back(p);
    
}

}
