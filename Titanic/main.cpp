#include <iostream>
  #include <string>
  #include <cassert>
  #include "Passenger.h"
  #include "PassengerDatabase.h"
  #include "PassengerOutputTable.h"
  #include "Settings.h"

  int main()  // FIGURE OUT MY INCLUDES
  {
     using namespace std;
     using namespace cs32;
   
   
     Passenger passenger;
     passenger.setName( "Jack Dawson" );
     passenger.setEmbarcation( "S" );
     passenger.setClass( "3" );
     passenger.setSurvived( "0" );
     passenger.setFare( "12.50" );
     assert( passenger.getName() == "Jack Dawson" );
     assert( passenger.getClass() == Class::THIRD );
     assert( passenger.getEmbarcation() == Embarcation::SOUTHHAMPTON );
     assert( std::to_string(passenger.getFare()) == "12.500000" );
     assert( passenger.getSurvived() == false );
   
     OutputTableRow row;
     row.setDescription( "testing" );
     row.setSurvived( 5 );
     row.setTotal( 10 );
     assert( row.getDescription() == "testing" );
     assert( row.getSurvived() == 5 );
     assert( row.getTotal() == 10 );
     assert( std::to_string(row.getPercentage()) == "0.500000" );
   
     PassengerDatabase database;
     database.load( PATH_TO_BIGGER_DATA_MAC );
     if (database.loaded())
     {
         vector< Passenger * > byclass = database.getPassengers_byClass(Class::FIRST, true, -10.00);
         vector< Passenger * > byembark = database.getPassengers_byEmbarcation(Embarcation::SOUTHHAMPTON, true, 0.00);
         
         Passenger * p = database.getPassenger_byName( "Howard" );
         if (p)
             p->setEmbarcation( "S" );
         
         
         PassengerOutputTable t( byclass );
         t.setDescription( "List of First Class Survivors With Fare > 0" );
         t.setOutputField( Field::BYCLASS );
         assert( t.getDescription() == "List of First Class Survivors With Fare > 0" );
         assert( t.getOutputField() == Field::BYCLASS );
         t.display();
         
         vector< Passenger * > byclassdied = database.getPassengers_byClass(Class::FIRST, false, -10.00);
         PassengerOutputTable t1( byclassdied );
         t1.setDescription( "List of First Class Died With Fare > 0" );
         t1.setOutputField( Field::BYCLASS );
         t1.display();
         
         vector< Passenger * > all = database.getPassengers();
         PassengerOutputTable t2( all );
         t2.setDescription( "List of all passengers by class" );
         t2.setOutputField( Field::BYCLASS );
         t2.display();
         
         assert( t2.rowCount() == 4 );
         // first class
         row = t2.getRow( 0 );
//                   assert( row.getSurvived() == 4 );
//                   assert( row.getTotal() == 5 );
//                   assert( std::to_string(row.getPercentage()) == "0.800000" );
         row = t2.getRow(0);
         assert(row.getSurvived() == 200);
         assert(row.getTotal() == 323);
         assert(row.getDescription() == "First Class");
         
         row = t2.getRow(1);
         assert(row.getSurvived() == 119);
         assert(row.getTotal() == 277);
         assert(row.getDescription() == "Second Class"); 
                 
                   t2.setDescription( "List of all passengers by embarcation" );
                   t2.setOutputField( Field::BYEMBARCATION );
                   t2.display();
                 
                   t2.setDescription( "List of all passengers by fare" );
                   t2.setOutputField( Field::BYFARE );
                   t2.display();
                 
                   t2.setDescription( "What is shown by NOVALUE??" );
                   t2.setOutputField( Field::NOVALUE );
                   t2.display();
                 
                }
                else
                {
                   cout << "database was not loaded correctly" << endl;
                   cout << PATH_TO_MOVIE_DATA_MAC << " is not working!" << endl;
                }
             

                cout << "all tests passed!" << endl;
                return( 0 );
             }  
