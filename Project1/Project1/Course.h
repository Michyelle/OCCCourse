/*
	Nguyen, Michael

	CS A250
	April 29, 2019

	Project 1 - Part A
*/

#ifndef COURSE_H
#define COURSE_H

#include "CourseType.h"
#include <vector>
using namespace std;

class Course : public CourseType
{
public:
	Course();
	Course(const string&, int, double, vector<int>&, char);

	bool isTransferable() const;

	void setTransfer(char);
	void setPrerequisites(const int[], int);

	void printCourse() const;
	void printPrereqs() const;

	~Course();
private:
	vector<int> preCourse;
	char transferable;
};
#endif