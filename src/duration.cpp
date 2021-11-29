#include <stdio.h>
#include "..\src\duration.h"
#include <assert.h>

int Duration::getDuration()
{
return time; // Return a number of seconds that have elasped 

}

Duration::Duration()
{
    time = 0; // Set the time of the duration to 0
    ResetAlarm();
}

Duration::Duration(int t)
{
    assert(t >= 0); 
    time = t; // Sets the time to the same as the interger we take 
    ResetAlarm();
}

// void Duration::tick()
// {

//     time++;

// }

bool Duration::Tick(int dt)
{
    time++; // Makes the time count up with one 
    assert(dt >= 0);
    time = time + dt - 1; // Makes the time count up with dt
    return checkAndUpdateAlarm();
    
}

void Duration::setAlarm(int t)
{
    assert(t > time);// The user must not set the alarm to a value in the past. Alarm value must be greater than the current time
    
    if(alarmHasBeenSet == false) // Checks if the alarm has been set
    {
        alarm = t; // Set the alarm to whatever interger we get
        alarmHasBeenSet = true; // The alarm has now been set
    }
        
}

void Duration::ResetAlarm()
{
    alarm = time + 10000; // Sets the alarm to large value, so time won't ever reach the alarm
    alarmHasBeenSet = false; // The alarm hasn't been set

}

bool Duration::checkAndUpdateAlarm()
{
if(alarmHasBeenSet == true)
    {
        if(time >= alarm) // If time overreach the alarm, the alarm has to be reset 
        { 
            ResetAlarm();
            return true;
        }
        else 
            return false;
        
    }
    else
        return false;

}


