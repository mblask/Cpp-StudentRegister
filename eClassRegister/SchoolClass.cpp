#include "SchoolClass.h"

//racuna se prosjek ocjena predmeta, pozbrajaju se sve ocjene i broje se sve ne-nula ocjene
float SchoolClass::gradeAverage() {
	int average = 0;
	int numberOfGrades = 0;

	int arrayLength = std::size(grades);
	for (int i = 0; i < arrayLength; i++)
	{
		if (grades[i] == 0)
			continue;

		numberOfGrades++;
		average += grades[i];
	}

	if (numberOfGrades == 0)
		return 0.0f;

	return (float)average / numberOfGrades;
}

//dodavanje ocjene na prvo slobodno mjesto - slobodno mjesto je 0
void SchoolClass::addGrade(int grade) {
	int numberOfGrades = std::size(grades);
	for (int i = 0; i < numberOfGrades; i++)
	{
		if (grades[i] != 0)
			continue;

		grades[i] = grade;
		break;
	}

	return;
}