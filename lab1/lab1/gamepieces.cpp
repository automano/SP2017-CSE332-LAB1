// gamepieces.cpp
// Author: Zhening Li E-mail: zhening.li@wustl.edu
// Purpose: Define functions
//

#include "stdafx.h"

#include <string>
using namespace std;

#include "common.h"
#include "gamepieces.h"

/**
 * Function that takes a single parameter of the enumerated type (e.g., piece_color) by value
 * and returns (again by value) an all lowercase C++ style string corresponding to the value that was passed
 */
string EnumToString(PieceColor color)
{
	string output;
	switch (color) 
	{
	case RED: output = "RED";break;
	case BLACK: output = "BLACK";break;
	case WHITE: output = "WHITE";break;
	}
	LowerCase(output); // all lowercase C++ style string
	return output;
}

/*
 * Function that takes a C++ style string by value as its only parameter
 * converts the passed string parameter (which is a local copy of what was passed by value) and returns (again by value) the element of the enumerated type (e.g., piece_color) that corresponds to that string.
*/
PieceColor StringToEnum(string color)
{
	PieceColor output;
	LowerCase(color);
	if (color == "red")
	{
		output = RED;
	}
	else if (color == "white")
	{
		output = WHITE;
	}
	else if (color == "black")
	{
		output = BLACK;
	}
	else if (color == " ")
	{
		output = NO_COLOR;
	}
	else
	{
		output = INVALID_COLOR;
	}
	return output;
}

