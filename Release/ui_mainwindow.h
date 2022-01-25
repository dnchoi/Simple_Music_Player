/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionServer_start;
    QAction *actionExit;
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QLabel *HGR_I;
    QLabel *print;
    QListWidget *list;
    QLabel *album;
    QSplitter *splitter;
    QPushButton *previous_2;
    QPushButton *play_2;
    QPushButton *pause_2;
    QPushButton *stop_2;
    QPushButton *next_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *album_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 994);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionServer_start = new QAction(MainWindow);
        actionServer_start->setObjectName(QString::fromUtf8("actionServer_start"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 584, 1921, 51));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 20pt \"Ubuntu\";"));
        HGR_I = new QLabel(centralWidget);
        HGR_I->setObjectName(QString::fromUtf8("HGR_I"));
        HGR_I->setGeometry(QRect(0, 44, 960, 540));
        HGR_I->setStyleSheet(QString::fromUtf8("font: italic 36pt \"Liberation Serif\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        HGR_I->setAlignment(Qt::AlignCenter);
        print = new QLabel(centralWidget);
        print->setObjectName(QString::fromUtf8("print"));
        print->setGeometry(QRect(1590, 635, 330, 281));
        print->setStyleSheet(QString::fromUtf8("font: italic 36pt \"Liberation Serif\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        print->setAlignment(Qt::AlignCenter);
        list = new QListWidget(centralWidget);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(0, 635, 1091, 281));
        list->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        album = new QLabel(centralWidget);
        album->setObjectName(QString::fromUtf8("album"));
        album->setGeometry(QRect(960, 44, 960, 540));
        album->setStyleSheet(QString::fromUtf8("font: italic 36pt \"Liberation Serif\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        album->setAlignment(Qt::AlignCenter);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 920, 1901, 51));
        splitter->setOrientation(Qt::Horizontal);
        previous_2 = new QPushButton(splitter);
        previous_2->setObjectName(QString::fromUtf8("previous_2"));
        previous_2->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/ps.png"), QSize(), QIcon::Normal, QIcon::Off);
        previous_2->setIcon(icon);
        previous_2->setIconSize(QSize(50, 50));
        splitter->addWidget(previous_2);
        play_2 = new QPushButton(splitter);
        play_2->setObjectName(QString::fromUtf8("play_2"));
        play_2->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        play_2->setIcon(icon1);
        play_2->setIconSize(QSize(50, 50));
        splitter->addWidget(play_2);
        pause_2 = new QPushButton(splitter);
        pause_2->setObjectName(QString::fromUtf8("pause_2"));
        pause_2->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pause_2->setIcon(icon2);
        pause_2->setIconSize(QSize(50, 50));
        splitter->addWidget(pause_2);
        stop_2 = new QPushButton(splitter);
        stop_2->setObjectName(QString::fromUtf8("stop_2"));
        stop_2->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stop_2->setIcon(icon3);
        stop_2->setIconSize(QSize(50, 50));
        splitter->addWidget(stop_2);
        next_2 = new QPushButton(splitter);
        next_2->setObjectName(QString::fromUtf8("next_2"));
        next_2->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/ns.png"), QSize(), QIcon::Normal, QIcon::Off);
        next_2->setIcon(icon4);
        next_2->setIconSize(QSize(50, 50));
        splitter->addWidget(next_2);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1100, 635, 491, 281));
        QFont font;
        font.setFamily(QString::fromUtf8("Liberation Serif"));
        font.setPointSize(25);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: italic 25pt \"Liberation Serif\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 4, 361, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Liberation Serif"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        label_2->setFont(font1);
"background-color: rgba(255, 255, 255, 0);"));
        label_2->setAlignment(Qt::AlignCenter);
        album_2 = new QLabel(centralWidget);
        album_2->setObjectName(QString::fromUtf8("album_2"));
        album_2->setGeometry(QRect(1779, 0, 141, 141));
        album_2->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionServer_start->setText(QCoreApplication::translate("MainWindow", "Server start", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Two Finger -&gt; Play Track     Five Finger -&gt; Pause Track     Zero Hand -&gt; Stop Track     Thumb Left -&gt; Previous Track     Thumb Right -&gt; Next Track</span></p></body></html>", nullptr));
        HGR_I->setText(QCoreApplication::translate("MainWindow", "HGR Image", nullptr));
        print->setText(QCoreApplication::translate("MainWindow", "Gesture Image", nullptr));
        album->setText(QCoreApplication::translate("MainWindow", "Album\n"
"Image", nullptr));
        previous_2->setText(QString());
        play_2->setText(QString());
        pause_2->setText(QString());
        stop_2->setText(QString());
        next_2->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "<UI>\n"
"Music Player with Hand Gesture", nullptr));
        label_2->setText(QString());
        album_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
