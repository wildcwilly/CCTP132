/* 2.11.1 Structure of time or time of structure
Chris Wild

We've shown you how to declare structures intended to store information about dates. Now we encourage you to declare a structure for
handling the time of day with an accuracy of one minute. We think your structure will have two fields, but we don't want to suggest
anything more – all the design decisions are up to you.

After you've done that, declare a variable of the previously declared structure type and write a code asking your user for two values:
hours and minutes. Note: you should use a 24-hour clock, sometimes referred to as "military time".

Check the inputted values carefully – don't accept ideas like 25:71; store the values in your structure variable.

Next, input an int value and assume that this is a number of minutes – let it be the duration of some event.

Your task is to output a time of day (hours and minutes respectively) that will be shown on clocks immediately after our event; try to
show it in the form "HH:MM".

Test your code using the data we've provided.

Example input

11
58
23

Example output

12:21

Example input

23
55
1880

Example output

7:15

Example input

23
55
1441

Example output

23:56

Example input

7
45
510

Example output

16:15
*/

#include <iostream>

using namespace std;

struct Time {
    int hour;
    int minute;
};

int main()
{
    Time time;
    int duration;
    bool invalid;

    do
    {
        invalid = false;   // preset validation flag for while loop

        cout << "Enter the hour (0 - 23): ";
        cin >> time.hour;

        cout << "Enter the minute (0 - 59): ";
        cin >> time.minute;

        if(time.hour < 0 || time.hour > 23)
        {
            cout << "Invalid hour, try again.\n";
            invalid = true;
        }

        if(time.minute < 0 || time.minute > 59)
        {
            cout << "Invalid minute, try again.\n";
            invalid = true;
        }
    }while(invalid);

    cout << "Enter duration of time in minutes: ";
    cin >> duration;

    time.minute += duration;

    if(time.minute > 59)    // time is past current hour
    {
        time.hour += (time.minute / 60);    // add the rounded (truncated) value
        time.minute %= 60;  // store remainder of minute mod 60
    }

    if(time.hour > 23)
    {
        time.hour %= 24;    // store remainder of hour mod 24 and ignore day
    }

    cout << time.hour << ":" << time.minute << endl;

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Enter the hour (0 - 23): 11
Enter the minute (0 - 59): 58
Enter duration of time in minutes: 23
12:21

Enter the hour (0 - 23): 23
Enter the minute (0 - 59): 55
Enter duration of time in minutes: 1880
7:15

Enter the hour (0 - 23): 23
Enter the minute (0 - 59): 55
Enter duration of time in minutes: 1441
23:56

Enter the hour (0 - 23): 74
Enter the minute (0 - 59): 5
Invalid hour, try again.
Enter the hour (0 - 23): 7
Enter the minute (0 - 59): 45
Enter duration of time in minutes: 510
16:15
*/
