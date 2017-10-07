#include "SudokuGUI.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include "Index.h"
QPushButton *gameIntro;

void Recv::startGame() const
{
	
}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SudokuGUI w;
	Recv recv;
	w.resize(1200, 800);
	Index index(&recv, &w);
	index.init();

	w.show();
	return a.exec();
}
