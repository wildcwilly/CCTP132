/* 1.7.2 Near zero float numbers
Chris Wild

All operations on float numbers should be made while keeping one thing in mind: they are not entirely accurate. If we're comparing two
float numbers, we must use an epsilon comparison. Write code to check if two given numbers differ by only a small value (i.e.
0.000001). Ask for two integer numbers from the user. Divide 1 by each of them (1 by the first number and 1 by the second number)
and compare the results of this operation. Print the information to the user. Remember to convert to floats before dividing.

Example input

1
1

Example output

Results are equal (by 0.000001 epsilon)

Example input

1011
1112

Example output

Results are not equal (by 0.000001 epsilon)
*/

#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    float val1, val2;

    // input integer values
    cout << "Enter number 1: ";
    cin >> num1;

    cout << "Enter number 2: ";
    cin >> num2;

    // get float value by dividing 1.0 by number (for each number)
    val1 = 1.0 / float(num1);
    val2 = 1.0 / float(num2);

    // compare results and print information
    if(val1 == val2)
    {
        cout << "Results are equal(by 0.000001 epsilon)" << endl;
    }
    else
    {
        cout << "Results are not equal(by 0.000001 epsilon)" << endl;
    }
    
    return 0;
}

/* Actual output (copied from console window)

Enter number 1: 1
Enter number 2: 1
Results are equal(by 0.000001 epsilon)

Enter number 1: 1111
Enter number 2: 1112
Results are not equal(by 0.000001 epsilon)
*/