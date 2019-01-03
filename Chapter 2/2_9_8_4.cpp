/* 2.9.4 Evaluating different kinds of means
Chris Wild

Nobody wants to be "a mean man", but paradoxically, "means" play a very important role in the modern world. We can say that many
people love "means": politicians love "means" (when they want to prove or disprove something), financiers love "means" too (when they
want to show that their profits are not as big as you may suspect) and, most of all, statisticians love "means" more than anything else.

Although an old joke claims that one statistician drowned in a lake whose mean depth didn't exceed 1 ft (ca. 30 cm), we think that it's
worth a try if you can evaluate some of the most commonly used variants of means.

Let's take four of them into consideration:
...
Look at the code below and complete it with a part that evaluates every mean mentioned. Compare your results with the ones we've
provided.

Note the additional #include directive – it's intended to include headers of the mathematical functions needed to finish your work. We
believe that two of them are essential:

    double pow(double x, double y) to evaluate x to the power of y;
    double sqrt(double x) to evaluate the square root of x.

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    double vector[] = { 1., 2., 3., 4., 5. };
    int n = sizeof(vector) / sizeof(vector[0]);
    double ArithmeticMean;
    double HarmonicMean;
    double GeometricMean;
    double RootMeanSquare;

    // Insert your code here

    cout << "Arithmetic Mean = " << ArithmeticMean << endl;
    cout << "Harmonic Mean = " << HarmonicMean << endl;
    cout << "Geometric Mean = " << GeometricMean << endl;
    cout << "RootMean Square = " << RootMeanSquare << endl;
    cout << endl;

    return 0;
}

Example output
Arithmetic Mean = 3
Harmonic Mean = 2.18978
Geometric Mean = 2.60517
RootMean Square = 3.31662
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    double vector[] = { 1., 2., 3., 4., 5. };
    int n = sizeof(vector) / sizeof(vector[0]);
    double ArithmeticMean = 0.;
    double HarmonicMean = 0.;
    double GeometricMean = 1.;  // vectors will be multiplied
    double RootMeanSquare = 0.;

    for(int a = 0; a < n; a++)
    {
        // Arithmetic Mean
        ArithmeticMean += vector[a];

        // Harmonic Mean
        HarmonicMean += (1 / vector[a]);

        // Geometric Mean
        GeometricMean *= vector[a];

        // Root Mean Square
        RootMeanSquare += (pow(vector[a], 2));
    }

    ArithmeticMean /= n;    // divide sum of vector by n

    HarmonicMean = n / HarmonicMean;    // divide n by sum of 1/vector

    GeometricMean = pow(GeometricMean, 1. / n);  // all vectors multiplied with each other to power of 1/n (use 1. to force to double)

    RootMeanSquare = sqrt(RootMeanSquare / n);  // square root of sum of vectors squared / n

    cout << "Arithmetic Mean = " << ArithmeticMean << endl;
    cout << "Harmonic Mean = " << HarmonicMean << endl;
    cout << "Geometric Mean = " << GeometricMean << endl;
    cout << "RootMean Square = " << RootMeanSquare << endl;
    cout << endl;

    system("pause");
    
    return 0;
}

/* Actual output (copied from console window)

Arithmetic Mean = 3
Harmonic Mean = 2.18978
Geometric Mean = 2.60517
RootMean Square = 3.31662
*/
