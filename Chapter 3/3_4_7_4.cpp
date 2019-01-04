/* 3.4.4 Third step further – counting the days
Chris Wild

Now you're ready to take on the next, more ambitious challenge.

We need a function which:

    *is called "daysBetween";
    *accepts two arguments of type Date – the first represents the "since" date, while the second represents the "till" date;
    *returns an int value, being the number of days passed between both dates;
    *returns -1 if the "till" date is earlier than the "since" date;
    *should be mute.

As usual, we've provided a skeleton of code and some test data. You provide the rest of the code and do the tests – that's the deal.

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
    // The code you've inserted already
}

int daysBetween(Date d1, Date d2) {
    // Insert you code here
}

int main(void) {
    Date since,to;

    cout << "Enter first date (y m d): ";
    cin >> since.year >> since.month >> since.day;
    cout << "Enter second date (y m d): ";
    cin >> till.year >> till.month >> till.day;
    cout << daysBetween(since,till) << endl;
    return 0;
}

Example input

1901 1 1
2016 1 1

Example output

42003

Example input

2001 12 30
2016 12 31

Example output

5480

Example input

1999 1 31
1999 12 1

Example output

304

Example input

1999 1 2
1999 1 11

Example output

9

Example input

1999 2 2
1999 1 11

Example output

-1
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

int daysBetween(Date d1, Date d2) {
    int year, month, days;
    
    // check if end date is before start date
    if ((d2.year < d1.year) ||
        (d2.year == d1.year && d2.month < d1.month) ||
        (d2.year == d1.year && d2.month == d1.month && d2.day < d1.day))
            return -1;

/*     // start by subtracting start date from end date
    year = d2.year - d1.year;
    month = d2.month - d1.month;
    days = d2.day - d1.day;

    // make adjustments for any negative values
    if(days < 1)
        days += monthLength(d1.year, d1.month);

    if(month < 0)
    {
        year -= 1;
        month += 12;
    }

    if(year < 0)
        return -1;  // date 2 is before date 1
 */

    // add days remaining in start date month
    days = monthLength(d1.year, d1.month) - d1.day;

    // add full months left in start year
    for(month = d1.month + 1; month <= 12; month++)
    {

        days += monthLength(d1.year, month);
    }

    // add full months left in end year
    for(month = 1; month < d2.month; month ++)
    {
        days += monthLength(d2.year, month);
    }

    // add days of end date
    days += d2.day;

    // add any years between both dates
    if(d1.year != d2.year)
    {
        for(year = d1.year + 1; year < d2.year; year++)
            days += isLeap(year) ? 366 : 365;
    }

    return days;
}

int main(void) {
    Date since,till;

    cout << "Enter first date (y m d): ";
    cin >> since.year >> since.month >> since.day;
    cout << "Enter second date (y m d): ";
    cin >> till.year >> till.month >> till.day;
    cout << daysBetween(since,till) << endl;

	system("pause");
	return 0;
}

/* Actual output (copied from console window)


*/
