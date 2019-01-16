/* 4.5.2 Text manipulation: find and replace
Chris Wild

A common action when editing text is to replace an expression or word with yet another expression.

Write a program that will read three lines of text. In the last line read replace all occurrences of the expression in the first line with the
expression in the second line.

Make sure that changing an expression to a similar expression will not cause your program any problems.

#include <string>
#include <iostream>

int main()
{
	std::string from;
	std::getline(std::cin, from);

	std::string to;
	std::getline(std::cin, to);

	std::string sentence;
	std::getline(std::cin, sentence);

	// change all occurrences of 'from' into 'to' in the sentence

	std::cout << sentence << "\n";
}

Example input

John
Mary
John had a little lamb

Example output

Mary had a little lamb

Example input

difficult problems
opportunities to grow
A software engineer may encounter many difficult problems

Example output

A software engineer may encounter many opportunities to grow

Example input

Linux
GNU Linux
Some prefer Linux over Windows

Example output

Some prefer GNU Linux over Windows
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int found, start = 0;

	string from;
	cout << "Enter the from expression: ";
	getline(cin, from);

	string to;
	cout << "Enter the to expression: ";
	getline(cin, to);

	string sentence;
	cout << "Enter the sentence: ";
	getline(cin, sentence);

	// change all occurrences of 'from' into 'to' in the sentence
	do
	{
		found = sentence.find(from, start);	// search for next instance of from

		if(found != string::npos)
			sentence.replace(found, from.length(), to);	// replace the from string with the to string

		start = found + to.length();	// move beginning of search to after the replaced string (stops recursive replacement)
	} while (found != string::npos);

	cout << sentence << "\n";

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Enter the from expression: John
Enter the to expression: Mary
Enter the sentence: John had a little lamb
Mary had a little lamb

Enter the from expression: difficult problems
Enter the to expression: opportunities to grow
Enter the sentence: A software engineer may encounter many difficult problems
A software engineer may encounter many opportunities to grow

Enter the from expression: Linux
Enter the to expression: GNU Linux
Enter the sentence: Some prefer Linux over Windows
Some prefer GNU Linux over Windows
*/
