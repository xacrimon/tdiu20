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

List::List(std::initializer_list<int> elems)
    : head{nullptr}, tail{nullptr}
{
    head = sentinel;
    tail = sentinel;

    for (auto v : elems) {
        push_back(v);
    }
}

// special: copy constructor
List::List(List const& other)
    : head{nullptr}, tail{nullptr}
{
    (void)other;
    throw std::runtime_error("Not implemented!");
}

// special: copy assignment
List& List::operator=(List const& rhs) {
    (void)rhs;
    throw std::runtime_error("Not implemented!");
}

// special: destructor
List::~List() {
    while (!is_empty()) {
        pop_back();
    }
}

// special: move constructor
List::List(List && other)
    : head{nullptr}, tail{nullptr}
{
    (void)other;
    throw std::runtime_error("Not implemented!");
}

// special: move assignment
List& List::operator=(List && rhs) {
    (void)rhs;
    throw std::runtime_error("Not implemented!");
}

void List::push_back(int elem) {
    (void)elem;
    throw std::runtime_error("Not implemented!");
}

void List::push_front(int elem) {
    (void)elem;
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::pop_back() {
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::pop_front() {
    throw std::runtime_error("Not implemented!");
}

void List::insert(int elem) {
    (void)elem;
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::remove(int index) {
    (void)index;
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
    (void)index;
    throw std::runtime_error("Not implemented!");
}

List List::sub(std::initializer_list<int> indices) const {
    (void)indices;
    throw std::runtime_error("Not implemented!");
}

List::iterator List::begin() const {
    return List::iterator{head};
}

List::iterator List::end() const {
    return List::iterator{tail};
}

std::ostream &operator<<(std::ostream &os, const List &list)
{
    (void)os;
    (void)list;
    throw std::runtime_error("Not implemented!");
}
