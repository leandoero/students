#include "stud.h"
#include <iostream>
#include <string>

Exams::Exams() {};
Exams::Exams(std::string Name, int Grade)
{
	name = Name;
	grade = Grade;
}

Tests::Tests() {};
Tests::Tests(std::string Name, bool Result)
{
	name = Name;
	grade = Result;
}

Student::Student() {};
Student::Student(int ID, int SEMESTR, int GROUP, std::string NAME, std::string SURNAME, std::string FULLNAME, Exams EXAM_GRADES[4][8], Tests TEST_GRADES[6][8])
{
	ot4isleni = false;
	id = ID;
	semestr = SEMESTR;
	group = GROUP;
	name = NAME;
	surname = SURNAME;
	fullname = FULLNAME;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			examGrades[i][j] = EXAM_GRADES[i][j];
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			testGrades[i][j] = TEST_GRADES[i][j];
		}
	}
}

const std::string examNames[] = { "Computer Science Fundamentals","Python programming","Operating Systems","Algorithms and data structures",
"Database Fundamentals", "Web-programming", "Discrete Mathematics", "Computer Architecture",
"Object-oriented programming", "Network technologies", "Mobile development", "Information systems security",
"Database design", "Artificial Intelligence Methods", "Internet of Things", "Software Testing",
"Distributed systems", "Computer graphics", "Big Data", "Electronic commerce",
"System software", "Game Development", "Cloud technologies", "Information security",
"Professional practice", "Internet marketing", "Project Management in IT", "Ethics in Information Technology",
"Information protection", "Consulting systems", "Innovations in information technologies", "Diploma project" };

const std::string testNames[] = { "Mathematics","English","Science","History","Geography","Physical Education",
"Art","Music","Computer Science","Foreign Language","Chemistry","Biology",
"Physics","Literature","Social Studies","Health Education","Drama","Economics",
 "Psychology","Sociology","Politics","Religious Studies","Ethics","Philosophy",
 "Home Economics","Culinary Arts","Woodwork","Metalwork","Graphic Design","Textiles",
 "Physical Science","Environmental Science","Government","Anthropology","Business Studies","Astronomy",
 "Dance","Photography","Journalism","Legal Studies","Media Studies","Archaeology",
 "Creative Writing","EFL","Film Studies","Physical Health and Education","Public Speaking","Theater Studies" };

const std::string names[] = { "Ivan", " Grisha", "Serega", "Artem", "Volodya" };
const std::string surnames[] = { "Ivanov", "Petrov", "Seregov", "Artemov", "Vladimirov" };
const std::string fullnames[] = { "Ivanovich", "Petrovich", "Seregich", "Artemich", "Volodich" };

const bool results[] = { true, false };
const int result_retake[] = { 2, 3, 4, 5 };

