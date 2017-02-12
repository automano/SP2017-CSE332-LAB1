#include "stdafx.h"
#include "common.h"
#include <iostream>
int UsageMessage(char * program_name)
{
	cout << "usage: " << program_name << " <input_file_name>" << endl;
	return WRONG_ARGUMENTS_NUMBER;
}