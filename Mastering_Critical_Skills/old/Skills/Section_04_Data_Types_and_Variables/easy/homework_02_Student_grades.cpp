#include <iostream>

auto main() -> int {
    // read in first student
    std::cout << "What is student 1 name: ";
    std::string first_student_name;
    std::cin >> first_student_name;

    std::cout << "His id: ";
    int first_student_id {};
    std::cin >> first_student_id;

    std::cout << "His math exam grade: ";
    double first_student_grade {};
    std::cin >> first_student_grade;

    // read in second student
    std::cout << "What is student 2 name: ";
    std::string second_student_name;
    std::cin >> second_student_name;

    std::cout << "His id: ";
    int second_student_id {};
    std::cin >> second_student_id;

    std::cout << "His math exam grade: ";
    double second_student_grade {};
    std::cin >> second_student_grade;

    // output the results
    std::cout << "Student grades in math\n"
              << first_student_name << " (with id " << first_student_id << ") got grade: "
              << first_student_grade << '\n'
              << second_student_name << " (with id " << second_student_id << ") got grade: "
              << second_student_grade << '\n'
              << "Average grade is " << (first_student_grade + second_student_grade) / 2.0 << '\n';
}
