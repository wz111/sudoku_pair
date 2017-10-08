#include "SudokuGUI.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include "Index.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    QFont font = a.font();
    font.setFamily(QObject::tr("Microsoft YaHei"));
    a.setFont(font);
	SudokuGUI w;
	Recv recv;
	w.resize(1200, 800);
	Index index(&recv, &w);
	index.init();

	w.show();
	return a.exec();
}
