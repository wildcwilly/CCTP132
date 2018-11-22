/* 1.4.2 Ints: operators and expressions
Chris Wild

Take a look at the code below: it reads two integer values, manipulates them and finally outputs the k variable. The problem is that the
manipulations have been described using natural language, so the code is completely useless now.
We want you to act as an intelligent (naturally!) compiler and to translate the formula into real C++ notation. Try to use pre/post and
short-cut operators – they fit perfectly into some of the steps.
Test your code using the data we've provided.

#include <iostream>

using namespace std;

int main(void) {
	int i, j, k;

	cout << "Enter i: ";
	cin >> i;
	cout << "Enter j: ";
	cin >> j;

	// increment i by 2
	// decrement j by i
	// divide i by j giving k
	// increment k by k
	// decrement k by 1
	// assign k modulo i to j
	// increment k by k added to i
	// increment k by k divided by j
	// assign k times k times k to k
	// increment k by i times j

	cout << k;
	return 0;
}

Example input

100
3

Example output

261838

Example input

31
00

Example output

-5

Example input

123
321

Example output

-125
*/

#include <iostream>

using namespace std;

int main(void)
{
	int i, j, k;

	cout << "Enter i: ";
	cin >> i;
	cout << "Enter j: ";
	cin >> j;

	i += 2;	// increment i by 2
	j -= i;	// decrement j by i
	k = i / j;	// divide i by j giving k
	k += k;		// increment k by k
	k--;		// decrement k by 1
	j = k % i;	// assign k modulo i to j
	k += k + i;	// increment k by k added to i
	k += k / j;	// increment k by k divided by j
	k *= k * k;		// assign k times k times k to k
	k += i * j;	// increment k by i times j

	cout << k << endl;

	system("pause");

	return 0;
}