/* 4.1.1 Multi-dimensional arrays of variable length
Chris Wild

Write a program that will calculate the average grade of a student and print a summary report.

The following rules apply:

	* a student may sign up for any number of courses;
	* during a course, the student may receive any number of grades;
	* grades are integer numbers in the range [1..5];
	* the final grade for a course is the arithmetic mean of all grades received during the course;
	* the overall final grade is the arithmetic mean of the final grades received for all the courses the student has taken.

	All floating-point numbers printed by the program should be limited to two decimal points. The input is given in the following form:
C
N1 G11 G12 .. G1n
N2 G21 G22 .. G2n
.
.
Nc Gc1 Gc2 .. Gcn
Where:
C – number of courses taken by the student
Nx – number of grades received during course number x
Gab – b-th grade received in course number a

Example input

34
2 3 4 5
2 4 5
3 4 4 5

Example output

Course 1: final 3.50, grades: 2 3 4 5
Course 2: final 4.50, grades: 4 5
Course 3: final 4.33, grades: 4 3 5
Overall final 4.11
*/

#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	int **courses, courseNum, numGrades, grade, course;
	float courseAvg, finalGrade = 0;

	// input number of courses as integer
	cout << "How many courses for student? ";
	cin >> courseNum;

	courses = new int*[courseNum];	// allocate pointer for each course

	for (course = 0; course < courseNum; course++)
	{
		// input grades as integers
		cout << "How many grades to enter for course " << course + 1 << "? ";
		cin >> numGrades;

		courses[course] = new int[numGrades + 1];	// +1 for storing number of grades (sizeof array)
		courses[course][0] = numGrades;	// store the number of grades in array element [0]

		// input and verify grades for course
		for (grade = 1; grade <= numGrades; grade++)
		{
			do
			{
				cout << "Grade #" << grade << " (1 - 5): ";
				cin >> courses[course][grade];

				if (courses[course][grade] < 1 || courses[course][grade] > 5)
				{
					cout << "Invalid grade. ";
				}

			} while (courses[course][grade] < 1 || courses[course][grade] > 5);
		}
	}

	cout << fixed << setprecision(2);	// set precision for floating point numbers (2 decimals)

	// display course results
	for (course = 0; course < courseNum; course++)
	{
		cout << "Course " << course << ": final ";

		// calculate course average
		courseAvg = 0;	// reset

		for (grade = 1; grade <= courses[course][0]; grade++)
		{
			courseAvg += float(courses[course][grade]);	// add all grades togther
		}

		courseAvg /= courses[course][0];	// divide by number of grades for course

		cout << courseAvg << ", grades: ";

		finalGrade += courseAvg;	// add all course averages for final grade average

		// display grades for course
		for (grade = 1; grade <= courses[course][0]; grade++)
		{
			cout << courses[course][grade] << " ";
		}
		cout << endl;

		delete[] courses[course];	// free memory for course
	}

	finalGrade /= courseNum;	// calculate final grade average

	cout << "Overall final " << finalGrade << endl;

	delete[] courses;	// free last of allocated memory

	system("pause");
	return 0;
}

/* Actual output (copied from console window)

How many courses for student? 3
How many grades to enter for course 1? 4
Grade #1 (1 - 5): 2
Grade #2 (1 - 5): 3
Grade #3 (1 - 5): 6
Invalid grade. Grade #3 (1 - 5): 4
Grade #4 (1 - 5): 5
How many grades to enter for course 2? 2
Grade #1 (1 - 5): 4
Grade #2 (1 - 5): 0
Invalid grade. Grade #2 (1 - 5): 5
How many grades to enter for course 3? 3
Grade #1 (1 - 5): 4
Grade #2 (1 - 5): 4
Grade #3 (1 - 5): 5
Course 0: final 3.50, grades: 2 3 4 5
Course 1: final 4.50, grades: 4 5
Course 2: final 4.33, grades: 4 4 5
Overall final 4.11
*/
