/* 4.5.7 Text manipulation: password validation
Chris Wild

Many services require authentication from their users. In order to ensure some level of security, a service may set some requirements
for the password structure.

Write a program that will read a line of text as a password and validate it according to the rules below.

The password must:

	* be eight characters long;
	* have at least one upper-case letter;
	* have at least one lower-case letter;
	* have at least one digit;
	* have at least one special character.

If any of these rules is broken, your program should inform the user why the password is not valid.

#include <string>
#include <iostream>

int main()
{
	std::string password;
	std::getline(std::cin, password);

	// manipulate the password here
	// and print validation result

	return 0;
}

Example input

Pas5w[]rd

Example output

The password is valid

Example input

qwerty

Example output

The password must be 8 characters long
The password must have at least one upper case letter
The password must have at least one digit
The password must have at least one special character
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool length = false, upper = false, lower = false, digit = false, special = false;
	int loop;
	string password;

	cout << "Password: ";
	getline(cin, password);

	// check length (8+ characters)
	if (password.length() >= 8)
		length = true;

	// iterate through password to check each character
	for (loop = 0; loop < password.length(); loop++)
	{
		// check for uppercase letter
		if (isupper(password[loop]))
			upper = true;
		else if (islower(password[loop]))	// check for lowercase letter
			lower = true;
		else if (isdigit(password[loop]))	// check for digit
			digit = true;
		else if (ispunct(password[loop]))	// check for special character
			special = true;
	}

	if (length && upper && lower && digit && special)
	{
		cout << "The password is valid.\n";
	}
	else
	{
		// display any errors
		if(!length)
			cout << "The password must be at least 8 characters long.\n";
		if(!upper)
			cout << "The password must have at least one uppercase letter.\n";
		if(!lower)
			cout << "The password must have at least one lowercase letter.\n";
		if(!digit)
			cout << "The password must have at least one digit.\n";
		if(!special)
			cout << "The password must have at least 1 special character.\n";
	}

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

Password: Pas5w[]rd
The password is valid.

Password: qwerty
The password must be at least 8 characters long.
The password must have at least one uppercase letter.
The password must have at least one digit.
The password must have at least 1 special character.

Password: QWERTY
The password must be at least 8 characters long.
The password must have at least one lowercase letter.
The password must have at least one digit.
The password must have at least 1 special character.

Password: P^s5word
The password is valid.

Password: P^s5wrd
The password must be at least 8 characters long.
*/
