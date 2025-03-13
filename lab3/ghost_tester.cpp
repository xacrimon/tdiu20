#include "ghost_tester.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>

// Komplettering: Testprogrammet ska vara generellt och hantera ett godtyckligt antal spöken.
// Kommentar: Det är generellt sätt bra att bryta ut funktioner som ni gör för
// att flytta spöken if-satsen innan ni kör kommandot gör dock så att man måste
// uppdatera den varje man lägger till ett nytt spöke. Gör ni inte den checken
// i for-loopen?

// Komplettering: Kodupprepning i funktionerna för pos, dir och flytta spöken.

// Kommentar: Om man kan göra en range-based for loop istället för en vanlig
// for loop så bör man göra det då det är säkrare (i command_anger())

Ghost_Tester::Ghost_Tester(Pacman *pacman)
    : pacman{pacman}, ghosts{}, scatter{false}
{
}

Ghost_Tester::~Ghost_Tester()
{
    for (Ghost *ghost : ghosts)
    {
        delete ghost;
    }

    delete pacman;
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
        else if (command == "quit")
        {
            break;
        }
        else
        {
            command_color(iss, command);
        }
    }
}

void Ghost_Tester::add_ghost(Ghost *ghost)
{
    for (Ghost *ghost_ : ghosts)
    {
        if (ghost_->get_color() == ghost->get_color())
        {
            throw std::runtime_error("Spöket finns redan i testprogrammet!");
        }
    }

    ghosts.push_back(ghost);
}

void Ghost_Tester::command_pos(std::istringstream &args)
{
    pacman->set_position(get_point(args));
}

void Ghost_Tester::command_anger()
{
    for (Ghost *ghost : ghosts)
    {
        Blinky *b{dynamic_cast<Blinky *>(ghost)};
        if (b != nullptr)
        {
            b->set_angry(true);
        }
    }
}

void Ghost_Tester::command_dir(std::istringstream &args)
{
    pacman->set_direction(get_point(args));
}

void Ghost_Tester::command_color(std::istringstream &args, std::string &command)
{
    for (Ghost *ghost : ghosts)
    {
        if (ghost->get_color() == command)
        {
            ghost->set_position(get_point(args));
        }
    }
}

Point Ghost_Tester::get_point(std::istringstream &args)
{
    Point point{};
    args >> point.x >> point.y;
    return point;
}

/*
  En hjälpfunktion som avgör vilka två tecken som ska ritas ut för en given position på
  spelplanen.
*/
std::string Ghost_Tester::to_draw(Point const &curr_pos) const
{
    std::string to_draw{"  "};

    if (pacman->get_position() == curr_pos)
    {
        to_draw[1] = '@';
    }

    for (const Ghost *ghost : ghosts)
    {
        char c{ghost->get_color()[0]};
        Point search_point{};

        if (scatter)
        {
            search_point = ghost->get_scatter_point();
        }
        else
        {
            search_point = ghost->get_chase_point();
        }

        if (search_point == curr_pos)
        {
            to_draw[0] = c;
        }

        if (ghost->get_position() == curr_pos)
        {
            to_draw[0] = toupper(c);
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
void Ghost_Tester::draw_map() const
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