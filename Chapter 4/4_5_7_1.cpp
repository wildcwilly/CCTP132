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
	int currentStart = 0, currentEnd, searchStart, searchEnd;

	cout << "Type a sentence: ";
	getline(cin, sentence);

	// iterate through each word to search for duplicates in sentence
	do
	{
		// current word is from currentStart to currentEnd in sentence
		currentEnd = sentence.find(" ", currentStart);

		searchStart = currentEnd + 1;	// start search for duplicates after current word

		if (currentEnd != string::npos)	// no need to search the last word
		{
			// iterate through remaining words to compare with current word
			do
			{
				searchEnd = sentence.find(" ", searchStart);

				// check if just a duplicate space
				if (searchStart == searchEnd)
				{
					sentence.erase(searchStart, 1);
				}

				// compare both words
				if (sentence.substr(currentStart, currentEnd - currentStart).compare(sentence.substr(searchStart, searchEnd - searchStart)))
				{
					// not equal
					searchStart = searchEnd + 1; // move search word to next word
				}
				else
				{
					// both words are equal, delete search word
					sentence.erase(searchStart, (searchEnd)-searchStart);
				}
			} while (searchEnd != string::npos);
		}

		currentStart = currentEnd + 1;	// move start to next word;
	} while (currentEnd != string::npos);

	cout << sentence << "\n";

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Type a sentence: This sentence has no duplicate words
This sentence has no duplicate words

Type a sentence: This sentence has has only unique words
This sentence has only unique words

Type a sentence: You should, should you be interested, look for for more informa
tion online
You should, should you be interested, look for more information online

Type a sentence: The old old brown cow cow!
The old brown cow cow!

Type a sentence: The old, old brown cow cow
The old, old brown cow

Type a sentence: The old brown cow!
The old brown cow!
*/
