/* 2.4.2 Bitwise palindromes
Chris Wild

A palindrome is a sequence of symbols (letters, digits, etc.) which reads the same backward and forward. For example, the word
"kayak" is a palindrome while the word "canoe" is not.

Bits placed in an integer variable may be palindromes too (to make this story shorter, we'll use the unsigned short int type in our
problem) e.g. the value 384 is a palindrome as its binary representation written in 16 bits looks as follows:

0000000110000000

Your task it to write a program that checks if any unsigned short int value is a bitwise palindrome.

Hint: the simplest (but probably not the smartest) solution is just to reverse the bit order in a value and compare it to the original one – an
(in)equality of both values is a clear indication of the answer.

Complete the following code to achieve your goal and do tests using the data we've provided.

#include <iostream>

using namespace std;

int main(void) {
    unsigned short int val;
    bool ispalindrome = false;

    cout << "value = ";
    cin >> val;

    // Insert your code here

    if(ispalindrome)
        cout << val << " is a bitwise palindrome" << endl;
    else
        cout << val << " is not a bitwise palindrome" << endl;
    return 0;
}

Example input

0

Example output

0 is a bitwise palindrome

Example input

65536

Example output

65535 is a bitwise palindrome

Example input

21930

Example output

21930 is a bitwise palindrome

Example input

21929

Example output

21929 is not a bitwise palindrome
*/

#include <iostream>

using namespace std;

int main(void) {
    unsigned short int val, rev = 0, mask1, mask2, loop;
    bool ispalindrome = false;

    cout << "value = ";
    cin >> val;

    // reverse bit order of val and store in rev
    for(loop = 0; loop < 16; loop++)    // loop through val (2 bytes * 8 bits = 16 bits)
    {
        mask1 = 1 << loop;  // set mask1 from right
        mask2 = 1 << 15 - loop; // set mask2 from left

        // if bit is set (from right), set bit in rev (from left)
        if(val & mask1)
        {
            rev |= mask2;
        }
    }

    if (val == rev)
        ispalindrome = true;

    if(ispalindrome)
        cout << val << " is a bitwise palindrome" << endl;
    else
        cout << val << " is not a bitwise palindrome" << endl;

    return 0;
}

/* Actual output (copied from console window)

value = 0
0 is a bitwise palindrome

value = 65536
0 is a bitwise palindrome

value = 21930
21930 is a bitwise palindrome

value = 21929
21929 is not a bitwise palindrome

value = 3
3 is not a bitwise palindrome
*/
