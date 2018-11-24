/* 2.1.5 Some actual evaluations - finding date of Easter
Chris Wild

Easter is a so-called moveable feast, and its date depends on two astronomical phenomena: the beginning of spring in the Northern
hemisphere and the first full moon occurring after it. You may think that finding the date of Easter would be extremely complex and
connected to complicated astronomical calculations, but, fortunately, it's much, much easier.
The algorithm we're going to show you was created by a famous German mathematician, Carl Friedrich Gauss. It's known in many
variations – we're going to use one of the simpler forms adapted for the 20th and 21st centuries. The only data it uses is the year
number. Okay, let's go!
    1. Divide year by 19 and find the remainder – assign it to a;
    2. divide year by 4 and find the remainder – assign it to b;
    3. divide year by 7 and find the remainder – assign it to c;
    4. take a, multiply it by 19, add 24, divide by 30 and find the remainder – assign it to d
    5. divide (2b + 4c + 6d + 5) by 7 and find the remainder - assign it to e;
    6. check the value of d + e -- if it's less than 10, Easter falls on the (d + e + 22) day of March;
    7. otherwise it falls on the (d + e – 9) day of April;
    8. that's all!
Now you're familiar with all the theory you need to write a code to find the date of Easter. The program should ask the user for the year
number and output a date in the form Month Day , e.g. April 5.
Test your code using the data we've provided.

Example input

2016

Example output

March 27

Example input

1980

Example output

April 6

Example input

2026

Example output

April 5
*/

#include <iostream>

using namespace std;

int main()
{
    int year, a, b, c, d, e;

    // prompt and enter year as integer
    cout << "Enter year (1900 - 2099): ";
    cin >> year;

    // validate entry
    if(year < 1900 || year > 2099)  // out of range
    {
        cout << "Invalid year. Must be between 1900 and 2099." << endl;
        return 1;
    }

    // 1. Divide year by 19 and find the remainder – assign it to a
    a = year % 19;

    // 2. divide year by 4 and find the remainder – assign it to b
    b = year % 4;

    // 3. divide year by 7 and find the remainder – assign it to c
    c = year % 7;

    // 4. take a, multiply it by 19, add 24, divide by 30 and find the remainder – assign it to d 
    d = (a * 19 + 24) % 30;

    // 5. divide(2b + 4c + 6d + 5) by 7 and find the remainder - assign it to e
    e = ((b * b) + (4 * c) + (6 * d) + 5) % 7;

    // 6. check the value of d + e -- if it's less than 10, Easter falls on the (d + e + 22) day of March
    // 7. otherwise it falls on the(d + e – 9) day of April
    if(d + e < 10)
    {
        cout << "March " << (d + e + 22) << endl;
    }
    else
    {
        cout << "April " << (d + e - 9) << endl;
    }

    return 0;
}

/* Actual output (copied from console window)

Enter year (1900 - 2099): 2016
March 27

Enter year (1900 - 2099): 1980
April 6

Enter year (1900 - 2099): 2026
April 5

Enter year (1900 - 2099): 2018
April 1
*/