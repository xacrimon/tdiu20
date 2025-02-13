#ifndef _GHOST_H_
#define _GHOST_H_

#include "given.h"

#include <string>

class Ghost
{
public:
    Ghost(Pacman *pacman, Point position, Point scatter_point);
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
    Blinky(Pacman *pacman, Point position, Point scatter_point);
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
    Pinky(Pacman *pacman, Point position, Point scatter_point);
    virtual Point get_chase_point() const override;
    virtual std::string get_color() const override;
};

class Clyde : public Ghost
{
public:
    Clyde(Pacman *pacman, Point start_position, Point scatter_point, int threshold);

    virtual Point get_chase_point() const override;
    virtual std::string get_color() const override;

private:
    const int threshold;
};

#endif