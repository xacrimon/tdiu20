#include "ghost.h"

#include <cmath>

Ghost::Ghost(Pacman *pacman, Point position, Point scatter_point)
    : pacman{pacman}, position{position}, scatter_point{scatter_point}
{
}

void Ghost::set_position(Point pos)
{
    position = pos;
}

Point Ghost::get_position() const
{
    return position;
}

Point Ghost::get_scatter_point() const
{
    return scatter_point;
}

Blinky::Blinky(Pacman *pacman, Point position, Point scatter_point)
    : Ghost{pacman, position, scatter_point}, angry{false}
{
}

Point Blinky::get_chase_point() const
{
    return pacman->get_position();
}

Point Blinky::get_scatter_point() const
{
    if (angry)
    {
        return get_chase_point();
    }
    else
    {
        return scatter_point;
    }
}

std::string Blinky::get_color() const
{
    return std::string{"red"};
}

bool Blinky::is_angry()
{
    return angry;
}

void Blinky::set_angry(bool angry)
{
    this->angry = angry;
}

Pinky::Pinky(Pacman *pacman, Point position, Point scatter_point)
    : Ghost{pacman, position, scatter_point}
{
}

Point Pinky::get_chase_point() const
{
    return pacman->get_position() + pacman->get_direction() * 2;
}

std::string Pinky::get_color() const
{
    return std::string{"pink"};
}

Clyde::Clyde(Pacman *pacman, Point start_position, Point scatter_point, int threshold)
    : Ghost{pacman, start_position, scatter_point}, threshold{threshold}
{
}

Point Clyde::get_chase_point() const
{
    Point pos{pacman->get_position()};
    float diff_x{static_cast<float>(abs(pos.x - position.x))};
    float diff_y{static_cast<float>(abs(pos.y - position.y))};

    if (sqrt(diff_x * diff_x + diff_y * diff_y) < static_cast<float>(threshold))
    {
        return scatter_point;
    }
    else
    {
        return pos;
    }
}

std::string Clyde::get_color() const
{
    return std::string{"orange"};
}

Inky::Inky(Pacman *pacman, Blinky *blinky, Point position, Point scatter_point)
    : Ghost{pacman, position, scatter_point}, blinky{blinky}
{
}

Point Inky::get_chase_point() const
{
    Point blinky_point{blinky->get_position()};
    Point player_pos{pacman->get_position() + pacman->get_direction() * 2};
    Point chase_point{(player_pos - blinky_point) * 2 + blinky_point};

    return chase_point;
}

std::string Inky::get_color() const
{
    return std::string{"blue"};
}