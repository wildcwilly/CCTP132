/* 1.6.1 Logical data: operators and expressions
Chris Wild

Take a look at the code below: it reads an integer value, and is then ready to perform a complicated magical test and print the answer – it
may be positive or it may not. Okay, you may be a bit surprised with the form of the line sending the result to the output, but don't
worry – it'll look familiar to you soon. Just accept it as-is and just remember that the purpose of this construction is to write a clear
message concerning the test result.

Now listen to an ancient story that says:

We need a number whose value:
    * is greater than or equal to 0 and less than 10, or
    * multiplied by 2 is less than 20 and reduced by 2 is greater than minus 2, or
    * reduced by 1 is greater than 1 and divided by 2 is less than 10, or
    * is equal to 111.

Write the above condition in the form of an expression accepted by the C++ language and assign its result to the answer variable.
Test your code using the data we've provided.

#include <iostream>

using namespace std;

int main(void) {
    bool answer;
    int value;

    cout << "Enter a value: ";
    cin >> value;

    answer = ... // insert your expression here

    cout << (answer ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;
    return 0;
}}

Example input

-2

Example output

THAT'S NOT TRUE :(

Example input

0

Example output

THAT'S TRUE :)

Example input

4

Example output

THAT'S TRUE :)

Example input

10

Example output

THAT'S TRUE :)

Example input

22

Example output

THAT'S NOT TRUE :(

Example input

100

Example output

THAT'S NOT TRUE :(

Example input

111

Example output

THAT'S TRUE :)
*/

#include <iostream>

using namespace std;

int main(void)
{
    bool answer;
    int value;

    cout << "Enter a value: ";
    cin >> value;

    answer = (value >= 0 && value < 10) || (value * 2 < 20 && value - 2 > -2) || (value - 1 > 1 && value / 2 < 10) || (value == 111);

    cout  << (answer ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;

    return 0;
}

/*
    * is greater than or equal to 0 and less than 10, or
    * multiplied by 2 is less than 20 and reduced by 2 is greater than minus 2, or
    * reduced by 1 is greater than 1 and divided by 2 is less than 10, or
    * is equal to 111.
*/