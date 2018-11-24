/* 2.1.3 Some actual evaluations - converting measurement systems
Chris Wild

Among the many measurement systems available, two seem to be the most widespread: metric and imperial. To make things simpler, we
assume that the first one uses the "meter" as its only unit (expressed as a real number), while the second uses the "foot" (always an
integer) and the "inch" (a real number).
Your task is to write a simple "measurement converter". We want it to perform the following actions:
    * ask the user which system she/he uses to input data; we assume that 0 means "metric" and 1 means "imperial";
    * depending on the user's answer, ask either for meters or feet and inches;
    * output the distance in proper (different) units: either in feet and inches or in meters;
    * a result outputted as metric should look like 123.4m ;
    * a result outputted as imperial should look like 12'3.5" .
Look at the code below – it's only a template. Use it to implement the whole converter.
Make your code smart – it shouldn't be fooled by stupid or unreasonable inputs.
Test your code using the data we've provided.

#include <iostream>

using namespace std;

int main(void) {
    int sys;
    float m, ft, in;

    // Insert your code here

    return 0;
}

Example input

0
1

Example output

3'3.37008"

Example input

1
3
3.37008

Example output
1m

Example input

0
0.0254

Example output

0'1"

Example input

1
0
1

Example output

0.0254m
*/

#include <iostream>

using namespace std;

int main(void)
{
    int sys;
    float m, ft, in;

    // prompt and input measurement system from user
    cout << "Which measurement system - 0 (metric) or 1 (imperial): ";
    cin >> sys;

    if(sys == 0)    // user entering metric
    {
        // prompt and input for meters from user
        cout << "Enter measurement in meters: ";
        cin >> m;

        // check for positive number
        if(m > 0)
        {
            ft = m * 3.28084;   // convert meters to feet (1m = 3.28084')

            in = ft - int(ft);  // inches is decimal part of feet
            ft = ft - in;       // remove decimal portion to leave feet
            in = in * 12;       // multiply decimal part of feet (12" / ft) to get actual inches

            // output result
            cout <<  ft << "\'" << in << "\"" << endl;
        }        
        else
        {
            cout << "measurement needs to be positive and greater than 0" << endl;
            return 1;
        }
        
    }
    else if(sys == 1) // user entering imperial
    {
        // prompt and input data from user
        cout << "How many feet: ";
        cin >> ft;

        cout << "How many inches: ";
        cin >> in;

        // combine feet and inches into feet for conversion
        in = in / 12;   // divide in by 12 (12" / ft) to get decimal fraction of foot
        ft += in;

        m = ft / 3.28084;   // convert feet to meters (1m = 3.28084')

        // output result
        cout << m << "m" << endl;
    }
    else    // user entered invalid choice
    {
        cout << "Invalid entry. 0 (metric) or 1 (imperial)" << endl;
        return 1;
    }

    return 0;
}

/* Actual output (copied from console window)

Which measurement system - 0 (metric) or 1 (imperial): 0
Enter measurement in meters: 1
3'3.37008"

Which measurement system - 0 (metric) or 1 (imperial): 1
How many feet: 3
How many inches: 3.37008
1m

Which measurement system - 0 (metric) or 1 (imperial): 0
Enter measurement in meters: 0.0254
0'1"

Which measurement system - 0 (metric) or 1 (imperial): 1
How many feet: 0
How many inches: 1
0.0254m
*/