#include "stdafx.h"
#include "string"
#include "iostream"
#include "fstream"
#include "EndProducer.h"
#include "SolveSudoku.h"

using namespace std;

SolveSudoku::SolveSudoku()
{
}

SolveSudoku::~SolveSudoku()
{
}

void SolveSudoku::setPuzzle(int a[]) 
{
	memcpy(_puzzle, a, sizeof(int)*81);
}

int* SolveSudoku::getPuzzle() 
{
	return _puzzle;
}

void SolveSudoku::setFlag(int a[])
{
	memcpy(_flag, a, sizeof(int)*81);
}

int SolveSudoku::NumTransfor(int a) 
{
	int temp = 0;
	switch (a)
	{
	case 1:
		temp = NUM1;
		break;  
	case 2:
		temp = NUM2;
		break;
	case 3:
		temp = NUM3;
		break;
	case 4:
		temp = NUM4;
		break;
	case 5:
		temp = NUM5;
		break;
	case 6:
		temp = NUM6;
		break;
	case 7:
		temp = NUM7;
		break;
	case 8:
		temp = NUM8;
		break;
	case 9:
		temp = NUM9;
		break;
	default:
		cout << "Error4" << endl;
		exit(1);
		break;
	}
	return temp;
}

int SolveSudoku::RemoveCandidates(int index) 
{
	if (_flag[index] == 1)
	{
		return _puzzle[index];
	}

	int row = index / 9;
	int col = index % 9;
	int m = row / 3;
	int n = col / 3;
	int i1;
	int j1;
	int pointCopy = _puzzle[index];

	//Palace candidates removal
	for (i1 = m * 3; i1 < m * 3 + 3; i1++)
	{
		for (j1 = n * 3; j1 < n * 3 + 3; j1++)
		{
			if (_flag[i1 * 9 + j1] == 1) 
			{
				pointCopy = pointCopy & (~NumTransfor(_puzzle[i1 * 9 + j1]));
			}
		}
	}

    //row and col candidates removal
	int i;
	for (i = 0; i < 9; i++) 
	{
		if (_flag[row * 9 + i] == 1) 
		{
			pointCopy = pointCopy & (~NumTransfor(_puzzle[row * 9 + i]));
		}
		if(_flag[i * 9 + col] == 1)
		{
		    pointCopy = pointCopy & (~NumTransfor(_puzzle[i * 9 + col]));
		}
		else
			;
	}
	return  pointCopy;
}

bool SolveSudoku::Fill(int index) 
{	
	if (index >= 81) 
	{
		return true;
	}
	int shiftvalue = RemoveCandidates(index);
	int pointCopy = _puzzle[index];
	
	if(_flag[index] == 0)
	{
		for (int i = 1 ; shiftvalue > 0 ; i++) 
		{
			if (shiftvalue % 2 != 0)
			{
				_puzzle[index] = i;
				_flag[index] = 1;
				if (Fill(index + 1))
				{
					return true;
				}
			}
			shiftvalue = shiftvalue >> 1;
		}
	}
	else
	{
		return Fill(index + 1);
	}
	_puzzle[index] = pointCopy;
	_flag[index] = 0;
	return false;
}