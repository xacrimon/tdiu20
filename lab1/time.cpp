#include <string>
#include <iostream>

#include "time.hpp"

Time::Time(int hour, int minute, int second) : secs{hour * 3600 + minute * 60 + second} {}
Time::Time(const std::string& time) : secs{0} {
    // TODO
}

std::string Time::to_string(TimeFormat format) const {}

bool Time::is_am() const {}

int Time::get_hour() const {}
int Time::get_minute() const {}
int Time::get_second() const {}

Time& Time::operator++() {}
Time Time::operator++(int) const {}

Time& Time::operator--() {}
Time Time::operator--(int) const {}

bool Time::operator==(const Time& rhs) const {}
bool Time::operator!=(const Time& rhs) const {}

bool Time::operator<(const Time& rhs) const {}
bool Time::operator>(const Time& rhs) const {}
bool Time::operator<=(const Time& rhs) const {}
bool Time::operator>=(const Time& rhs) const {}

Time Time::operator+(const Time& rhs) const {}
Time& Time::operator+=(const Time& rhs) {}

Time Time::operator-(const Time& rhs) const {}
Time& Time::operator-=(const Time& rhs) {}

std::ostream& operator<<(std::ostream& stream, const Time& time) {}
std::ostream& operator>>(std::ostream& stream, const Time& time) {}
