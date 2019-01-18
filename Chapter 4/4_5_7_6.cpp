/* 4.5.6 Text manipulation: plain-text formatting
Chris Wild

When dealing with plain-text mediums, the formatting options are fairly limited compared to modern WYSIWYG rich-text editors.

A common practice is to emphasize words or text fragments using the asterisk character ("*") or the underline character ("_").

Write a program that will change this style of formatting according to the following rules:
	* all alphabet characters surrounded by asterisks will be made upper-case, and the asterisks will be removed, i.e. "this is *it*" will
	  be changed to "this is IT";
	* all characters surrounded by underscores will be separated by additional spaces, and the underscores will be changed to spaces,
	  i.e. "is _this_ it?" will be changed to "is t h i s it?";
	* an underscore or asterisk will be ignored if no matching character has been found until the end of the string;
	* an underscore will be ignored if an asterisk has been encountered before a matching underscore;
	* an asterisk will be ignored if an underscore has been encountered before a matching asterisk.

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

What do you *mean*?

Example output

What do you MEAN?

Example input

This is _really_ important!

Example output

This is r e a l l y important!

Example input

*This* one _might *be _quite tricky_*, if you know what I mean.

Example output
THIS one might be q u i t e t r i c k y , if you know what I mean.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	unsigned int character, loop, start = 0, end = 0;
	bool asterisk = false, underscore = false;
	string sentence;

	cout << "Sentence: ";
	getline(cin, sentence);

	// itterate through sentence one character at a time
	for (character = 0; character < sentence.length(); character++)
	{
		if (sentence[character] == '*')
		{
			// remove asterisk
			sentence.erase(character, 1);

			// check if first asterisk encountered and no underscore check set
			if (asterisk == false && underscore == false)
			{
				asterisk = true;
				start = character;
			}
			else if (asterisk == true)	// just found the second asterisk
			{
				end = character;

				// change characters from start to end to uppercase
				for (loop = start; loop < end; loop++)
				{
					sentence[loop] = toupper(sentence[loop]);
				}

				// reset search flag
				asterisk = false;
			}
			else if (underscore == true)	// underscore was found first, reset both
			{
				underscore = false;
				asterisk = false;
			}
		}

		if (sentence[character] == '_')
		{
			// remove asterisk
			sentence.erase(character, 1);

			// check if first asterisk encountered and no underscore check set
			if (asterisk == false && underscore == false)
			{
				underscore = true;
				start = character;
			}
			else if (underscore == true)	// just found the second asterisk
			{
				end = character;

				// add space between each character inside of underscores
				for (loop = end; loop >= start; loop--)	// adding spaces makes sentence longer so itterating backwards requires no adjustments
				{
					sentence.insert(loop, 1, ' ');
				}

				// reset search flag
				underscore = false;
			}
			else if (asterisk == true)	// underscore was found first, reset both
			{
				underscore = false;
				asterisk = false;
			}
		}
	}

	cout << sentence << "\n";

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Sentence: What do you *mean*?
What do you MEAN?

Sentence: This is _really_ important!
This is  r e a l l y  important!

Sentence: *This* one _might *be _quite tricky_*, if you know what I mean
THIS one might be  q u i t e   t r i c k y , if you know what I mean
*/
