#include <iostream>

#include "program.h"

int main()
{
	Program* program = new Program();

	program->open();
	program->run();

	return 0;
}