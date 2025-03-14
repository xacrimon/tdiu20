#ifndef _GHOST_H_
#define _GHOST_H_

#include "given.h"

#include <string>

// Komplettering: Parameteröverföring av sammansatta datatyper ska om möjligt ske som konstant referens.

// Kommentar: Använd inte pekare om det inte är nödvändigt. För Pacman-medlemmen kan en referens användas.

class Ghost
{
public:
    Ghost(Pacman *pacman, const Point &position, const Point &scatter_point);
    virtual ~Ghost() = default;

    Ghost(const Ghost &) = delete;
    Ghost operator=(const Ghost &) = delete;

    virtual Point get_chase_point() const = 0;
    virtual std::string get_color() const = 0;
    virtual Point get_scatter_point() const;
    void set_position(Point pos);
    Point get_position() const;

protected:
    const Pacman *pacman;
    Point position;
    const Point scatter_point;
};

class Blinky : public Ghost
{
public:
    Blinky(Pacman *pacman, const Point &position, const Point &scatter_point);
    virtual Point get_chase_point() const override;
    virtual std::string get_color() const override;
    virtual Point get_scatter_point() const override;

    bool is_angry();
    void set_angry(bool angry);

private:
    bool angry;
};

class Pinky : public Ghost
{
public:
    Pinky(Pacman *pacman, const Point &position, const Point &scatter_point);
    virtual Point get_chase_point() const override;
    virtual std::string get_color() const override;
};

class Clyde : public Ghost
{
public:
    Clyde(Pacman *pacman, const Point &start_position, const Point &scatter_point, int threshold);

    virtual Point get_chase_point() const override;
    virtual std::string get_color() const override;

private:
    const int threshold;
};

class Inky : public Ghost
{
public:
    Inky(Pacman *pacman, Blinky *blinky, const Point &position, const Point &scatter_point);
    virtual Point get_chase_point() const override;
    virtual std::string get_color() const override;

    Inky(const Inky &) = delete;
    Inky operator=(const Inky &) = delete;

private:
    Blinky *blinky;
};

#endif