// File Name: MoveStack.cpp
//
// Author: Ashok Paudel
// Collaborators: None
// Date: 15 Apr, 2024

//
// Description: 
// This file contains the implementation of the MoveStack class, 
// which is a stack data structure specifically designed for 
// storing moves in a Tic-Tac-Toe game. It provides functionality to
// push moves onto the stack, pop moves off the stack, 
// and retrieve the size and top element of the stack.

#include "MoveStack.h"
#include <iostream>

//***********************************************************
// MoveStack::MoveStack()
//
// Constructor for MoveStack class. Initializes the position to 0.
//**********************************************************
MoveStack::MoveStack() {
  position = 0;
}

//***********************************************************
// MoveStack::~MoveStack()
//
// Destructor for MoveStack class.
//**********************************************************
MoveStack::~MoveStack() {

}

//***********************************************************
// int MoveStack::getSize()
//
// Gets the current size of the stack.
//
// returns: The current size of the stack.
//**********************************************************
int MoveStack::getSize() {
  return position;
}

//***********************************************************
// void MoveStack::push(Move move)
//
// Pushes a move onto the stack.
//
// move: The move to be pushed onto the stack.
//**********************************************************
void MoveStack::push(Move move) {
  if (position + 1 <= SIZE) {
    TicTacToeMove[position] = move;
    position++;
  }
}

//***********************************************************
// Move MoveStack::top()
//
// Retrieves the top element of the stack.
//
// returns: The top move on the stack.
//**********************************************************
Move MoveStack::top() {
  return TicTacToeMove[position - 1];
}

//***********************************************************
// void MoveStack::pop()
//
// Pops the top element off the stack.
//**********************************************************
void MoveStack::pop() {
  position--;
}
