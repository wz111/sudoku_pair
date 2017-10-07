#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sudoku_pair/Core.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT_generate3
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		int result[10010][81];
		int number = 10000;
		TEST_METHOD(TestMethod1)
		{
			Core core;			
			int mode = 1;
			core.generate(number, mode, result);
			for (int i = 0; i < number; i++)
			{
				int blankNum = 0;
				for (int j = 0; j < SUDOKU_SIZE; j++)
				{
					if (result[i][j] == 0)
					{
						blankNum++;
					}
				}
				bool left = 20 <= blankNum;
				bool right = blankNum <= 31;
				Assert::IsTrue(left && right);
			}
		}
		TEST_METHOD(TestMethod2)
		{
			Core core;
			int mode = 2;			
			core.generate(number, mode, result);
			for (int i = 0; i < number; i++)
			{
				int blankNum = 0;
				for (int j = 0; j < SUDOKU_SIZE; j++)
				{
					if (result[i][j] == 0)
					{
						blankNum++;
					}
				}
				bool left = 32 <= blankNum;
				bool right = blankNum <= 43;
				Assert::IsTrue(left && right);
			}
		}
		TEST_METHOD(TestMethod3)
		{
			Core core;
			int mode = 3;
			core.generate(number, mode, result);
			for (int i = 0; i < number; i++)
			{
				int blankNum = 0;
				for (int j = 0; j < SUDOKU_SIZE; j++)
				{
					if (result[i][j] == 0)
					{
						blankNum++;
					}
				}
				bool left = 44 <= blankNum;
				bool right = blankNum <= 55;
				Assert::IsTrue(left && right);
			}
		}
		TEST_METHOD(TestMethod4)
		{
			int puzzle[81] = {
				1, 2, 3, 4, 5, 6, 7, 8, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 9,
				0, 0, 0, 0, 0, 0, 0, 0, 8,
				0, 0, 0, 0, 0, 0, 0, 0, 7,
				0, 0, 0, 0, 0, 0, 0, 0, 6,
				0, 0, 0, 0, 0, 0, 0, 0, 5,
				0, 0, 0, 0, 0, 0, 0, 0, 4,
				0, 0, 0, 0, 0, 0, 0, 0, 3,
				0, 0, 0, 0, 0, 0, 0, 0, 2
			};
			int solution[81] = { 0 };
			Core c;
			Assert::IsFalse(c.solve(puzzle, solution));
		}
		TEST_METHOD(TestMethod5)
		{
			int puzzle[81] = {
				0, 0, 1, 6, 5, 0, 4, 0, 0,
				0, 8, 0, 2, 4, 0, 5, 9, 0,
				0, 0, 0, 0, 0, 0, 0, 6, 3,
				0, 0, 0, 0, 0, 8, 0, 5, 9,
				0, 5, 0, 0, 0, 6, 0, 7, 1,
				0, 9, 0, 5, 3, 0, 0, 4, 6,
				2, 6, 0, 9, 0, 5, 0, 0, 0,
				0, 1, 0, 0, 0, 0, 6, 0, 5,
				4, 3, 5, 0, 0, 0, 0, 1, 8
			};
			Core c;
			int flag[81] = { 0 };
			for (int i = 0; i < 81; i++)
			{
				if (puzzle[i] == 0)
				{
					puzzle[i] = 511;
				}
				else
				{
					flag[i] = 1;
				}
			}
			Assert::IsFalse(c.Fill(0, puzzle, flag, 2));
		}
		TEST_METHOD(IsUnique1)
		{
			int puzzle[81] = {
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0
			};
			Core c;
			Assert::IsFalse(c.isUnique(puzzle));
		}
		TEST_METHOD(IsUnique2)
		{
			int puzzle[81] = {
				9, 4, 1, 2, 8, 3, 6, 7, 5,
				3, 7, 2, 5, 6, 1, 8, 9, 4,
				8, 5, 6, 7, 4, 9, 1, 2, 3,
				2, 6, 4, 1, 5, 7, 3, 8, 9,
				1, 9, 5, 8, 3, 4, 7, 6, 2,
				7, 8, 3, 6, 9, 2, 5, 4, 1,
				5, 2, 7, 9, 1, 8, 4, 3, 6,
				4, 1, 9, 3, 7, 6, 2, 5, 8,
				0, 0, 0, 0, 0, 0, 0, 0, 0
			};
			Core c;
			Assert::IsTrue(c.isUnique(puzzle));
		}
		TEST_METHOD(IsUnique3)
		{
			int puzzle[81] = {
				9, 4, 1, 2, 8, 3, 6, 7, 5,
				3, 7, 2, 5, 6, 1, 8, 9, 4,
				8, 5, 6, 7, 4, 9, 1, 2, 3,
				2, 6, 4, 1, 5, 7, 3, 8, 9,
				1, 9, 5, 8, 3, 4, 7, 6, 2,
				7, 8, 3, 6, 9, 2, 5, 4, 1,
				5, 2, 7, 9, 1, 8, 4, 3, 6,
				0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0
			};
			Core c;
			Assert::IsFalse(c.isUnique(puzzle));
		}
		TEST_METHOD(IsUnique4)
		{
			int puzzle[81] = {
				9, 4, 1, 2, 8, 3, 6, 7, 5,
				3, 7, 2, 5, 6, 1, 8, 9, 4,
				8, 5, 6, 7, 4, 9, 1, 2, 3,
				2, 6, 4, 1, 5, 7, 3, 8, 9,
				1, 9, 5, 8, 3, 4, 7, 6, 2,
				7, 8, 3, 6, 9, 2, 5, 4, 1,
				5, 2, 7, 9, 1, 8, 4, 3, 6,
				4, 1, 9, 3, 7, 6, 2, 5, 8,
				6, 3, 8, 4, 2, 5, 9, 1, 7
			};
			Core c;
			Assert::IsTrue(c.isUnique(puzzle));
		}
		TEST_METHOD(IsUnique5)//ÎÞ½âÊý¶À
		{
			int puzzle[81] = {
				9, 4, 1, 2, 8, 3, 6, 7, 5,
				3, 0, 2, 5, 6, 1, 8, 9, 4,
				8, 5, 6, 7, 4, 9, 1, 2, 3,
				2, 6, 4, 1, 5, 7, 3, 8, 9,
				1, 9, 5, 8, 3, 4, 7, 6, 2,
				7, 8, 3, 6, 9, 2, 5, 4, 1,
				5, 2, 7, 9, 1, 8, 4, 3, 6,
				4, 1, 9, 3, 7, 6, 2, 5, 8,
				6, 7, 8, 4, 2, 5, 9, 1, 0
			};
			Core c;
			Assert::IsFalse(c.isUnique(puzzle));
		}
		TEST_METHOD(str2num1)
		{
			char *s = "100";
			Core c;
			Assert::AreEqual(100, c.str2num(s, 200));
		}
		TEST_METHOD(str2num2)
		{
			char *s = "100";
			Core c;
			Assert::AreEqual(100, c.str2num(s, 100));
		}
		TEST_METHOD(str2num3)
		{
			char *s = "100";
			Core c;
			Assert::AreEqual(100, c.str2num(s, 101));
		}
		TEST_METHOD(str2num4)
		{
			char *s = "100";
			Core c;
			Assert::AreEqual(-1, c.str2num(s, 99));
		}
		TEST_METHOD(str2num5)
		{
			char *s = "100";
			Core c;
			Assert::AreEqual(-1, c.str2num(s, 0));
		}
		TEST_METHOD(str2num6)
		{
			char *s = "-100";
			Core c;
			Assert::AreEqual(-1, c.str2num(s, 200));
		}
		TEST_METHOD(str2num7)
		{
			char *s = "+100";
			Core c;
			Assert::AreEqual(-1, c.str2num(s, 200));
		}
		TEST_METHOD(str2num8)
		{
			char *s = "10a0";
			Core c;
			Assert::AreEqual(-1, c.str2num(s, 200));
		}
		TEST_METHOD(str2num9)
		{
			char *s = "";
			Core c;
			Assert::AreEqual(-1, c.str2num(s, 200));
		}
		TEST_METHOD(solve1)
		{
			int puzzle[81] = {
				9, 4, 1, 2, 8, 3, 6, 7, 5,
				3, 7, 2, 5, 6, 1, 8, 9, 4,
				8, 5, 6, 7, 4, 9, 1, 2, 3,
				2, 6, 4, 1, 5, 7, 3, 8, 9,
				1, 9, 5, 8, 3, 4, 7, 6, 2,
				7, 8, 3, 6, 9, 2, 5, 4, 1,
				5, 2, 7, 9, 1, 8, 4, 3, 6,
				4, 1, 9, 3, 7, 6, 2, 5, 8,
				6, 3, 8, 4, 2, 5, 9, 1, 7
			};
			int solution[81] = { 0 };
			Core c;
			Assert::IsTrue(c.solve(puzzle, solution));
		}
		TEST_METHOD(solve2)
		{
			int puzzle[81] = {
				9, 4, 1, 2, 8, 3, 6, 7, 5,
				3, 7, 2, 5, 6, 1, 8, 9, 4,
				8, 5, 6, 7, 4, 9, 1, 2, 3,
				2, 6, 4, 1, 5, 7, 3, 8, 9,
				1, 9, 5, 8, 3, 4, 7, 6, 2,
				7, 8, 3, 6, 9, 2, 5, 4, 1,
				5, 2, 7, 9, 1, 8, 4, 3, 6,
				4, 1, 9, 3, 7, 6, 2, 5, 8,
				0, 0, 0, 0, 0, 0, 0, 0, 0
			};
			int solution[81] = { 0 };
			Core c;
			Assert::IsTrue(c.solve(puzzle, solution));
		}
		TEST_METHOD(solve3)
		{
			int puzzle[81] = {
				9, 4, 1, 2, 8, 3, 6, 7, 5,
				3, 0, 2, 5, 6, 1, 8, 9, 4,
				8, 5, 6, 7, 4, 9, 1, 2, 3,
				2, 6, 4, 1, 5, 7, 3, 8, 9,
				1, 9, 5, 8, 3, 4, 7, 6, 2,
				7, 8, 3, 6, 9, 2, 5, 4, 1,
				5, 2, 7, 9, 1, 8, 4, 3, 6,
				4, 1, 9, 3, 7, 6, 2, 5, 8,
				6, 7, 8, 4, 2, 5, 9, 1, 0
			};
			int solution[81] = { 0 };
			Core c;
			Assert::IsFalse(c.solve(puzzle, solution));
		}
		int n = 100;
		int solve4puzzle[10000][81] = { 0 };
		TEST_METHOD(solve4)
		{
			int solution[81] = { 0 };
			Core c;

			c.generate(n, 1, solve4puzzle);
			for (int i = 0; i < n; i++)
			{
				Assert::IsTrue(c.solve(solve4puzzle[i], solution));
			}
			
			c.generate(n, 2, solve4puzzle);
			for (int i = 0; i < n; i++)
			{
				Assert::IsTrue(c.solve(solve4puzzle[i], solution));
			}

			c.generate(n, 3, solve4puzzle);
			for (int i = 0; i < n; i++)
			{
				Assert::IsTrue(c.solve(solve4puzzle[i], solution));
			}
		}
		int solve5puzzle[10000][81] = { 0 };
		TEST_METHOD(solve5)
		{
			int solution[81] = { 0 };
			Core c;

			c.generate(n, 20, 55, true, solve5puzzle);
			for (int i = 0; i <n; i++)
			{
				Assert::IsTrue(c.solve(solve5puzzle[i], solution));
			}

			c.generate(n, 20, 55, false, solve5puzzle);
			for (int i = 0; i < n; i++)
			{
				Assert::IsTrue(c.solve(solve5puzzle[i], solution));
			}
		}
	};
}