#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../../src/duration.h"



// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 

TEST_CASE("getDuration")
{
    Duration Ex_1 = Duration();
    Duration Ex_2 = Duration(0);
    Duration Ex_3 = Duration(10);
    Duration Ex_4 = Duration(100);

    REQUIRE(Ex_1.getDuration()==0); 
    REQUIRE(Ex_2.getDuration()==0); 
    REQUIRE(Ex_3.getDuration()==10); 
    REQUIRE(Ex_4.getDuration()==100); 
}

TEST_CASE("Tick")
{ 
    Duration Ex_1 = Duration(0);
    // Duration Ex_2 = Duration(10);
    // Duration Ex_3 = Duration(100);

    Ex_1.Tick(20);

    REQUIRE(Ex_1.getDuration()==20); 
    
}  

TEST_CASE("ALARM")
{
    Duration Ex_1 = Duration(0);

    Ex_1.Tick(20);

    REQUIRE(Ex_1.getDuration()==20); 

    Ex_1.setAlarm(22);

    REQUIRE(Ex_1.Tick(1)==false);
    REQUIRE(Ex_1.Tick(2)==true);

    REQUIRE(Ex_1.Tick(2)==false);
    REQUIRE(Ex_1.getDuration()==25); 
}