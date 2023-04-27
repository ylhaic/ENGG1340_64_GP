#include "game5.h"
#include <iostream>

using namespace std;
const int BOARD_SIZE = 10;
const int NUM_MINES = 10;

class Minesweeper {
public:
Minesweeper() {
board = new char*[BOARD_SIZE];
for (int i = 0; i < BOARD_SIZE; i++) {
  board[i] = new char[BOARD_SIZE];
  for (int j = 0; j < BOARD_SIZE; j++) {
    board[i][j] = '-';
  }
}

    srand(time(NULL));
    int count = 0;
    while (count < NUM_MINES) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        if (board[row][col] != '*') {
            board[row][col] = '*';
            count++;
        }
    }
}

~Minesweeper() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        delete[] board[i];
    }
    delete[] board;
}

void printBoard() {
    // Print column labels
    cout << "   ";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << (i + 1) << "   ";
    }
    cout << endl;

    // Print the top border
    cout << " \u2554";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << "\u2550\u2550\u2550";
        if (i < BOARD_SIZE - 1) {
            cout << "\u2566";
        }
    }
    cout << "\u2557\n";

    // Print the board content and horizontal borders
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i > 0) {
            cout << " \u2560";
            for (int j = 0; j < BOARD_SIZE; j++) {
                cout << "\u2550\u2550\u2550";
                if (j < BOARD_SIZE - 1) {
                    cout << "\u256C";
                }
            }
            cout << "\u2563\n";
        }

        // Print row labels
        cout << static_cast<char>('A' + i);

        // Print board cells
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << "\u2551 " << board[i][j] << " ";
        }
        cout << "\u2551\n";
    }

    // Print the bottom border
    cout << " \u255A";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << "\u2550\u2550\u2550";
        if (i < BOARD_SIZE - 1) {
            cout << "\u2569";
        }
    }
    cout << "\u255D\n";
}
bool play() {
    while (true) {
      printBoard();

      string input;
      int row, col;
      cout << "Enter row and column (A-J)(1-10), e.g., A1: ";
      cin >> input;

      if (input.length() < 2 || input.length() > 3 || !isalpha(input[0]) || !isdigit(input[1])) {
        cout << "Invalid input. Try again." << endl;
        continue;
      }

      row = toupper(input[0]) - 'A';
      if (input.length() == 2) {
        col = input[1] - '1';
      } 
      else {
        if (!isdigit(input[2])) {
            cout << "Invalid input. Try again." << endl;
            continue;
        }
        col = (input[1] - '0') * 10 + (input[2] - '1');
      }

  


        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        if (board[row][col] == '*') {
            cout << "Game over! You hit a mine." << endl;
            board[row][col] = 'X';
            printBoard();
			return false;
            break;
        } else {
            int count = countMines(row, col);
            board[row][col] = '0' + count;

            if (count == 0) {
                revealAdjacentCells(row, col);
            }

            bool win = true;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == '-' && !(i == row && j == col)) {
                        win = false;
                        break;
                    }
                }
                if (!win) {
                    break;
                }
            }

            if (win) {
                cout << "Congratulations! You win!" << endl;
                printBoard();
                return true;
                break;
            }
        }
    }
}
private:
char** board;

int countMines(int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE) {
                if (board[i][j] == '*') {
                    count++;
                }
            }
        }
    }
    return count;
}

void revealAdjacentCells(int row, int col) {
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE) {
                if (board[i][j] == '-') {
                    int count = countMines(i, j);
                    board[i][j] = '0' + count;
                    if (count == 0) {
                        revealAdjacentCells(i, j);
                    }
                }
            }
        }
    }
}
};



bool playgame5() {
  Minesweeper game;
  return game.play();
}
