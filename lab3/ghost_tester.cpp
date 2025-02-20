#include "ghost_tester.h"

Ghost_Tester::Ghost_Tester()
    : pacman{}, ghosts{}, scatter{false}
{
    pacman = new Pacman{};
    ghosts.push_back(new Blinky{pacman, Point{9, 8}, Point{WIDTH - 1, HEIGHT - 1}});
    ghosts.push_back(new Pinky{pacman, Point{2, 7}, Point{0, HEIGHT - 1}});
    ghosts.push_back(new Clyde{pacman, Point{8, 2}, Point{0, 0}, 6});
}

Ghost_Tester::~Ghost_Tester()
{
    for (Ghost *ghost : ghosts)
    {
        delete ghost;
    }
}

void Ghost_Tester::run()
{
    while (true)
    {
        draw_map();
        std::cout << "> ";

        std::string line{};
        std::getline(std::cin, line);
        std::istringstream iss{line};

        std::string command{};
        iss >> command;

        if (command == "pos")
        {
            command_pos(iss);
        }
        else if (command == "scatter")
        {
            scatter = true;
        }
        else if (command == "chase")
        {
            scatter = false;
        }
        else if (command == "anger")
        {
            command_anger();
        }
        else if (command == "dir")
        {
            command_dir(iss);
        }
        else if (command == "red" || command == "pink" || command == "orange")
        {
            command_color(iss, command);
        }
        else if (command == "quit")
        {
            break;
        }
    }
}

void Ghost_Tester::command_pos(std::istringstream &args)
{
    Point new_pos{};
    args >> new_pos.x >> new_pos.y;
    pacman->set_position(new_pos);
}

void Ghost_Tester::command_anger()
{
    for (std::size_t i{0}; i < ghosts.size(); ++i)
    {
        Blinky *b{dynamic_cast<Blinky *>(ghosts.at(i))};
        if (b != nullptr)
        {
            b->set_angry(true);
        }
    }
}

void Ghost_Tester::command_dir(std::istringstream &args)
{
    Point new_dir{};
    args >> new_dir.x >> new_dir.y;
    pacman->set_direction(new_dir);
}

void Ghost_Tester::command_color(std::istringstream &args, std::string &command)
{
    for (Ghost *ghost : ghosts)
    {
        if (ghost->get_color() == command)
        {
            Point new_pos{};
            args >> new_pos.x >> new_pos.y;
            ghost->set_position(new_pos);
        }
    }
}

/*
  En hjälpfunktion som avgör vilka två tecken som ska ritas ut för en given position på
  spelplanen.
*/
std::string Ghost_Tester::to_draw(Point const &curr_pos)
{
    std::string to_draw{"  "};

    if (pacman->get_position() == curr_pos)
    {
        to_draw[1] = '@';
    }

    for (const Ghost *ghost : ghosts)
    {
        if (ghost->get_position() == curr_pos)
        {
            auto c = ghost->get_color()[0];
            to_draw[0] = toupper(c);
        }

        if (scatter)
        {
            if (ghost->get_scatter_point() == curr_pos)
            {
                auto c = ghost->get_color()[0];
                to_draw[0] = tolower(c);
            }
        }
        else
        {
            if (ghost->get_chase_point() == curr_pos)
            {
                auto c = ghost->get_color()[0];
                to_draw[0] = tolower(c);
            }
        }
    }

    return to_draw;
}

/*
  En hjälpfunktion för att rita ut spelplanen för testprogrammet.

  Itererar över varje rad och column i kartan. Index för raderna är flippade för att placera
  y = 0 längst ned.

  Varje punkt i kartan ritas som två tecken eftersom ett tecken i terminalen är ca dubbelt så
  högt som det är brett.
*/
void Ghost_Tester::draw_map()
{
    std::cout << "+" << std::setfill('-') << std::setw(WIDTH * 2) << "-" << "+\n";

    for (int y{HEIGHT - 1}; y >= 0; --y)
    {
        std::cout << "|";
        for (int x{}; x < WIDTH; ++x)
        {
            std::cout << to_draw(Point{x, y});
        }
        std::cout << "|\n";
    }

    std::cout << "+" << std::setfill('-') << std::setw(WIDTH * 2) << "-" << "+" << std::endl;
}