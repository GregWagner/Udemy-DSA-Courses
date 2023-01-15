/*
 * Student Grades
 */
#include <iostream>

auto main() -> int {
    std::string name_1;
    int id_1 {};
    std::cout << "What is student 1 name: ";
    std::cin >> name_1;
    std::cout << "His id: ";
    std::cin >> id_1;

    double grade_1 {};
    std::cout << "His math exam grade: ";
    std::cin >> grade_1;

    std::string name_2;
    std::cout << "What is student 2 name: ";
    std::cin >> name_2;

    int id_2 {};
    std::cout << "His id: ";
    std::cin >> id_2;

    double grade_2 {};
    std::cout << "His math exam grade: ";
    std::cin >> grade_2;

    std::cout << "\nStudents grade in math\n"
              << name_1 << " (with id " << id_1 << ") got grade: "
              << grade_1 << '\n'
              << name_2 << " (with id " << id_2 << ") got grade: "
              << grade_2 << '\n';
    std::cout << "Average grade is " << (grade_1 + grade_2) / 2.0 << '\n';
}