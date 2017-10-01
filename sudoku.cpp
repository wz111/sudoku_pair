// sudoku.cpp:
//

#include "stdafx.h"
#include "Core.h"
#include "SolveSudoku.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <regex>
#include <sstream>

using namespace std;

int main(int argc,char** argv)
{
	clock_t start, finish;
	double totaltime;
	start = clock();

	if (argv[1][0] == '-' && argv[1][1] == 'c')
	{
		const regex pattern("\\+*\\d+");
		bool isValid = regex_match(argv[2], pattern);
		int Nums = -1;
		if (!isValid) 
		{
			cout << "The Paramter must be positive!! Exit......" << endl;
		}
		else 
		{
			char buf[50] = { 0 };
			std::regex addSign("\\+");
			string whitespace = "";
			regex_replace(buf, argv[2], argv[2]+strlen(argv[2]), addSign, whitespace);
			Nums = atoi(buf);
			if (Nums > 1000000 || Nums < 1) 
			{
				cout << "The Paramter must be positive!! Exit......" << endl;
			}
			EndProducer EP(Nums);
			EP.MainOperation(Check);
			cout << Nums << " sudokus have been produced!" << endl;

		}
	}
	else if (argv[1][0] == '-' && argv[1][1] == 's')
	{
		int line = -1;
		int count = 0;
		int bufferMartix[81] = { 0 };
		int bufferFlag[81] = { 0 };
		SolveSudoku ss;
		string filepath;
		string buffer;
		string linestr;
		filepath = argv[2];

		fstream infile(filepath.c_str());
		ofstream outfile("sudoku.txt"/*, std::ofstream::binary*/);
		if (!infile)
		{
			cout << "Unable to open the file. Exit" << endl;
			exit(1);
		}
		if (!outfile)
		{
			cout << "Unable to write the file. Exit" << endl;
			exit(1);
		}
		buffer.assign(istreambuf_iterator<char>(infile), istreambuf_iterator<char>());
		stringstream strStr;
		strStr.str(buffer);

		do
		{
			for (int i = 0; linestr[i] != '\0'; i++) 
			{
				if (linestr[i] >= '0' && linestr[i] <= '9') 
				{
					bufferMartix[count] = linestr[i] - '0';
					if(linestr[i] != '0')
					{
						bufferFlag[count] = 1;
					}
					else
					{
					    bufferMartix[count] = NUM0;
					}
					count++;
				}
				else 
				{
					continue;
				}
			}
			line++;
			if (linestr == "\n" || line == 9)
			{
				//Solve the sudoku
				ss.setPuzzle(bufferMartix);
				ss.setFlag(bufferFlag);
				if (ss.Fill(0))
				{
					//$to do: find an efficent way to output to file
					int m = 0;
					char temp[325];
					for (int j = 0; j < 81; j++, m+=2)
					{
						temp[m] = ss.getPuzzle()[j] + '0';
						//outfile << ss.getPuzzle()[j];
						if ((j + 1) % 9 == 0)
						{
							temp[m + 1] = '\n';
							//outfile << '\n';
							continue;
						}
						if (j < 81)
						{
							temp[m + 1] = ' ';
							//outfile << ' ';
						}
					}
					temp[m] = '\n';
					temp[m + 1] = '\0';
					outfile.write(temp, strlen(temp));
					//outfile << '\n';
				}
				memset(bufferFlag, 0, sizeof(int) * 81);
				memset(bufferMartix, 0, sizeof(int) * 81);
				ss.setPuzzle(bufferMartix);
				ss.setFlag(bufferFlag);
				count = 0;
				line = -1;
				continue;
			}
		} while (getline(strStr, linestr));
		cout << "Solved Sudoku!" << endl;
	}
	else if (argv[1][0] == '-' && argv[1][1] == 't') {
		string filepath;
		string buffer;
		string linestr;
		int zeroNum = -1;
		int zero_Count = 0;
		int zero_index = -1;
		int line = 0;
		filepath = argv[2];

		fstream infile(filepath.c_str());
		fstream outfile(filepath.c_str());
		if (!infile)
		{
			cout << "Unable to open the file. Exit" << endl;
			exit(1);
		}
		buffer.assign(istreambuf_iterator<char>(infile), istreambuf_iterator<char>());
		stringstream strStr;
		strStr.str(buffer);

		srand((unsigned)time(NULL));
		while (getline(strStr, linestr))
		{
			if (linestr[0] >= '1' && linestr[0] <= '9')
			{
				zeroNum = (rand() % 3) + 4;
				zero_Count = 0;
				while (true)
				{
					if (zero_Count < zeroNum)
					{
						if (line % 10 == 0)
						{
							zero_index = (rand() % 8) + 1;
						}
						else
						{
							zero_index = rand() % 9;
						}
						if (linestr[2 * zero_index] == '0')
						{
							continue;
						}
						linestr[2 * zero_index] = '0';
						zero_Count++;
					}
					else
					{
						outfile << linestr;
						outfile << "\n";
						break;
					}
				}
			}
			else 
			{
				outfile << "\n";
			}
			line++;
		}
	}

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\nProgram time is " << totaltime << "s!" << endl;
    return 0;
}

