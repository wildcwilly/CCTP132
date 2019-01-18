/* 4.5.5 Text manipulation: pattern matching
Chris Wild

When searching through big amounts of text data, it's useful to be able to search for data in a specific format rather than to search for
specific values.

For example, when looking for a PIN number for a key lock, it would be useful to be able to search for four digits in a row, and not to
have to go over every possible combination.

Let's define a pattern-matching system for such situations. Here are the rules for our system:

	* a pattern will consist of non-whitespace characters;
	* the letter 'D' will match any decimal digit, so the pattern "DDDD" will match for strings "1234", "2309" etc.;
	* the letter 'A' will match any character of the English alphabet (upper and lower-case), so the pattern "AAA" will match for strings
	  "CAT", "dog", "ToC" etc.;
	* lower-case letters in a pattern will match according to the letters of the English alphabet, so the pattern "cat" will match for
	  strings "Cat", "cat" "CAT", etc.;
	* the character "?" will match every character, including whitespace, so the pattern "a?b" will match for strings "A+B", "a0b",
	  "Acb", "a B", etc.;
	* any punctuation except "?" will match exactly the same punctuation in a string, so the pattern "AA-DDD" will match for strings
	  "NE-785", "am-236", etc.;

Write a program that will read two lines of text. The first line will be a pattern to be matched against the string in the second line. Your
program should print all matches found in the string provided.

#include <string>
#include <iostream>

int main()
{
	std::string pattern;
	std::getline(std::cin, pattern);

	std::string sentence;
	std::getline(std::cin, sentence);
	// match pattern against sentence

	std::cout << sentence << "\n";
}}

Example input

DDDD
The combination for the safe is 2380, but please keep it a secret!

Example output

2380

Example input

AAAAAA
Mary has a little lamb with white fleece

Example output
little
fleece

Example input

DD-DDD
My zip code is 02-154, make sure you don't forget it

Example output
02-154

Example input

??
a lot!

Example output
a
 l
lo
ot
t!
*/

#include <iostream>
#include <string>

using namespace std;

void patternSearch(string pattern, string sentence);
bool isMatch(string pattern, string partString);

int main()
{
	string pattern;
	cout << "Enter pattern to match: ";
	getline(cin, pattern);

	string sentence;
	cout << "Enter sentence: ";
	getline(cin, sentence);

	// match pattern against sentence
	patternSearch(pattern, sentence);

//	cout << sentence << "\n";

	system("pause");
	return 0;
}

void patternSearch(string pattern, string sentence)
{
	unsigned int loop;

	// itterate through sentence to find match
	for (loop = 0; loop <= (sentence.length() - pattern.length()); loop++)
	{
		if (isMatch(pattern, sentence.substr(loop, pattern.length())))
			cout << sentence.substr(loop, pattern.length()) << endl;
	}
}

bool isMatch(string pattern, string partString)
{
	unsigned int character;
	bool match = true;

	// itterate through each pattern character
	for (character = 0; character < pattern.length(); character++)
	{
		switch (pattern[character])
		{
		case ('D'):	// check for digit
			if (!isdigit(partString[character]))
				match = false;
			break;

		case ('A'):	// check for alphabetic character
			if (!isalpha(partString[character]))
				match = false;
			break;

		case ('?'):	// check for wild character
			// This will always match and removes '?" from punctuation check
			break;

		default:
			// if pattern character is lowercase or punctuation, match exact (case insensitive for characters)
			if (islower(pattern[character]) || ispunct(pattern[character]))
			{
				if (tolower(partString[character]) != pattern[character])
					match = false;
			}
			break;
		}
	}

	return match;
}

/* Actual output (copied from console window)

Enter pattern to match: DDDD
Enter sentence: The combination for the safe is 2380, but please keep it a secret!
2380

Enter pattern to match: AAAAAA
Enter sentence: Mary has a little lamb with white fleece
little
fleece

Enter pattern to match: DD-DDD
Enter sentence: My zip code is 02-154, make sure you don't forget it
02-154

Enter pattern to match: ??
Enter sentence: a lot!!
a
 l
lo
ot
t!
!!

Enter pattern to match: a?c
Enter sentence: abcdefg
abc

Enter pattern to match: a?c
Enter sentence: ABCDEFG
ABC

Enter pattern to match: ch???
Enter sentence: There are 5 characters in the name Chris and the word child
chara
Chris
child
*/
