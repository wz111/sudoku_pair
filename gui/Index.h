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
    QPushButton *leaderBackBtn;

    QPushButton *modeStartBtn;

    QButtonGroup *modeGroup;
    QRadioButton *easyBtn;
    QRadioButton *mediumBtn;
    QRadioButton *hardBtn;

    QButtonGroup *softKeyGroup;

    QLabel *titleLabel;
    QLabel *introLabel;
    QLabel *modeLabel;

    QTimer * timer;      //¶¨Ê±Æ÷ Ã¿Ãë¸üÐÂÊ±¼ä
    QTime * timeRecord;  //¼ÇÂ¼Ê±¼ä
    bool isStart;        //¼ÇÂ¼ÊÇ·ñÒÑ¾­¿ªÊ¼¼ÆÊ±

    QLabel *timeLabel;

    QPushButton *softKey[10];

    bool sudokuChecked;
    QLabel *leaderTitle;
    QLabel *easyLeader;
    QLabel *mediumLeader;
    QLabel *hardLeader;
    QLabel *easyTime;
    QLabel *mediumTime;
    QLabel *hardTime;

    QIcon unselectIcon;
    QIcon selectedIcon;

public:
    Index(Recv *recv, SudokuGUI *w);
    ~Index();
    void init();
    void initSudoku();
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
    void generateQuery() const;

    void updateTime() const;
    void startTimer() const;
    void stopTimer() const;

    void generateNew() const;
    void fillBox() const;
    void giveHint() const;
    void checkSudoku() const;

    void showLeaderboard() const;
    void hideLeaderboard() const;
};

