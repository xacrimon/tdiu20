#include "list.h"

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
    : head{nullptr}, tail{nullptr}, sentinel{nullptr}
{
    sentinel = new Node{0, nullptr, nullptr};
    head = sentinel;
    tail = sentinel;
}

List::List(std::initializer_list<int> elems)
    : head{nullptr}, tail{nullptr}, sentinel{nullptr}
{
    sentinel = new Node{0, nullptr, nullptr};
    head = sentinel;
    tail = sentinel;

    for (auto v : elems)
    {
        push_back(v);
    }
}

// special: copy constructor
List::List(List const &other)
    : head{nullptr}, tail{nullptr}, sentinel{nullptr}
{
    sentinel = new Node{0, nullptr, nullptr};
    head = sentinel;
    tail = sentinel;

    Node *curr{other.head};
    for (curr !=)
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
    other.tail = nullptr;
    other.head = nullptr;
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
    rhs.tail = nullptr;
    rhs.head = nullptr;

    return *this;
}

void List::push_back(int elem)
{
    auto node = new Node{elem, nullptr, tail};
    tail->next = node;
    tail = node;
    if (head == nullptr)
    {
        head = tail;
    }
}

int List::pop_back()
{
    if (tail == nullptr)
    {
        throw std::runtime_error("Listan är tom!");
    }

    auto node = tail;
    tail = tail->prev;
    if (tail == nullptr)
    {
        head = nullptr;
    }
    else
    {
        tail->next = nullptr;
    }

    auto elem = node->elem;
    delete node;
    return elem;
}

void List::insert(int elem)
{
    Node *prev = nullptr;
    auto current = head;

    while (true)
    {
        if (current == nullptr)
        {
            auto node = new Node{elem, nullptr, prev};
            if (head == nullptr)
            {
                // listan är tom
                head = node;
                tail = node;
            }
            else if (tail == prev)
            {
                // vi är i slutet på listan
                prev->next = node;
                tail = node;
            }

            break;
        }
        else if (elem < current->elem)
        {
            auto node = new Node{elem, current, prev};
            if (current == head)
            {
                // insert i början på listan
                current->prev = node;
                head = node;
            }

            prev->next = node;
            current->prev = node;
            break;
        }

        prev = current;
        current = current->next;
    }
}

void List::remove(int index)
{
    if (is_empty())
    {
        throw std::logic_error("listan är tom!");
    }

    Node *prev = nullptr;
    auto current = head;

    for (int i{0}; i < index; i++)
    {
        prev = current;
        current = current->next;

        if (current == nullptr)
        {
            throw std::logic_error("index fanns ej i listan!");
        }
    }

    if (current->next == nullptr)
    {
        // slutet på listan
        pop_back();
        return;
    }

    auto unlinked = current;
    current = current->next;
    if (prev != nullptr)
    {
        // ej början på listan
        prev->next = current;
    }
    else
    {
        // början på listan
        head = current;
    }

    current->prev = prev;
    delete unlinked;
}

bool List::is_empty() const
{
    return head == nullptr;
}

int List::length() const
{
    int len{0};

    for (const auto &elem : *this)
    {
        (void)elem;
        len++;
    }

    return len;
}

int List::front() const
{
    if (head == nullptr)
    {
        throw std::runtime_error("Listan är tom!");
    }

    return head->elem;
}

int List::back() const
{
    if (tail == nullptr)
    {
        throw std::runtime_error("Listan är tom!");
    }

    return tail->elem;
}

int List::at(int index) const
{
    auto it = begin();

    for (int i = 0; i < index; i++)
    {
        if (it == end())
        {
            throw std::runtime_error("Listan är tom!");
        }

        it++;
    }

    return *it;
}

List List::sub(std::initializer_list<int> indices) const
{
    auto is_sorted = std::is_sorted(indices.begin(), indices.end());
    if (!is_sorted)
    {
        throw std::logic_error("index ej sorterade!");
    }

    List sub;
    auto curr_idx = 0;
    auto it = begin();

    for (const auto &index : indices)
    {
        auto diff = index - curr_idx;

        for (int i = 0; i < diff; i++)
        {
            if (it == end())
            {
                throw std::runtime_error("givna index fanns ej i listan!");
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
    return List::iterator{nullptr};
}

std::ostream &operator<<(std::ostream &os, const List &list)
{
    os << "[";
    auto it = list.begin();

    while (true)
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
