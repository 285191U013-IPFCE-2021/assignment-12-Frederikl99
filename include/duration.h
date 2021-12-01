#ifndef _DURATION_CLASS_H
#define _DURATION_CLASS_H
#include <assert.h>
#include <stdio.h>


class Duration
{
private: // Private means that only instances of this class can access these variables. These parts are the restricted internal implementation details
    int time;
    int alarm;
    bool alarmHasBeenSet;
    void ResetAlarm();
    bool checkAndUpdateAlarm();

public:// Public means any other program can call these functions. These parts are the external interface for users
    int getDuration();
    void tick();
    bool Tick(int dt);
    void setAlarm(int t);

    Duration(); // A constructor. When you call an object of type Duration this constructor function is called automatically 
    Duration(int t);  // A constructor. When you call an object of type Duration that takes an interger this constructor function is called automatically 
    // ~Duration(); This is the destructor 
};

#endif