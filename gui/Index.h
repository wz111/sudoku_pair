#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SudokuGUI.h"
#include <QPushButton>
#include <QLabel>
#include <QDateTime>
#include <QTimer>
#include <QTime>
#include <QRadioButton>
#include <QButtonGroup>
#include "QGridLayout"
#include "SudokuGUI.h"
#include "Core.h"

namespace Ui {
	class Index;
}

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
	QPushButton *introBackBtn;
	QPushButton *settingBackBtn;
	QPushButton *modeStartBtn;

	QButtonGroup *modeGroup;
	QRadioButton *easyBtn;
	QRadioButton *mediumBtn;
	QRadioButton *hardBtn;

	QLabel *titleLabel;
	QLabel *introLabel;
	QLabel *modeLabel;

	QTimer * timer;      //定时器 每秒更新时间
	QTime * timeRecord;  //记录时间
	bool isStart;        //记录是否已经开始计时

	QLabel *timeLabel;
public:
	Index(Recv *recv, SudokuGUI *w);
	~Index();
	void init();
	public slots:
	void hideMain() const;
	void sudokuShow() const;
	void showMain() const;
	void sudokuHide() const;
	void startNew() const;
	void backMain() const;
	void showIntro() const;
	void hideIntro() const;
	void showSetting() const;
	void hideSetting() const;
	void changeBtnGroup(int id) const;
	void showMode() const;
	void showModeStart() const;
	void backQuery() const;

	void updateTime() const;
	void startTimer() const;
	void stopTimer() const;

	void generateNew() const;
};

