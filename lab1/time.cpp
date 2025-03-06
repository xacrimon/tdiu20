#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <stdexcept>

// Komplettering: Kasta alltid ett faktiskt undantag.

#include "time.h"

const int SECONDS_PER_DAY{24 * 60 * 60};

Time::Time()
    : hours{0}, minutes{0}, seconds{0}
{
}

Time::Time(int hours, int minutes, int seconds)
    : hours{hours}, minutes{minutes}, seconds{seconds}
{
    if (hours > 23 || hours < 0 || minutes > 59 || minutes < 0 || seconds > 59 || seconds < 0)
    {
        throw std::logic_error("Ogiltigt tidsformat!");
    }
}

Time::Time(const std::string &time)
    : hours{0}, minutes{0}, seconds{0}
{
    std::stringstream ss{time};

    std::string token{};
    std::vector<std::string> tokens{};

    while (std::getline(ss, token, ':'))
    {
        tokens.push_back(token);
    }

    hours = stoi(tokens[0]);
    minutes = stoi(tokens[1]);
    seconds = stoi(tokens[2]);

    if (hours > 23 || hours < 0 || minutes > 59 || minutes < 0 || seconds > 59 || seconds < 0)
    {
        throw std::logic_error("Ogiltigt tidsformat!");
    }
}

std::string Time::to_string(TimeFormat format) const
{
    std::stringstream ss{};

    int conv_hours{hours};
    if (format == TimeFormat::TWELVE_HOUR)
    {
        conv_hours %= 12;
        if (hours == 0 || hours == 12)
        {
            conv_hours = 12;
        }
    }

    ss << std::setw(2) << std::setfill('0') << conv_hours << ':'
       << std::setw(2) << minutes << ':'
       << std::setw(2) << seconds;

    if (format == TimeFormat::TWELVE_HOUR)
    {
        if (hours >= 12)
        {
            ss << "pm";
        }
        else
        {
            ss << "am";
        }
    }

    return ss.str();
}

bool Time::is_am() const
{
    return hours < 12;
}

int Time::get_hour() const
{
    return hours;
}

int Time::get_minute() const
{
    return minutes;
}

int Time::get_second() const
{
    return seconds;
}

Time &Time::operator++()
{
    return *this += 1;
}

Time Time::operator++(int)
{
    Time old{*this};
    *this += 1;
    return old;
}

Time &Time::operator--()
{
    return *this -= 1;
}

Time Time::operator--(int)
{
    Time old{*this};
    *this -= 1;
    return old;
}

bool Time::operator==(const Time &rhs) const
{
    return hours == rhs.hours && minutes == rhs.minutes && seconds == rhs.seconds;
}

bool Time::operator!=(const Time &rhs) const
{
    return !(*this == rhs);
}

bool Time::operator<(const Time &rhs) const
{
    return this->to_seconds() < rhs.to_seconds();
}

bool Time::operator>(const Time &rhs) const
{
    return this->to_seconds() > rhs.to_seconds();
}

bool Time::operator<=(const Time &rhs) const
{
    return this->to_seconds() <= rhs.to_seconds();
}

bool Time::operator>=(const Time &rhs) const
{
    return this->to_seconds() >= rhs.to_seconds();
}

Time Time::operator+(int rhs) const
{
    return from_seconds(this->to_seconds() + rhs);
}

Time &Time::operator+=(int rhs)
{
    *this = from_seconds(this->to_seconds() + rhs);
    return *this;
}

Time Time::operator-(int rhs) const
{
    return from_seconds(this->to_seconds() - rhs);
}

Time &Time::operator-=(int rhs)
{
    *this = from_seconds(this->to_seconds() - rhs);
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Time &time)
{
    stream << time.to_string();
    return stream;
}

std::istream &operator>>(std::istream &stream, Time &time)
{
    std::string s{};
    char c;

    for (int i{0}; i < 8; i++)
    {
        stream >> c;
        s += c;
    }

    time = Time{s};

    return stream;
}

int Time::to_seconds() const
{
    return 3600 * hours + 60 * minutes + seconds;
}

Time from_seconds(int sum)
{
    sum %= SECONDS_PER_DAY;
    if (sum < 0)
    {
        sum = SECONDS_PER_DAY + sum;
    }

    int hours{sum / 3600};
    sum -= hours * 3600;
    int minutes{sum / 60};
    sum -= minutes * 60;
    int seconds{sum};

    return Time{hours, minutes, seconds};
}