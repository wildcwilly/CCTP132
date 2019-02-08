/* 5.1.1 Classes and Objects in C++
Chris Wild

Before we start doing anything useful with classes, objects and the like, we should familiarize ourselves a little with these concepts.

So for now, let's represent a person in terms of classes!

Run the code below and then experiment with it. Add some more members to the class and try accessing them.

#include <iostream>
#include <string>

using namespace std;

class Person
{
	public:
	string name;
	int age;
	// Your code here
};

void print(Person* person)
{
	cout << person->name << " is " person->age << " years old" << endl;
}

int main()
{
	Person person;
	person.name = "Harry";
	person.age = 23;

	cout << "Meet " << person.name();
	print(&person);

	// Your code here

	return 0;
}
*/

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	string name;
	int age;
	string city;
	string province;
	string country;
};

void print(Person* person)
{
	cout << person->name << " is " << person->age << " years old" << endl;
	cout << person->name << " lives in " << person->city << ", " << person->province << " " << person->country << endl;
}

int main()
{
	Person person;
	person.name = "Harry";
	person.age = 23;
	person.city = "Edmonton";
	person.province = "AB";
	person.country = "Canada";

	cout << "Meet " << person.name << endl;
	print(&person);

	system("pause");
	return 0;
}

/* Actual output (copied from console window)
Meet Harry
Harry is 23 years old
Harry lives in Edmonton, AB Canada

*/
