/* 2.9.5 Two-dimensional square array – symmetric or not?
Chris Wild

A matrix (a two-dimensional array) is symmetric if:

    it's a square matrix (its sides are equal);
    its elements are placed symmetrically about the main diagonal (the diagonal that goes from the upper-left to the bottom-right
    vertex).

To be clear – this is a symmetric matrix:

1 2 3
2 1 2
3 2 1

and this is not:

1 2 3
2 1 2
4 2 1

The code below declares a 4×4 matrix initially filled with some data. Your task is to complete the code and to answer the fundamental
question: is this matrix symmetric or not?

When you complete your code, play with the matrix a bit: change its dimensions, move some of the elements – be sure that your code
works well in any situation.

#include <iostream>

using namespace std;

int main(void) {
    double matrix[][4] = { { 1, 2, 3, 4 },
    { 2, 2, 3, 1 },
    { 3, 3, 3, 2 },
    { 4, 1, 2, 4 } };
    int side = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    bool issymmetric = true;

    // Insert your code here

    if(issymmetric)
        cout << "The matrix is symmetric" << endl;
    else
        cout << "The matrix is not symmetric" << endl;
    return 0;
}
*/

#include <iostream>

using namespace std;

int main()
{
    double matrix[][3] = {  { 1, 2, 3 },
                            { 2, 1, 2 },
                            { 3, 2, 1 } };
    int width = sizeof(matrix[0]) / sizeof(matrix[0][0]);   // number of elements across
    int height = sizeof(matrix) / sizeof(matrix[0]);        // number of elements high
    int row, column;
    bool issymmetric = true;

    // display matrix
    for(row = 0; row < height; row++)
    {
        for(column = 0; column < width; column++)
        {
            cout << matrix[row][column] << " ";
        }

        cout << endl;
    }

    cout << endl;

    // check if matrix is symetrical
    if(width == height)
    {
        // compare top element of matrix with equivalent left element of matrix
        // reduce size of box each time
        for(row = 0; row < width; row++)
            for(column = row; column < width; column++)
                if(matrix[column][row] != matrix[row][column])
                    issymmetric = false;
    }
    else
    {
        issymmetric = false;
    }

    if(issymmetric)
        cout << "The matrix is symmetric" << endl;
    else
        cout << "The matrix is not symmetric" << endl;

	system("pause");
    
	return 0;
}

/* Actual output (copied from console window)

1 2 3 4
2 2 3 1
3 3 3 2
4 1 2 4

The matrix is symmetric

1 2 3 4 5
2 2 3 1 4
3 3 3 2 3
4 1 2 4 2

The matrix is not symmetric

1 2 3 4 5
2 2 3 1 4
3 3 3 2 3
4 1 2 4 2
5 4 3 2 7

The matrix is symmetric

1 2 3
2 2 3
3 3 3
4 1 2
5 4 3

The matrix is not symmetric

1 2 3
2 1 2
3 2 1

The matrix is symmetric
*/
