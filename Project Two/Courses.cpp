// Courses.cpp
#include "Courses.h"
#include <iostream>
#include <string>

Courses::Courses() : root(nullptr) {}

Courses::~Courses() {
    destroyTree(root);
}

void Courses::Insert(const Course& course) {
    insertNode(root, course);
}

void Courses::InOrder() const {
    inOrderTraversal(root);
}

Course Courses::Search(const std::string& courseId) const {
    Node* result = searchNode(root, courseId);
    if (result == nullptr) {
        return Course("", "", {});  // Return an empty course if not found
    }
    return result->course;
}

// Private methods
void Courses::insertNode(Node*& node, const Course& course) {
    if (node == nullptr) {
        node = new Node(course);
    } else if (course.getCourseId() < node->course.getCourseId()) {
        insertNode(node->left, course);
    } else {
        insertNode(node->right, course);
    }
}

void Courses::inOrderTraversal(Node* node) const {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        std::cout << node->course.courseToString() << std::endl;
        inOrderTraversal(node->right);
    }
}

void Courses::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

Courses::Node* Courses::searchNode(Node* node, const std::string& courseId) const {
    if (node == nullptr) {
        return nullptr;
    }
    if (courseId == node->course.getCourseId()) {
        return node;
    }
    if (courseId < node->course.getCourseId()) {
        return searchNode(node->left, courseId);
    }
    return searchNode(node->right, courseId);
}
