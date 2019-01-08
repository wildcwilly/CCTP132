/* 3.6.1 Modifying a function argument's value – how do we do it?
Chris Wild

We need a very specific function and we need it ASAP. This is how we imagine it:

	* its name is "increment";
	* it returns void;
	*when invoked with one argument (an int variable), it simply increments the variable by 1;
	*when invoked with two arguments (an int variable and int expression), it increments the variable by the expression's value.

Sorry, we cannot show you the function's header – it would be too easy. We'll only show you how we invoke the function – the rest is
up to you.

Complete the code below.

Run your code and check whether your output is the same as ours.

#include <iostream>

using namespace std;

// Insert your function here

int main(void) {
	int var = 0;
	for(int i = 0; i < 10; i++)
		if(i % 2)
			increment(var);
		else
			increment(var,i);
	cout << var << endl;
	return 0;
}

Example output

25
*/

#include <iostream>

using namespace std;

/* increment function must take value by reference and modify it directly
   as it does not return a value. If inc is not provided, default value will be 1 */
void increment(int &val, int inc = 1)
{
	val += inc;
}

int main(void)
{
	int var = 0;

	for (int i = 0; i < 10; i++)
		if (i % 2)
			increment(var);
		else
			increment(var, i);

	cout << var << endl;

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

25
*/
