#ifndef TIME_HPP
#define TIME_HPP

#include <string>
#include <iostream>

enum class TimeFormat
{
    TWENTY_FOUR_HOUR,
    TWELVE_HOUR,
};

class Time
{
public:
    Time(int hours, int minutes, int seconds);
    Time(const std::string &time);

    std::string to_string(TimeFormat format = TimeFormat::TWENTY_FOUR_HOUR) const;

    bool is_am() const;

    int get_hour() const;
    int get_minute() const;
    int get_second() const;

    Time &operator++();
    Time operator++(int);

    Time &operator--();
    Time operator--(int);

    bool operator==(const Time &rhs) const;
    bool operator!=(const Time &rhs) const;

    bool operator<(const Time &rhs) const;
    bool operator>(const Time &rhs) const;
    bool operator<=(const Time &rhs) const;
    bool operator>=(const Time &rhs) const;

    Time operator+(int rhs) const;
    Time &operator+=(int rhs);

    Time operator-(int rhs) const;
    Time &operator-=(int rhs);

private:
    int hours;
    int minutes;
    int seconds;

    int to_seconds() const;
    static Time from_seconds(int seconds);
};

std::ostream &operator<<(std::ostream &stream, const Time &time);
std::istream &operator>>(std::istream &stream, Time &time);

#endif
