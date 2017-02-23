// gameboard.cpp
// Author: Zhening Li E-mail: zhening.li@wustl.edu
// Purpose: 
//          Define a function for reading in the dimensions of a game board from an input file stream

#include "stdafx.h"

#include <iostream> 
#include <fstream>   
#include <string>    
#include <vector>	 
#include <sstream>	 

using namespace std;

#include "gameboard.h"


int GetDimension(ifstream & gameboard, unsigned int & x, unsigned int & y)
{
	string boardimension;
	
	if(getline(gameboard, boardimension))
	{
		stringstream ss;
		ss << boardimension;
		if (!(ss >> x >> y))
		{// Could not extract the board dimensions
			return FAIL_EXTRACT_DIMENSIONS;
		}
		else
		{// All three of them returned true
			return SUCCESS;
		}
	}
	else
	{// Could not read a line from the input file stream
		return FAIL_TO_GETLINE;
	}
}

int GetGamePieces(ifstream & gameboard, vector<GamePieces> & gamepiece, unsigned int index_x, unsigned int index_y)
{
	string onegamepiece;
	bool success_flag = false;

	while (getline(gameboard, onegamepiece))
	{
		stringstream ss;
		ss << onegamepiece;
		string piece_color_temp;
		string piece_name;
		string piece_display;
		PieceColor piece_color;
		unsigned int x; // horizontal position
		unsigned int y; // vertical position
		
		if (ss >> piece_color_temp >> piece_name >> piece_display >> x >> y)
		{// successfully extract five values
			piece_color = StringToEnum(piece_color_temp);
			if (piece_color == INVALID_COLOR || x >= index_x || y >= index_y)
			{// the game piece color is invalid, 
			 //or if either the horizontal or vertical coordinate is greater than or equal to the corresponding dimension of the game board
				continue;
			}
			else
			{// five well formated values
				unsigned int index = index_x * y + x;
				gamepiece[index].piece_color = piece_color;
				gamepiece[index].piece_name = piece_name;
				gamepiece[index].piece_display = piece_display;
				success_flag = true; // At least one well formed piece
			}
		}
		else
		{// Not able to extract five values from that line
			continue;
		}
	}
	if (success_flag)
	{
		return SUCCESS;
	}
	else
	{
		return NO_WELL_FORMED_PIECE;
	}
	
}

int PrintGameBoard(const vector<GamePieces> & gamepiece, unsigned int index_x, unsigned int index_y)
{
	if (gamepiece.size() <= index_x*index_y)
	{
		for (int y_iterator = index_y - 1; y_iterator >= 0;y_iterator--)
		{// Descending order
			for (int x_iterator = 0; x_iterator < int(index_x); x_iterator++)
			{// Ascending order
				unsigned int index = index_x * y_iterator + x_iterator;
				cout << gamepiece[index].piece_display; 
			}
			cout << endl;
		}
		return SUCCESS;
	}
	else
	{ // the size of the vector might not match the dimensions of the game board that were passed in
		return UNABLE_TO_PRINT_GAMEBOARD;
	}
}