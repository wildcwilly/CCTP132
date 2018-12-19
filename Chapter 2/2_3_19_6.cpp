/* 2.3.6 Postcard from Gizah
Chris Wild

It seems that drawing rectangles is a piece of cake for you. Okay, we're aware that we should put the word "drawing" in quotes as it's
as far from actual drawing as walking is from flying. But we're sure that the time when you'll be able to create real computer graphics is
near – the beginnings are always difficult.

We'd like to see how well you can use the for loop, so now we want you to draw a "Postcard from Gizah" i.e. create a view of a
famous location: a few famous pyramids.

Your program should ask the user about a single pyramid's height (h, 2 < h < 9) and then create a picture like the one below.

Don't cheat! Don't output hard-coded strings containing a rigid number of asterisks and spaces – all elements must be created
dynamically!

Example input

3

Example output

  *     *     *
 * *   * *   * *
***** ***** *****

Example input

8

Example output

       *               *               *
      * *             * *             * *
     *   *           *   *           *   *
    *     *         *     *         *     *
   *       *       *       *       *       *
  *         *     *         *     *         *
 *           *   *           *   *           *
*************** *************** ***************
*/

#include <iostream>

using namespace std;

int main()
{
	int height, row, pyramids, outsideSpaces, insideSpaces, loop;

	// prompt and enter pyramid height as int
	cout << "Enter the height of the pyramid (2 - 8): ";
	cin >> height;

	if (height < 2) // number too low
	{
		cout << "Your number is too low!";
	}
	else if (height > 8)	// number too high
	{
		cout << "Your number is too hight";
	}
	else
	{
		for (row = 0; row < height; row++)
		{
			for (pyramids = 0; pyramids < 3; pyramids++)
			{
				// calculate outside spaces for pyramid row
				outsideSpaces = height - row - 1;	// the 1 represents the '*'

				// calculate inside spaces for pyramid row
				insideSpaces = (row * 2) - 1;

				// display pyramids
				// spaces on left side
				for (loop = 0; loop < outsideSpaces; loop++)
				{
					cout << " ";
				}

				cout << "*";

				// spaces (or '*' for bottom row) inside pyramid
				for (loop = 0; loop < insideSpaces; loop++)
				{
					if (row < height - 1)
					{
						cout << " ";
					}
					else
					{
						cout << "*";
					}
				}

				if (row > 0)	// ignore second '*' if first row
				{
					cout << "*";
				}

				// spaces on right side of pyramid
				for (loop = 0; loop < outsideSpaces; loop++)
				{
					cout << " ";
				}

				cout << " ";	// space between pyramids
			}

			cout << "\n";	// next row
		}
	}

	return 0;
}

/* Actual output (copied from console window)

Enter the height of the pyramid (2 - 8): 3
  *     *     *
 * *   * *   * *
***** ***** *****

Enter the height of the pyramid (2 - 8): 8
	   *               *               *
	  * *             * *             * *
	 *   *           *   *           *   *
	*     *         *     *         *     *
   *       *       *       *       *       *
  *         *     *         *     *         *
 *           *   *           *   *           *
*************** *************** ***************
*/
