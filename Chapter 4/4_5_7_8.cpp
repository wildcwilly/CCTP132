/* 4.5.8 Text manipulation: templates
Chris Wild

When running a newsletter or preparing announcements targeted at a group of people, one might need to prepare many very similar messages, differing only in minor
details.

Write a program that reads two lines of text.

The first line should contain a list of name value pairs separated by commas. Each pair should be in the following form: "name=value".

The second line should contain a template that should be filled with the values from the first line. A placeholder should have the form "[name]" and should be replaced
by an appropriate value.

If your program encounters a placeholder with an unknown name, the placeholder should be left unprocessed in the output text.

#include <string>
#include <iostream>

int main()
{
	std::string values;
	std::getline(std::cin, values);

	std::string template;
	std::getline(std::cin, template);

	// Put values into the template

	std::cout << template << "\n";
}}

Example input

person=Paul,action=strolls around,place=the park
[person] [action] [place]

Example output

Paul strolls around the park

Example input

customer=John,pet=dog
Dear [customer], we were happy to take care of your [pet] while you were away. Please call our pet hotel again if you need help with your [pet]!

Example output

Dear John, we were happy to take care of your dog while you were away. Please call our pet hotel again if you need help with your dog!

Example input

date=02/02/02 3:00PM,room=504
Dear [customer], your exam will take place on [date] in room [room]

Example output

Dear [customer], your exam will take place on 02/02/02 3:00PM in room 504
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int start = 0, end, found;
	string keyValue, key, value;

	string values;
	cout << "Name=Value pairs: ";
	getline(cin, values);

	string sentence;
	cout << "Template: ";
	getline(cin, sentence);

	do
	{
		// get key/value pairs from values string (seperated by ',')
		end = values.find(',', start);

		keyValue = values.substr(start, end - start);

		// break up key and value pair (seperated by '=')
		found = keyValue.find('=');

		key = keyValue.substr(0, found);
		value = keyValue.substr(found + 1);

		// define actual template key
		key.insert(0, 1, '[');
		key.push_back(']');

		// find all instances of key in sentence
		do
		{
			found = sentence.find(key);

			if (found != string::npos)	// string found
			{
				sentence.replace(found, key.length(), value);
			}
		} while (found != string::npos);

		start = end + 1;
	} while (end != string::npos);

	std::cout << sentence << "\n";

	system("pause");
	return 0;
}

/* Actual output (copied from console window)
Name=Value pairs: person=Paul,action=strolls around,place=the park
Template: [person] [action] [place]
Paul strolls around the park

Name=Value pairs: customer=John,pet=dog
Template: Dear [customer], we were happy to take care of your [pet] while you we
re away. Please call our pet hotel again if you need help with your [pet]!
Dear John, we were happy to take care of your dog while you were away. Please ca
ll our pet hotel again if you need help with your dog!

Name=Value pairs: date=02/02/02 3:00PM,room=504
Template: Dear [customer], your exam will take place on [date] in room [room]
Dear [customer], your exam will take place on 02/02/02 3:00PM in room 504
*/
