#ifndef LIST_H
#define LIST_H

#include <iostream>

class List
{
public:
    List();
    List(const List &other);
    List(List &&other);
    ~List();

    List &operator=(const List &rhs);
    List &operator=(List &&rhs);

    void insert(int data);
    void remove(int index);
    int at(int index) const;

    void push_back(int data);

private:
    struct Node
    {
        int data;
        Node *next;
        Node *previous;

        Node(int data, Node *next, Node *previous)
            : data{data}, next{next}, previous{previous}
        {
        }
    };

    Node *first;
    Node *last;
};

std::ostream &operator<<(std::ostream &os, const List &list);

#endif