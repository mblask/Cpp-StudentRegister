#include "Student.h"

//inicijalizacija inicijala studenta
void Student::initializeStudent() {
	char alfabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	for (int i = 0; i < 2; i++)
	{
		int randIndex = rand() % std::size(alfabet);
		nameSurname.push_back(alfabet[randIndex]);
		nameSurname.push_back('.');
	}
}

//inicijalizacija mogucih predmeta
void Student::initializeClasses() {
	classes[0].className = "English";
	classes[1].className = "Mathematics";
	classes[2].className = "Physics";
	classes[3].className = "Chemistry";
};

//zakljucivanje ocjene studentu, zbroj prosjeka kroz broj predmeta
float Student::finalizeGrade() {

	float average = 0.0f;
	int numberOfClasses = std::size(classes);
	for (int i = 0; i < numberOfClasses; i++)
	{
		average += classes[i].gradeAverage();
	}

	return average / numberOfClasses;
}

//provjera dal bar jedna ocjena postoji u svakom predmetu, prosjek predmeta mora biti != 0
bool Student::gradesEntered() {

	int numberOfClasses = std::size(classes);
	for (int i = 0; i < numberOfClasses; i++)
	{
		if (classes[i].gradeAverage() == 0)
			return false;
	}

	return true;
}