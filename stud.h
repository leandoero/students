#include <iostream>
#include <string>

struct Exams
{
    int grade;
    std::string name;
    Exams();
    Exams(std::string Name, int Grade);
};

struct Tests
{
    bool grade;
    std::string name;
    Tests();
    Tests(std::string Name, bool Result);
};

struct Student
{
    bool ot4isleni;
    Student();
    int id, semestr, group;
    std::string name, surname, fullname;
    Exams examGrades[4][8];
    Tests testGrades[6][8];
    Student(int ID, int SEMESTR, int GROUP, std::string NAME, std::string SURNAME, std::string FULLNAME, Exams EXAM_GRADES[4][8], Tests TEST_GRADES[6][8]);
};
void next_sem(Student* students, int number_of_students);
void creating_a_student(Student* students, int number_of_students);
void output_by_student(Student* students, int number_of_students, int ID_student);
void list_of_students(Student* students, int number_of_students);
void retake_the_exam(Student* students, int number_of_students);
