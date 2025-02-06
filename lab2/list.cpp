#include "list.h"

#include <stdexcept>

List::List()
    : first{nullptr}, last{nullptr}
{
}

List::List(const List &other)
    : first{nullptr}, last{nullptr}
{
    Node *curr{other.first};

    while (curr != nullptr)
    {
        push_back(curr->data);
        curr = curr->next;
    }
}

List::List(List &&other)
    : first{other.first}, last{other.last}
{
    other.first = nullptr;
    other.last = nullptr;
}

List::~List()
{
}

List &List::operator=(const List &rhs)
{
    Node *curr{rhs.first};
    List list{};

    while (curr != nullptr)
    {
        list.push_back(curr->data);
        curr = curr->next;
    }

    return list;
}

List &List::operator=(List &&rhs)
{
    List list{};
    list.first = rhs.first;
    list.last = rhs.last;
    rhs.first = nullptr;
    rhs.last = nullptr;
}

void List::insert(int data)
{
    Node *curr{first};

    if (first == nullptr)
    {
        first = new Node{data, nullptr, nullptr};
        last = first;
    }
    else
    {
        while (curr != nullptr)
        {
            if (curr->data >= data)
            {
                Node *tmp;
                tmp = new Node{data, curr->previous, curr};
                curr->previous->next = tmp;
            }

            curr = curr->next;
        }
    }
}

void List::remove(int index)
{
}

int List::at(int index) const
{
    Node *curr{first};
    for (int i{0}; i < index; ++i)
    {
        if (curr == nullptr)
        {
            throw std::runtime_error("Index out of range!");
            return 0;
        }
    }

    return curr->data;
}

void List::push_back(int data)
{
    if (first == nullptr)
    {
        first = new Node{data, nullptr, nullptr};
        last = first;
    }
    else
    {
        Node *tmp;
        tmp = new Node{data, nullptr, last};
        last->next = tmp;
        last = tmp;
    }
}

std::ostream &operator<<(std::ostream &os, const List &list)
{
}