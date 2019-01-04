/* 3.4.2 One step further: finding the lengths of months
Chris Wild

Let's continue our coder's reflections on time. Now, when you have a reliable function diagnosing the nature of any year, you can use it
to implement another important function returning the length of any month (measured in days, of course).

Write a function equipped with the following features:

    * its name is "monthLength"
    * it accepts two arguments of type int: year number (first) and month number (second)
    * it returns an int value which represents a length of specified month in a specified year (obviously, year is important only when
    * month == 2) or 0 if any of the input arguments isn't valid
    * it should be mute
    * 
We've prepared a skeleton of the program - fill the function body with an appropriate content!

We've also attached the output that is expected from your program.

Hint: there are at least two ways of implementing the function: you can use switch or (something which seems a bit smarter) declare a
vector storing months' lengths – choose the more convenient style.

#include <iostream>

using namespace std;

bool isLeap(int year) {
    // The code you've inserted already
}

int monthLength(int year, int month) {
    // Insert a new code here
}

int main(void) {
    for(int yr = 2000; yr < 2002; yr++) {
        for(int mo = 1; mo <= 12; mo++)
            cout << monthLength(yr,mo) << " ";
        cout << endl;
    }
    return 0;
}

Example output

31 29 31 30 31 30 31 31 30 31 30 31
31 28 31 30 31 30 31 31 30 31 30 31
*/

#include <iostream>

using namespace std;

bool isLeap(int year) {
	if (year % 4)	// a common year if year / 4 not = 0
		return false;
	else if (!(year % 100))	// a leap year if year not divisible by 100
		if (year % 400)	// a common year if not divisible by 400
			return false;
		else
			return true;
	else
		return true;    // default to leap year
}

int monthLength(int year, int month) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if(month < 1 || month > 12)
        return 0;   // invalid input

    if(isLeap(year) && month == 2)
        return 29;  // only February of a leap year
    else
        return daysInMonth[month - 1];  // subtract 1 because array is indexed from 0, month starts at 1
}

int main(void) {
    for(int yr = 2000; yr < 2002; yr++) {
        for(int mo = 1; mo <= 12; mo++)
            cout << monthLength(yr,mo) << " ";
        cout << endl;
    }

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

31 29 31 30 31 30 31 31 30 31 30 31
31 28 31 30 31 30 31 31 30 31 30 31

*** make month for loop from 0 to 13 to introduce invalid month data
0 31 29 31 30 31 30 31 31 30 31 30 31 0
0 31 28 31 30 31 30 31 31 30 31 30 31 0
*/
