/*
	Nguyen, Michael

	CS A250
	April 29, 2019

	Project 1 - Part A
*/

#include "Course.h"

Course::Course():transferable('N') {}

Course::Course(const string& name, int num,
	double unit, vector<int>& cPreCourse, char cTransferable)
		: CourseType(name, num, unit) 
{
	preCourse = cPreCourse;
	transferable = cTransferable;
}

bool Course::isTransferable() const
{
	return (transferable == 'Y') ? true : false;
}

void Course::setTransfer(char trans)
{
	transferable = (trans ? 'Y' : 'N');
}

void Course::setPrerequisites(const int prerequisites[], 
	int numOfElem)
{
	preCourse.insert(preCourse.begin(), prerequisites,
		prerequisites + numOfElem);
}

void Course::printCourse() const
{
		cout << getPrefix() << getCourseNumber() << " - "<< getCourseName()
		<< " (" << fixed << showpoint << setprecision(2)
		<< getCourseUnits() << " units, "
		<< (transferable ? "transferable)" : "not transferable)") << endl;
}

void Course::printPrereqs() const
{
	cout << getPrefix() << getCourseNumber() << " - Prerequisites: ";

	for (int i = 0; i < static_cast<int>(preCourse.size()); ++i)
	{
		cout << getPrefix() << preCourse[i];
		
		if (i < static_cast<int>(preCourse.size()) - 1)
		{
			cout << " and ";
		}	
	}
	cout << endl;
}

Course::~Course(){}