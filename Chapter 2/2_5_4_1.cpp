/* 2.5.1 A real and usable calculator
Chris Wild

Your task it to write a real, interactive, four-function calculator. Of course, you may add as many new functions as you want, but four
basic operations (+ - * /) are a must. Moreover, we hope that your calculator will be smart enough not to be fooled by a division by 0.
Be careful!

We want your program to display a menu that looks like this one:

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice?

Next, your program should read an int value representing the chosen option and act accordingly. If the option requires the execution of
further operations, your program should read two double values, perform an operation and display the result. Then, your program should
display a menu and... the story repeats until the user enters 0.

Hint: use a switch statement - you expected this, didn't you?

Test your program carefully using a wide range of data.
*/

#include <iostream>

using namespace std;

int main()
{
    int operation;
    double op1, op2, result;

    do
    {
        // display menu
        cout << "MENU:\n";
        cout << "0 - exit\n";
        cout << "1 - addition\n";
        cout << "2 - subtraction\n";
        cout << "3 - multiplication\n";
        cout << "4 - division\n";
        cout << "Your choice? ";

        cin >> operation;

        // Enter 2 numbers if operation is valid choice
        if(operation >= 1 && operation <= 4)
        {
            cout << "First number: ";
            cin >> op1;
            cout << "Second number: ";
            cin >> op2;
        }

        // perform appropriate operation on both numbers
        switch(operation)
        {
            case 0:
                break;
            case 1:
                cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
                break;
            case 2:
                cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
                break;
            case 3:
                cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
                break;
            case 4:
                if(op2 != 0)
                {
                    cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
                }
                else
                {
                    cout << "Can't divide by 0!\n";
                }
                break;
            default:
                cout << "Invalid entry, try again.\n";
                operation = 5;
        }
        
        cout << endl;   // add extra blank line for next menu listing

    }while(operation);

	return 0;
}

/* Actual output (copied from console window)

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 1
First number: 10
Second number: 10
10 + 10 = 20

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 1
First number: 10.236
Second number: 183.1362
10.236 + 183.136 = 193.372

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 1
First number: -15
Second number: -45
-15 + -45 = -60

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice?
2
First number: 2
Second number: 2
2 - 2 = 0

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 2
First number: 5
Second number: 10
5 - 10 = -5

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 2
First number: 33.623
Second number: 12.4862
33.623 - 12.4862 = 21.1368

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 3
First number: 3
Second number: 3
3 * 3 = 9

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 3
First number: 5.5
Second number: 5.55
5.5 * 5.55 = 30.525

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 3
First number: -12
Second number: -75
-12 * -75 = 900

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 3
First number: 3
Second number: 3
3 * 3 = 9

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 4
First number: 3
Second number: 3
3 / 3 = 1

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 4
First number: 3
Second number: 1
3 / 1 = 3

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 4
First number: 235.23
Second number: 2
235.23 / 2 = 117.615

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 4
First number: 3
Second number: 0
Can't divide by 0!

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 5
Invalid entry, try again.

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? -1
Invalid entry, try again.

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 25
Invalid entry, try again.

MENU:
0 - exit
1 - addition
2 - subtraction
3 - multiplication
4 - division
Your choice? 0
*/
