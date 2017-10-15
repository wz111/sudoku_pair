// sudokupair.cpp: 
//
#include "stdafx.h"
#include "Core.h"

int main(int argc, char *argv[])
{
	clock_t start, finish;
	start = clock();

	int test_argc[100];
	char *test_argv[100][10];
	

	test_argc[0] = 6;
	test_argv[0][1] = "-r";
	test_argv[0][2] = "20~50";
	test_argv[0][3] = "-n";
	test_argv[0][4] = "10000";
	test_argv[0][5] = "-u";

	test_argc[1] = 3;
	test_argv[1][1] = "-n";
	test_argv[1][2] = "10";

	test_argc[2] = 4;
	test_argv[2][1] = "-n";
	test_argv[2][2] = "100";
	test_argv[2][3] = "-u";

	test_argc[3] = 5;
	test_argv[3][1] = "-n";
	test_argv[3][2] = "100";
	test_argv[3][3] = "-m";
	test_argv[3][4] = "1";

	test_argc[4] = 4;
	test_argv[4][1] = "-n";
	test_argv[4][2] = "100";
	test_argv[4][3] = "-u";

	test_argc[5] = 6;
	test_argv[5][1] = "-n";
	test_argv[5][2] = "100";
	test_argv[5][3] = "-r";
	test_argv[5][4] = "30~40";
	test_argv[5][5] = "-u";

	test_argc[6] = 5;
	test_argv[6][1] = "-n";
	test_argv[6][2] = "100";
	test_argv[6][3] = "-r";
	test_argv[6][4] = "30~40";

	test_argc[7] = 5;
	test_argv[7][1] = "-n";
	test_argv[7][2] = "100";
	test_argv[7][3] = "-m";
	test_argv[7][4] = "2";

	test_argc[8] = 5;
	test_argv[8][1] = "-n";
	test_argv[8][2] = "100";
	test_argv[8][3] = "-m";
	test_argv[8][4] = "3";

	test_argc[9] = 5;
	test_argv[9][1] = "-m";
	test_argv[9][2] = "1";
	test_argv[9][3] = "-n";
	test_argv[9][4] = "3";

	test_argc[10] = 5;
	test_argv[10][1] = "-r";
	test_argv[10][2] = "20~30";
	test_argv[10][3] = "-n";
	test_argv[10][4] = "3";

	test_argc[11] = 6;
	test_argv[11][1] = "-n";
	test_argv[11][2] = "100";
	test_argv[11][3] = "-u";
	test_argv[11][4] = "-r";
	test_argv[11][5] = "20~30";

	test_argc[12] = 6;
	test_argv[12][1] = "-u";
	test_argv[12][2] = "-n";
	test_argv[12][3] = "10";
	test_argv[12][4] = "-r";
	test_argv[12][5] = "20~30";

	test_argc[13] = 6;
	test_argv[13][1] = "-u";
	test_argv[13][2] = "-r";
	test_argv[13][3] = "20~30";
	test_argv[13][4] = "-n";
	test_argv[13][5] = "2";

	test_argc[14] = 3;
	test_argv[14][1] = "-s";
	test_argv[14][2] = "puzzle.txt";
	
	test_argc[15] = 4;
	test_argv[15][1] = "-u";
	test_argv[15][2] = "-n";
	test_argv[15][3] = "1";

	test_argc[16] = 6;
	test_argv[16][1] = "-r";
	test_argv[16][2] = "20~30";
	test_argv[16][3] = "-n";
	test_argv[16][4] = "1";
	test_argv[16][5] = "-u";

	test_argc[17] = 6;
	test_argv[17][1] = "-r";
	test_argv[17][2] = "20~30";
	test_argv[17][3] = "-u";
	test_argv[17][4] = "-n";
	test_argv[17][5] = "1";

	test_argc[18] = 1;
	//test_argv[17][1] = "-r";
	
	test_argc[19] = 6;
	test_argv[19][1] = "-r";
	test_argv[19][2] = "20~30";
	test_argv[19][3] = "-u";
	test_argv[19][4] = "-n";
	test_argv[19][5] = "-2";


	int num = 1;

	try {
		Core core;
		for (int i = 0; i < num; i++)
		{
			core.read(test_argc[i], test_argv[i]);
		}
		//core.read(argc, argv);
		
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

