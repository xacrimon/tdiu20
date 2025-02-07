#include "list.h"

#include <stdexcept>

List::List()
    : head{nullptr}, tail{nullptr}
{
    throw std::runtime_error("Not implemented!");
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
    throw std::runtime_error("Not implemented!");
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

int List::pop_back() {
    throw std::runtime_error("Not implemented!");
}

int List::pop_front() {
    throw std::runtime_error("Not implemented!");
}

void List::insert(int elem) {
    throw std::runtime_error("Not implemented!");
}

int List::remove(int index) {
    throw std::runtime_error("Not implemented!");
}

void List::front() const {
    throw std::runtime_error("Not implemented!");
}

void List::back() const {
    throw std::runtime_error("Not implemented!");
}

int List::at(int index) const {
    throw std::runtime_error("Not implemented!");
}

std::ostream &operator<<(std::ostream &os, const List &list)
{
    throw std::runtime_error("Not implemented!");
}
