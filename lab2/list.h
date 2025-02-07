#ifndef LIST_H
#define LIST_H

#include <iostream>

class List
{
public:
    List();

    // special: copy constructor
    List(List const& other);
    // special: copy assignment
    List& operator=(List const& rhs);
    // special: destructor
    ~List();
    // special: move constructor
    List(List && other);
    // special: move assignment
    List& operator=(List && rhs);

    void push_back(int elem);
    void push_front(int elem);
    int pop_back();
    int pop_front();

    void insert(int elem);
    int remove(int index);

    void front() const;
    void back() const;
    int at(int index) const;
private:
    struct Node
    {
        int elem;
        Node* next;
        Node* prev;

        Node(int elem, Node* next, Node* prev)
            : elem{elem}, next{next}, prev{prev}
        {
        }
    };

    Node* head;
    Node* tail;
    const Node* sentinel = new Node{0, nullptr, nullptr};
};

std::ostream &operator<<(std::ostream &os, const List &list);

#endif
