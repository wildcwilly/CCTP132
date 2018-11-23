/* 2.1.1 Essentials of if-else statement
Chris Wild

As you surely know, due to some astronomical reason, a year may be leap or common. The former is 366 days long while the latter is
365 days.
Since the introduction of the Gregorian calendar (in 1582), the following rule is used to determine the kind of year:
	* if the year number isn't divisible by 4, it is a common year;
	* otherwise, if the year number isn't divisible by 100, it is a leap year;
	* otherwise, if the year number isn't divisible by 400, it is a common year;
	* otherwise, it is a leap year.
Look at the code below – it only reads a year number and it needs to be completed with instructions that implement the test we just
described. The code should output one of two possible messages, which are Leap year or Common year, depending on the value
entered.
It would be good to verify if the year entered falls into the Gregorian era and to output a warning otherwise.
Test your code using the data we've provided.

using namespace std;

int main(void) {
	int year;

	cout << "Enter a year: ";
	cin >> year;

	// Insert your code here

	return 0;
}

Example input

2000

Example output

Leap year

Example input

2015

Example output

Common year

Example input

1999

Example output

Common year

Example input

1996

Example output

Leap year

Example input

1900

Example output

Common year
*/

#include <iostream>

using namespace std;

int main(void) {
	int year;

	cout << "Enter a year: ";
	cin >> year;

	/*	* if the year number isn't divisible by 4, it is a common year;
	* otherwise, if the year number isn't divisible by 100, it is a leap year;
	* otherwise, if the year number isn't divisible by 400, it is a common year;
	* otherwise, it is a leap year.
*/
	if (year % 4)	// a common year if year / 4 not = 0
	{
		cout << "Common year" << endl;
	}
	else if (!(year % 100))	// a leap year if year not divisible by 100
	{
		if (year % 400)	// a common year if not divisible by 400
		{
			cout << "Common year" << endl;
		}
		else
		{
			cout << "Leap year" << endl;
		}
	}
	else
	{
		// default to leap year
		cout << "Leap year" << endl;
	}

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Enter a year: 2000
Leap year

Enter a year: 2015
Common year

Enter a year: 1999
Common year

Enter a year: 1996
Leap year

Enter a year: 1900
Common year
*/