#include "Index.h"



Index::Index(Recv *recv, SudokuGUI *w)
{
	this -> _recv = recv;
	this -> _w = w;
}

Index::~Index()
{
}

void Index::hide5btn() const
{
	startGameBtn->hide();
	loadGameBtn->hide();
	leaderboardBtn->hide();
	settingBtn->hide();
	gameIntroBtn->hide();
	sudokuShow();
}

void Index::show5btn() const
{
    startGameBtn->show();
    loadGameBtn->show();
    leaderboardBtn->show();
    settingBtn->show();
    gameIntroBtn->show();
    sudokuHide();
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

void Index::init()
{
	startGameBtn = new QPushButton("Start Game", _w);
	startGameBtn->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	startGameBtn->setGeometry(500, 400, 200, 50);
	QObject::connect(startGameBtn, SIGNAL(clicked()), this, SLOT(hide5btn()));

	loadGameBtn = new QPushButton("Load Game", _w);
	loadGameBtn->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	loadGameBtn->setGeometry(500, 475, 200, 50);

	leaderboardBtn = new QPushButton("Leaderboard", _w);
	leaderboardBtn->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	leaderboardBtn->setGeometry(500, 550, 200, 50);

	settingBtn = new QPushButton("Setting", _w);
	settingBtn->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	settingBtn->setGeometry(500, 625, 200, 50);

	gameIntroBtn = new QPushButton("Introduction", _w);
	gameIntroBtn->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	gameIntroBtn->setGeometry(500, 700, 200, 50);
    
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
    QObject::connect(backBtn, SIGNAL(clicked()), this, SLOT(show5btn()));
}
