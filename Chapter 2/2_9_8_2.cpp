/* 2.9.2 Collecting banknotes
Chris Wild

Once upon a time there was a country called Plusplusland. The monetary system they used there was simple: the currency name was the
"plussar" and their central bank issued five different banknotes of values 50, 20, 10, 5 and 1 plussar.
Your task is to write a driver for the ATMs of Plusplusland. The driver should find the minimal number of banknotes needed to deliver
any amount of money to the client.

The Treasury Minister has asked you personally to do this. He expects your code to print the values of all the needed banknotes in a row
– this is the format accepted by all ATMs in Plusplusland.

Test your code using the data we've provided.

Example input

125

Example output

50 50 20 5

Example input

127

Example output

50 50 20 5 1 1

Example input

49

Example output

20 20 5 1 1 1 1
*/

#include <iostream>

using namespace std;

int main()
{
    int plussar[5] = { 50, 20, 10, 5, 1 };
    int notes[5];
    int money, loop, loop2;

    cout << "Enter the amount of money to dispense: ";
    cin >> money;

    for(loop = 0; loop < 5; loop++)
    {
        notes[loop] = money / plussar[loop];    // calculate number of each note
        money %= plussar[loop];                 // reduce money until 0
    }

    // output notes
    for(loop = 0; loop < 5; loop++)
    {
        for(loop2 = 0; loop2 < notes[loop]; loop2++)
        {
            cout << plussar[loop] << " ";
        }
    }

    cout << endl;

	return 0;
}

/* Actual output (copied from console window)

Enter the amount of money to dispense: 125
50 50 20 5

Enter the amount of money to dispense: 127
50 50 20 5 1 1

Enter the amount of money to dispense: 49
20 20 5 1 1 1 1

Enter the amount of money to dispense: 236
50 50 50 50 20 10 5 1

Enter the amount of money to dispense: 3
1 1 1
*/
