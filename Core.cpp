#include "stdafx.h"
#include "Core.h"
#include "stdlib.h"
#include "time.h"
#include "algorithm"
#include "iostream"
#include "fstream"
#include "set"

using namespace std;

Core::Core()
{
}


Core::~Core()
{
	;
}

void Core::Swap(int* a, int* b) 
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

bool Core::DuplicateCheck(int* a, int aim, int count) 
{
	int i = 0;
	for(i = 0 ; i < count ; i++)
	{
		if (a[i] == aim)
			return true;
	}
	return false;
}

int* Core::getInitialSeed() 
{
	return _initialSeed;
}

void Core::RowSwap(int* srcMartix, int Type, int* rank) 
{
	int ranktemp[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		ranktemp[i] = rank[i];
	}
	while (ranktemp[0] !=  Type || ranktemp[1] != Type + 1 || ranktemp[2] != Type + 2)
	{
		if (ranktemp[0] != Type) {
			if (ranktemp[1] == Type)
			{
				int top = (ranktemp[0] - 1)*NUM_ROW;
				int end = (ranktemp[1] - 1)*NUM_ROW;

				for (int i = 0; i < NUM_ROW; i++) {
					Swap(&srcMartix[top + i], &srcMartix[end + i]);
				}
				int temp = ranktemp[0];
				ranktemp[0] = ranktemp[1];
				ranktemp[1] = temp;
				continue;
			}
			else if (ranktemp[2] == Type)
			{
				int top = (ranktemp[0] - 1)*NUM_ROW;
				int end = (ranktemp[2] - 1)*NUM_ROW;

				for (int i = 0; i < NUM_ROW; i++) {
					Swap(&srcMartix[top + i], &srcMartix[end + i]);
				}
				int temp = ranktemp[0];
				ranktemp[0] = ranktemp[2];
				ranktemp[2] = temp;
				continue;
			}
		}
		if (ranktemp[1] != Type + 1) {
			if (ranktemp[0] == Type + 1)
			{
				int top = (ranktemp[0] - 1)*NUM_ROW;
				int end = (ranktemp[1] - 1)*NUM_ROW;

				for (int i = 0; i < NUM_ROW; i++) {
					Swap(&srcMartix[top + i], &srcMartix[end + i]);
				}
				int temp = ranktemp[0];
				ranktemp[0] = ranktemp[1];
				ranktemp[1] = temp;
				continue;
			}
			else if (ranktemp[2] == Type + 1)
			{
				int top = (ranktemp[1] - 1)*NUM_ROW;
				int end = (ranktemp[2] - 1)*NUM_ROW;

				for (int i = 0; i < NUM_ROW; i++) {
					Swap(&srcMartix[top + i], &srcMartix[end + i]);
				}
				int temp = ranktemp[1];
				ranktemp[1] = ranktemp[2];
				ranktemp[2] = temp;
				continue;
			}
		}
		if (ranktemp[2] != Type + 2) {
			if (ranktemp[0] == Type + 2)
			{
				int top = (ranktemp[0] - 1)*NUM_ROW;
				int end = (ranktemp[2] - 1)*NUM_ROW;

				for (int i = 0; i < NUM_ROW; i++) {
					Swap(&srcMartix[top + i], &srcMartix[end + i]);
				}
				int temp = ranktemp[0];
				ranktemp[0] = ranktemp[2];
				ranktemp[2] = temp;
				continue;
			}
			else if (ranktemp[1] == Type + 2)
			{
				int top = (ranktemp[2] - 1)*NUM_ROW;
				int end = (ranktemp[1] - 1)*NUM_ROW;

				for (int i = 0; i < NUM_ROW; i++) {
					Swap(&srcMartix[top + i], &srcMartix[end + i]);
				}
				int temp = ranktemp[1];
				ranktemp[1] = ranktemp[2];
				ranktemp[2] = temp;
				continue;
			}
		}
	}
}

void Core::IndexSubstitution(int* seed, int* a, int* b, int len)
{    
	int i;
	//int result[81] = { 0 };
    for( i = 0 ; i < len ; i++ )
	{
		int temp = a[i];
		b[i] = seed[temp - 1];
	}
}

void Core::SeedInitialRandom() 
{
	int i;
	_initialSeed[8] = 9;
	srand((unsigned)time(NULL));
	for (i = 0 ; i < 8 ; i++) 
	{
		int b = (rand() % 8) + 1;
		if(DuplicateCheck(_initialSeed, b, i))
		{
			i--;
			continue;
		}
		else
		{
			_initialSeed[i] = b;
		}
	}
}

void Core::SudokuCheck(char temp[])
{
	string a(temp);
	endSet.insert(a);
}
int Core::getendSetNum() 
{
	return endSet.size();
}

