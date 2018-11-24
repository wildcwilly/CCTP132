/* 2.1.2 Some actual evaluations - taxes
Chris Wild

Wherever you are and whatever you pay for, you usually spend your money on two things: the first is for a good or service you are
buying, and the second is taxes. This means that the amount of money you are transferring (named "gross price") to the seller is a sum
of the actual price (named "net price") and the tax. The tax is calculated as a percentage of the net price and its rate depends on a lot of
unpredictable factors (e.g. where you live, what you buy, etc., etc., etc.).
Your task is to write a simple "tax calculator" – it should accept two values: a gross price and a tax rate expressed as a percentage (i.e. a
value greater than 0 and, let's be optimistic, less than 100).
Look at the code below – it only reads two input values and outputs the results, so you need to complete it with a few smart
calculations.
It would be good to verify if the values entered are reasonable (e.g. gross price is greater than zero and tax rate falls into the previously
mentioned range).
Test your code using the data we've provided.

#include <iostream>

using namespace std;

int main(void) {
	float grossprice, taxrate, netprice, taxvalue;

	cout << "Enter a gross price: ";
	cin >> grossprice;
	cout << "Enter a tax rate: ";
	cin >> taxrate;

	// Insert you code here

	cout << "Net price: " << netprice << endl;
	cout << "Tax value: " << taxvalue << endl;
	return 0;
}

Example input

123
23

Example output

Net price: 100
Tax value: 23

Example input

123
50

Example output

Net price: 82
Tax value: 41

Example input

123
98

Example output

Net price: 62.1212
Tax value: 60.8788

Example input

11
10

Example output

Net price: 10
Tax value: 1
*/

#include <iostream>

using namespace std;

int main(void) {
	float grossprice, taxrate, netprice, taxvalue;

	cout << "Enter a gross price: ";
	cin >> grossprice;
	cout << "Enter a tax rate: ";
	cin >> taxrate;

	// verify values entered
	if (grossprice < 0)	// invalid - price must be above 0
	{
		cout << "Gross price must be >= 0." << endl;
		return 1;
	}

	if (taxrate < 0 || taxrate > 100)	// invalid
	{
		cout << "Tax rate must be 0 - 100." << endl;
		return 1;
	}

	// Formula for calculating tax from gross and tax %
	// Tax = Gross - (Gross / 1+Vat)
	taxvalue = grossprice - (grossprice / (taxrate / 100 + 1));
	netprice = grossprice - taxvalue;

	cout << "Net price: " << netprice << endl;
	cout << "Tax value: " << taxvalue << endl;

	return 0;
}

/* Actual output (copied from console window)

Enter a gross price: 123
Enter a tax rate: 23
Net price: 100
Tax value: 23

Enter a gross price: 123
Enter a tax rate: 50
Net price: 82
Tax value: 41

Enter a gross price: 123
Enter a tax rate: 98
Net price: 62.1212
Tax value: 60.8788

Enter a gross price: 11
Enter a tax rate: 10
Net price: 10
Tax value: 1
*/