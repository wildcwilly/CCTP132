/* 4.5.4 Text manipulation: anagrams
Chris Wild

Anagrams are words that consist of the same letters in a different order.

For example, "sweat" and "waste" are anagrams, while "cat" and "dog" are not.

Write a program that will read two words and decide if they are anagrams.

Your program should assume lower case for all the words read.

Example input

cat dog

Example output

not anagrams

Example input

cellar recall

Example output

anagrams

Example input

antler learnt

Example output

anagrams
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


// count the letters in a word
void letters(int alpha[], string word)
{
	int loop;

	// iterate through each letter of word
	for (loop = 0; loop < word.length(); loop++)
	{
		alpha[word[loop] - 'a']++;	// increment current letter
	}
}

// compare letters in words
bool Anagram(string word1, string word2)
{
	int alpha1[26] = { 0 }, alpha2[26] = { 0 };
	bool isAnagram = true;

	// get count of letters
	letters(alpha1, word1);
	letters(alpha2, word2);	

	// compare if both words have same number of same letters
	for (int loop = 0; loop < 26; loop++)
	{
		if (alpha1[loop] != alpha2[loop])
			isAnagram = false;
	}

	return isAnagram;
}

int main()
{
	string word1, word2;

	cout << "Enter 2 words: ";
	cin >> word1 >> word2;

	// make sure words are in lowercase for check
	transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
	transform(word2.begin(), word2.end(), word2.begin(), ::tolower);

	cout << (Anagram(word1, word2) ? "Anagrams\n" : "Not Anagrams\n");

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Enter 2 words: cat dog
Not Anagrams

Enter 2 words: cellar recall
Anagrams

Enter 2 words: Cellar Recall
Anagrams

Enter 2 words: antler learnt
Anagrams
*/
