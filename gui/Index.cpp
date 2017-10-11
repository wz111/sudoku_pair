#include "Index.h"
#include "QGridLayout"
#include "ui_SudokuGUI.h"
#include "SudokuGUI.h"
#include "QDialog"



Index::Index(Recv *recv, SudokuGUI *w)
{
	this->_recv = recv;
	this->_w = w;
}

Index::~Index()
{
}

void Index::startNew() const
{
	hideMain();
	easyBtn->hide();
	mediumBtn->hide();
	hardBtn->hide();
	modeStartBtn->hide();
	modeLabel->hide();
	sudokuShow();
}

void Index::backMain() const
{
	showMain();
	sudokuHide();
}

void Index::backQuery() const
{
	QDialog *dlg = new QDialog(_w);
	dlg->resize(600, 200);
	//dlg->setGeometry(450, 700, 300, 200);
	QLabel *backQueryLabel = new QLabel("Warning:", dlg);
	QLabel *backQueryLabel0 = new QLabel("Are you sure you want to give up the current game?", dlg);
	QLabel *backQueryLabel1 = new QLabel("(System will not keep your changes)", dlg);
	QPushButton *backMainBtn = new QPushButton("back to main", dlg);
	QPushButton *closeBtn = new QPushButton("close", dlg);
	backQueryLabel->setStyleSheet("font-size:30px;");
	backQueryLabel->setGeometry(QRect(5, 5, 590, 20));
	backQueryLabel->adjustSize();
	backQueryLabel->setWordWrap(true);
	backQueryLabel->setAlignment(Qt::AlignTop);

	backQueryLabel0->setStyleSheet("font-size:20px;");
	backQueryLabel0->setGeometry(QRect(5, 60, 590, 20));
	backQueryLabel0->adjustSize();
	backQueryLabel0->setWordWrap(true);
	backQueryLabel0->setAlignment(Qt::AlignTop);

	backQueryLabel1->setStyleSheet("font-size:20px;font:bold;");
	backQueryLabel1->setGeometry(QRect(5, 100, 590, 20));
	backQueryLabel1->adjustSize();
	backQueryLabel1->setWordWrap(true);
	backQueryLabel1->setAlignment(Qt::AlignTop);

	backMainBtn->setGeometry(130, 160, 105, 30);
	closeBtn->setGeometry(365, 160, 105, 30);
	QObject::connect(backMainBtn, SIGNAL(clicked()), dlg, SLOT(close()));
	QObject::connect(backMainBtn, SIGNAL(clicked()), this, SLOT(backMain()));
	QObject::connect(closeBtn, SIGNAL(clicked()), dlg, SLOT(close()));
	dlg->setModal(true);
	dlg->show();
}

void Index::hideMain() const
{
	startGameBtn->hide();
	loadGameBtn->hide();
	leaderboardBtn->hide();
	settingBtn->hide();
	gameIntroBtn->hide();
	titleLabel->hide();
}

void Index::showMain() const
{
	startGameBtn->show();
	loadGameBtn->show();
	leaderboardBtn->show();
	settingBtn->show();
	gameIntroBtn->show();
	titleLabel->show();
}

void Index::sudokuShow() const
{
	for (int i = 0; i < 81; i++)
	{
		sudoku[i]->show();
	}
	int result[10][81] = { 0 };
	Core c;
	while (true)
	{
		if (easyBtn->isChecked())
		{
			/*for (int i = 0; i < 20; i++)
			{
				sudoku[i]->setText("");
			}*/			
		    c.generate(1, 1, result);
			for (int i = 0; i < 81; i++)
			{
				if (result[0][i] == 0)
				{
					sudoku[i]->setText(" ");
				}
				else
				{
					sudoku[i]->setText(QString::number(result[0][i]));
				}
			}
			//~ c;
			break;
		}
		else if (mediumBtn->isChecked())
		{
			/*for (int i = 0; i < 40; i++)
			{
				sudoku[i]->setText("");
			}*/
			c.generate(1, 2, result);
			for (int i = 0; i < 81; i++)
			{
				if (result[0][i] == 0)
				{
					sudoku[i]->setText(" ");
				}
				else
				{
					sudoku[i]->setText(QString::number(result[0][i]));
				}
			}
			break;
		}
		else if (hardBtn->isChecked())
		{
			/*for (int i = 0; i < 60; i++)
			{
				sudoku[i]->setText("");
			}*/
			c.generate(1, 3, result);
			for (int i = 0; i < 81; i++)
			{
				if (result[0][i] == 0)
				{
					sudoku[i]->setText(" ");
				}
				else
				{
					sudoku[i]->setText(QString::number(result[0][i]));
				}
			}
			break;
		}
		else
		{
			continue;
		}
	}
	generateBtn->show();
	hintBtn->show();
	checkBtn->show();
	backBtn->show();
	startTimer();
}


