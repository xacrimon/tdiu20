#include "../lib/catch.hpp"
#include "list.h"

TEST_CASE("list")
{
    List l1;
    CHECK(l1.length() == 0);

    l1.insert(1);
    CHECK(l1.length() == 1);

    l1.insert(2);
    CHECK(l1.length() == 2);

    CHECK(l1.front() == 1);
    CHECK(l1.back() == 2);

    l1 = List{3, 4, 5, 6, 7, 8, 9};
    CHECK(l1.length() == 7);

    CHECK(l1.at(2) == 5);
    CHECK(l1.at(5) == 8);

    auto sub = l1.sub({1, 3, 5});
    CHECK(sub.length() == 3);
    CHECK(sub.at(0) == 4);
    CHECK(sub.at(1) == 6);
    CHECK(sub.at(2) == 8);

    CHECK(l1.to_string() == "[3, 4, 5, 6, 7, 8, 9]");
    CHECK(sub.to_string() == "[4, 6, 8]");

    l1.insert(13);
    CHECK(l1.back() == 13);

    l1.insert(6);
    l1.insert(8);
    CHECK(l1.to_string() == "[3, 4, 5, 6, 6, 7, 8, 8, 9, 13]");

    List l2;
    l2.insert(3);
    l2.insert(75);
    l2.insert(13);
    l2.insert(1);
    CHECK(l2.to_string() == "[1, 3, 13, 75]");

    l2.remove(2);
    CHECK(l2.to_string() == "[1, 3, 75]");

    l1.remove(1);
    CHECK(l1.to_string() == "[3, 5, 6, 6, 7, 8, 8, 9, 13]");

    l1.remove(0);
    CHECK(l1.to_string() == "[5, 6, 6, 7, 8, 8, 9, 13]");

    l1.remove(7);
    CHECK(l1.to_string() == "[5, 6, 6, 7, 8, 8, 9]");

    SECTION("Copy constructor")
    {
        List l1{4, 5};
        List l2{l1};

        CHECK(l1.to_string() == l2.to_string());
        l2.insert(7);
        CHECK_FALSE(l1.to_string() == l2.to_string());
    }

    SECTION("Move constructor")
    {
        List l1{4, 5};
        List l2{std::move(l1)};

        CHECK(l2.to_string() == "[4, 5]");
        CHECK(l1.is_empty());
    }

    SECTION("Copy assignment")
    {
        List l1{4, 5};
        List l2{};
        l2 = l1;

        CHECK(l1.to_string() == l2.to_string());
        l2.insert(7);
        CHECK_FALSE(l1.to_string() == l2.to_string());
    }

    SECTION("Move assignment")
    {
        List l1{4, 5};
        List l2{};
        l2 = std::move(l1);

        CHECK(l2.to_string() == "[4, 5]");
        CHECK(l1.is_empty());
    }
}
