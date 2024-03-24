
#include <iostream>
#include <string>
#include "stud.h"

int main()
{
    char progOn;
    int number_of_students;
    int choice;
    int ID_student;
    setlocale(LC_ALL, "ru");
    std::cout << "Введите количество поступивших студентов: ";
    std::cin >> number_of_students;
    Student* students = new Student[number_of_students];
    creating_a_student(students, number_of_students);
    do
    {
        std::cout << "Выберите номер операции:\n"
            "1. Открыть список всех студентов\n"
            "2. Открыть информацию по студенту\n"
            "3. Открыть список отчислений\n"
            "4. Перевести студентов на семестр (+1)\n";

        std::cin >> choice;
        switch (choice)
        {
        case 1:
            list_of_students(students, number_of_students);
            break;
        case 2:
            std::cout << "enter the student's ID:";
            std::cin >> ID_student;
            output_by_student(students, number_of_students, ID_student);
            break;
        case 3:
            retake_the_exam(students, number_of_students);
            break;
        case 4:
            next_sem(students, number_of_students);
            break;
        default:
            std::cout << "Некорректный ввод!" << std::endl;
            break;
        }
        std::cout << "Хотите продолжить?    y/n" << std::endl;
        std::cin >> progOn;
    } while (progOn == 'Y' || progOn == 'y');
}