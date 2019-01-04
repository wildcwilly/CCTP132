/* 3.4.1 Old problems, new methods: functions
Chris Wild

Some time ago we asked you to write a program to find out if a certain year was leap or common. We want to return to the issue, but in
a completely different form.

We want you to write a function equipped with the following features:

    * its name should be "isLeap";
    * it accepts one argument of type int representing the year number;
    * it returns a bool value: true if the year is leap and false otherwise;
    * it should be mute! It mustn't write anything to the output – the only way it reveals its actions is by the value it returns.

We've prepared a skeleton of the program – fill the function body with the appropriate content.

We've also attached the output that is expected from your program.

using namespace std;

bool isLeap(int year) {
    // Insert your code here
}

int main(void) {
    for(int yr = 1995; yr < 2017; yr++)
        cout << yr << " -> " << isLeap(yr) << endl;
    return 0;
}

Example output

1995 -> 0
1996 -> 1
1997 -> 0
1998 -> 0
1999 -> 0
2000 -> 1
2001 -> 0
2002 -> 0
2003 -> 0
2004 -> 1
2005 -> 0
2006 -> 0
2007 -> 0
2008 -> 1
2009 -> 0
2010 -> 0
2011 -> 0
2012 -> 1
2013 -> 0
2014 -> 0
2015 -> 0
2016 -> 1
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

int main(void) {
    for(int yr = 1995; yr < 2017; yr++)
        cout << yr << " -> " << isLeap(yr) << endl;

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

1995 -> 0
1996 -> 1
1997 -> 0
1998 -> 0
1999 -> 0
2000 -> 1
2001 -> 0
2002 -> 0
2003 -> 0
2004 -> 1
2005 -> 0
2006 -> 0
2007 -> 0
2008 -> 1
2009 -> 0
2010 -> 0
2011 -> 0
2012 -> 1
2013 -> 0
2014 -> 0
2015 -> 0
2016 -> 1
*/
