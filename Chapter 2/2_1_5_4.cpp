/* 2.1.4 Some actual evaluations - finding day of week
Chris Wild

Have you ever wondered how to find a weekday for any (past or future) date? Okay, you can check it in a calendar (you probably have
one on your smartphone), but this is no solution for a coder. We do it the harder and more exciting way – we're going to write a
program for it (did you ever suspect we were going to offer you anything else?)
One of the most popular algorithms for this task is the so-called "Zeller's congruence". Sounds complicated? Nothing could be further
from the truth, and we're going to show you exactly that. You'll need three values:
    * year number (int – let's assume that we're interested only in dates from the 20th and 21st centuries);
    * month number (int – 1 to 12);
    * day number (int – 1 to it depends)
Be patient – this will take a while:
    1. Decrease month number by 2;
    2. if month number becomes less than 0, increment it by 12 and decrement year by 1;
    3. take month number and multiply it by 83 and divide it by 32;
    4. add day number to month;
    5. add year number to month;
    6. add year/4 to month;
    7. subtract year/100 from month;
    8. add year/400 to month;
    9. find the remainder of dividing month by 7;
    10. Congrats! A weekday number is ready for you! 0 – Sunday, 1 – Monday, ... and so on.

We want you to write a code which finds a weekday number for a date entered by a user. The program should ask the user for the year,
month and day (in this order) and output a value indicating a weekday.
Make your code as smart as possible.
Test your code using the data we've provided.

Example input

2016
2
10

Example output

3

Example input

2000
1
1

Example output

6

Example input

1999
12
31

Example output

5

Example input

1964
12
21

Example output

1
*/

#include <iostream>

using namespace std;

int main()
{
    int year, month, day, dayOfWeek, maxDays;

    // prompt and enter date from user
    cout << "Enter year (1900 - 2099): ";
    cin >> year;

    if (year < 1900 || year > 2099) // out of range
    {
        cout << "Not a valid year. Must be between 1900 and 2099." << endl;
        return 1;
    }

    cout << "Enter month (1 - 12): ";
    cin >> month;

    if(month < 1 || month > 12) // out of range
    {
        cout << "Not a valid month. Must be between 1 and 12." << endl;
        return 1;
    }

    // figure out max day of month
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        maxDays = 31;

    if(month == 4 || month == 6 || month == 9 || month == 11)
        maxDays = 30;

    if(month == 2)
    {
        // need to know if year is leap or not (use algorithm from lab 2_1_5_1.cpp)5

        if (year % 4) // a common year if year / 4 not = 0
        {
            maxDays = 28;
        }
        else if (!(year % 100)) // a leap year if year not divisible by 100
        {
            if (year % 400) // a common year if not divisible by 400
            {
                maxDays = 28;
            }
            else
            {
                maxDays = 29;
            }
        }
        else
        {
            // default to leap year
            maxDays = 29;
        }
    }

    cout << "Enter the day (1 to " << maxDays << ") ";
    cin >> day;

    if(day < 0 || day > maxDays)    // out of range
    {
        cout << "Not a valid day. Must be between 1 and " << maxDays << "." << endl;
    }

    // Decrease month number by 2;
    dayOfWeek = month - 2;

    // if month number becomes less than 0, increment it by 12 and decrement year by 1
    if(dayOfWeek <= 0)
    {
        dayOfWeek = dayOfWeek + 12;
        year--;
    }


    // take month number and multiply it by 83 and divide it by 32
    dayOfWeek = dayOfWeek * 83 / 32;

    // add day number to month
    dayOfWeek += day;

    // add year number to month
    dayOfWeek += year;

    // add year / 4 to month
    dayOfWeek = dayOfWeek + (year / 4);

    // subtract year / 100 from month
    dayOfWeek = dayOfWeek - (year / 100);

    // add year / 400 to month
    dayOfWeek = dayOfWeek + (year / 400);

    // find the remainder of dividing month by 7
    dayOfWeek = dayOfWeek % 7;

    // output result
    cout << dayOfWeek << endl;

    return 0;
}

/* Actual output (copied from console window)

Enter year (1900 - 2099): 2016
Enter month (1 - 12): 2
Enter the day (1 to 29) 10
3

Enter year (1900 - 2099): 2000
Enter month (1 - 12): 1
Enter the day (1 to 31) 1
6

Enter year (1900 - 2099): 1999
Enter month (1 - 12): 12
Enter the day (1 to 31) 31
5

Enter year (1900 - 2099): 1964
Enter month (1 - 12): 12
Enter the day (1 to 31) 21
1

Enter year (1900 - 2099): 2018
Enter month (1 - 12): 11
Enter the day (1 to 30) 24
6
*/