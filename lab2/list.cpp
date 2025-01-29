#include "list.h"

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

List::List(List && other)
    : first{other.first}, last{other.last}
{
    other.first = nullptr;
    other.last = nullptr;
}

List::~List()
{
}

List &List::operator=(const List &)
{
}

List &List::operator=(List &&)
{
}

void List::insert(int data)
{
}

void List::remove(int index)
{
}

int List::at(int index) const
{
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