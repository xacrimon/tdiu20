#ifndef LIST_H
#define LIST_H

#include <iostream>

class List
{
public:
    List();
    List(const List&);
    List(List&&);
    ~List();

    List& operator=(const List&);   // Copy
    List& operator=(List&&);        // Move

    void insert(int data);
    void remove(int index);
    int at(int index);
private:
    struct Node
    {
        int data;
        Node* next;
        Node* previous;
    };

    Node* first;
    Node* last;
};

std::ostream& operator<<(std::ostream& os, const List& list);

#endif