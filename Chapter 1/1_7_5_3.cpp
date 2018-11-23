/* 1.7.3 Getting input from user
Chris Wild

Write a simple code to input an IP number. Check the given data with a few simple conditions (i.e. if the number is in the range from 1
to 255) and concatenate it into an IP number. You must get four numbers from the user, connect them with dots and print them.

Example input

4
2
255
212

Example output

4.2.255.212

Example input

4
1
2
3

Example output

4.1.2.3
*/

#include <iostream>

using namespace std;

int main()
{
    int ip1, ip2, ip3, ip4;

    // input 4 IP number parts from user as integers
    cout << "IP part 1: ";
    cin >> ip1;

    cout << "IP part 2: ";
    cin >> ip2;

    cout << "IP part 3: ";
    cin >> ip3;

    cout << "IP part 4: ";
    cin >> ip4;

    // check that numbers are valid (1 - 255)
    if(ip1 < 1 || ip1 > 255)
    {
        cout << "IP part 1 is out of range (1 - 255)" << endl;
    }
    else if (ip2 < 1 || ip2 > 255)
    {
        cout << "IP part 2 is out of range (1 - 255)" << endl;
    }
    else if (ip3 < 1 || ip3 > 255)
    {
        cout << "IP part 3 is out of range (1 - 255)" << endl;
    }
    else if (ip4 < 1 || ip4 > 255)
    {
        cout << "IP part 4 is out of range (1 - 255)" << endl;
    }
    else
    {
        // print result
        cout << ip1 << "." << ip2 << "." << ip3 << "." << ip4 << endl;
    }    

    return 0;
}

/*Actual output (copied from console window)

IP part 1: 4
IP part 2: 2
IP part 3: 255
IP part 4: 212
4.2.255.212

IP part 1: 4
IP part 2: 1
IP part 3: 2
IP part 4: 3
4.1.2.3

IP part 1: 0
IP part 2: 412
IP part 3: 3
IP part 4: 255
IP part 1 is out of range (1 - 255)
*/