void Core::create(int number, int result[][SUDOKU_SIZE])
{
	int rank123[3] = { 1,2,3 };
	int rank132[3] = { 1,3,2 };
	int rank456[3] = { 4,5,6 };
	int rank465[3] = { 4,6,5 };
	int rank546[3] = { 5,4,6 };
	int rank564[3] = { 5,6,4 };
	int rank645[3] = { 6,4,5 };
	int rank654[3] = { 6,5,4 };
	int rank789[3] = { 7,8,9 };
	int rank798[3] = { 7,9,8 };
	int rank879[3] = { 8,7,9 };
	int rank897[3] = { 8,9,7 };
	int rank978[3] = { 9,7,8 };
	int rank987[3] = { 9,8,7 };

	int palaceVary1 = 0;
	int palaceVary2 = 0;
	int palaceVary3 = 0;
	int param = 0;
	int martixCount = 0;
	/*
	ofstream out;
	out.open("sudoku.txt");
	*/
	SeedInitialRandom();
	IndexSubstitution(_initialSeed, _ancestorMartix, _originalMartix, SUDOKU_SIZE);
	
	do 
	{
		int paramArray[MAX_NUM_ROWSUB] = { 0 };
		int count = 0;
		int OriMarRowCopy[81] = { 0 };
		int OriMartixCopy[81] = { 0 };
		//IndexSubstitution(_seed, _originalMartix, OriMartixCopy, NUM_POINT);
		srand((unsigned)time(NULL));
		memcpy(OriMartixCopy, _originalMartix, sizeof(int) * 81);
		//OriMartixCopy = _originalMartix;
		IndexSubstitution(_seed, OriMartixCopy, OriMartixCopy, SUDOKU_SIZE);
		for (int i = 0; i < MAX_NUM_ROWSUB && martixCount < number ; i++) 
		{
			memcpy(OriMarRowCopy, OriMartixCopy, sizeof(int) * 81);
			palaceVary1 = (rand() % 2) + 1;
			palaceVary2 = (rand() % 6) + 1;
			palaceVary3 = (rand() % 6) + 1;
			param = palaceVary1 * 100 + palaceVary2 * 10 + palaceVary3;
			if(!DuplicateCheck(paramArray, param, count))
			{
				paramArray[count++] = param;
			}
			else 
			{
				i--;
				continue;
			}
			switch (palaceVary1)
			{
			case 1:
				RowSwap(OriMarRowCopy, Type123, rank123);
				break;
			case 2:
				RowSwap(OriMarRowCopy, Type123, rank132);
				break;
			default:
				cout << "Error1" << endl;
				break;
			}
			switch (palaceVary2)
			{
			case 1:
				RowSwap(OriMarRowCopy, Type456, rank456);
				break;
			case 2:
				RowSwap(OriMarRowCopy, Type456, rank465);
				break;
			case 3:
				RowSwap(OriMarRowCopy, Type456, rank546);
				break;
			case 4:
				RowSwap(OriMarRowCopy, Type456, rank564);
				break; 
			case 5:
				RowSwap(OriMarRowCopy, Type456, rank645);
				break;
			case 6:
				RowSwap(OriMarRowCopy, Type456, rank654);
				break;
			default:
				cout << "Error2" << endl;
				break;
			}
			switch (palaceVary3)
			{
			case 1:
				RowSwap(OriMarRowCopy, Type789, rank789);
				break;
			case 2:
				RowSwap(OriMarRowCopy, Type789, rank798);
				break;
			case 3:
				RowSwap(OriMarRowCopy, Type789, rank879);
				break;
			case 4:
				RowSwap(OriMarRowCopy, Type789, rank897);
				break;
			case 5:
				RowSwap(OriMarRowCopy, Type789, rank978);
				break;
			case 6:
				RowSwap(OriMarRowCopy, Type789, rank987);
				break;
			default:
				cout << "Error3" << endl;
				break;
			}
			for (int i = 0; i < SUDOKU_SIZE; i++)
			{
				result[martixCount][i] = OriMarRowCopy[i];
			}
			//memcpy(result[martixCount], OriMarRowCopy, sizeof(int) * SUDOKU_SIZE);
			martixCount++;
		}
		
	} while (next_permutation(_seed, _seed + 8) && martixCount < number );

	/*
	if (checkOption) {
		if (number != getendSetNum())
		{
			cout << "duplicate" << endl;
		}
		else
		{
			cout << "not duplicate" << endl;
		}
	}
	else;
	*/
}

void Core::generate(int number, int mode, int result[][SUDOKU_SIZE])
{
	create(number, result);
	int blankNum = 0;
	srand((unsigned)time(NULL));
	for (int i = 0; i < number; i++) 
	{
		blankNum = rand() % 12 + 8 + mode * 12;
		//$todo: study set random
		for (int j = 0; j < blankNum; j++)
		{
			int t = rand() % 81;
			while (result[i][t] == 0)
			{
				t = rand() % 81;
			}
			result[i][t] = 0;
		}
	}
}

