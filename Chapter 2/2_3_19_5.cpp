/* 2.3.5 Drawing squares (actually: rectangles)
Chris Wild

Look at the sample code below – it draws a shape pretending to be a rectangle (we would like to name it "square", but neither the
monitor nor the printer can show it as a real square).

Your task is to modify the code to achieve the following goals:

	* ask the user to enter a positive integer value greater than 1 (n);
	* check the entered value and if it isn't legal, output a message stating the reason;
	* draw a square with a side of n.

Find the reasonable upper limit for n (depending on your screen's dimensions) and embed it into your code.

#include <iostream>

using namespace std;

int main(void)
{
	cout << '+';
	for(int i = 0; i < 4; i++)
		cout << '-';
	cout << '+' << endl;
	for(int i = 0; i < 4; i++)
	{
		cout << '|';
		for(int j = 0; j < 4; j++)
			cout << ' ';
			cout << '|' << endl;
	}
	cout << '+';
	for(int i = 0; i < 4; i++)
		cout << '-';
	cout << '+' << endl;
	return 0;
}

Example input

3

Example output

+-+
| |
+-+

Example input

8

Example output
+------+
|	   |
|	   |
|	   |
|	   |
|	   |
|	   |
+------+

Example input

100

Example output

Sorry, the side size is too big
*/

#include <iostream>

using namespace std;

int main()
{
	int size;

	// prompt and enter size as integer
	cout << "Enter a number (2 - 23): ";
	cin >> size;

	if (size <= 1)	// number too small
	{
		cout << "Your number is too low!";
	}
	else if (size > 23)	// larger than 23 is larger than default console window
	{
		cout << "Your number is too high!";
	}
	else
	{
		size -= 2;	// reduce by 2 for included corners

		cout << '+';
		for (int i = 0; i < size; i++)
			cout << '-';
		cout << '+' << endl;
		for (int i = 0; i < size; i++)
		{
			cout << '|';
			for (int j = 0; j < size; j++)
				cout << ' ';
			cout << '|' << endl;
		}
		cout << '+';
		for (int i = 0; i < size; i++)
			cout << '-';
		cout << '+' << endl;
	}

	return 0;
}

/* Actual output (copied from console window)

Enter a number (2 - 23): 1
Your number is too low!

Enter a number (2 - 23): 3
+-+
| |
+-+

Enter a number (2 - 23): 8
+------+
|      |
|      |
|      |
|      |
|      |
|      |
+------+

Enter a number (2 - 23): 24
Your number is too high!
*/
