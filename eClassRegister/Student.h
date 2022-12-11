#pragma once
#include "SchoolClass.h"

struct Student
{
	std::string nameSurname = "";
	SchoolClass classes[4];

	void initializeStudent();
	void initializeClasses();
	bool gradesEntered();
	float finalizeGrade();
};