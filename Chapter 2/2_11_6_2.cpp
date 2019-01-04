/* 2.11.2 Times and durations
Chris Wild

We hope that your previous program enables you to travel in time smoothly and accurately. Now we want you to modify it a bit:
declare two structure variables – one for the start time, another for the end time;

Ask your user for both times – be sure that the end time denotes a later time of day than the start time (we assume that both
times fall on the same day);

evaluate and output the duration of time (in hours and minutes) between both times.

Note: we're still using a 24-hour clock!

Test your code using the data we've provided.

Example input

0 1
23 59

Example output

23:58

Example input

12 58
13 3

Example output

0:5

Example input

8 2
17 43

Example output

9:41
*/

#include <iostream>

using namespace std;

struct Time {
    int hour;
    int minute;
};


int main()
{
    Time startTime, endTime;
    bool invalid;

    // Enter and validate start time
    do
    {
        invalid = false;    // preset validation flag for while loop

        cout << "Enter start time hour (0 - 23): ";
        cin >> startTime.hour;

        cout << "Enter start time minute (0 - 59): ";
        cin >> startTime.minute;

        if(startTime.hour < 0 || startTime.hour > 23)
        {
            cout << "Invalid hour. Try again.\n";
            invalid = true;
        }
        if(startTime.minute < 0 || startTime.minute > 59)
        {
            cout << "Invalid minute. Try again.\n";
            invalid = true;
        }
    }while(invalid);

    // Enter and validate end time
    do
    {
        invalid = false;    // preset validation flag for while loop

        cout << "Enter end time hour (0 - 23): ";
        cin >> endTime.hour;
        cout << "Enter end time minute (0 - 59): ";
        cin >> endTime.minute;

        if(endTime.hour < 0 || endTime.hour > 23)
        {
            cout << "Invalid hour. Try again.\n";
            invalid = true;
        }
        if(endTime.minute < 0 || endTime.minute > 59)
        {
            cout << "Invalid minute. Try again.\n";
            invalid = true;
        }

        if((endTime.hour < startTime.hour) || (endTime.hour == startTime.hour && endTime.minute < startTime.minute))
        {
            cout << "End time must be later than start time. Try again.\n";
            invalid = true;
        }
    }while(invalid);

    // calculate duration from start time to end time (endTime will hold final duration)
    endTime.hour -= startTime.hour;
    endTime.minute-= startTime.minute;

    if(endTime.minute < 0)
    {
        // adjust for valid time
        endTime.hour -= 1;
        endTime.minute = 60 + endTime.minute;
    }

    cout << endTime.hour << ":" << endTime.minute << endl;

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Enter start time hour (0 - 23): 0
Enter start time minute (0 - 59): 1
Enter end time hour (0 - 23): 23
Enter end time minute (0 - 59): 59
23:58

Enter start time hour (0 - 23): 12
Enter start time minute (0 - 59): 58
Enter end time hour (0 - 23): 13
Enter end time minute (0 - 59): 3
0:5

 start time hour (0 - 23): 8
Enter start time minute (0 - 59): 2
Enter end time hour (0 - 23): 17
Enter end time minute (0 - 59): 43
9:41

Enter start time hour (0 - 23): 10
Enter start time minute (0 - 59): 45
Enter end time hour (0 - 23): 10
Enter end time minute (0 - 59): 44
End time must be later than start time. Try again.
Enter end time hour (0 - 23): 24
Enter end time minute (0 - 59): 00
Invalid hour. Try again.
Enter end time hour (0 - 23): 00
Enter end time minute (0 - 59): 00
End time must be later than start time. Try again.
Enter end time hour (0 - 23): 23
Enter end time minute (0 - 59): 59
13:14
*/
