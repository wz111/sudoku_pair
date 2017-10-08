#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SudokuGUI.h"
#include <QDateTime>
#include <QTimer>
#include <QTime>


class SudokuGUI : public QMainWindow
{
	Q_OBJECT

public:
	SudokuGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::SudokuGUIClass ui;
};

class Recv : public QObject
{
	Q_OBJECT

public:
	Recv() {}
	
};