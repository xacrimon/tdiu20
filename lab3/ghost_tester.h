#ifndef GHOST_TESTER_H
#define GHOST_TESTER_H

#include <string>
#include <sstream>
#include <vector>

#include "ghost.h"

class Ghost_Tester
{
public:
    Ghost_Tester();
    ~Ghost_Tester();

    Ghost_Tester(const Ghost_Tester &) = delete;
    Ghost_Tester operator=(const Ghost_Tester &) = delete;

    void run();

private:
    std::string to_draw(Point const &curr_pos) const;
    void draw_map() const;

    void command_pos(std::istringstream &args);
    void command_anger();
    void command_dir(std::istringstream &args);
    void command_color(std::istringstream &args, std::string &command);

    Pacman *pacman;
    std::vector<Ghost *> ghosts;

    bool scatter;
};

#endif