int Core::numTransfor(int a)
{
	int temp = 1;
	for (int k = 1; k < a; k++)
	{
		temp <<= 1;
	}
	return temp;
}

int Core::RemoveCandidates(int index, int puzzle[], int flag[])
{
	if (flag[index] == 1)
	{
		return puzzle[index];
	}

	int row = index / 9;
	int col = index % 9;
	int m = row / 3;
	int n = col / 3;
	int i1;
	int j1;
	int pointCopy = puzzle[index];

	//Palace candidates removal
	for (i1 = m * 3; i1 < m * 3 + 3; i1++)
	{
		for (j1 = n * 3; j1 < n * 3 + 3; j1++)
		{
			if (flag[i1 * 9 + j1] == 1)
			{
				pointCopy = pointCopy & (~numTransfor(puzzle[i1 * 9 + j1]));
			}
		}
	}

	//row and col candidates removal
	int i;
	for (i = 0; i < 9; i++)
	{
		if (flag[row * 9 + i] == 1)
		{
			pointCopy = pointCopy & (~numTransfor(puzzle[row * 9 + i]));
		}
		if (flag[i * 9 + col] == 1)
		{
			pointCopy = pointCopy & (~numTransfor(puzzle[i * 9 + col]));
		}
		else
			;
	}
	return  pointCopy;
}
int tt = 0;
bool Core::Fill(int index, int puzzle[], int flag[])
{
	if (index >= 81)
	{
		tt++;
		//if (tt == 2)
			return true;
		//else
			//return false;
	}
	int shiftvalue = RemoveCandidates(index, puzzle, flag);
	int pointCopy = puzzle[index];

	if (flag[index] == 0)
	{
		for (int i = 1; shiftvalue > 0; i++)
		{
			if (shiftvalue % 2 != 0)
			{
				puzzle[index] = i;
				flag[index] = 1;
				if (Fill(index + 1, puzzle, flag))
				{
					return true;
				}
			}
			shiftvalue = shiftvalue >> 1;
		}
	}
	else
	{
		return Fill(index + 1, puzzle, flag);
	}
	puzzle[index] = pointCopy;
	flag[index] = 0;
	return false;
}

bool Core::isUnique(int puzzle[SUDOKU_SIZE])
{
	return true;
	/*int flag[SUDOKU_SIZE] = { 0 };
	int binary[SUDOKU_SIZE] = { 0 };
	for (int i = 0; i < SUDOKU_SIZE; i++)
	{
		if (puzzle[i] == 0)
		{
			int t = 0x1ff;
			for (int j = 0; j < 9; j++)
			{
				if (puzzle[9 * j + i % 9] != 0)
				{
					int shift = 1;
					for (int k = 1; k < puzzle[9 * j + i % 9]; k++)
					{
						shift <<= 1;
					}
					t = t & (~shift);
				}
			}
			for (int j = 0; j < 9; j++)
			{
				if (puzzle[i / 9 * 9 + j] != 0)
				{
					int shift = 1;
					for (int k = 1; k < puzzle[i / 9 * 9 + j]; k++)
					{
						shift <<= 1;
					}
					t = t & (~shift);
				}
			}
			int x = i / 9 / 3;
			int y = i % 9 / 3;
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (puzzle[ (x + j) * 9 + y + k] != 0)
					{
						int shift = 1;
						for (int k = 1; k < puzzle[(x + j) * 9 + y + k]; k++)
						{
							shift <<= 1;
						}
						t = t & (~shift);
					}
				}
			}
			binary[i] = t;
			flag[i] = 1;
		}
	}*/


}

void Core::generate(int number, int lower, int upper, bool unique, int result[][SUDOKU_SIZE])
{
	create(number, result);
	int blankNum = 0;
	srand((unsigned)time(NULL));
	for (int i = 0; i < number; i++)
	{
		blankNum = rand() % (upper - lower + 1) + lower;
		//$todo: study set random
		for (int j = 0; j < blankNum; j++)
		{
			int t = rand() % 81;
			while (result[i][t] == 0)
			{
				t = rand() % 81;
			}
			result[i][t] = 0;
		}
	}
}

void Core::print(int number, int result[][SUDOKU_SIZE])
{
	FILE* outfile;
	errno_t err1;

	if ((err1 = fopen_s(&outfile, "sudoku.txt", "w")) != 0)
	{
		printf("Unable to open sudoku.txt\n");
		exit(1);
	}

	for (int i = 0; i < number; i++) {
		//$todo: to solve the leak of the memory
		int m = 0;
		char temp[325];
		for (int j = 0; j < SUDOKU_SIZE; j++, m += 2)
		{
			temp[m] = result[i][j] + '0';
			if ((j + 1) % 9 == 0)
			{
				temp[m + 1] = '\n';
				continue;
			}
			temp[m + 1] = ' ';
		}
		temp[m] = '\n';
		temp[m + 1] = '\0';
		std::fputs(temp, outfile);
	}
	std::fclose(outfile);
}