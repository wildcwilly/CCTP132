/* 4.4.1 String manipulation: pangrams
Chris Wild

A pangram is a sentence that uses every letter of the alphabet at least once. The most popular English pangram is "The quick brown fox
jumps over the lazy dog." It contains 35 letters and each letter is used at least once. Write code to check whether a given string is a
pangram or not. Try to write the shortest code possible. You can use the string class and arrays. Remember not to count spaces and
other special characters. At the end of this program you should print how many times each letter has been used.

Example input

The quick brown fox jumps over the lazy dog

Example output

Pangram
a-1
b-1
c-1
d-1
e-3
f-1
g-1
h-2
i-1
j-1
k-1
l-1
m-1
n-1
o-4
p-1
q-1
r-2
s-1
t-2
u-2
w-1
v-1
x-1
y-1
z-1

Example input

quick brown fox jumps over lazy dog

Example output

Not pangram
a-1
b-1
c-1
d-1
e-1
f-1
g-1
h-0
i-1
j-1
k-1
l-1
m-1
n-1
o-4
p-1
q-1
r-2
s-1
t-0
u-2
w-1
v-1
x-1
y-1
z-1
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string sentence;
	char letter;
	int position, alpha[26] = { 0 };
	bool isPangram = true;

	cout << "Enter a sentence: ";
	getline(cin, sentence);

	// make sure sentence is in lowercase for check
	transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);	// algorithm found on Stack Overflow

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		position = 0;	// set to beginning of sentence
		do
		{
			position = sentence.find(letter, position);

			if (position != string::npos)
			{
				alpha[letter - 'a']++;	// add to count of letter in array
				position++;	// continue search from next character
			}
		} while (position != string::npos);
	}

	// check if sentence is pangram
	for (letter = 'a'; letter <= 'z'; letter++)
	{
		if (alpha[letter - 'a'] == 0)
			isPangram = false;
	}

	// display results
	cout << (isPangram ? "Pangram" : "Not Pangram") << endl;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		cout << letter << " - " << alpha[letter - 'a'] << endl;
	}

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Enter a sentence: The quick brown fox jumps over the lazy dog
Pangram
a - 1
b - 1
c - 1
d - 1
e - 3
f - 1
g - 1
h - 2
i - 1
j - 1
k - 1
l - 1
m - 1
n - 1
o - 4
p - 1
q - 1
r - 2
s - 1
t - 2
u - 2
v - 1
w - 1
x - 1
y - 1
z - 1

Enter a sentence: quick brown fox jumps over lazy dog
Not Pangram
a - 1
b - 1
c - 1
d - 1
e - 1
f - 1
g - 1
h - 0
i - 1
j - 1
k - 1
l - 1
m - 1
n - 1
o - 4
p - 1
q - 1
r - 2
s - 1
t - 0
u - 2
v - 1
w - 1
x - 1
y - 1
z - 1
*/
