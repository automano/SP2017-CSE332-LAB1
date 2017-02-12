// gamepieces.h
// Author: Zhening Li E-mail: zhening.li@wustl.edu
// Purpose: Declare an enumerated type(for example, named piece_color) for the colors of game pieces.
//
#pragma once
#include <string>
using namespace std;

enum PieceColor
{
	NO_COLOR,
	INVALID_COLOR,
	RED,
	BLACK,
	WHITE
};

string EnumToString(PieceColor color);
PieceColor StringToEnum(string color);