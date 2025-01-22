#ifndef TIME_HPP
#define TIME_HPP

#include <string>
#include <iostream>

enum class TimeFormat
{
    TWENTYY_FOUR_HOUR,
    TWELVE_HOUR,
};

class Time
{
public:
    Time(int hour, int minute, int second);
    Time(const std::string& time);

    std::string to_string(TimeFormat format) const;

    bool is_am() const;

    int get_hour() const;
    int get_minute() const;
    int get_second() const;

    Time& operator++();
    Time operator++(int) const;

    Time& operator--();
    Time operator--(int) const;

    bool operator==(const Time& rhs) const;
    bool operator!=(const Time& rhs) const;

    bool operator<(const Time& rhs) const;
    bool operator>(const Time& rhs) const;
    bool operator<=(const Time& rhs) const;
    bool operator>=(const Time& rhs) const;

    Time operator+(const Time& rhs) const;
    Time& operator+=(const Time& rhs);
    Time operator-(const Time& rhs) const;
    Time& operator-=(const Time& rhs);

private:
    int secs;
};

std::ostream& operator<<(std::ostream& stream, const Time& time);
std::ostream& operator>>(std::ostream& stream, const Time& time);

#endif
