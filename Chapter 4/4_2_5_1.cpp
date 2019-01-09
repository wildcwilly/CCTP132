/* 4.2.1 Range of integer types
Chris Wild

Write a program that, given a number N, will calculate the sum of all numbers in the range [1..N].

Your program must give correct results for N up to 100,000.


Example input

5

Example output

15

Example input

124

Example output

7750

Example input

100000

Example output

50005000
*/

#include <iostream>

using namespace std;

int main()
{
	unsigned int number, loop;
	long long sum = 0;

	do
	{
		// prompt and input number as integer
		cout << "Enter a positive number ( >= 1 ): ";
		cin >> number;

		if (number < 1)
			cout << "Invalid number. ";
	} while (number < 1);

	for (loop = 1; loop <= number; loop++)
		sum += loop;
	
	cout << "The sum of all the numbers from 1 to " << number << " equals " << sum << endl;

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Enter a positive number ( >= 1 ): 5
The sum of all the numbers from 1 to 5 equals 15

Enter a positive number ( >= 1 ): 124
The sum of all the numbers from 1 to 124 equals 7750

Enter a positive number ( >= 1 ): 100000
The sum of all the numbers from 1 to 100000 equals 5000050000
*/
