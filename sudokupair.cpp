// sudokupair.cpp: 
//
#include "stdafx.h"
#include "Core.h"

int main(int argc, char *argv[])
{
	clock_t start, finish;
	start = clock();

	try {
		Core core;
		core.read(argc, argv);
		
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
	finish = clock();
	printf("time = %.2f", ((double)(finish - start)) / 1000);
	return 0;
}

