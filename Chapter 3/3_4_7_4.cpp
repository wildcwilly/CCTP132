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
	int days = 0, loop;

// if both dates in same year, subtract day of d2 from d1
	if (d1.year == d2.year)
		if (dayOfYear(d2) - dayOfYear(d1) >= 0)	// confirm d2 is after d1
			return dayOfYear(d2) - dayOfYear(d1);
	
	// if d2 is not the same year as d1
	if (d2.year - d1.year > 0)
	{
		days += (isLeap(d1.year) ? 366 : 365) - dayOfYear(d1);	// add remaining days in year of d1

		for (loop = d1.year + 1; loop < d2.year; loop++)	// will be ignored if d2 year is less than 2 years after d1 year
			days += isLeap(loop) ? 366 : 365;

		days += dayOfYear(d2);	// add days of year for d2

		return days;
	}

	// d2 is before d1
	return -1;
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

Enter first date (y m d): 2018 12 31
Enter second date (y m d): 2019 1 7
7

Enter first date (y m d): 1901 1 1
Enter second date (y m d): 2016 1 1
42003

Enter first date (y m d): 2001 12 30
Enter second date (y m d): 2016 12 31
5480

Enter first date (y m d): 1999 1 31
Enter second date (y m d): 1999 12 1
304

Enter first date (y m d): 1999 1 2
Enter second date (y m d): 1999 1 11
9

Enter first date (y m d): 1999 2 2
Enter second date (y m d): 1999 1 11
-1

Enter first date (y m d): 2019 2 2
Enter second date (y m d): 2018 3 6
-1
*/
