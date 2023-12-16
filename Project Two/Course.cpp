
#include "Course.h"
#include <sstream>
#include <string>
#include <vector>

Course::Course(const std::string &id, const std::string &name, const std::vector<std::string> &prerequisites)
    : courseId(id), courseName(name), coursePrerequisites(prerequisites) {}

std::string Course::getCourseId() const {
    return courseId;
}

std::string Course::getCourseName() const {
    return courseName;
}

const std::vector<std::string>& Course::getCoursePrerequisites() const {
    return coursePrerequisites;
}

std::string Course::courseToString() const {
    std::stringstream ss;
    ss << courseId << ", " << courseName;
    if (!coursePrerequisites.empty()) {
        ss << "\nPrerequisites: ";
        for (const auto& prereq : coursePrerequisites) {
            ss << prereq;
            if (&prereq != &coursePrerequisites.back()) {
                ss << ", ";
            }
        }
    }
    return ss.str();
}
