/* 4.5.1 Text manipulation: duplicate white space
Chris Wild

Write a program that will read a line of text and remove all duplicate whitespace.

Note that any single whitespace characters must remain intact.

#include <string>
#include <iostream>

int main()
{
	std::string sentence;
	std::getline(std::cin, sentence);

	// manipulate the sentence here
	
	std::cout << sentence << "\n";
}}

Example input

This is    a totally     normal    sentence.

Example output

This is a totally normal sentence.

Example input

This shouldn't change a bit!

Example output

This shouldn't change a bit!
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string sentence;
	int start = 0, end;

	cout << "Type a sentence: ";
	getline(cin, sentence);

	do
	{
		end = sentence.find(" ", start);	// find next space

		if (start == end)	// only a space was found, which was either at beginning or duplicate
		{
			sentence.erase(start, 1); // remove the extra space
		}
		else
		{
			start = end + 1;	// move the start to the next character
		}
	} while (end != string::npos);

	cout << sentence << "\n";

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Type a sentence: This shouldn't change a bit!
This shouldn't change a bit!

Type a sentence: This is    a totally     normal    sentence.
This is a totally normal sentence.
*/
