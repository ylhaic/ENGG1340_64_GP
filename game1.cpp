#include "game1.h"
#include <iostream>


using namespace std;

void generatePuzzle(vector<string> &puzzle) {
  string chars = "12345678 ";
  int size = chars.size();
  srand((unsigned int)time(NULL));
  for (int i = 0; i < size; i++) {
    int index = rand() % chars.size();
    puzzle.push_back(chars.substr(index, 1));
    chars.erase(index, 1);
  }
}

void displayPuzzle(const vector<string> &puzzle) {
  cout << "\u2554";
  for (int i = 0; i < 3; i++) {
    cout << "\u2550\u2550\u2550";
    if (i < 2) {
      cout << "\u2566";
    }
  }
  cout << "\u2557\n";

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "\u2551 " << puzzle[i * 3 + j] << " ";
    }
    cout << "\u2551\n";

    if (i < 2) {
      cout << "\u2560";
      for (int j = 0; j < 3; j++) {
        cout << "\u2550\u2550\u2550";
        if (j < 2) {
          cout << "\u256C";
        }
      }
      cout << "\u2563\n";
    }
  }

  cout << "\u255A";
  for (int i = 0; i < 3; i++) {
    cout << "\u2550\u2550\u2550";
    if (i < 2) {
      cout << "\u2569";
    }
  }
  cout << "\u255D\n";
}

bool checkPuzzle(const vector<string> &puzzle) {
  string target = "12345678 ";
  return target ==
         puzzle[0] + puzzle[1] + puzzle[2] + puzzle[3] + puzzle[4] + puzzle[5] +
         puzzle[6] + puzzle[7] + puzzle[8];
}

void moveBlock(vector<string> &puzzle, int x, int y, int dx, int dy) {
  int nx = x + dx;
  int ny = y + dy;
  if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) {
    return;
  }
  int index1 = y * 3 + x;
  int index2 = ny * 3 + nx;
  puzzle[index1].swap(puzzle[index2]);
}

int getch_int() {
  struct termios oldt, newt;
  int ch;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}

bool playgame1() {
  vector<string> puzzle;
  generatePuzzle(puzzle);
  
  cout << "Welcome to the sliding puzzle game!\n";
  cout << "Objective: Arrange the numbers in ascending order, from 1 to 8, with the blank space at the end.\n";
  cout << "The puzzle consists of a 3x3 grid containing eight numbered tiles and one blank space.\n";
  cout << "You can slide the numbered tiles into the blank space to rearrange them.\n\n";
  cout << "Generated puzzle:\n";
  displayPuzzle(puzzle);
  cout << "Controls:\n";
  cout << " - W (up): Move the blank space up\n";
  cout << " - A (left): Move the blank space left\n";
  cout << " - S (down): Move the blank space down\n";
  cout << " - D (right): Move the blank space right\n";
  cout << " - Q: Quit the game (This will reduce your health points by 40)\n\n";

  while (!checkPuzzle(puzzle)) {
    int input = getch_int();

    int dx = 0;
    int dy = 0;
    if (input == 's' || input == 'S') {
      dy = -1;
    } else if (input == 'w' || input == 'W') {
      dy = 1;
    } else if (input == 'd' || input == 'D') {
      dx = -1;
    } else if (input == 'a' || input == 'A') {
      dx = 1;
    } else if (input == 'q' || input == 'Q') {
      cout << "You have quit the game. Your health points will be reduced by 40.\n";
      return false;
    } else {
      continue;
    }

    int x = -1;
    int y = -1;
    for (int i = 0; i < 9; i++) {
      if (puzzle[i] == " ") {
        x = i % 3;
        y = i / 3;
        break;
      }
    }
    moveBlock(puzzle, x, y, dx, dy);
    displayPuzzle(puzzle);
  }

  cout << "Congratulations! You solved the puzzle.\n";
  return true;
}
