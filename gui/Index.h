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
	QPushButton *startGameBtn;
	QPushButton *loadGameBtn;
	QPushButton *leaderboardBtn;
	QPushButton *settingBtn;
	QPushButton *gameIntroBtn;
	QPushButton *sudoku[81];
    QPushButton *generateBtn;
    QPushButton *hintBtn;
    QPushButton *checkBtn;
    QPushButton *backBtn;
public:
	Index(Recv *recv, SudokuGUI *w);
	~Index();
	void init();
public slots:
	void hide5btn() const;
	void sudokuShow() const;
    void show5btn() const;
    void sudokuHide() const;
};

