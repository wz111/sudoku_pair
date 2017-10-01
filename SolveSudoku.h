#include "iostream"
#include "string"

#pragma once

#ifndef SLOVESUDOKU_H_
#define SLOVESUDOKU_H_

#define LEN 81

#define NUM1 0x1
#define NUM2 0x2
#define NUM3 0x4
#define NUM4 0x8
#define NUM5 0x10
#define NUM6 0x20
#define NUM7 0x40
#define NUM8 0x80
#define NUM9 0x100
#define NUM0 0x1ff

class SolveSudoku
{
private:
	int _puzzle[81] = { 0 };
	int _flag[81] = { 0 };
public:
	SolveSudoku();
	~SolveSudoku();
	void setPuzzle(int a[]);
	int* getPuzzle();
	void setFlag(int a[]);
	int NumTransfor(int a);
	int RemoveCandidates(int index);
	bool Fill(int index);

};
#endif // !SLOVESUDOKU_H_


