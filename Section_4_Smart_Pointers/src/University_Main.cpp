// University_Main.cpp
#include <memory>
#include <iostream>
#include <string>
#include "University_Types.h"

int main() {
    // Creates department 
    Department* physics = new Department("Physics");

    //Creates student 
    Student* luz = new Student("Luz");

    //Adds student to department
    luz->setDepartment(physics);
    auto physList = physics->getList();

    //Prints out a student list of a given department 
    std::cout << "Students in " << physics->getName() << ":";
    for (const auto& element : physList) {
        std::cout << " "<<element->getName() << " & id: " << element->getId()<< " ";
    }
    std::cout << std::endl;

    //Destructors 
    delete luz;
    delete physics;

    return 0;
}