/* 1.4.40.1 Floats: operators and expressions
Chris Wild

Scenario
Take a look at the code below: it reads a float value, puts it into a variable named x and prints the value of a variable named y. Your task
is to complete the code in order to evaluate the following expression:
    see document
We expect the result to be assigned to y.
Note: we've prepared a variable containing the value of π. Use it.
Be careful! Watch the operators and keep their priorities in mind. Remember that classical algebraic notation likes to omit the
multiplication operator – you need to use it explicitly.
Don't hesitate to use as many parentheses as you need. Keep your code clean and readable – surround the operators with spaces.
Use additional variables to shorten the expression.
Hint: multiply x by x to get x squared.
Test your code by using the data we've provided – don't be discouraged by any initial failures. Be persistent and inquisitive. Good luck!

#include <iostream>

using namespace std;

    int main(void) {
    float pi = 3.14159265359;
    float x,y;
    cout << "Enter value for x: ";
    cin >> x;
    // put your code here
    cout << "y = " << y;
    return 0;
}

Example input

1

Example output

y = 0.0949234

Example input

-1.5

Example output

y = 0.0890702

Example input

12.345

Example output

y = 0.101057
*/

#include <iostream>

using namespace std;

    int main(void) {
    float pi = 3.14159265359;
    float x,y;
    cout << "Enter value for x: ";
    cin >> x;
    // put your code here
    cout << "y = " << y;
    return 0;
}
