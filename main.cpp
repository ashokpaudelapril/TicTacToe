// File Name: main.cpp
//
// Author: Ashok Paudel
// Collaborators: None
// Date: 15 Apr, 2024
// Assignment Number: PA#6
// CS 2308 Spring 2024
//
// Description: 
// This program implements a simple console-based Tic-Tac-Toe game.
// It allows two players to take turns making moves on a 3x3 grid 
// until one player wins or the game ends in a draw. Players 
// can make moves by entering coordinates or undoing their last 
// move. The game state is displayed after each move.

#include "GameState.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
  Move move;
  int draw_indication = 1;
  bool winner = false;
  string command;
  GameState TicTacToe;
  int player = 0;
  TicTacToe.displayBoardState(cout);
  while (draw_indication != 0 && !winner)
  {
    player = TicTacToe.getCurrentPlayer();
    cout << "Player " << TicTacToe.getCurrentPlayer() << " make a turn."
         << endl;
    cin >> command;
    if (command == "undo")
    {
      bool result = TicTacToe.undoLast();
      if (!result)
      {
        cout << "No moves to undo." << endl;
      }
      else
      {
        TicTacToe.displayBoardState(cout);
      }
    }
    else if (command == "move")
    {
      cin >> move.x >> move.y;
      draw_indication = TicTacToe.addMove(move);
      if (draw_indication == 0)
      {
        TicTacToe.displayBoardState(cout);
        winner = TicTacToe.checkLastPlayerWin();
        if (!winner)
        {
          cout << "It's a draw!" << endl;
        }
      }
      else if (draw_indication == -1)
      {
        cout << "Incorrect move. Please try again." << endl;
      }
      else
      {
        TicTacToe.displayBoardState(cout);
        winner = TicTacToe.checkLastPlayerWin();
        if (winner)
        {
          cout << "Player " << player << " won!" << endl;
          break;
        }
      };
    }
    else
    {
      cout << "Invalid command" << endl;
    }
  }

  return 0;
}
