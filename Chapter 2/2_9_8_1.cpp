/* 2.9.1 Simple vector manipulations
Chris Wild

Take a look at the code below - it declares two equally sized vectors. The former is initialized, the latter isn't.
We want the second vector to store the same values as the first one, but in a different order: imagine that all the values have been moved
one cell to the right, while the last element has gone to the first position. We can say that the vector has been rotated to the right.
Warning: you must use the for loop for it. Don't use single assignments - they may work but they'll reflect badly on you and on your
programming skills.

Once you get the expected results, play around a bit with your code: change the size of your vectors and check if your program
executes properly.

#include <iostream>

using namespace std;

int main(void) {
    int vector1[7] = {4, 7, 2, 8, 1, 3, 0};
    int vector2[7];

    // Insert your code here

    for(int i = 0; i < 7; i++)
        cout << vector2[i] << ' ';
    cout << endl;

    return 0;
}

Example output

0 4 7 2 8 1 3
*/

#include <iostream>

using namespace std;

int main(void) {
    int vector1[7] = {4, 7, 2, 8, 1, 3, 0};
    int vector2[7], loop;

    for(loop = 0; loop < 7; loop++)
    {
        if(loop < 6)    // not the last element
            vector2[loop + 1] = vector1[loop];
        else
            vector2[loop - 6] = vector1[loop];
    }

    for(int i = 0; i < 7; i++)
        cout << vector2[i] << ' ';
    cout << endl;

    return 0;
}

/* Actual output (copied from console window)

C:\Users\...>CCTP132.exe
0 4 7 2 8 1 3
*/
