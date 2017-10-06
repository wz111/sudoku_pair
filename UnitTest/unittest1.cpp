#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sudoku_pair/Core.h"
#include "set"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool isEqual(int Left[], int Right[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (Left[i] != Right[i])
        {
            return false;
        }
    }
    return true;
}

bool isSudoku(int martix[])
{
    for (int i = 0; i < SUDOKU_SIZE; i++)
    {
        int k = -1;
        int row = i / 9;
        int col = i % 9;
        int m = row / 3;
        int n = col / 3;
        int i1 = -1;
        int j1 = -1;
        //Palace Check
        for (i1 = m * 3; i1 < m * 3 + 3; i1++)
        {
            for (j1 = n * 3; j1 < n * 3 + 3; j1++)
            {
                if (martix[i1 * 9 + j1] == martix[i] && i1 * 9 + j1 != i)
                {
                    return false;
                }
            }
        }
        //Row and Col Check
        for (k = 0; k < 9; k++)
        {
            if (martix[row * 9 + k] == martix[i] && row * 9 + k != i)
            {
                return false;
            }
            if (martix[k * 9 + col] == martix[i] && k * 9 + col != i)
            {
                return false;
            }
        }
        return true;
    }
}

bool haveSameSudoku(set<string> Set, int expectedNum)
{
    if (Set.size() == expectedNum)
    {
        return false;
    }
    else
    {
        return true;
    }
}

