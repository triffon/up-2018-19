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

/*
  Проверява за колко стъпки можем да стигнем до съкровището от текущата позиция
  Връща -1, ако не е възможно да се стигне до него.
*/
int findTreasureMoves(char labyrinth[][MAX], int row, int col, int& trow, int& tcol) {
  // някой ни е пуснал на позиция (row,col)
  // мога ли въобще да стъпя тук?
  cout << "Можем ли да стъпим на позиция (" << row << ", " << col << ")? ";
  if (row < 0 || col < 0 ||          // излизаме извън лабиринта на север или запад
      labyrinth[row][col] == '\0' || // излизаме извън лабиринта на юг или изток
      labyrinth[row][col] == '*'  ||  // има стена
      labyrinth[row][col] == '.') {  // има троха

    cout << "не!" << endl;
    // отказваме се
    return -1;
  }
  cout << "да!" << endl;
  if (labyrinth[row][col] == '$') { // намерихме съкровището!
    trow = row;
    tcol = col;
    return 0;
  }
  // стъпваме в лабиринта!
  labyrinth[row][col] = '.';
  // трябва да опитаме посоките една по една
  // север
  cout << "Пробваме да тръгнем на север" << endl;
  int moves = findTreasureMoves(labyrinth, row - 1, col    , trow, tcol);
  if (moves > -1)
    return moves + 1;
  // изток
  cout << "Пробваме да тръгнем на изток" << endl;
  moves = findTreasureMoves(labyrinth, row    , col + 1, trow, tcol);
  if (moves > -1)
    return moves + 1;
  // юг
  cout << "Пробваме да тръгнем на юг" << endl;
  moves = findTreasureMoves(labyrinth, row + 1, col    , trow, tcol);
  if (moves > -1)
    return moves + 1;
  // запад
  cout << "Пробваме да тръгнем на запад" << endl;
  moves = findTreasureMoves(labyrinth, row    , col - 1, trow, tcol);
  if (moves > -1)
    return moves + 1;
  cout << "Не можем да стигнем до съкровището в нито една от посоките!" << endl;
  return -1;
}

const int MAX_PATH = MAX * MAX;

/*
  Записва в масива path пътя до съкровището от текущата позиция
  (row, col) е текущата позиция
  currentMoves е текущият брой стъпки, който сме направили до момента
  Връща -1, ако не е възможно да се стигне до него.
*/
int findTreasurePath(char labyrinth[][MAX], int row, int col, int& trow, int& tcol, int path[2][MAX_PATH], int currentMoves) {
  // някой ни е пуснал на позиция (row,col)
  // мога ли въобще да стъпя тук?
  cout << "Можем ли да стъпим на позиция (" << row << ", " << col << ")? ";
  if (row < 0 || col < 0 ||          // излизаме извън лабиринта на север или запад
      labyrinth[row][col] == '\0' || // излизаме извън лабиринта на юг или изток
      labyrinth[row][col] == '*'  ||  // има стена
      labyrinth[row][col] == '.') {  // има троха

    cout << "не!" << endl;
    // отказваме се
    return -1;
  }
  cout << "да!" << endl;
  // стъпваме в лабиринта!
  // добавяме текущата позиция в пътя
  // тя трябва да се запише в колоната с индекс currentMoves
  path[0][currentMoves] = row;
  path[1][currentMoves] = col;
  if (labyrinth[row][col] == '$') { // намерихме съкровището!
    trow = row;
    tcol = col;
    return 0;
  }
  // пускаме "трохичка", за да знаем да не минаваме оттук втори път
  labyrinth[row][col] = '.';
  // трябва да опитаме посоките една по една
  // север
  cout << "Пробваме да тръгнем на север" << endl;
  int moves = findTreasurePath(labyrinth, row - 1, col    ,
                               trow, tcol, path, currentMoves + 1);
  if (moves > -1)
    return moves + 1;
  // изток
  cout << "Пробваме да тръгнем на изток" << endl;
  moves = findTreasurePath(labyrinth, row    , col + 1,
                            trow, tcol, path, currentMoves + 1);
  if (moves > -1)
    return moves + 1;
  // юг
  cout << "Пробваме да тръгнем на юг" << endl;
  moves = findTreasurePath(labyrinth, row + 1, col    ,
                            trow, tcol, path, currentMoves + 1);
  if (moves > -1)
    return moves + 1;
  // запад
  cout << "Пробваме да тръгнем на запад" << endl;
  moves = findTreasurePath(labyrinth, row    , col - 1,
                            trow, tcol, path, currentMoves + 1);
  if (moves > -1)
    return moves + 1;
  cout << "Не можем да стигнем до съкровището в нито една от посоките!" << endl;
  return -1;
}

void printPath(int path[2][MAX_PATH], int length) {
  for(int i = 0; i < length; i++)
    cout << "(" << path[0][i] << ", " << path[1][i] << ") ";
  cout << endl;
}

void testLabyrinth() {
  char labyrinth[MAX][MAX] = { "* ** ",
                               "     ",
                               " ***$",
                               "    *",
                               "  ** " };
  int startrow = 4, startcol = 1;
  int treasurerow, treasurecol;
  int path[2][MAX_PATH];
  int moves = findTreasurePath(labyrinth, startrow, startcol, treasurerow, treasurecol, path, 0);
  if (moves > -1) {
    cout << "Намерихме съкровището на позиция (" << treasurerow << ", " << treasurecol << ") за " << moves << " стъпки!" << endl;
    cout << "Пътят до съкровището е: ";
    printPath(path, moves + 1);
  }
  else
    cout << "Не успяхме да намерим съкровище" << endl;
}

int main() {
  testLabyrinth();
  return 0;
}
