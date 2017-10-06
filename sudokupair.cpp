// sudokupair.cpp: 
//
#include "stdafx.h"
#include "Core.h"

int main(int argc, char *argv[])
{
	try {
		Core core;
		core.read(argc, argv);
		return 0;
	}
	catch (MyOrderException& e)
	{
		std::cout << "MyOrderException caught" << std::endl;
		std::cout << e.msg() << std::endl;
	}
	catch (MyFileException& e)
	{
		std::cout << "MyFileException caught" << std::endl;
		std::cout << e.msg() << std::endl;
	}
	catch (MySudokuException& e)
	{
		std::cout << "MySudokuException caught" << std::endl;
		std::cout << e.msg() << std::endl;
	}
	catch (MyParameterException& e)
	{
		std::cout << "MyParameterException caught" << std::endl;
		std::cout << e.msg() << std::endl;
	}
	
}

