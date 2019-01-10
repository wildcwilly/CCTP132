/* 4.5.1 Text manipulation: eliminate duplicates
Chris Wild

When editing text, it is more than common to revisit and edit some previously written sentences. When doing so, people tend to duplicate
words.

Write a program that will read a line of text and remove all the duplicate words in that line of text.

However, two identical words separated by punctuation should not be considered duplicate.

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

This sentence has no duplicate words

Example output

This sentence has no duplicate words

Example input

This sentence has has only unique words

Example output

This sentence has only unique words

Example input

You should, should you be interested, look for for more information online

Example output

You should, should you be interested, look for more information online
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string sentence;

	cout << "Type a sentence: ";
	getline(cin, sentence);

	// manipulate the sentence here

	cout << sentence << "\n";

	system("pause");
	return 0;
}

/* Actual output (copied from console window)


*/
