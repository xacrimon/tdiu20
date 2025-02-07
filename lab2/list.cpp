#include "list.h"

#include <optional>
#include <iostream>
#include <stdexcept>

List::List()
    : head{nullptr}, tail{nullptr}
{
    head = sentinel;
    tail = sentinel;
}

// special: copy constructor
List::List(List const& other) {
    throw std::runtime_error("Not implemented!");
}

// special: copy assignment
List& List::operator=(List const& rhs) {
    throw std::runtime_error("Not implemented!");
}

// special: destructor
List::~List() {
    while (!is_empty()) {
        pop_back();
    }
}

// special: move constructor
List::List(List && other) {
    throw std::runtime_error("Not implemented!");
}

// special: move assignment
List& List::operator=(List && rhs) {
    throw std::runtime_error("Not implemented!");
}

void List::push_back(int elem) {
    throw std::runtime_error("Not implemented!");
}

void List::push_front(int elem) {
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::pop_back() {
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::pop_front() {
    throw std::runtime_error("Not implemented!");
}

void List::insert(int elem) {
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::remove(int index) {
    throw std::runtime_error("Not implemented!");
}

bool List::is_empty() const {
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::front() const {
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::back() const {
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::at(int index) const {
    throw std::runtime_error("Not implemented!");
}

std::ostream &operator<<(std::ostream &os, const List &list)
{
    throw std::runtime_error("Not implemented!");
}
