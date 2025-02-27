#include "game.h"

#include "ghost.h"

Game::Game()
    : grid{"map.txt"},
      pacman {{200, 340}, grid},
      ghosts {},
      window {sf::VideoMode {static_cast<unsigned>(SCREEN_WIDTH), static_cast<unsigned>(SCREEN_HEIGHT)}, "Pacman" }
{
    // Lägger till tre dynamiskt allokerade spöken i en vektor.
    // Ett spökes konstruktor tar argumenten (pacman, startposition, scatterposition, + speciella argument). 
    ghosts.emplace_back(sf::Vector2f{360,  40}, grid, new Blinky{pacman, Point{}, Point{WIDTH, 0}});
    ghosts.emplace_back(sf::Vector2f{40 ,  40}, grid, new Pinky {pacman, Point{}, Point{0, 0}});
    ghosts.emplace_back(sf::Vector2f{360, 420}, grid, new Clyde{pacman, Point{}, Point{0, HEIGHT}, 8});
    window.setFramerateLimit(FPS);
}

void Game::run()
{
    bool running {true};
    while (running)
    {
        window.clear();
            
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                running = false;
            }
        }

        update();
        draw();

        if (check_collision())
        {
            std::cout << "Du kolliderade med ett spöke..." << std::endl;
            running = false;
        }

        if (grid.food_count() == 0)
        {
            std::cout << "Du åt upp all mat! Bra jobbat!!" << std::endl;
            running = false;
        }
    }
}

void Game::update()
{
    pacman.update();
    
    for (Ghost_Wrapper & g : ghosts)
    {
        g.update();
    }
}

bool Game::check_collision() const
{
    for (Ghost_Wrapper const& g : ghosts)
    {
        if (pacman.getGlobalBounds().intersects(g.getGlobalBounds()))
        {
            return true;
        }
    }
    return false;
}

void Game::draw()
{
    grid.draw(window);
    window.draw(pacman);
    for (Ghost_Wrapper const& g : ghosts)
    {
        window.draw(g);
    }
    
    window.display();      
}

int Game::get_score()
{
    return pacman.get_score();
}
