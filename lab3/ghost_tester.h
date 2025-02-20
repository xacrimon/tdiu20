#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>

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
    std::string to_draw(Point const &curr_pos);
    void draw_map();

    void command_pos(std::istringstream &args);
    void command_anger();
    void command_dir(std::istringstream &args);
    void command_color(std::istringstream &args, std::string &command);

    Pacman *pacman;
    std::vector<Ghost *> ghosts;

    bool scatter;
};