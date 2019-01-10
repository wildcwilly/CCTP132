/* 4.5.1 String in functions: IP numbers
Chris Wild

Write a function to check a string parameter that contains an IP address – return the string with information about whether the address
is correct or not. Here are some possible return strings:
	* Correct IP;
	* Too many characters in a part;
	* Too many parts;
	* Only digits and dots allowed;
	* Too big a value of a part;
	* Incorrect parts count.

Example input

1.2.3.4
255.255.255.255
355.255.255.255
1000.255.255.255
ASD.255.255.255

Example output

Correct IP
Correct IP
Too big a value of a part
Too many characters in a part
Only digits and dots allowed
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string ip, part;
	int partCount = 0, start = 0, end;
	bool correctIP = true;

	cout << "Enter an IP address: ";
	getline(cin, ip);

	// break string apart and check each part
	do
	{
		end = ip.find('.', start);	// define start and end positions of part

		part = ip.substr(start, end - start);
		partCount++;

		// verify parts
		if (!(part.find_first_not_of("0123456789") == string::npos))
		{
			cout << "Only digits and dots allowed!" << endl;
			correctIP = false;
		}
		else
		{
			if (stoi(part) > 255)
			{
				cout << "Too big a value of a part!" << endl;
				correctIP = false;
			}
		}

		if (part.length() > 3)
		{
			cout << "Too many characters in part!" << endl;
			correctIP = false;
		}

		start = end + 1;	// setup for next part search
	} while (end != string::npos);

	// verify number of parts
	if (partCount < 4)
	{
		cout << "Too few parts!" << endl;
		correctIP = false;
	}
	if (partCount > 4)
	{
		cout << "Too many parts!" << endl;
		correctIP = false;
	}

	if(correctIP)
		cout << "Correct IP!" << endl;

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Enter an IP address: 1.2.3.4
Correct IP!

Enter an IP address: 255.255.255.255
Correct IP!

Enter an IP address: 355.255.255.255
Too big a value of a part!

Enter an IP address: 1000.255.255.255
Too big a value of a part!
Too many characters in part!

Enter an IP address: ASD.255.255.255
Only digits and dots allowed!

Enter an IP address: 192.1684.a.1
Too big a value of a part!
Too many characters in part!
Only digits and dots allowed!

Enter an IP address: 255.255.255
Too few parts!

Enter an IP address: 255.255.255.255.255
Too many parts!
*/