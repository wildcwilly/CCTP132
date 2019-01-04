/* 3.2.1 Vectors and pointers: first try
Chris Wild

Look at the code below. It doesn't look scary, right?

Your task doesn't look scary either – you just have to find the smallest element in the vector. But there's one condition – you mustn't use
indexing. In other words, using brackets in your code is strictly prohibited.

Hint: You may use as many pointers as you wish.

Forgive us that we don't show you any sample output. We would much rather see your code – it's much more interesting.

using namespace std;

int main(void) {
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int n = sizeof(vector) / sizeof(vector[0]);

    // Insert your code here

    return 0;
}

*/

#include <iostream>

using namespace std;

int main()
{
    int vector[] = { 3, -5, 7, 10, -4, 14, 5 };
    int n = sizeof(vector) / sizeof(vector[0]);
    int *smallest = vector, *nextNum = vector, loop;

    cout << *smallest;

    for(loop = 1; loop < n; loop++)
    {
        nextNum++;  // increment to next index value

        cout << " " << *nextNum;

        if(*nextNum < *smallest)
            smallest = nextNum;
    }

    cout << "\nThe smallest number in the vector is " << *smallest << endl;

    cout << endl;

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

3 -5 7 10 -4 14 5 2 -13
The smallest number in the vector is -13

3 -5 7 10 -4 14 5
The smallest number in the vector is -5
*/
