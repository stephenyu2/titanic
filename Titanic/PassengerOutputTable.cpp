//
//  PassengerOutputTable.cpp
//  Titanic
//
//  Created by Stephen Yu on 11/15/23.
//

#include "PassengerOutputTable.h"

namespace cs32{

PassengerOutputTable::PassengerOutputTable(std::vector<Passenger *> passengers){
    
    mPassengerList = passengers;
    mField = Field::NOVALUE;
    mDescription = ""; 
    
}

void PassengerOutputTable::setOutputField(Field f){
    
    mField = f;
    
}

void PassengerOutputTable::setDescription(std::string description){
    
    mDescription = description;
    
}

Field PassengerOutputTable::getOutputField(){
    
    return(mField);
    
}

std::string PassengerOutputTable::getDescription(){
    
    return(mDescription);
    
}

void PassengerOutputTable::display(){
    
    mRows.clear();
    
    if(mField != Field::NOVALUE){
        
        std::cout << getDescription() << std::endl;
        std::cout << "            Survived / Total     %" << std::endl;
        
    }
    
    if(mField == Field::BYCLASS){
        
        OutputTableRow First;
        OutputTableRow Second;
        OutputTableRow Third;
        OutputTableRow NotKnown;
        
        First.setDescription("First Class");
        Second.setDescription("Second Class");
        Third.setDescription("Third Class");
        NotKnown.setDescription("Not Known");
        
        First.setTotal(0);
        Second.setTotal(0);
        Third.setTotal(0);
        NotKnown.setTotal(0);
        
        First.setSurvived(0);
        Second.setSurvived(0);
        Third.setSurvived(0);
        NotKnown.setSurvived(0);

        for(std::vector< Passenger * >::iterator iter = mPassengerList.begin(); iter != mPassengerList.end(); iter++){
            
            if((*iter)->getClass() == Class::FIRST){
                
                First.setTotal((First.getTotal()) + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    First.setSurvived(First.getSurvived() + 1);
                    
                }
                
            }else if((*iter)->getClass() == Class::SECOND){
                
                Second.setTotal((Second.getTotal()) + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    Second.setSurvived(Second.getSurvived() + 1);
                    
                }
                
            }else if((*iter)->getClass() == Class::THIRD){
                
                Third.setTotal((Third.getTotal()) + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    Third.setSurvived(Third.getSurvived() + 1);
                    
                }
                
            }else{
                    
                NotKnown.setTotal(NotKnown.getTotal() + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    NotKnown.setSurvived(NotKnown.getSurvived() + 1);
                    
                }
                    
            }
            
        }
        
        mRows.push_back(First);
        mRows.push_back(Second);
        mRows.push_back(Third);
        mRows.push_back(NotKnown);
        
        for(std::vector< OutputTableRow >::iterator iter = mRows.begin(); iter != mRows.end(); iter++){
            
            iter->display();
            
        }
        
    }
    
    if(mField == Field::BYEMBARCATION){
        
        OutputTableRow Cherbourg;
        OutputTableRow Queenstown;
        OutputTableRow Southhampton;
        OutputTableRow NotKnown;
        
        Cherbourg.setDescription("Cherbourg");
        Queenstown.setDescription("Queenstown");
        Southhampton.setDescription("Southhampton");
        NotKnown.setDescription("Not Known");
        
        Cherbourg.setTotal(0);
        Queenstown.setTotal(0);
        Southhampton.setTotal(0);
        NotKnown.setTotal(0);
        
        Cherbourg.setSurvived(0);
        Queenstown.setSurvived(0);
        Southhampton.setSurvived(0);
        NotKnown.setSurvived(0);

        for(std::vector< Passenger * >::iterator iter = mPassengerList.begin(); iter != mPassengerList.end(); iter++){
            
            if((*iter)->getEmbarcation() == Embarcation::CHERBOURG){
                
                Cherbourg.setTotal((Cherbourg.getTotal()) + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    Cherbourg.setSurvived(Cherbourg.getSurvived() + 1);
                    
                }
                
            }else if((*iter)->getEmbarcation() == Embarcation::QUEENSTOWN){
                
                Queenstown.setTotal((Queenstown.getTotal()) + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    Queenstown.setSurvived(Queenstown.getSurvived() + 1);
                    
                }
                
            }else if((*iter)->getEmbarcation() == Embarcation::SOUTHHAMPTON){
                
                Southhampton.setTotal((Southhampton.getTotal()) + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    Southhampton.setSurvived(Southhampton.getSurvived() + 1);
                    
                }
                
            }else{
                    
                NotKnown.setTotal(NotKnown.getTotal() + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    NotKnown.setSurvived(NotKnown.getSurvived() + 1);
                    
                }
                    
            }
            
        }
        
        mRows.push_back(Cherbourg);
        mRows.push_back(Queenstown);
        mRows.push_back(Southhampton);
        mRows.push_back(NotKnown);
        
        for(std::vector< OutputTableRow >::iterator iter = mRows.begin(); iter != mRows.end(); iter++){
            
            iter->display();
            
        }
        
    }
    
    if(mField == Field::BYFARE){
        
        OutputTableRow NotKnown;
        OutputTableRow OneTen;
        OutputTableRow TenTwentyFive;
        OutputTableRow TwentyFiveFifty;
        OutputTableRow FiftyPlus;
        
        NotKnown.setDescription("Not Known");
        OneTen.setDescription("$ 1-$10");
        TenTwentyFive.setDescription("$10-$25");
        TwentyFiveFifty.setDescription("$25-$50");
        FiftyPlus.setDescription(">$50");
        
        NotKnown.setTotal(0);
        OneTen.setTotal(0);
        TenTwentyFive.setTotal(0);
        TwentyFiveFifty.setTotal(0);
        FiftyPlus.setTotal(0);
        
        NotKnown.setSurvived(0);
        OneTen.setSurvived(0);
        TenTwentyFive.setSurvived(0);
        TwentyFiveFifty.setSurvived(0);
        FiftyPlus.setSurvived(0);
        
        for(std::vector< Passenger * >::iterator iter = mPassengerList.begin(); iter != mPassengerList.end(); iter++){
            
            if((*iter)->getFare() > 0 && (*iter)->getFare() <= 10){
                
                OneTen.setTotal(OneTen.getTotal() + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    OneTen.setSurvived(OneTen.getSurvived() + 1); 
                    
                }
                
            }else if((*iter)->getFare() > 10 && (*iter)->getFare() <= 25){
                
                TenTwentyFive.setTotal(TenTwentyFive.getTotal() + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    TenTwentyFive.setSurvived(TenTwentyFive.getSurvived() + 1);
                    
                }
                
            }else if((*iter)->getFare() > 25 && (*iter)->getFare() <= 50){
                
                TwentyFiveFifty.setTotal(TwentyFiveFifty.getTotal() + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    TwentyFiveFifty.setSurvived(TwentyFiveFifty.getSurvived() + 1);
                    
                }
                
            }else if((*iter)->getFare() > 50){
                
                FiftyPlus.setTotal(FiftyPlus.getTotal() + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    FiftyPlus.setSurvived(FiftyPlus.getSurvived() + 1);
                    
                }
                
            }else{
                
                NotKnown.setTotal(NotKnown.getTotal() + 1);
                
                if((*iter)->getSurvived() == true){
                    
                    NotKnown.setSurvived(NotKnown.getSurvived() + 1);
                    
                }
                
            }
            
        }
        
        mRows.push_back(NotKnown);
        mRows.push_back(OneTen);
        mRows.push_back(TenTwentyFive);
        mRows.push_back(TwentyFiveFifty);
        mRows.push_back(FiftyPlus);
        
        for(std::vector< OutputTableRow >::iterator iter = mRows.begin(); iter != mRows.end(); iter++){
            
            iter->display();
            
        }
        
    }
    
}

size_t PassengerOutputTable::rowCount(){
    
    return(mRows.size());
    
}

OutputTableRow PassengerOutputTable::getRow(int index){
    
    return(mRows.at(index)); 
    
}

}
