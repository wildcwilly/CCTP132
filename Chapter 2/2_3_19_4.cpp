/* 2.3.4 Finding negative powers of 2
Chris Wild

Okay, positive powers of two are no longer a mystery, but we mustn't forget about the negative ones. They are as important as their
positive siblings. Let's remind ourselves of the basic rule:
	2^-n = 1 / 2^n

We want you to modify your previous program to make it able to evaluate negative powers of two.

Hint 1: use division instead of multiplication.

Hint 2: use a double to store the result – remember, you operate in fractions!

Hint 3: don't forget to add cout.precision(20); before printing the final result (unless you want to lose the most interesting part of the
value)

Test your code using the data we've provided.

Example input

0

Example output

1

Example input

1

Example output

0.5

Example input

8

Example output

0.00390625

Example input

10

Example output

0.0009765625
*/

#include <iostream>

using namespace std;

int main()
{
	int pow, loop;
	double result = 1;

	// prompt and input negative power of 2 as integer
	cout << "Enter the negative power of 2 (as positive number): ";
	cin >> pow;

	// calculate result by dividing 2 by itself pow times
	for (loop = 0; loop < pow; loop++)
	{
		result /= 2;
	}

	// display result
	cout.precision(20);
	cout << "2 ^ " << pow << " = " << result << endl;
	
	return 0;
}

/* Actual output (copied from console window)

Enter the negative power of 2 (as positive number): 0
2 ^ 0 = 1

Enter the negative power of 2 (as positive number): 1
2 ^ 1 = 0.5

Enter the negative power of 2 (as positive number): 8
2 ^ 8 = 0.00390625

Enter the negative power of 2 (as positive number): 10
2 ^ 10 = 0.0009765625
*/
