#include "Index.h"
#include "QGridLayout"
#include "ui_SudokuGUI.h"
#include "SudokuGUI.h"



Index::Index(Recv *recv, SudokuGUI *w)
{
	this -> _recv = recv;
	this -> _w = w;
}

Index::~Index()
{
}

void Index::startNew() const
{
    hideMain();
    sudokuShow();
}

void Index::backMain() const
{
    showMain();
    sudokuHide();
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
    generateBtn->show();
    hintBtn->show();
    checkBtn->show();
    backBtn->show();
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
    timer->stop();    //��ʱ��ֹͣ
    time->setHMS(0, 0, 0); //ʱ����Ϊ0
    ui->Timer->display(time->toString("hh:mm:ss")); //��ʾ00:00:00
    isStart = false;
}

void Index::updateTime() const
{
    *time = time->addSecs(1);
    this->Timer->display(time->toString("hh:mm:ss"));
}
*/

void Index::init()
{   
    QGridLayout* mainlayout = new QGridLayout;

    isStart = false;
    timer = new QTimer;
    time = new QTime(0, 0, 0);

	startGameBtn = new QPushButton("Start Game", _w);
	startGameBtn->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	startGameBtn->setGeometry(500, 400, 200, 50);
	QObject::connect(startGameBtn, SIGNAL(clicked()), this, SLOT(startNew()));

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
    QObject::connect(backBtn, SIGNAL(clicked()), this, SLOT(backMain()));

    titleLabel = new QLabel("Sudoku", _w);
    titleLabel->setStyleSheet("font-size:120px;");
    titleLabel->adjustSize();
    titleLabel->setGeometry(QRect(380, 100, 720, 200 * 1));  //�ı��о�
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
 so it is also called 'nine squares'", _w);
    introLabel->setStyleSheet("font-size:30px;");
    introLabel->adjustSize();    
    introLabel->setGeometry(QRect(40, 100, 1120, 30*24));  //�ı��о�
    introLabel->setWordWrap(true);
    introLabel->setAlignment(Qt::AlignTop);
    introLabel->hide();

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
}
