/* 3.8.1 Overloading functions
Chris Wild

Sorry for bothering you, but we have to tell you that the function you implemented last time needs to be supplemented with another one
that performs (more or less) the same actions, but uses different type of data. We can't say anything more, but we're sure that you'll be
able to deduce all our intentions and needs from the code below.

Complete the code and run it to check whether your output is the same as ours.

#include <iostream>
#include <cmath>

using namespace std;

// Insert your functions here

int main(void){
	int intvar = 0;
	float floatvar = 1.5;

	for(int i = 0; i < 10; i++)
		if(i % 2) {
			increment(intvar);
			increment(floatvar, sqrt(intvar));
		}
		else {
			increment(intvar,i);
			increment(floatvar);
		}
	cout << intvar * floatvar << endl;
	return 0;
}

Example output

537.5
*/

#include <iostream>
#include <cmath>

using namespace std;

void increment(int &val, int inc = 1)
{
	val += inc;
}

void increment(float &val, double inc = 1.)
{
	val += inc;
}

int main(void)
{
	int intvar = 0;
	float floatvar = 1.5;

	for (int i = 0; i < 10; i++)
		if (i % 2)
		{
			increment(intvar);
			increment(floatvar, sqrt(intvar));
		}
		else
		{
			increment(intvar, i);
			increment(floatvar);
		}

	cout << intvar * floatvar << endl;

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

537.5
*/
