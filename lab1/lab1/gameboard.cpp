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

int GetGamePieces(ifstream & gameboard, vector<GamePieces> & position, unsigned int x, unsigned int y)
{

	return SUCCESS;
}