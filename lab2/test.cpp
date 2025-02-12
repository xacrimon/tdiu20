#include "../lib/catch_amalgamated.hpp"
#include "list.h"

#include <string>
#include <iostream>

std::string to_string(const List &l)
{
    std::stringstream ss;
    ss << l;
    return ss.str();
}

TEST_CASE("list")
{
    List l1;
    CHECK(l1.length() == 0);

    l1.insert(1);
    CHECK(l1.length() == 1);

    l1.insert(2);
    CHECK(l1.length() == 2);

    CHECK(l1.front().value() == 1);
    CHECK(l1.back().value() == 2);

    l1 = List{3, 4, 5, 6, 7, 8, 9};
    CHECK(l1.length() == 7);

    CHECK(l1.at(2).value() == 5);
    CHECK(l1.at(5).value() == 8);

    auto sub = l1.sub({1, 3, 5});
    CHECK(sub.length() == 3);
    CHECK(sub.at(0).value() == 4);
    CHECK(sub.at(1).value() == 6);
    CHECK(sub.at(2).value() == 8);

    CHECK(to_string(l1) == "[3, 4, 5, 6, 7, 8, 9]");
    CHECK(to_string(sub) == "[4, 6, 8]");

    l1.insert(13);
    CHECK(l1.back() == 13);

    l1.insert(6);
    l1.insert(8);
    CHECK(to_string(l1) == "[3, 4, 5, 6, 6, 7, 8, 8, 9, 13]");

    List l2;
    l2.insert(3);
    l2.insert(75);
    l2.insert(13);
    l2.insert(1);
    CHECK(to_string(l2) == "[1, 3, 13, 75]");

    l2.remove(2);
    CHECK(to_string(l2) == "[1, 3, 75]");

    l1.remove(1);
    CHECK(to_string(l1) == "[3, 5, 6, 6, 7, 8, 8, 9, 13]");

    l1.remove(0);
    CHECK(to_string(l1) == "[5, 6, 6, 7, 8, 8, 9, 13]");

    l1.remove(7);
    CHECK(to_string(l1) == "[5, 6, 6, 7, 8, 8, 9]");

    SECTION("Copy constructor")
    {
        List l1{4, 5};
        List l2{l1};

        CHECK(to_string(l1) == to_string(l2));
        l2.insert(7);
        CHECK_FALSE(to_string(l1) == to_string(l2));
    }

    SECTION("Move constructor")
    {
        List l1{4, 5};
        List l2{std::move(l1)};

        CHECK(to_string(l2) == "[4, 5]");
        CHECK(l1.is_empty());
    }

    SECTION("Copy assignment")
    {
        List l1{4, 5};
        List l2{};
        l2 = l1;

        CHECK(to_string(l1) == to_string(l2));
        l2.insert(7);
        CHECK_FALSE(to_string(l1) == to_string(l2));
    }

    SECTION("Move assignment")
    {
        List l1{4, 5};
        List l2{};
        l2 = std::move(l1);

        CHECK(to_string(l2) == "[4, 5]");
        CHECK(l1.is_empty());
    }
}
