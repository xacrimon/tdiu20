#include "../lib/catch_amalgamated.hpp"
#include "time.hpp"

using namespace std;

TEST_CASE("Constructors and getters")
{
    SECTION("Integer")
    {
        Time t0{0, 0, 0};
        Time t1{12, 30, 30};
        Time t2{23, 59, 59};

        CHECK_THROWS(Time{13, 35, 60});
        CHECK_THROWS(Time{13, 60, 35});
        CHECK_THROWS(Time{24, 35, 35});

        CHECK(t0.get_hour() == 0);
        CHECK(t0.get_minute() == 0);
        CHECK(t0.get_second() == 0);
        CHECK(t1.get_hour() == 12);
        CHECK(t1.get_minute() == 30);
        CHECK(t1.get_second() == 30);
        CHECK(t2.get_hour() == 23);
        CHECK(t2.get_minute() == 59);
        CHECK(t2.get_second() == 59);
    }

    SECTION("String")
    {
        Time t0{"00:00:00"};
        Time t1{"12:30:30"};
        Time t2{"23:59:59"};

        CHECK_THROWS(Time{"13:35:60"});
        CHECK_THROWS(Time{"13:60:35"});
        CHECK_THROWS(Time{"24:35:35"});
        CHECK_THROWS(Time{"a12:bb:35"});

        CHECK(t0.get_hour() == 0);
        CHECK(t0.get_minute() == 0);
        CHECK(t0.get_second() == 0);
        CHECK(t1.get_hour() == 12);
        CHECK(t1.get_minute() == 30);
        CHECK(t1.get_second() == 30);
        CHECK(t2.get_hour() == 23);
        CHECK(t2.get_minute() == 59);
        CHECK(t2.get_second() == 59);
    }
}

TEST_CASE("is_am")
{
    Time t0{"05:00:00"};
    Time t1{"14:00:00"};
    Time t2{"12:00:00"};
    Time t3{"00:00:00"};

    CHECK(t0.is_am());
    CHECK_FALSE(t1.is_am());
    CHECK_FALSE(t2.is_am());
    CHECK(t3.is_am());
    // Fill with extra corner cases!
}

TEST_CASE("to_string")
{
    Time t0{0, 0, 0};
    Time t1{11, 59, 59};
    Time t2{12, 0, 0};
    Time t3{13, 0, 0};
    Time t4{23, 59, 59};
    SECTION("24 hour format no argument")
    {
        CHECK(t0.to_string() == "00:00:00");
        CHECK(t1.to_string() == "11:59:59");
        CHECK(t2.to_string() == "12:00:00");
        CHECK(t3.to_string() == "13:00:00");
        CHECK(t4.to_string() == "23:59:59");
        // Fill with more tests!
    }

    SECTION("24 hour format with argument")
    {
        CHECK(t0.to_string(TimeFormat::TWENTY_FOUR_HOUR) == "00:00:00");
        CHECK(t1.to_string(TimeFormat::TWENTY_FOUR_HOUR) == "11:59:59");
        CHECK(t2.to_string(TimeFormat::TWENTY_FOUR_HOUR) == "12:00:00");
        CHECK(t3.to_string(TimeFormat::TWENTY_FOUR_HOUR) == "13:00:00");
        CHECK(t4.to_string(TimeFormat::TWENTY_FOUR_HOUR) == "23:59:59");
        // Fill with more tests!
    }

    SECTION("12 hour format")
    {
        CHECK(t0.to_string(TimeFormat::TWELVE_HOUR) == "12:00:00am");
        CHECK(t1.to_string(TimeFormat::TWELVE_HOUR) == "11:59:59am");
        CHECK(t2.to_string(TimeFormat::TWELVE_HOUR) == "12:00:00pm");
        CHECK(t3.to_string(TimeFormat::TWELVE_HOUR) == "01:00:00pm");
        CHECK(t4.to_string(TimeFormat::TWELVE_HOUR) == "11:59:59pm");
        // Fill with more tests!
    }
}

// Fill with more tests of other functions and operators!

TEST_CASE("operators")
{
    SECTION("Comparison")
    {
        Time t0{0, 0, 0};
        Time t1{11, 59, 59};
        Time t2{12, 0, 0};
        Time t3{12, 0, 0};
        Time t4{23, 59, 59};

        CHECK(t0 < t1);
        CHECK_FALSE(t0 < t0);
        CHECK_FALSE(t0 > t1);
        CHECK_FALSE(t0 > t0);
        CHECK(t0 <= t1);
        CHECK(t2 <= t3);
        CHECK_FALSE(t0 >= t1);
        CHECK(t0 >= t0);
        CHECK(t2 == t3);
        CHECK_FALSE(t1 == t2);
        CHECK(t1 != t2);
        CHECK_FALSE(t2 != t3);
    }

    SECTION("Output")
    {
        ostringstream oss{};
        Time t0{23, 59, 59};
        oss << t0;
        CHECK(oss.str() == "23:59:59");
    }

    SECTION("Increment")
    {
        Time t0{23, 59, 59};
        Time t1{0, 0, 0};
        Time t3{++t0};
        CHECK(t0 == t1);
        CHECK(t3 == t1);

        Time t4{23, 59, 59};
        Time t5{0, 0, 0};
        Time t6{23, 59, 59};
        Time t7{t4++};
        CHECK(t4 == t5);
        CHECK(t7 == t6);
    }

    SECTION("Decrement")
    {
        Time t0{0, 0, 0};
        Time t1{23, 59, 59};
        Time t3{--t0};
        CHECK(t0 == t1);
        CHECK(t3 == t1);

        Time t4{0, 0, 0};
        Time t5{23, 59, 59};
        Time t6{0, 0, 0};
        Time t7{t4--};
        CHECK(t4 == t5);
        CHECK(t7 == t6);
    }

    SECTION("Addition")
    {
        Time t0{4, 29, 0};
        Time t1{4, 29, 50};
        Time t2{4, 30, 20};
        CHECK(t0 + 50 == t1);
        CHECK(t1 + 30 == t2);
    }

    SECTION("Subtraction")
    {
    }

    SECTION("String Streams")
    {
    }
}