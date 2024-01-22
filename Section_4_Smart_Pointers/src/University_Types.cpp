#include <memory>
#include <iostream>
#include <string>
#include "University_Types.h"
#include <vector>

using namespace std;

void Student::setDepartment(Department *dept) {
    department = dept;
    if (department) {
        department -> addStudent(this);
    }

    string nameDept = Department(*dept).getName();

    cout << "Student " << name << " has been added to department " << nameDept << endl;
}

// Static variables need to be initialised outside their class declaration
int Student::max_id = 0;

void Department::addStudent(Student *student) {
    students.push_back(student);
}

