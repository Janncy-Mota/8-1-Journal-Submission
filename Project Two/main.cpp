#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "Courses.h"

void loadCourses(Courses& courses) {
    // Hardcodes some course additions for now
    courses.Insert(Course("MATH201", "Discrete Mathematics", {}));
    courses.Insert(Course("CSCI300", "Introduction to Algorithms", {"CSCI200", "MATH201"}));
    courses.Insert(Course("CSCI350", "Operating Systems", {"CSCI300"}));
    courses.Insert(Course("CSCI101", "Introduction to Programming in C++", {"CSCI100"}));
    courses.Insert(Course("CSCI100", "Introduction to Computer Science", {}));
    courses.Insert(Course("CSCI301", "Advanced Programming in C++", {"CSCI101"}));
    courses.Insert(Course("CSCI400", "Large Software Development", {"CSCI301", "CSCI350"}));
    courses.Insert(Course("CSCI200", "Data Structures", {"CSCI101"}));
}

void printCourseList(const Courses& courses) {
    courses.InOrder(); // This assumes InOrder prints the courses sorted by courseId
}

void printCourse(const Courses& courses) {
    std::string courseId;
    std::cout << "Enter the course ID you want to know about: ";
    std::cin >> courseId;
    std::transform(courseId.begin(), courseId.end(), courseId.begin(), ::toupper); // Convert to uppercase

    Course course = courses.Search(courseId);
    if (!course.getCourseId().empty()) {
        std::cout << "Course ID: " << course.getCourseId() << std::endl;
        std::cout << "Course Name: " << course.getCourseName() << std::endl;
        std::cout << "Prerequisites: ";
        const auto& prereqs = course.getCoursePrerequisites();
        if (!prereqs.empty()) {
            for (const auto& prereq : prereqs) {
                std::cout << prereq;
                if (&prereq != &prereqs.back()) {
                    std::cout << ", ";
                }
            }
        } else {
            std::cout << "None";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Course not found." << std::endl;
    }
}

int main() {
    Courses courses;
    int choice;

    do {
        std::cout << "\nWelcome to the course planner." << std::endl;
        std::cout << "1. Load Data Structure." << std::endl;
        std::cout << "2. Print Course List." << std::endl;
        std::cout << "3. Print Course." << std::endl;
        std::cout << "9. Exit" << std::endl;

        std::cout << "What would you like to do? ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore newline character in the input buffer

        switch (choice) {
            case 1:
                loadCourses(courses);
                break;
            case 2:
                printCourseList(courses);
                break;
            case 3:
                printCourse(courses);
                break;
            case 9:
                std::cout << "Thank you for using the course planner!" << std::endl;
                break;
            default:
                std::cout << choice << " is not a valid option." << std::endl;
        }
    } while (choice != 9);

    return 0;
}
