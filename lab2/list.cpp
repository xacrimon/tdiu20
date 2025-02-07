#include "list.h"

#include <optional>
#include <iostream>
#include <stdexcept>

impl::ListIterator::ListIterator(Node *node)
    : curr{node}
{
}

impl::ListIterator::reference impl::ListIterator::operator*() const
{
    return curr->elem;
}

impl::ListIterator &impl::ListIterator::operator++()
{
    curr = curr->next;
    return *this;
}

impl::ListIterator impl::ListIterator::operator++(int)
{
    ListIterator tmp = *this;
    curr = curr->next;
    return tmp;
}

impl::ListIterator &impl::ListIterator::operator--()
{
    curr = curr->prev;
    return *this;
}

impl::ListIterator impl::ListIterator::operator--(int)
{
    ListIterator tmp = *this;
    curr = curr->prev;
    return tmp;
}

bool impl::ListIterator::operator==(const ListIterator &rhs)
{
    return curr == rhs.curr;
}

bool impl::ListIterator::operator!=(const ListIterator &rhs)
{
    return curr != rhs.curr;
}

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

    for (auto v : elems)
    {
        push_back(v);
    }
}

// special: copy constructor
List::List(List const &other)
    : head{nullptr}, tail{nullptr}
{
    head = sentinel;
    tail = sentinel;

    for (const auto &elem : other)
    {
        push_back(elem);
    }
}

// special: copy assignment
List &List::operator=(List const &rhs)
{
    while (!is_empty())
    {
        pop_back();
    }

    for (const auto &elem : rhs)
    {
        push_back(elem);
    }

    return *this;
}

// special: destructor
List::~List()
{
    while (!is_empty())
    {
        pop_back();
    }
}

// special: move constructor
List::List(List &&other)
    : head{nullptr}, tail{nullptr}
{
    head = other.head;
    tail = other.tail;
    other.tail = other.sentinel;
    other.head = other.sentinel;
}

// special: move assignment
List &List::operator=(List &&rhs)
{
    while (!is_empty())
    {
        pop_back();
    }

    head = rhs.head;
    tail = rhs.tail;
    rhs.tail = rhs.sentinel;
    rhs.head = rhs.sentinel;

    return *this;
}

void List::push_back(int elem)
{
    (void)elem;
    throw std::runtime_error("Not implemented!");
}

void List::push_front(int elem)
{
    (void)elem;
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::pop_back()
{
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::pop_front()
{
    throw std::runtime_error("Not implemented!");
}

void List::insert(int elem)
{
    (void)elem;
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::remove(int index)
{
    (void)index;
    throw std::runtime_error("Not implemented!");
}

bool List::is_empty() const
{
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::front() const
{
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::back() const
{
    throw std::runtime_error("Not implemented!");
}

std::optional<int> List::at(int index) const
{
    (void)index;
    throw std::runtime_error("Not implemented!");
}

List List::sub(std::initializer_list<int> indices) const
{
    (void)indices;
    throw std::runtime_error("Not implemented!");
}

List::iterator List::begin() const
{
    return List::iterator{head};
}

List::iterator List::end() const
{
    return List::iterator{tail};
}

std::ostream &operator<<(std::ostream &os, const List &list)
{
    (void)os;
    (void)list;
    throw std::runtime_error("Not implemented!");
}
