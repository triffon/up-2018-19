#include <iostream>
using namespace std;

const int MAX = 100;

bool findTreasure(char labyrinth[][MAX], int row, int col, int& trow, int& tcol) {
  // някой ни е пуснал на позиция (row,col)
  // мога ли въобще да стъпя тук?
  cout << "Можем ли да стъпим на позиция (" << row << ", " << col << ")? ";
  if (row < 0 || col < 0 ||          // излизаме извън лабиринта на север или запад
      labyrinth[row][col] == '\0' || // излизаме извън лабиринта на юг или изток
      labyrinth[row][col] == '*'  ||  // има стена
      labyrinth[row][col] == '.') {  // има троха

    cout << "не!" << endl;
    // отказваме се
    return false;
  }
  cout << "да!" << endl;
  if (labyrinth[row][col] == '$') { // намерихме съкровището!
    trow = row;
    tcol = col;
    return true;
  }
  // стъпваме в лабиринта!
  labyrinth[row][col] = '.';
  // трябва да опитаме посоките една по една
  // север
  cout << "Пробваме да тръгнем на север" << endl;
  if (findTreasure(labyrinth, row - 1, col    , trow, tcol))
    return true;
  // изток
  cout << "Пробваме да тръгнем на изток" << endl;
  if (findTreasure(labyrinth, row    , col + 1, trow, tcol))
    return true;
  // юг
  cout << "Пробваме да тръгнем на юг" << endl;
  if (findTreasure(labyrinth, row + 1, col    , trow, tcol))
    return true;
  // запад
  cout << "Пробваме да тръгнем на запад" << endl;
  if (findTreasure(labyrinth, row    , col - 1, trow, tcol))
    return true;
  cout << "Не можем да стигнем до съкровището в нито една от посоките!" << endl;
  return false;
}

void testLabyrinth() {
  char labyrinth[MAX][MAX] = { "* ** ",
                               "     ",
                               " ***$",
                               "    *",
                               "  ** " };
  int startrow = 4, startcol = 1;
  int treasurerow, treasurecol;
  if (findTreasure(labyrinth, startrow, startcol, treasurerow, treasurecol))
    cout << "Намерихме съкровището на позиция (" << treasurerow << ", " << treasurecol << ")!" << endl;
  else
    cout << "Не успяхме да намерим съкровище" << endl;
}

int main() {
  testLabyrinth();
  return 0;
}
