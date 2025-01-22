#include <string>
#include <iostream>

#include "time.hpp"

Time::Time(int hour, int minute, int second) : secs{hour * 3600 + minute * 60 + second} {}
Time::Time(const std::string& time) : secs{0} {
    // TODO
}
