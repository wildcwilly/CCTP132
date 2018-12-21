/* 2.3.8 Do it yourself: factorials
Chris Wild

We want to stay a little longer in the land of mathematics – we hope you won't hold that against us.

We're going to show you a function that comes from one of the most interesting parts of mathematics: combinatorics. Its name is
"factorial" and it was initially used to find a number of possible permutations of a set e.g. if you have three books (A,B,C) on your shelf,
there are six possible arrangements of them: ABC, ACB, BCA, BAC, CAB, CBA. This means that there are six possible permutations of a
three-element set. Therefore, we can say that the factorial of 3 is equal to 6.

The last sentence is often shortened to the following form:

3! = 6

One of the possible formal definitions of the factorial function has prompted us to formulate the next task for you, as it's a classic
example of using a loop. Which one would be better? "While"? "For"? It's up to you!

Here goes the definition:

	* 0! = 1 (strange, but true)
	* 1! = 1 (obvious)
	* n! = 1 * 2 * ... * n (can you see a loop here?)

We aren't going to waste your time any longer – let's start coding! Your program should ask the user for the value of n and then output
the value of n!. We should warn you that factorial values grow extremely fast – don't be surprised. That's why our example input data
doesn't look very impressive, in contrast to the output.

Example input

5

Example output

10

Example input

10

Example output

3628800

Example input

20

Example output

2432902008176640000
*/

#include <iostream>

using namespace std;

int main()
{
	int number, loop;
	long long factorial = 1;

	// pompt and enter number as integer
	cout << "Enter a positive number: ";
	cin >> number;

	if (number < 0)	// check that number is positive
	{
		cout << "Your number must be positive" << endl;
	}
	else
	{
		//if(number == 0)	// factorial will be 1, change value to 1 for loop to work

		for (loop = 1; loop <= number; loop++)
		{
			factorial *= loop;
		}

		// output value
		cout << number << "! = " << factorial << endl;
	}

	return 0;
}

/* Actual output (copied from console window)

Enter a positive number: -1
Your number must be positive

Enter a positive number: 0
0! = 1

Enter a positive number: 1
1! = 1

Enter a positive number: 5
5! = 120						<<--- Lab has incorrect result for this

Enter a positive number: 10
10! = 3628800

Enter a positive number: 20
20! = 2432902008176640000
*/
