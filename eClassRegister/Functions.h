#pragma once

#include <iostream>
#include "Student.h"

void printStudentMenu(const Student student);
void gradeEntryMenu(Student& student, int chosen);
void eStudent(Student& student);
void printMainMenu(const Student students[], int arrayLength);
void eStudentRegister();
