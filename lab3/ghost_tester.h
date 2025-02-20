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

    void run();

private:
    std::string to_draw(Point const &curr_pos);
    void draw_map();

    std::unique_ptr<Pacman> pacman;
    std::vector<Ghost *> ghosts;

    bool scatter;
};