#include <iostream>
#include <vector>

struct Employee {
    std::string name;
    int age;
    double salary;
    char gender;
};

auto getMenuSelection() -> int {
    std::cout << "\nEnter your choice:\n";
    std::cout << "1) Add new employeee\n";
    std::cout << "2) Print all employees\n";
    std::cout << "3) Delete by age\n";
    std::cout << "4) Update Salaray by name\n";

    int choice {};
    std::cin >> choice;
    return choice;
}

auto addNewEmployee(std::vector<Employee>& a) -> void {
    Employee e {};
    std::cout << "Enter name: ";
    std::cin >> e.name;
    std::cout << "Enter age: ";
    std::cin >> e.age;
    std::cout << "Enter salary: ";
    std::cin >> e.salary;
    std::cout << "Enter gender(M/F): ";
    std::cin >> e.gender;
    a.push_back(e);
}

auto printAllEmployess(const std::vector<Employee>& a) -> void {
    std::cout << "*******************\n";
    for (const auto& emp : a) {
        std::cout << emp.name << ' ' << emp.age << ' ' << emp.salary
        << ' ' << emp.gender << '\n';
    }
    std::cout << '\n';
}

auto deleteByAge(std::vector<Employee>& a) -> void {
    std::cout << "Enter start and end age: ";
    int start {}, end {};
    std::cin >> start >> end;
    for (size_t i {}; i < a.size(); ++i) {
        Employee emp = a[i];
        if (emp.age >= start && emp.age <= end) {
            a.erase(a.begin() + i);
        }
    }
}

auto updateSalaryByName(std::vector<Employee>& a) -> void {
    std::cout << "Enter the name and salary: ";
    std::string name {};
    double salary {};
    std::cin >> name >> salary;
    for (auto& emp : a) {
        if (emp.name == name) {
            emp.salary = salary;
            break;
        }
    }
}

auto main() -> int {
    std::vector<Employee> a {};

    while (true) {
        int selection = getMenuSelection();

        switch (selection) {
        case 1:
            addNewEmployee(a);
            break;
        case 2:
            printAllEmployess(a);
            break;
        case 3:
            deleteByAge(a);
            break;
        case 4:
            updateSalaryByName(a);
            break;
        }
    }
}