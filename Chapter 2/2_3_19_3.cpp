/* 2.3.3 Finding positive powers of 2
Chris Wild

As powers of ten play an important role in the real lives of humans, powers of two are significant in computers' lives. Can you
enumerate the first few powers of two? It's easy at the beginning: 1, 2, 4, 8,.. but it gets complicated very soon and you'll need some
time to find the next number.

This is a good reason to use a computer instead of our brains.

	* Write a program which shows the n-th power of two (n will be the input for the program). We'll use the following assumptions:
	  the largest value of n to take into consideration is 63, as unsigned long integers use exactly 64 bits to represent their values (note:
	  a value of 2n needs n+1 bits – can you explain why?);
	* we won't use any actual exponentiation – we're going to substitute it with repeated multiplications.

Write a program that implements the task described above.

Test your code using the data we've provided.

Example input

8

Example output

256

Example input

16

Example output

65536

Example input

32

Example output

4294967296

Example input

63

Example output

9223372036854775808
*/

#include <iostream>

using namespace std;

int main()
{
	int pow, loop;
	unsigned long long result = 1;	// needed to use unsigned long long on Windows 7 32 bit machine

	// prompt and input for power of 2 as integer
	cout << "Enter the power of 2 to calculate (0 - 63): ";
	cin >> pow;

	// check that pow is in required bounds
	if (pow < 0 or pow > 63)
	{
		cout << "Invalid value. Number must be between 0 and 63." << endl;
	}
	else
	{
		// calculate result by multiplying 2 by itself pow times
		for (loop = 0; loop < pow; loop++)
		{
			result *= 2;
		}

		// display result
		cout << "2 ^ " << pow << " = " << result << endl;
	}

	return 0;
}

/* Actual output (copied from console window)

Enter the power of 2 to calculate (0 - 63): 8
2 ^ 8 = 256

Enter the power of 2 to calculate (0 - 63): 16
2 ^ 16 = 65536

Enter the power of 2 to calculate (0 - 63): 32
2 ^ 32 = 4294967296

Enter the power of 2 to calculate (0 - 63): 63
2 ^ 63 = 9223372036854775808

Enter the power of 2 to calculate (0 - 63): 64
Invalid value. Number must be between 0 and 63.
*/
