#include "ghost_tester.h"

/*
  Ledning och Tips:

  - Modifiera stukturen till en header-fil och en implementationsfil
  - Utöka 'run()' och 'draw_map()' med övrig funktionalitet.
  - Lägg alla spöken i en lämplig behållare som en datamedlem.
  - Bryt ut stora kodblock till egna funktioner.
  - Använd hjälpfunktioner för att undvika duplicering av kod.
  - Tänk på att varje funktion inte borde vara längre än 25 rader.
 */

int main()
{
    Pacman *pacman{new Pacman{}};
    Ghost_Tester gt{pacman};

    Blinky *blinky{new Blinky{pacman, Point{9, 8}, Point{WIDTH - 1, HEIGHT - 1}}};
    gt.add_ghost(blinky);
    gt.add_ghost(new Pinky{pacman, Point{2, 7}, Point{0, HEIGHT - 1}});
    gt.add_ghost(new Clyde{pacman, Point{8, 2}, Point{0, 0}, 6});
    gt.add_ghost(new Inky{pacman, blinky, Point{7, 10}, Point{WIDTH - 1, 0}});

    gt.run();
    return 0;
}
