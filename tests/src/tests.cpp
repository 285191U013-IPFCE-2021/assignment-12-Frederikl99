#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "..\include\duration.h"



// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 

TEST_CASE("getDuration")
{
    Duration Ex_1 = Duration(); // The time on the duration should be 0, because we set time=0 in the function
    Duration Ex_2 = Duration(0);// Set the time of the duration at 0
    Duration Ex_3 = Duration(10); // Set the time of the duration at 10     
    Duration Ex_4 = Duration(100); // Set the time of the duration at 100

    REQUIRE(Ex_1.getDuration()==0); // The duration is 0
    REQUIRE(Ex_2.getDuration()==0); // The duration is 0    
    REQUIRE(Ex_3.getDuration()==10); // The duration is 10  
    REQUIRE(Ex_4.getDuration()==100); // The duration is 100
}

TEST_CASE("Tick")
{ 
    Duration Ex_1 = Duration(0); // Set the time of the duration at 0


    Ex_1.Tick(20); // Increases the clock with 20

    REQUIRE(Ex_1.getDuration()==20); // The duration should be 20 because we have increased the clock with 20
    
}  

TEST_CASE("tick")
{ 
    Duration Ex_1 = Duration(0); // Set the time of the duration at 0
   

    Ex_1.tick(); // Increases the clock with 1

    REQUIRE(Ex_1.getDuration()==1); // The duration should be 1 because we have increased the clock with 1
    
}  


TEST_CASE("ALARM")
{
    Duration Ex_1 = Duration(0); // Set the time of the duration at 0

    Ex_1.Tick(20); //Increases the clock with 20

    REQUIRE(Ex_1.getDuration()==20); //The duration should be 20 because we have increased the clock with 20
    Ex_1.setAlarm(22); // Set the alarm at 22

    REQUIRE(Ex_1.Tick(1)==false); // The clock increases with 1 and check if the time value has passed the alarm or is equal to the alarm
    REQUIRE(Ex_1.Tick(2)==true); // The clock increases with 2 and check if the time value has passed the alarm or is equal to the alarm
                                // The clock should be reset
    REQUIRE(Ex_1.Tick(2)==false); // The clock increases with 2 and check if the alarm is still set
    REQUIRE(Ex_1.getDuration()==25); // The time of the duration should be 25 because the clock have been increased with 5
}