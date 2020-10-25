/*
	Nguyen, Michael

	CS A250
	May 1, 2019

	Project 1 - Part B
*/

#include "CourseList.h"

// Default constructor
CourseList::CourseList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

// Definition function addCourse
void CourseList::addCourse(const string& name, int number,
	double units, vector<int>& prere, char transferable)
{
	Course course(name, number, units, prere, transferable);
	Node *newCourse = new Node;
	newCourse->setCourse(course);
	Node *current = first;

	if (current == nullptr)
		first = newCourse;
	else 
	{
		while (current->getNext() != nullptr)
		{
			current = current->getNext();
		}

		current->setNext(newCourse);
	}

	last = newCourse;
	count++;
}

// Definition function isEmpty
bool CourseList::isEmpty() const
{
	return (count == 0? true : false);
}

bool CourseList::searchCourse(int num) const
{
	Node *current = first;

	while (current != nullptr)
	{
		if (current->getCourse().getCourseNumber() == num)
			return true;

		current = current->getNext();
	}

	return false;
}

void CourseList::printAllCourses() const
{
	Node *current = first;

	while (current != nullptr)
	{
		cout << (current->getCourse()).getPrefix()
			<< (current->getCourse()).getCourseNumber()
			<< " - " << (current->getCourse()).getCourseName() << endl;
		current = current->getNext();
	}
}

void CourseList::printTransferCourses() const
{
	Node *current = first;

	while (current != nullptr)
	{
		if ((current->getCourse()).isTransferable())
			cout << (current->getCourse()).getPrefix()
			<< (current->getCourse()).getCourseNumber()
			<< " - " << (current->getCourse()).getCourseName() << endl;

		current = current->getNext();
	}
}

void CourseList::printVocationalCourses() const
{
	Node* current = first;

	while (current != nullptr)
	{
		if (!((current->getCourse()).isTransferable()))
			cout << (current->getCourse()).getPrefix()
			<< (current->getCourse()).getCourseNumber()
			<< " - " << (current->getCourse()).getCourseName() << endl;

		current = current->getNext();
	}
}

void CourseList::printCourseByNumber(int num) const
{
	getCourseLocation(num)->getCourse().printCourse();
}

void CourseList::printPrereqs(int num) const
{
	getCourseLocation(num)->getCourse().printPrereqs();
}

void CourseList::clearList()
{
	Node* current = first;

	while (current != nullptr)
	{
		if (current->getNext() != nullptr)
		{
			first = current->getNext();
			delete current;
			current = first;
		}
		else
		{
			delete current;
			current = nullptr;
		}
	}

	count = 0;
}

CourseList::~CourseList()
{
	clearList();
}


// Definition function getCourseLocation
Node* CourseList::getCourseLocation(int num) const
{
	Node *current = first;

	while (current != nullptr)
	{
		if (current->getCourse().getCourseNumber() == num)
			return current;

		current = current->getNext();
	}
}