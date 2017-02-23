// gameboard.h
// Author: Zhening Li E-mail: zhening.li@wustl.edu
// Purpose: 
//          Declare a function for reading in the dimensions of a game board from an input file stream

#pragma once
#include "common.h"
#include "gamepieces.h"

int GetDimension(ifstream & gameboard, unsigned int & x, unsigned int & y);
int GetGamePieces(ifstream & gameboard, vector<GamePieces> & position, unsigned int x, unsigned int y);
int PrintGameBoard(const vector<GamePieces> & gamepiece, unsigned int index_x, unsigned int index_y);