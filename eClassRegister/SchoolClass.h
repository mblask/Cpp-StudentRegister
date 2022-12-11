#pragma once

#include <iostream>
#include <string>

struct SchoolClass
{
	std::string className;
	int grades[20] = { 0 };

	float gradeAverage();
	void addGrade(int grade);
};