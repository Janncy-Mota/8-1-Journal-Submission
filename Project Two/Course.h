// Course.h
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

class Course {
private:
    std::string courseId;
    std::string courseName;
    std::vector<std::string> coursePrerequisites;

public:
    Course(const std::string &id, const std::string &name, const std::vector<std::string> &prerequisites);
    std::string getCourseId() const;
    std::string getCourseName() const;
    const std::vector<std::string>& getCoursePrerequisites() const;
    std::string courseToString() const;
};

#endif // COURSE_H