namespace UTCore
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		Core core;
		TEST_METHOD(TestMethodRowSwap)
		{
            int test_srcMartix[SUDOKU_SIZE] = {
                1,1,1,1,1,1,1,1,1,
                2,2,2,2,2,2,2,2,2,
                3,3,3,3,3,3,3,3,3,
                4,4,4,4,4,4,4,4,4,
                5,5,5,5,5,5,5,5,5,
                6,6,6,6,6,6,6,6,6,
                7,7,7,7,7,7,7,7,7,
                8,8,8,8,8,8,8,8,8,
                9,9,9,9,9,9,9,9,9
            };
            int test_srcMartixCopy[SUDOKU_SIZE] = { 0 };
            int test_type123 = 1;
            int test_type456 = 4;
            int test_type789 = 7;
            int test_rank1[6][3] = {
                { 1,2,3 },{ 1,3,2 },{ 2,1,3 },{ 2,3,1 },
                { 3,1,2 },{ 3,2,1 }
            };
            int test_rank2[6][3] = {
                { 4,5,6 },{ 4,6,5 },{ 5,4,6 },{ 5,6,4 },
                { 6,4,5 },{ 6,5,4 }
            };
            int test_rank3[6][3] = {
                { 7,8,9 },{ 7,9,8 },{ 8,7,9 },{ 8,9,7 },
                { 9,7,8 },{ 9,8,7 }
            };
            /*
                only one row swap 123
            */
            memcpy(test_srcMartixCopy, test_srcMartix, sizeof(int) * SUDOKU_SIZE);
            core.RowSwap(test_srcMartixCopy, test_type123, test_rank1[0]);
            bool test1 = isEqual(test_srcMartix, test_srcMartixCopy, SUDOKU_SIZE);
            Assert::IsTrue(test1);
            //row swap 132
            memcpy(test_srcMartixCopy, test_srcMartix, sizeof(int) * SUDOKU_SIZE);
            core.RowSwap(test_srcMartixCopy, test_type123, test_rank1[1]);
            int test2_expected[SUDOKU_SIZE] = {
                1,1,1,1,1,1,1,1,1,
                3,3,3,3,3,3,3,3,3,
                2,2,2,2,2,2,2,2,2,
                4,4,4,4,4,4,4,4,4,
                5,5,5,5,5,5,5,5,5,
                6,6,6,6,6,6,6,6,6,
                7,7,7,7,7,7,7,7,7,
                8,8,8,8,8,8,8,8,8,
                9,9,9,9,9,9,9,9,9
            };
            bool test2 = isEqual(test2_expected, test_srcMartixCopy, SUDOKU_SIZE);
            Assert::IsTrue(test2);

            /*
                two rows swap
            */
            memcpy(test_srcMartixCopy, test_srcMartix, sizeof(int) * SUDOKU_SIZE);
            core.RowSwap(test_srcMartixCopy, test_type123, test_rank1[5]);
            core.RowSwap(test_srcMartixCopy, test_type456, test_rank2[5]);
            int test3_expected[SUDOKU_SIZE] = {
                3,3,3,3,3,3,3,3,3,
                2,2,2,2,2,2,2,2,2,
                1,1,1,1,1,1,1,1,1,
                6,6,6,6,6,6,6,6,6,
                5,5,5,5,5,5,5,5,5,
                4,4,4,4,4,4,4,4,4,
                7,7,7,7,7,7,7,7,7,
                8,8,8,8,8,8,8,8,8,
                9,9,9,9,9,9,9,9,9
            };
            bool test3 = isEqual(test3_expected, test_srcMartixCopy, SUDOKU_SIZE);
            Assert::IsTrue(test3);

            /*
            three rows swap
            */
            memcpy(test_srcMartixCopy, test_srcMartix, sizeof(int) * SUDOKU_SIZE);
            core.RowSwap(test_srcMartixCopy, test_type123, test_rank1[5]);
            core.RowSwap(test_srcMartixCopy, test_type456, test_rank2[5]);
            core.RowSwap(test_srcMartixCopy, test_type789, test_rank3[3]);
            int test4_expected[SUDOKU_SIZE] = {
                3,3,3,3,3,3,3,3,3,
                2,2,2,2,2,2,2,2,2,
                1,1,1,1,1,1,1,1,1,
                6,6,6,6,6,6,6,6,6,
                5,5,5,5,5,5,5,5,5,
                4,4,4,4,4,4,4,4,4,
                8,8,8,8,8,8,8,8,8,
                9,9,9,9,9,9,9,9,9,
                7,7,7,7,7,7,7,7,7
            };
            bool test4 = isEqual(test4_expected, test_srcMartixCopy, SUDOKU_SIZE);
            Assert::IsTrue(test4);

            /*
            one row swap twice
            */
            memcpy(test_srcMartixCopy, test_srcMartix, sizeof(int) * SUDOKU_SIZE);
            core.RowSwap(test_srcMartixCopy, test_type123, test_rank1[5]);
            core.RowSwap(test_srcMartixCopy, test_type123, test_rank1[5]);
            int test5_expected[SUDOKU_SIZE] = {
                1,1,1,1,1,1,1,1,1,
                2,2,2,2,2,2,2,2,2,
                3,3,3,3,3,3,3,3,3,
                4,4,4,4,4,4,4,4,4,
                5,5,5,5,5,5,5,5,5,
                6,6,6,6,6,6,6,6,6,
                7,7,7,7,7,7,7,7,7,
                8,8,8,8,8,8,8,8,8,
                9,9,9,9,9,9,9,9,9
            };
            bool test5 = isEqual(test5_expected, test_srcMartixCopy, SUDOKU_SIZE);
            Assert::IsTrue(test5);
		}

        TEST_METHOD(TestMethodNumTranfor)
        {
            int test_num[9] = { 1,2,3,4,5,6,7,8,9 };
            int test_transforedNum = 0;
            for (int i = 0; i < 9; i++)
            {
                test_transforedNum = core.numTransfor(test_num[i]);
                int test_expected = pow(2, i);
                Assert::AreEqual(test_transforedNum, test_expected);
            }
        }

        TEST_METHOD(TestMethodCreate)
        {
            int test1_number = 1;
            int test1_result[1][SUDOKU_SIZE] = { 0 };
            core.create(test1_number, test1_result);
            bool test1 = isSudoku(test1_result[0]);
            Assert::IsTrue(test1);

            int test2_number = 100;
            int test2_result[100][SUDOKU_SIZE] = { 0 };
            bool test2[100] = { false };
            core.create(test2_number, test2_result);
            for (int i = 0; i < test2_number; i++)
            {
                test2[i] = isSudoku(test2_result[i]);
                Assert::IsTrue(test2[i]);
            }
            set<string> test2_Set;
            for (int j = 0; j < test2_number; j++)
            {   
                char test2_charSudoku[81];
                for (int k = 0; k < SUDOKU_SIZE; k++)
                {
                    test2_charSudoku[k] = test2_result[j][k] + '0';
                }
                string test2_stringSudoku;
                test2_stringSudoku = test2_charSudoku;
                test2_Set.insert(test2_stringSudoku);
            }
            bool test2_isSame = haveSameSudoku(test2_Set, test2_number);
            Assert::IsTrue(!test2_isSame);

            int test3_number = 1000;
            int test3_result[1000][SUDOKU_SIZE] = { 0 };
            bool test3[1000] = { false };
            core.create(test3_number, test3_result);
            for (int i = 0; i < test3_number; i++)
            {
                test3[i] = isSudoku(test3_result[i]);
                Assert::IsTrue(test3[i]);
            }
            set<string> test3_Set;
            for (int j = 0; j < test3_number; j++)
            {
                char test3_charSudoku[81];
                for (int k = 0; k < SUDOKU_SIZE; k++)
                {
                    test3_charSudoku[k] = test3_result[j][k] + '0';
                }
                string test3_stringSudoku;
                test3_stringSudoku = test3_charSudoku;
                test3_Set.insert(test3_stringSudoku);
            }
            bool test3_isSame = haveSameSudoku(test3_Set, test3_number);
            Assert::IsTrue(!test3_isSame);
        }
        
        TEST_METHOD(TestMethodGenerate3)
        {
            int test1_number = 1;
            int test1_mode = EASY;
            int test1_result[1][SUDOKU_SIZE] = { 0 };
            int test1_zeroCount = 0;
            bool test1_rightZero = false;
            core.generate(test1_number, test1_mode, test1_result);
            for (int i = 0; i < test1_number; i++)
            {
                for (int j = 0; j < SUDOKU_SIZE; j++)
                {
                    if (test1_result[i][j] == 0)
                    {
                        test1_zeroCount++;
                    }
                }
            }
            test1_rightZero = (test1_zeroCount >= 20 && test1_zeroCount <= 31);
            Assert::IsTrue(test1_rightZero);

            int test2_number = 1000;
            int test2_mode = MEDIUM;
            int test2_result[1000][SUDOKU_SIZE] = { 0 };
            int test2_zeroCount[1000] = { 0 };
            bool test2_rightZero = true;
            bool test2_isSame = true;
            core.generate(test2_number, test2_mode, test2_result);
            for (int i = 0; i < test2_number; i++)
            {
                for (int j = 0; j < SUDOKU_SIZE; j++)
                {
                    if (test2_result[i][j] == 0)
                    {
                        test2_zeroCount[i]++;
                    }
                }
                test2_rightZero = test2_rightZero && 
                    (test2_zeroCount[i] >= 32 && test2_zeroCount[i] < 44);
            }
            set<string> test2_Set;
            for (int k = 0; k < test2_number; k++)
            {
                char test2_charSudoku[81];
                for (int l = 0; l < SUDOKU_SIZE; l++)
                {
                    test2_charSudoku[l] = test2_result[k][l] + '0';
                }
                string test2_stringSudoku;
                test2_stringSudoku = test2_charSudoku;
                test2_Set.insert(test2_stringSudoku);
            }
            test2_isSame = haveSameSudoku(test2_Set, test2_number);
            Assert::IsTrue(test2_rightZero && !test2_isSame);

            int test3_number = 1000;
            int test3_mode = HARD;
            int test3_result[1000][SUDOKU_SIZE] = { 0 };
            int test3_zeroCount[1000] = { 0 };
            bool test3_rightZero = true;
            bool test3_isSame = true;
            core.generate(test3_number, test3_mode, test3_result);
            for (int i = 0; i < test3_number; i++)
            {
                for (int j = 0; j < SUDOKU_SIZE; j++)
                {
                    if (test3_result[i][j] == 0)
                    {
                        test3_zeroCount[i]++;
                    }
                }
                test3_rightZero = test3_rightZero &&
                    (test3_zeroCount[i] >= 44 && test3_zeroCount[i] < 56);
            }
            set<string> test3_Set;
            for (int k = 0; k < test3_number; k++)
            {
                char test3_charSudoku[81];
                for (int l = 0; l < SUDOKU_SIZE; l++)
                {
                    test3_charSudoku[l] = test3_result[k][l] + '0';
                }
                string test3_stringSudoku;
                test3_stringSudoku = test3_charSudoku;
                test3_Set.insert(test3_stringSudoku);
            }
            test3_isSame = haveSameSudoku(test3_Set, test3_number);
            Assert::IsTrue(test3_rightZero && !test3_isSame);
        }
        TEST_METHOD(TestMethodGenerate5)
        {
            int test1_number = 1;
            int test1_lower = 20;
            int test1_upper = 30;
            bool test1_unique = true;
            int test1_result[1][SUDOKU_SIZE] = { 0 };
            int test1_flag[1][SUDOKU_SIZE] = { 0 };
            core.generate(test1_number, test1_lower, test1_upper, 
                            test1_unique, test1_result);
            int test1_zeroCount = 0;
            bool test1_rightZero = false;
            for (int i = 0; i < test1_number; i++)
            {
                for (int j = 0; j < SUDOKU_SIZE; j++)
                {
                    if (test1_result[i][j] == 0)
                    {
                        test1_zeroCount++;
                    }
                    else
                    {
                        test1_flag[i][j] = 1;
                    }
                }
            }
            test1_rightZero = (test1_zeroCount >= test1_lower && 
                                test1_zeroCount <= test1_upper);
            
            bool test1_expected = !core.Fill(0, test1_result[0], test1_flag[0], 2) && test1_unique;
            Assert::IsTrue(test1_rightZero && test1_expected);

            int test2_number = 1000;
            int test2_lower = 30;
            int test2_upper = 55;
            bool test2_unique = true;
            int test2_result[1000][SUDOKU_SIZE] = { 0 };
            int test2_flag[1000][SUDOKU_SIZE] = { 0 };
            core.generate(test2_number, test2_lower, test2_upper,
                test2_unique, test2_result);
            int test2_zeroCount[1000] = { 0 };
            bool test2_rightZero = true;
            bool test2_isSame = true;
            bool test2_expected = true;

            set<string> test2_Set;
            for (int k = 0; k < test2_number; k++)
            {
                char test2_charSudoku[81];
                for (int l = 0; l < SUDOKU_SIZE; l++)
                {
                    test2_charSudoku[l] = test2_result[k][l] + '0';
                }
                string test2_stringSudoku;
                test2_stringSudoku = test2_charSudoku;
                test2_Set.insert(test2_stringSudoku);
            }
            test2_isSame = haveSameSudoku(test2_Set, test2_number);
            Assert::IsTrue(test2_rightZero && !test2_isSame);

            for (int i = 0; i < test2_number; i++)
            {
                for (int j = 0; j < SUDOKU_SIZE; j++)
                {
                    if (test2_result[i][j] == 0)
                    {
                        test2_zeroCount[i]++;
                    }
                    else
                    {
                        test2_flag[i][j] = 1;
                    }
                }
                test2_rightZero = (test2_zeroCount[i] >= test2_lower &&
                    test2_zeroCount[i] <= test2_upper) && test2_rightZero;
                test2_expected = test2_expected &&
                    !core.Fill(0, test2_result[i], test2_flag[i], 2) &&
                    test2_unique;
            }
            Assert::IsTrue(test2_rightZero && test2_expected && !test2_isSame);
        }
	};
}