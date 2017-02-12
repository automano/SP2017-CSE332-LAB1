// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "common.h"
#include <string>
#include <iostream>

int main(int agrc, char * argv[])
{
	string test = "ABCDEFGXYZ";
	LowerCase(test);
	cout << test << endl;
    return SUCCESS;
}

