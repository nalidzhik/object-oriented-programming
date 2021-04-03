/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Nazife Alidzhik
* @idnumber 62598
* @task 2
* @compiler VC
*/
#include <string.h>
#include <iostream>

///
/// Allocates memory for a new zero-terminared string and
/// copies a value into it
///
void AllocateAndCopy(char*& ptr, const char* value)
{
	// If NULL has been passed, free the memory instead
	if (!value)
	{
		delete[] ptr;
		ptr = NULL;
		return;
	}

	// If a valid string has been passed, make a copy
	try {
		size_t BufferSize = strlen(value) + 1;

		char* buffer = new char[BufferSize];
		delete[] ptr;
		ptr = buffer;

		strcpy_s(ptr, BufferSize, value);
	}
	catch (std::bad_alloc&)
	{
		// TODO: When later in the course we cover exceptions,
		//       change the way this error is handled.
		std::cerr << "Not enough memory!\n";
	}
}
