/* 3.4.3 Second step further: finding day of year
Chris Wild

Let's add another powerful tool to our calendar toolkit.

Now write a function which:

    * is named "dayOfYear"
    * accepts one argument of type Date – it's a structure similar to the one you were using before;
    * returns an int value, being the number of the day within a certain year (assuming that 1st January is the first day of every year);
    * should be mute.
    * 
A skeleton of the code is here for you, as well as an example of input and output.

#include <iostream>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

bool isLeap(int year) {
    // The code you've inserted already
}

int monthLength(int year, int month) {
    // The code you've inserted already
}

int dayOfYear(Date date) {
    // Insert your code here
}

int main(void) {
    Date d;

    cout << "Enter year month day: ";
    cin >> d.year >> d.month >> d.day;
    cout << dayOfYear(d) << endl;

    return 0;
}

Example input

2016 3 1

Example output

61

Example input

2015 3 1

Example output

60

Example input

2016 12 30

Example output

365

Example input

2015 12 31

Example output

365
*/

#include <iostream>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

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

int dayOfYear(Date date) {
    int days = 0;

    for(int month = 1; month < date.month; month++)
        days += monthLength(date.year, month);

    days += date.day;

    return days;
}

int main(void) {
    Date d;

    cout << "Enter year month day: ";
    cin >> d.year >> d.month >> d.day;
    cout << dayOfYear(d) << endl;

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Enter year month day: 2016 3 1
61

Enter year month day: 2015 3 1
60

Enter year month day: 2016 12 30
365

Enter year month day: 2015 12 31
365
*/
