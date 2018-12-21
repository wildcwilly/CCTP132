/* 2.3.7 Do it yourself: Fibonacci sequence
Chris Wild

We're almost sure that you've heard of the Fibonacci sequence. It's a series of natural numbers built up by a simple formula:

	* the first Fibonacci number is equal to 1;
	* the second Fibonacci number is equal to 1 too;
	* the third, fourth and every subsequent Fibonacci number is equal to the sum of the previous two numbers.

This means that the first five Fibonacci numbers look as follows:

	1, 1, 2, 3, 5

Is that clear? Of course it is! Now it's your turn � write a code asking the user for a number (let's name it n) and then print an n-th
Fibonacci number.

But beware! These numbers grow very fast � use proper data types to avoid premature overflows!

Test your code using the data we've provided.

Example input

8

Example output

21

Example input

20

Example output

6765

Example input

55

Example output

139583862445
*/

#include <iostream>

using namespace std;

int main()
{
	int number, loop;
	long long num1 = 0, num2 = 1, fibonacci = 1;	// need a long long on 32 bit Windows system

	// prompt user for number and enter as integer
	cout << "Enter a number: ";
	cin >> number;

	if (number < 1)
	{
		cout << "Your number is too low!";
	}
	else
	{
		for (loop = 0; loop < number-1; loop++)
		{
			fibonacci = num1 + num2;
			num1 = num2;
			num2 = fibonacci;
		}

		cout << fibonacci << endl;
	}

	return 0;
}

/* Actual output (copied from console window)

Enter a number: 8
21

Enter a number: 20
6765

Enter a number: 55
139583862445
*/