void creating_a_student(Student* students, int number_of_students)
{
	for (int i = 0; i < number_of_students; i++)
	{
		int id = i;
		int semestr = (rand() % 4) * 2 + 1;
		int group = 220 + rand() % 10;

		std::string name = names[rand() % 5];
		std::string surname = surnames[rand() % 5];
		std::string fullname = fullnames[rand() % 5];

		Exams examGrades[4][8];
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < semestr; ++k)
			{
				Exams exam{ examNames[k * 4 + j], rand() % 4 + 2 };
				examGrades[j][k] = exam;
			}
		}

		Tests testGrades[6][8];
		for (int j = 0; j < 6; ++j)
		{
			for (int k = 0; k < semestr; ++k)
			{
				Tests test{ testNames[k * 6 + j], results[rand() % 2] };
				testGrades[j][k] = test;
			}
		}
		Student student{ id, semestr, group, name, surname, fullname, examGrades, testGrades };
		students[i] = student;
	}
}
void output_by_student(Student* students, int number_of_students, int ID_student)
{
	Student student;
	bool flag = false;
	for (int i = 0; i < number_of_students; i++)
	{
		if (students[i].id == ID_student)
		{
			student = students[i];
			flag = true;
		}
	}
	if (!flag)
	{
		std::cout << "Student not found";
		return;
	}
	std::cout << "Fullname: " << student.surname << " " << student.name << " " << student.fullname << std::endl;
	std::cout << "ID: " << student.id << "; Group: " << student.group << "; Semestr: " << student.semestr << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	std::cout << "Exams:" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < student.semestr; ++i)
	{
		std::cout << (i + 1) << " semester:" << std::endl;
		for (int j = 0; j < 4; ++j)
		{
			std::cout << student.examGrades[j][i].name << ": " << student.examGrades[j][i].grade << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Tests:" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < student.semestr; ++i)
	{
		std::cout << (i + 1) << " semester: " << std::endl;

		for (int j = 0; j < 6; ++j)
		{
			bool result = student.testGrades[j][i].grade;
			std::cout << student.testGrades[j][i].name << ": " << (result ? "pass" : "fail") << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	int Number_of_items_1 = 0;
	int Number_of_items = 0;


	for (int i = 0; i < student.semestr; i++)
	{
		std::cout << (i + 1) << " semester: " << "\t";
		int Number_of_items_1 = 0;
		for (int j = 0; j < 4; j++)
		{
			if (student.examGrades[j][i].grade == 2 || student.examGrades[j][i].grade == 3)
			{
				Number_of_items_1++;
			}

		}
		std::cout << Number_of_items_1 << std::endl;

		std::cout << (i + 1) << " semester: " << "\t";

		for (int j = 0; j < 6; j++)
		{
			if (student.testGrades[j][i].grade == 0)
			{
				Number_of_items++;
			}

		}
		std::cout << Number_of_items << std::endl;

		if (Number_of_items_1 == 0 && Number_of_items == 0)
		{
			std::cout << "The scholarship is paid in the" << (i + 1) << "semester" << std::endl;
		}
		else
		{
			std::cout << "the scholarship is not paid" << std::endl;
		}
		Number_of_items = 0;
		Number_of_items_1 = 0;
	}
	std::cout << std::endl;
}
void list_of_students(Student* students, int number_of_students)
{
	for (int i = 0; i < number_of_students; i++)
	{
		Student& students_ = students[i];
		std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "Student number: " << (i + 1) << std::endl;
		std::cout << "Fullname: " << students_.surname << " " << students_.name << " " << students_.fullname << std::endl;
		std::cout << "ID: " << students_.id << "; Group: " << students_.group << "; Semestr: " << students_.semestr << std::endl;
		std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
}
void retake_the_exam(Student* students, int number_of_students)
{
	for (int i = 0; i < number_of_students; i++)
	{
		Student& students_retake = students[i];
		std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < students_retake.semestr; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (students_retake.examGrades[j][i].grade == 2)
				{
					std::cout << "Студент с ID: " << (students_retake.id + 1) << "\tотправлен на пересдачу по предмету: " << students_retake.examGrades[j][i].name << " на " << students_retake.semestr << " семестре." << std::endl;
					students_retake.examGrades[j][i].grade = result_retake[rand() % 4];
					if (students_retake.examGrades[j][i].grade == 2)
					{
						std::cout << "Студент с ID: " << (students_retake.id + 1) << "\tотчислен из-за предмета: " << students_retake.examGrades[j][i].name << " на " << students_retake.semestr << " семестре." << std::endl;
					}
				}
			}
		}
		for (int i = 0; i < students_retake.semestr; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if (students_retake.testGrades[j][i].grade == 2)
				{
					std::cout << "Студент с ID: " << (students_retake.id + 1) << "\tотправлен на пересдачу по предмету: " << students_retake.testGrades[j][i].name << " на " << students_retake.semestr << " семестре." << std::endl;
					students_retake.testGrades[j][i].grade = result_retake[rand() % 4];
					if (students_retake.testGrades[j][i].grade == 2)
					{
						std::cout << "Студент с ID: " << (students_retake.id + 1) << "\tотчислен из-за предмета: " << students_retake.testGrades[j][i].name << " на " << students_retake.semestr << " семестре." << std::endl;
					}
				}
			}
		}

		std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
}

void next_sem(Student* students, int number_of_students)
{

	int finish = 0;
	int* tokick = new int[number_of_students];
	int kick_count = 0;
	for (int i = 0; i < number_of_students; i++)
	{
		Student& student = students[i];

		if (student.ot4isleni)
		{
			finish++;
			continue;
		}
		std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
		if (student.semestr >= 7)
		{
			

			std::cout << "Студент с ID: " << student.id << " выпустился из университета" << std::endl;
			finish++;
			continue;
		}
		student.semestr++;
		int tries = 1;
		std::cout << "СТУДЕНТ С ID:	" << student.id << std::endl;
		while (tries <= 3)
		{
			bool res = false;
			std::cout << "----------------------------" << std::endl;
			std::cout << "Exams:" << std::endl;
			std::cout << std::endl;
			int a = student.semestr;
			std::cout << (a + 1) << " semester:" << std::endl;

			for (int j = 0; j < 4; ++j)
			{
				if (tries > 1 && student.examGrades[j][a].grade != 2)
				{
					continue;
				}
				Exams exam{examNames[student.semestr * 4 + j], rand() % 4 + 2 };
				student.examGrades[j][student.semestr] = exam;
			}


			for (int j = 0; j < 6; ++j)
			{
				if (tries > 1 && student.testGrades[j][a].grade)
				{
					continue;
				}
				Tests test{testNames[student.semestr * 6 + j], results[rand() % 2] };
				student.testGrades[j][student.semestr] = test;
			}
			for (int j = 0; j < 4; ++j)
			{
				std::cout << student.examGrades[j][a].name << ": " << student.examGrades[j][a].grade << "\n";
				if (student.examGrades[j][a].grade == 2)
				{
					res = true;
				}
			}
			std::cout << std::endl;

			std::cout << "Tests:" << std::endl;
			std::cout << std::endl;

			std::cout << (a + 1) << " semester: " << std::endl;

			for (int j = 0; j < 6; ++j)
			{
				bool result = student.testGrades[j][a].grade;
				std::cout << student.testGrades[j][a].name << ": " << (result ? "pass" : "fail") << "\n";
				if (student.testGrades[j][a].grade == false)
				{
					res = true;
				}
			}
			if (tries == 3 && res)
			{
				tokick[kick_count] = i;
				kick_count++;
			}
			if (!res)
			{
				break;
			}
			tries++;
		}
		std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	}
	kick_count = ((float)kick_count / (number_of_students - finish)) >= 0.8 ? ((number_of_students - finish) * 0.8) : kick_count;
	for (int i = 0; i < kick_count; i++)
	{
		students[tokick[i]].ot4isleni = true;
		std::cout << "Студент c ID " << students[tokick[i]].id << " отчислен!" << std::endl;
	}
	std::cout << "ОТЧИСЛЕНО: " << kick_count << " СТУДЕНТОВ!" << std::endl;
	std::cout << std::endl;
	delete[] tokick;
}
