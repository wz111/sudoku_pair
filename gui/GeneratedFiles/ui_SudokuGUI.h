/********************************************************************************
** Form generated from reading UI file 'SudokuGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKUGUI_H
#define UI_SUDOKUGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SudokuGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SudokuGUIClass)
    {
        if (SudokuGUIClass->objectName().isEmpty())
            SudokuGUIClass->setObjectName(QStringLiteral("SudokuGUIClass"));
        SudokuGUIClass->resize(600, 400);
        menuBar = new QMenuBar(SudokuGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SudokuGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SudokuGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SudokuGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SudokuGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SudokuGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SudokuGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SudokuGUIClass->setStatusBar(statusBar);

        retranslateUi(SudokuGUIClass);

        QMetaObject::connectSlotsByName(SudokuGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *SudokuGUIClass)
    {
        SudokuGUIClass->setWindowTitle(QApplication::translate("SudokuGUIClass", "SudokuGUI", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SudokuGUIClass: public Ui_SudokuGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUGUI_H
