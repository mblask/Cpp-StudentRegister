#include "Functions.h"

//ispis studentovog izbornika
void printStudentMenu(const Student student) {
	std::cout << "Student: " << student.nameSurname << std::endl;
	std::cout << std::endl;
	std::cout << "Choose an operation: " << std::endl;
	std::cout << "0 Go back to the eRegister" << std::endl;

	int duljinaNizaPredmeta = std::size(student.classes);
	for (int i = 0; i < duljinaNizaPredmeta; i++)
	{
		std::cout << (i + 1) << " Enter a grade into - " << student.classes[i].className << std::endl;
	}

	std::cout << (duljinaNizaPredmeta + 1) << " Finalize grade" << std::endl;
}

//unos ocjene po predmetu, tj student.predmet[izabrano], student je referenca, jer structovi sami po sebi nisu referentni tipovi
//pa kad unio studenta direktno, unio bi samo kopiju
void gradeEntryMenu(Student& student, int chosen) {

	int grade = 0;
	bool gradeCorrect = false;

	do
	{
		std::cout << "Enter 0 to go back to the main menu!" << std::endl;
		std::cout << chosen << " Enter a grade into - " << student.classes[chosen - 1].className << ": ";
		std::cin >> grade;

		if (grade == 0) {
			std::cout << std::endl;
			return;
		}

		if (grade < 0 || grade > 5) {
			std::cout << "Grade entered incorrectly! Enter it again!" << std::endl;
			continue;
		}

		student.classes[chosen - 1].addGrade(grade);
		gradeCorrect = true;

	} while (gradeCorrect || grade != 0);
}

//glavna funkcija eStudenta, uzima referencu na studenta, jer bi inace stvorio kopiju i zapravo se nis ne bi dogodilo sa originalnim studentom
void eStudent(Student& student) {

	bool gradeFinalized = student.finalizeGrade() != 0.0f;

	if (gradeFinalized)
	{
		std::cout << "Student " << student.nameSurname << " has its grade finalized!" << std::endl;
		std::cout << std::endl;
		return;
	}

	int chosen = 0;
	do
	{
		printStudentMenu(student);

		std::cout << std::endl;
		std::cout << "Your choice: ";
		std::cin >> chosen;
		std::cout << std::endl;

		if (chosen == 0)
			break;

		if (chosen == std::size(student.classes) + 1)
		{
			if (!student.gradesEntered()) {
				std::cout << "Not all grades are entered!" << std::endl;
				std::cout << std::endl;
				continue;
			}

			std::cout << "Student " << student.nameSurname << ", final grade: " << student.finalizeGrade() << std::endl;
			gradeFinalized = true;
			std::cout << std::endl;
			break;
		}

		gradeEntryMenu(student, chosen);

	} while (!gradeFinalized);
}

//glavni izbornik eDnevnika
void printMainMenu(const Student students[], int arrayLength) {
	std::cout << "Choose a student by entering the number in front of the name:" << std::endl;

	for (int i = 0; i < arrayLength; i++)
	{
		if (i == 0) {
			std::cout << i << " Exit eRegister" << std::endl;
			continue;
		}

		std::cout << i << " Student " << students[i].nameSurname << std::endl;
	}
}

//glavna funkcija ednevnika
void eStudentRegister() {

	//nasumicna generacija studenta
	srand(time(NULL));
	Student students[10];
	for (int i = 0; i < std::size(students); i++)
	{
		students[i].initializeStudent();
		students[i].initializeClasses();
	}

	//pocetak glavnog programa
	std::cout << "eRegister" << std::endl;

	int mainMenuChoice = 0;
	bool closeRegister = false;
	do
	{
		printMainMenu(students, std::size(students));

		std::cout << std::endl;
		std::cout << "Your choice: ";
		std::cin >> mainMenuChoice;
		std::cout << std::endl;

		if (mainMenuChoice == 0) {
			closeRegister = true;
			break;
		}

		eStudent(students[mainMenuChoice]);

	} while (!closeRegister);

	std::cout << "eRegister closed" << std::endl;
}