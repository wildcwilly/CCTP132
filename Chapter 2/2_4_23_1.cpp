/* 2.4.1 Counting bits (the ones)
Chris Wild

Scenario
We've told you many, many times that computers store information using bits. You know perfectly well that a single bit is in fact a twostate device. It's easier to name these states "0"and "1", although technically they are actually connected to electrical phenomena like
voltage or electric charge.

Now it's time to feel the bits – to look inside the variables and to see their internal life.

Your task is to write a program that counts the ones (bits set to "1") in an integer variable. We suggest that you use an unsigned long
for that purpose.

Hint 1: you can test an individual bit to find if it's set or reset – the '&' operator will do that for you.

Hint 2: you can shift the value to prepare the remaining bits for testing.

Hint 3: you can repeat the above steps to... sorry, we won't say anything more...

...but we'll provide you with the test data!

Example input

15

Example output

4

Example input

65536

Example output

1

Example input

2222222

Example output

10
*/

#include <iostream>

using namespace std;

int main()
{
    int ones = 0, loop;
    unsigned long number, flag = 1;

    // prompt and input a number as an integer
    cout << "Enter a number: ";
    cin >> number;

    // loop through each bit of number (8 bytes * 8 bits = 64 bits)
    for(loop = 0; loop < 64; loop++)
    {
        if(number & flag)
        {
            ones++;
        }

        flag <<= 1;
    }

    cout << "There are " << ones << " bits set to 1 in " << number << endl;

	return 0;
}

/* Actual output (copied from console window)

Enter a number: 0
There are 0 bits set to 1 in 0

Enter a number: 1
There are 1 bits set to 1 in 1

Enter a number: 15
There are 4 bits set to 1 in 15

Enter a number: 65536
There are 1 bits set to 1 in 65536

Enter a number: 2222222
There are 10 bits set to 1 in 2222222
*/
