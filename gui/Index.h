#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SudokuGUI.h"
#include <QPushButton>
#include "SudokuGUI.h"

class Index : public QObject
{
	Q_OBJECT
private:
	Recv * _recv;
	SudokuGUI * _w;
	QPushButton *startGame;
	QPushButton *loadGame;
	QPushButton *leaderboard;
	QPushButton *setting;
	QPushButton *gameIntro;
	QPushButton *sudoku[81];
public:
	Index(Recv *recv, SudokuGUI *w);
	~Index();
	void init();
public slots:
	void hide5btn() const;
	void sudokuShow() const;
};

