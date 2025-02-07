#ifndef LIST_H
#define LIST_H

#include <optional>
#include <iostream>

namespace impl
{
    struct Node
    {
        int elem;
        Node *next;
        Node *prev;

        Node(int elem, Node *next, Node *prev)
            : elem{elem}, next{next}, prev{prev}
        {
        }
    };

    class ListIterator
    {
    public:
        using value_type = int;
        using difference_type = std::ptrdiff_t;
        using pointer = int *;
        using reference = int &;
        using iterator_category = std::bidirectional_iterator_tag;

        explicit ListIterator(Node *node);

        reference operator*() const;

        ListIterator &operator++();
        ListIterator operator++(int);

        ListIterator &operator--();
        ListIterator operator--(int);

        bool operator==(const ListIterator &rhs);
        bool operator!=(const ListIterator &rhs);

    private:
        Node *curr;
    };

    static impl::Node SENTINEL = impl::Node{0, nullptr, nullptr};
}

class List
{
public:
    using iterator = impl::ListIterator;

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

    void push_back(int elem);
    void push_front(int elem);
    std::optional<int> pop_back();
    std::optional<int> pop_front();

    void insert(int elem);
    std::optional<int> remove(int index);

    bool is_empty() const;
    int length() const;
    std::optional<int> front() const;
    std::optional<int> back() const;
    std::optional<int> at(int index) const;

    List sub(std::initializer_list<int> indices) const;

    iterator begin() const;
    iterator end() const;

private:
    impl::Node *head;
    impl::Node *tail;
    impl::Node *sentinel = &impl::SENTINEL;
};

std::ostream &operator<<(std::ostream &os, const List &list);

#endif
