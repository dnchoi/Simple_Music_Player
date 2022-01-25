#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSlider>
#include <QTimer>
#include <QProcess>
#include <QThread>
#include <opencv2/opencv.hpp> // Include OpenCV API
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <vector>
//#include "SharedVars.h"
#include "packet_definitions.h"
//std::unique_ptr<SharedVars> SharedVars::mInstance;
//std::once_flag SharedVars::mOnceFlag;
#include <QMenuBar>

class QMenu;
class QAction;
class QMenuBar;

#define MAXLINE 1024 //buf 크기
#define LISTENQ 10   //Listen Q 설정
#define THREAD_NUM 5 //클라이언 동시 접속 수

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Mat HGR;
    QTimer *timer;
    QTimer *timer2;

public slots:

    void Print_Gesture();

signals:

private slots:
    void open_floder();

    void exit_GUI();

    void on_previous_2_clicked();

    void on_next_2_clicked();

    void on_play_2_clicked();

    void on_stop_2_clicked();

    void on_pause_2_clicked();

    void print_album_img(QString name);

    void find_soundfile_name();

    string qstring_2_string(QString qs);

    QString string_2_qstring(string str);

    void start_server();

//    void Print_Gesture();

    void Print_UI();

private:
    Ui::MainWindow *ui;
    QString Q_path;
    QMediaPlayer * A_player;
    QMediaPlaylist * A_playerlist;
    QSlider * slider;
    QStringList files;
    string now_played_file = "";

    QString Q_file_name = "";
    QString now_file_name;
    char st2ch[100];

    QMenu *fileMenu; QAction *newAct; QAction *exitAct; QAction *server_open;
};

#endif // MAINWINDOW_H

