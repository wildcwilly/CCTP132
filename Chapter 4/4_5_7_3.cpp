/* 4.5.3 Text manipulation: stop word elimination
Chris Wild

A common practice in search engines is to remove very common words – that add little value – from a document before further
processing.

These words are known as "stop words" and include words like "a", "the", "or", etc.

Write a program that will read two lines of text. The first line will consist of comma-separated stop words and the second line is text to
be processed. Your program should remove all stop words from the text to be processed.

Your program should assume lower case for stop words and ignore the case in the processed words.

#include <string>
#include <iostream>

int main()
{
	std::string stop_words;
	std::getline(std::cin, sentence);

	std::string sentence;
	std::getline(std::cin, sentence);
	// remove stop_words from sentence here

	std::cout << sentence << "\n";
}}

Example input

has,no,this
This sentence has no stop words

Example output

sentence stop words

Example input

a,has
Mary has a little lamb

Example output

Mary little lamb
*/

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int currentStart = 0, currentEnd, searchStart, searchEnd;

	string stop_words;
	cout << "Enter the stop words (seperated by commas): ";
	getline(cin, stop_words);

	string sentence;
	cout << "Enter sentence to process: ";
	getline(cin, sentence);

	// make sure sentence is in lowercase for check
	transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);	// algorithm found on Stack Overflow

	// iterate through each word to search for duplicates in sentence
	do
	{
		// stop word is from currentStart to currentEnd in stop_words phrase
		currentEnd = stop_words.find(",", currentStart);

		// iterate through sentence to compare with stop word
		searchStart = 0;	// start search for stop word from beginning of sentence

		do
		{
			searchEnd = sentence.find(" ", searchStart);

			// check if just a duplicate space
			if (searchStart == searchEnd)
			{
				sentence.erase(searchStart, 1);	// remove duplicate space (from removing word between 2 spaces)
			}

			// compare both words
			if (sentence.substr(searchStart, searchEnd - searchStart).compare(stop_words.substr(currentStart, currentEnd - currentStart)))
			{
				// not equal
				searchStart = searchEnd + 1; // move search word to next word
			}
			else
			{
				// both words are equal, delete stop word, including trailing space (+1)
				sentence.erase(searchStart, searchEnd - searchStart + 1);
			}
		} while (searchEnd != string::npos);

		currentStart = currentEnd + 1;	// move start to next word;
	} while (currentEnd != string::npos);


	cout << sentence << "\n";

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Enter the stop words (seperated by commas): has,no,this
Enter sentence to process: This sentence has no stop words
sentence stop words

Enter the stop words (seperated by commas): a,has
Enter sentence to process: Mary has a little lamb
mary little lamb
*/
