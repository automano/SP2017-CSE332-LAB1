// gamepieces.h
// Author: Zhening Li E-mail: zhening.li@wustl.edu
// Purpose: Declare an enumerated type(for example, named piece_color) for the colors of game pieces.
//			Declare functions

#pragma once
#include "common.h"

enum PieceColor
{
	NO_COLOR,
	INVALID_COLOR,
	RED,
	BLACK,
	WHITE
};

//struct declaration (in gamepieces.h)
struct GamePieces
{
	PieceColor piece_color; 
	string piece_name; 
	string piece_display;
};

string EnumToString(PieceColor color);
PieceColor StringToEnum(string color);