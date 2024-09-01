// File Name: MoveStack.h
//
// Author: Ashok Paudel
// Collaborators: None
// Date: 15 Apr, 2024
// Assignment Number: PA#6
// CS 2308 Spring 2024
//
// Description: 
// This file contains the declaration of the MoveStack class, 
// which is a stack data structure specifically designed for
// storing moves in a Tic-Tac-Toe game. It provides functionality to
// push moves onto the stack, pop moves off the stack, and 
// retrieve the size and top element of the stack.

#include <iostream>

struct Move
{
    int x;
    int y;

    // Default constructor initializes x and y to 0.
    Move()
    {
        x = 0;
        y = 0;
    }

    // Constructor with parameters to initialize x and y.
    Move(int a, int b) { x = a, y = b; }
};

class MoveStack
{
private:
    const static int SIZE = 9; // Maximum size of the stack
    Move TicTacToeMove[SIZE];  // Array to store moves
    int position;               // Current position in the stack

public:
    // Constructor
    MoveStack();

    // Destructor
    ~MoveStack();

    // Get the current size of the stack
    int getSize();

    // Get the top move on the stack
    Move top();

    // Push a move onto the stack
    void push(Move move);

    // Pop a move off the stack
    void pop();
};