void Index::sudokuHide() const
{
	for (int i = 0; i < 81; i++)
	{
		sudoku[i]->hide();
	}
	generateBtn->hide();
	hintBtn->hide();
	checkBtn->hide();
	backBtn->hide();
	stopTimer();
}

void Index::showIntro() const
{
	hideMain();
	introBackBtn->show();
	introLabel->show();
}

void Index::hideIntro() const
{
	showMain();
	introBackBtn->hide();
	introLabel->hide();
}

void Index::showSetting() const
{
	hideMain();
	settingBackBtn->show();
}

void Index::hideSetting() const
{
	showMain();
	settingBackBtn->hide();
}

void Index::changeBtnGroup(int id) const
{
	switch (id)
	{
	case 0:
		easyBtn->setChecked(true);
		mediumBtn->setChecked(false);
		hardBtn->setChecked(false);
		break;
	case 1:
		easyBtn->setChecked(false);
		mediumBtn->setChecked(true);
		hardBtn->setChecked(false);
		break;
	case 2:
		easyBtn->setChecked(false);
		mediumBtn->setChecked(false);
		hardBtn->setChecked(true);
		break;
	default:
		break;
	}
}

/*
void Index::startTimer() const
{
if (!isStart)
{
ui->Start->setIconSize(QSize(70, 70));
ui->Start->setIcon(*pauseIcon);
ui->Start->show();
timer->start(1000);
}
else
{
ui->Start->setIcon(*generateBtn);
ui->Start->show();
timer->stop();
}
isStart = !isStart;
}

void Index::stopTimer() const
{
timer->stop();    //计时器停止
time->setHMS(0, 0, 0); //时间设为0
ui->Timer->display(time->toString("hh:mm:ss")); //显示00:00:00
isStart = false;
}

void Index::updateTime() const
{
*time = time->addSecs(1);
this->Timer->display(time->toString("hh:mm:ss"));
}
*/

void Index::showMode() const
{
	hideMain();
	modeLabel->show();
	easyBtn->show();
	mediumBtn->show();
	hardBtn->show();
	modeStartBtn->show();
}

void Index::showModeStart() const
{
	modeStartBtn->setEnabled(true);
}
void Index::startTimer() const
{
	timeLabel->show();
	timeLabel->setText("00:00:00");
	timer->start(1000);
}
void Index::stopTimer() const
{
	timeLabel->hide();
	timer->stop();
}
void Index::updateTime() const
{
	QString nowTime = timeLabel->text();
	int hourNum = nowTime.mid(0, 2).toInt();
	int minuteNum = nowTime.mid(3, 2).toInt();
	int secondNum = nowTime.mid(6, 2).toInt();
	secondNum++;
	if (secondNum == 60)
	{
		secondNum = 0;
		minuteNum++;
		if (minuteNum == 60)
		{
			minuteNum = 0;
			hourNum++;
			if (hourNum == 24)
			{
				exit(1);
			}
		}
	}
	QString hourString = QString::number(hourNum);
	QString minuteString = QString::number(minuteNum);
	QString secondString = QString::number(secondNum);
	QString zeroString = QString::number(0);
	QString outString;
	if (hourNum > 9)
	{
		outString = hourString;
	}
	else
	{
		outString = zeroString + hourString;
	}
	outString.append(":");
	if (minuteNum > 9)
	{
		outString += minuteString;
	}
	else
	{
		outString += zeroString + minuteString;
	}
	outString.append(":");
	if (secondNum > 9)
	{
		outString += secondString;
	}
	else
	{
		outString += zeroString + secondString;
	}
	timeLabel->setText(outString);
	//timeLabel->adjustSize();
}

