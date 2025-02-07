#include "list.h"

#include <optional>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

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
    other.tail = sentinel;
    other.head = sentinel;
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
    rhs.tail = sentinel;
    rhs.head = sentinel;

    return *this;
}

void List::push_back(int elem)
{
    auto node = new impl::Node{elem, sentinel, tail};
    tail->next = node;
    tail = node;
    if (head == sentinel)
    {
        head = tail;
    }
}

void List::push_front(int elem)
{
    auto node = new impl::Node{elem, head, sentinel};
    head->prev = node;
    head = node;
    if (tail == sentinel)
    {
        tail = head;
    }
}

std::optional<int> List::pop_back()
{
    if (tail == sentinel)
    {
        return std::nullopt;
    }

    auto node = tail;
    tail = tail->prev;
    if (tail == sentinel)
    {
        head = sentinel;
    }
    else
    {
        tail->next = sentinel;
    }

    auto elem = node->elem;
    delete node;
    return elem;
}

std::optional<int> List::pop_front()
{
    if (head == sentinel)
    {
        return std::nullopt;
    }

    auto node = head;
    head = head->next;
    if (head == sentinel)
    {
        tail = sentinel;
    }
    else
    {
        head->prev = sentinel;
    }

    auto elem = node->elem;
    delete node;
    return elem;
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
    return head == sentinel;
}

int List::length() const
{
    int len = 0;

    for (const auto &elem : *this)
    {
        (void)elem;
        len++;
    }

    return len;
}

std::optional<int> List::front() const
{
    if (head == sentinel)
    {
        return std::nullopt;
    }

    return head->elem;
}

std::optional<int> List::back() const
{
    if (tail == sentinel)
    {
        return std::nullopt;
    }

    return tail->elem;
}

std::optional<int> List::at(int index) const
{
    auto it = begin();

    for (int i = 0; i < index; i++)
    {
        if (it == end())
        {
            return std::nullopt;
        }

        it++;
    }

    return *it;
}

List List::sub(std::initializer_list<int> indices) const
{
    auto is_sorted = std::is_sorted(indices.begin(), indices.end());
    auto sorted = [indices]()
    {
        std::vector<int> list = indices;
        std::sort(list.begin(), list.end());
        return list;
    };

    List sub;
    auto curr_idx = 0;
    auto it = begin();
    auto indices_sorted = is_sorted ? indices : sorted();

    for (const auto &index : indices_sorted)
    {
        auto diff = index - curr_idx;

        for (int i = 0; i < diff; i++)
        {
            if (it == end())
            {
                throw std::runtime_error("crap");
            }

            it++;
            curr_idx++;
        }

        sub.push_back(*it);
    }

    return sub;
}

List::iterator List::begin() const
{
    return List::iterator{head};
}

List::iterator List::end() const
{
    return List::iterator{sentinel};
}

std::ostream &operator<<(std::ostream &os, const List &list)
{
    os << "[";
    auto it = list.begin();

    for (;;)
    {
        os << *it;
        it++;

        if (it != list.end())
        {
            os << ", ";
        }
        else
        {
            break;
        }
    }

    os << "]";
    return os;
}
