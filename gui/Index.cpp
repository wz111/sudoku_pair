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
	startGame->hide();
	loadGame->hide();
	leaderboard->hide();
	setting->hide();
	gameIntro->hide();
	sudokuShow();
}

void Index::sudokuShow() const
{
	for (int i = 0; i < 81; i++)
	{
		sudoku[i]->show();
	}
}

void Index::init()
{
	startGame = new QPushButton("Start Game", _w);
	startGame->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	startGame->setGeometry(500, 400, 200, 50);
	QObject::connect(startGame, SIGNAL(clicked()), this, SLOT(hide5btn()));

	loadGame = new QPushButton("Load Game", _w);
	loadGame->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	loadGame->setGeometry(500, 475, 200, 50);

	leaderboard = new QPushButton("Leaderboard", _w);
	leaderboard->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	leaderboard->setGeometry(500, 550, 200, 50);

	setting = new QPushButton("Setting", _w);
	setting->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	setting->setGeometry(500, 625, 200, 50);

	gameIntro = new QPushButton("Introduction", _w);
	gameIntro->setStyleSheet("font-size:30px;background-color: #a9a9a9;");
	gameIntro->setGeometry(500, 700, 200, 50);

	for (int i = 0; i < 81; i++)
	{
		sudoku[i] = new QPushButton("", _w);
		sudoku[i]->setStyleSheet("font-size:30px;background-color:pink;");
		sudoku[i]->setGeometry(40 + (i % 9) * 80, 40 + (i / 9) * 80, 80, 80);
		sudoku[i]->hide();
	}
}
