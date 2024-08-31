#include <iostream>

auto main() -> int {
    // read the first students information
    std::cout << "What is student 1's name: ";
    std::string first_students_name{};
    std::cin >> first_students_name;

    std::cout << "His id: ";
    int first_students_id{};
    std::cin >> first_students_id;

    std::cout << "His math exam grade: ";
    double first_students_grade{};
    std::cin >> first_students_grade;

    // read the seconds students information
    std::cout << "What is student 2's name: ";
    std::string second_students_name{};
    std::cin >> second_students_name;

    std::cout << "His id: ";
    int second_students_id{};
    std::cin >> second_students_id;

    std::cout << "His math exam grade: ";
    double second_students_grade{};
    std::cin >> second_students_grade;

    // output the results
    std::cout << "\nStudents grades in math\n"
        << first_students_name << " (with id " << first_students_id << ") got grade: " << first_students_grade << '\n'
        << second_students_name << " (with id " << second_students_id << ") got grade: " << second_students_grade << '\n'
        << "Average grade: " << (first_students_grade + second_students_grade) / 2.0 << '\n';
}
