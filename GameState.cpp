// File Name: GameState.cpp
//
// Author: Ashok Paudel
// Collaborators: None
// Date: 15 Apr, 2024
//
// Description: 
// This program implements a Tic-Tac-Toe game represented by a 3x3 grid.
// It includes functionality to add moves, check for a win, undo 
// the last move, and display the current state of the game board.

#include "GameState.h"
#include <iostream>
using namespace std;

//***********************************************************
// bool GameState::checkLastPlayerWin()
//
// Checks if the last player to make a move has won the game.
//
// returns: true if the last player has won, false otherwise.
//**********************************************************
bool GameState::checkLastPlayerWin()
{
  char targetSymbol = getCurrentPlayer() ? 'x' : 'o';
  int sumHorizontal, sumVertical;
  for (int i = 0; i < 3; ++i)
  {
    sumHorizontal = 0;
    sumVertical = 0;
    for (int j = 0; j < 3; ++j)
    {
      sumHorizontal += boardState[i][j] == targetSymbol;
      sumVertical += boardState[j][i] == targetSymbol;
    }
    if (sumHorizontal == 3 || sumVertical == 3)
      return true;
  }
  int sumDiagonal1 = 0, sumDiagonal2 = 0;
  for (int i = 0; i < 3; ++i)
  {
    sumDiagonal1 += boardState[i][i] == targetSymbol;
    sumDiagonal2 += boardState[i][2 - i] == targetSymbol;
  }
  if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
    return true;

  return false;
}

//***********************************************************
// GameState::GameState()
//
// Constructor for GameState class. Initializes the game board with '_' characters.
//**********************************************************
GameState::GameState()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      boardState[i][j] = '_';
    }
  }
}

//***********************************************************
// int GameState::getCurrentPlayer()
//
// Determines the current player based on the number of moves made.
//
// returns: 0 for player 'x', 1 for player 'o'.
//**********************************************************
int GameState::getCurrentPlayer()
{
  if (moveStack.getSize() % 2 == 0)
  {
    return 0;
  }
  return 1;
}

//***********************************************************
// int GameState::addMove(Move move)
//
// Adds a move to the game board.
//
// move: The move to be added.
// returns: 0 if the move was added successfully, -1 if the move is invalid (position occupied),
//          1 if the move was added successfully and the game continues.
//**********************************************************
int GameState::addMove(Move move)
{
  if (moveStack.getSize() == 8)
  {
    if (!getCurrentPlayer())
    {
      boardState[move.x][move.y] = 'x';
      moveStack.push(move);
    }
    else
    {
      boardState[move.x][move.y] = 'o';
      moveStack.push(move);
    }
    return 0;
  }
  else if (boardState[move.x][move.y] != '_')
  {
    return -1;
  }
  else
  {
    if (!getCurrentPlayer())
    {
      boardState[move.x][move.y] = 'x';
      moveStack.push(move);
    }
    else
    {
      boardState[move.x][move.y] = 'o';
      moveStack.push(move);
    }
    return 1;
  }
}

//***********************************************************
// bool GameState::undoLast()
//
// Undoes the last move made in the game.
//
// returns: true if the last move was successfully undone, false if there are no moves to undo.
//**********************************************************
bool GameState::undoLast()
{
  if (moveStack.getSize() == 0)
  {
    return false;
  }
  else
  {
    boardState[moveStack.top().x][moveStack.top().y] = '_';
    moveStack.pop();
    return true;
  }
}

//***********************************************************
// void GameState::displayBoardState(std::ostream &out)
//
// Displays the current state of the game board.
//
// out: The output stream to display the board state.
//**********************************************************
void GameState::displayBoardState(std::ostream &out)
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      out << boardState[i][j];
    }
    out << endl;
  }
}
