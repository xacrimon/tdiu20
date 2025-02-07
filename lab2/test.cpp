#include "../lib/catch_amalgamated.hpp"
#include "list.h"

TEST_CASE("list")
{
    List l1;
    CHECK(l1.length() == 0);

    l1.push_back(1);
    CHECK(l1.length() == 1);

    l1.push_front(2);
    CHECK(l1.length() == 2);

    CHECK(l1.back().value() == 1);
    CHECK(l1.front().value() == 2);

    l1 = List{3, 4, 5, 6, 7, 8, 9};
    CHECK(l1.length() == 7);
}
