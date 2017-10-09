#include "SudokuGUI.h"
#include <QtWidgets/QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QTime>
#include <QTimer>
#include <QDateTime>
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
	w.setObjectName("myWindow");
	w.setStyleSheet("#myWindow{border-image:url(MainImage/main.jpg);}");

	Index index(&recv, &w);
	index.init();
	w.show();

	return a.exec();
}
