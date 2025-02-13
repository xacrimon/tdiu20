// TODO: skydd för dubbel inkludering

/*
  I denna fil finns ett utval av kod från det dina kollegor skrivit till ert pacman-projekt. Det är
  precis det som du behöver för att skriva din del av koden.

  Tips: Du får utöka denna fil med saker som du behöver för att ditt program ska kompilera. Det är
  även okej att utöka Point med fler operatorer om det skulle behövas.
 */

#include <stdexcept>
#include <iostream>

/*
  Globala variabler för storlek på spelplanen.

  Din kollega som skrev detta är medveten om att globala variabler är dåligt och borde undvikas, men
  har inte haft tid att åtgärda det. I den slutgiltiga versionen av koden borde dessa såklart läsas
  från en fil med konfigurationsdata.
 */
extern int WIDTH;
extern int HEIGHT;

/*
  Ett aggregat som använd för att representera punkter och riktninar på spelplanen.
  Aggregatet har också hjälpsamma operatorer som kan underlätta din implementation.

 */
struct Point
{
  int x;
  int y;
};
bool operator==(Point const &lhs, Point const &rhs);
Point operator+(Point const &lhs, Point const &rhs);
Point operator*(Point const &lhs, int rhs);
std::istream &operator>>(std::istream &is, Point &rhs);

/*
  En klass för att representera spelarfiguren. Detta är en nedskalad version jämfört med det som
  kollegan skrev till spelet. Notera att din kod inte behöver ändras om man skulle gå från denna
  implementaion till den faktiska implementationen.
 */
class Pacman
{
public:
  Pacman();

  Point get_position() const;
  void set_position(Point const &p);

  Point get_direction() const;
  void set_direction(Point const &p);

private:
  Point pos{};
  Point dir{};
};