void Index::init()
{
	QGridLayout* mainlayout = new QGridLayout;

	/*isStart = false;
	timer = new QTimer;
	time = new QTime(0, 0, 0);*/

	startGameBtn = new QPushButton("Start Game", _w);
	startGameBtn->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	startGameBtn->setGeometry(500, 400, 200, 50);
	QObject::connect(startGameBtn, SIGNAL(clicked()), this, SLOT(showMode()));

	loadGameBtn = new QPushButton("Load Game", _w);
	loadGameBtn->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	loadGameBtn->setGeometry(500, 475, 200, 50);
	//QObject::connect(loadGameBtn, SIGNAL(clicked()), this, SLOT(hide5btn()));

	leaderboardBtn = new QPushButton("Leaderboard", _w);
	leaderboardBtn->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	leaderboardBtn->setGeometry(500, 550, 200, 50);
	//QObject::connect(startGameBtn, SIGNAL(clicked()), this, SLOT(hide5btn()));

	settingBtn = new QPushButton("Setting", _w);
	settingBtn->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	settingBtn->setGeometry(500, 625, 200, 50);
	QObject::connect(settingBtn, SIGNAL(clicked()), this, SLOT(showSetting()));

	gameIntroBtn = new QPushButton("Introduction", _w);
	gameIntroBtn->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	gameIntroBtn->setGeometry(500, 700, 200, 50);
	QObject::connect(gameIntroBtn, SIGNAL(clicked()), this, SLOT(showIntro()));

	for (int i = 0; i < 81; i++)
	{
		sudoku[i] = new QPushButton("8", _w);
		sudoku[i]->setStyleSheet("font-size:30px;background-color:white;");
		sudoku[i]->setGeometry(40 + (i % 9) * 80, 40 + (i / 9) * 80, 80, 80);
		sudoku[i]->hide();
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sudoku[3 + i * 9 + j]->setStyleSheet("font-size:30px;background-color:#e5e5e5;");
			sudoku[27 + i * 9 + j]->setStyleSheet("font-size:30px;background-color:#e5e5e5;");
			sudoku[33 + i * 9 + j]->setStyleSheet("font-size:30px;background-color:#e5e5e5;");
			sudoku[57 + i * 9 + j]->setStyleSheet("font-size:30px;background-color:#e5e5e5;");
		}
	}

	generateBtn = new QPushButton("generate", _w);
	generateBtn->setStyleSheet("font-size:40px;background-color:yellow;");
	generateBtn->setGeometry(900, 400, 200, 40);
	generateBtn->hide();

	hintBtn = new QPushButton("hint", _w);
	hintBtn->setStyleSheet("font-size:40px;background-color:blue;");
	hintBtn->setGeometry(900, 480, 200, 40);
	hintBtn->hide();

	checkBtn = new QPushButton("check", _w);
	checkBtn->setStyleSheet("font-size:40px;background-color:green;");
	checkBtn->setGeometry(900, 560, 200, 40);
	checkBtn->hide();

	backBtn = new QPushButton("back", _w);
	backBtn->setStyleSheet("font-size:40px;background-color:red;");
	backBtn->setGeometry(900, 640, 200, 40);
	backBtn->hide();
	QObject::connect(backBtn, SIGNAL(clicked()), this, SLOT(backQuery()));

	titleLabel = new QLabel("Sudoku", _w);
	titleLabel->setStyleSheet("font-size:120px;");
	titleLabel->adjustSize();
	titleLabel->setGeometry(QRect(380, 100, 720, 200 * 1));  //四倍行距
	titleLabel->setWordWrap(true);
	titleLabel->setAlignment(Qt::AlignTop);

	introLabel = new QLabel("   Sudoku comes from a math game in Switzerland in the eighteenth Century.\
 It is a logic game using paper and pen for calculation.\
 The player needs to deduce the number of all the remaining spaces\
 based on the known numbers on the 9 * 9 disk and satisfy\
 every row, column, and every row of lines (3*3)\
 with 1-9 digits and no repetition.\n\n\
    Sudoku disk is a house, every house is divided into nine compartments.\
 In these eighty-one spaces, we give a certain number of known numbers and problem solving conditions,\
 and use logic and reasoning to fill 1-9 numbers in the other spaces.\
 So that each of the 1-9 numbers in each row, each column and each palace only appears once,\
 so it is also called 'nine squares'.", _w);
	introLabel->setStyleSheet("font-size:30px;");
	introLabel->adjustSize();
	introLabel->setGeometry(QRect(40, 100, 1120, 30 * 24));  //四倍行距
	introLabel->setWordWrap(true);
	introLabel->setAlignment(Qt::AlignTop);
	introLabel->hide();

	modeLabel = new QLabel("Mode Selection", _w);
	modeLabel->setStyleSheet("font-size:90px;");
	modeLabel->adjustSize();
	modeLabel->setGeometry(QRect(260, 100, 1120, 200 * 1));  //四倍行距
	modeLabel->setWordWrap(true);
	modeLabel->setAlignment(Qt::AlignTop);
	modeLabel->hide();

	introBackBtn = new QPushButton("back to main", _w);
	introBackBtn->setStyleSheet("font-size:30px;background-color:red;");
	introBackBtn->setGeometry(500, 700, 200, 40);
	introBackBtn->hide();
	QObject::connect(introBackBtn, SIGNAL(clicked()), this, SLOT(hideIntro()));

	settingBackBtn = new QPushButton("back to main", _w);
	settingBackBtn->setStyleSheet("font-size:30px;background-color:red;");
	settingBackBtn->setGeometry(500, 700, 200, 40);
	settingBackBtn->hide();
	QObject::connect(settingBackBtn, SIGNAL(clicked()), this, SLOT(hideSetting()));

	modeStartBtn = new QPushButton("Start!", _w);
	modeStartBtn->setStyleSheet("font-size:30px;background-color:#a9a9a9;");
	modeStartBtn->setGeometry(500, 700, 200, 40);
	modeStartBtn->setEnabled(false);
	modeStartBtn->hide();
	QObject::connect(modeStartBtn, SIGNAL(clicked()), this, SLOT(startNew()));

	easyBtn = new QRadioButton(QString::fromUtf8("Easy"), _w);
	easyBtn->setStyleSheet("font-size:45px;");
	easyBtn->setGeometry(500, 300, 800, 100);
	easyBtn->hide();
	QObject::connect(easyBtn, SIGNAL(clicked()), this, SLOT(showModeStart()));

	mediumBtn = new QRadioButton(QString::fromUtf8("Medium"), _w);
	mediumBtn->setGeometry(500, 400, 800, 100);
	mediumBtn->setStyleSheet("font-size:45px;");
	mediumBtn->hide();
	QObject::connect(mediumBtn, SIGNAL(clicked()), this, SLOT(showModeStart()));

	hardBtn = new QRadioButton(QString::fromUtf8("Hard"), _w);
	hardBtn->setGeometry(500, 500, 800, 100);
	hardBtn->setStyleSheet("font-size:45px;");
	hardBtn->hide();
	QObject::connect(hardBtn, SIGNAL(clicked()), this, SLOT(showModeStart()));

	modeGroup = new QButtonGroup();
	modeGroup->addButton(easyBtn, 0);
	modeGroup->addButton(mediumBtn, 1);
	modeGroup->addButton(hardBtn, 2);
	modeGroup->setExclusive(true);
	QObject::connect(modeGroup, SIGNAL(buttonClicked(int)), this, SLOT(changeBtnGroup(int)));

	timer = new QTimer;
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
	timer->start(1000);
	timer->stop();
	timeLabel = new QLabel("00:00:00", _w);
	timeLabel->setStyleSheet("font-size:60px;");
	timeLabel->adjustSize();
	timeLabel->setGeometry(QRect(900, 200, 720, 200 * 1));  //四倍行距
	timeLabel->hide();

}
