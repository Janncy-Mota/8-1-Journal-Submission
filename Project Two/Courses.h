// Courses.h
#ifndef COURSES_H
#define COURSES_H

#include "Course.h"
#include <string>

class Courses {
private:
    struct Node {
        Course course;
        Node* left;
        Node* right;

        Node(const Course& c) : course(c), left(nullptr), right(nullptr) {}
    };

    Node* root;
    
    void insertNode(Node*& node, const Course& course);
    void inOrderTraversal(Node* node) const;
    void destroyTree(Node* node);
    Node* searchNode(Node* node, const std::string& courseId) const;

public:
    Courses();
    ~Courses();
    void Insert(const Course& course);
    void InOrder() const;
    Course Search(const std::string& courseId) const;
};

#endif // COURSES_H