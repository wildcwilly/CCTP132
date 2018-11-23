/* 1.7.1 Printing data
Chris Wild

Define five variables in your code. Assign the values from the input to these variables. Print these variables to get the specified output.

Example input

Put these values into your code:
2.3
2.3
2.123456
2.123456
2.123456

Example output

2.3
2.30
2.123456
2.12
2
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float var1, var2, var3, var4, var5;

    // input values for the 5 variables
    cout << "Number 1: ";
    cin >> var1;

    cout << "Number 2: ";
    cin >> var2;

    cout << "Number 3: ";
    cin >> var3;

    cout << "Number 4: ";
    cin >> var4;

    cout << "Number 5: ";
    cin >> var5;

    // print the variables
    cout << var1 << endl;
    cout << fixed << setprecision(2) << var2 << endl;
    cout << setprecision(6) << var3 << endl;
    cout << setprecision(2) << var4 << endl;
    cout << setprecision(0) << var5 << endl;

    return 0;
}

/* Actual output (copied from console window)

Number 1: 2.3
Number 2: 2.3
Number 3: 2.123456
Number 4: 2.123456
Number 5: 2.123456
2.3
2.30
2.123456
2.12
2
*/
