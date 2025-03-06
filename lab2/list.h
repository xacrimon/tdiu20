#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

class List
{
public:
    List();
    List(std::initializer_list<int> elems);

    // special: copy constructor
    List(List const &other);
    // special: copy assignment
    List &operator=(List const &rhs);
    // special: destructor
    ~List();
    // special: move constructor
    List(List &&other);
    // special: move assignment
    List &operator=(List &&rhs);

    void insert(int elem);
    void remove(int index);

    bool is_empty() const;
    int length() const;
    int front() const;
    int back() const;
    int at(int index) const;

    std::string to_string() const;

    List sub(std::initializer_list<int> indices) const;

private:
    struct Node
    {
        int elem;
        Node *next;
        Node *prev;
    };

    void push_back(int elem);
    int pop_back();
    void add_node(Node *curr_node, Node *new_node);
    void remove_node(Node *node);
    Node *self_referencing();

    Node *sentinel;
};

std::ostream &operator<<(std::ostream &os, const List &list);

#endif
