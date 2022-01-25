#include "mainwindow.h"
#include "ui_mainwindow.h"

int last_type = -1;
int last_type_tmp = 0;
int gesture_idx = 0;
static int track_num;
static int now_track_num;

cv::Mat HGR_img;

#define cam_w 960
#define cam_h 540

#define gesture_w 330
#define gesture_h 281

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void *main_client(void *argv);
void *thClient(void *arg); //쓰레드 시작 함수

int cntNum = 0; //client count

std::string strGesture[] =
    {"Check", "Fist", "Flat Hand", "Hand Down", "Hand Up",
     "No Gesture", "Show Five Fingers", "Show Two Fingers", "Stop Sign", "Thumb Left",
     "Thumb Right", "Thumb Up", "Zero"};

std::vector<pthread_t> vclient;

//mutex
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int listen_sock, client_sock[THREAD_NUM];

pthread_t tid[THREAD_NUM];

///////////////////////////////////////////////////////////////

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->play->setStyleSheet("border-image:url(:/icon/background.png);");
//    ui->stop->setStyleSheet("border-image:url(:/icon/background.png);");
//    ui->next->setStyleSheet("border-image:url(:/icon/background.png);");
//    ui->pause->setStyleSheet("border-image:url(:/icon/background.png);");
//    ui->previous->setStyleSheet("border-image:url(:/icon/background.png);");
    fileMenu = menuBar()->addMenu(tr("&Menu"));
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcut(tr("Ctrl+O"));
    connect(newAct, SIGNAL(triggered()),this,SLOT(open_floder()));
    server_open = new QAction(tr("&Server"), this);
    server_open->setShortcut(tr("Ctrl+P"));
    connect(server_open, SIGNAL(triggered()),this,SLOT(start_server()));
    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcut(tr("Ctrl+X"));
    connect(exitAct, SIGNAL(triggered()),this,SLOT(exit_GUI()));

    fileMenu->addAction(newAct);
    fileMenu->addAction(server_open);
    fileMenu->addAction(exitAct);

    timer = new QTimer(this);
    timer2 = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Print_Gesture()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(Print_UI()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::open_floder()
{
    ///MUSIC PLAYER///
    A_player = new QMediaPlayer;
    A_playerlist = new QMediaPlaylist(A_player);

    QString directory = QFileDialog::getExistingDirectory(this,tr("Select dir for files to import"));
    if(directory.isEmpty())
        return;
    Q_path = directory;
    QDir dir(directory);
    files = dir.entryList(QStringList() << "*.mp3",QDir::Files);
    QList<QMediaContent> content;
    for(const QString& f:files)
    {
        content.push_back(QUrl::fromLocalFile(dir.path()+"/" + f));
        QFileInfo fi(f);
        ui->list->addItem(fi.fileName());
    }

    A_playerlist->addMedia(content);
    ui->list->setCurrentRow(A_playerlist->currentIndex() != -1? A_playerlist->currentIndex():0);

    A_player->setPlaylist(A_playerlist);
    A_player->setVolume(50);
    track_num = ui->list->count() - 1;
    now_track_num = 0;
///////////////////////////////////////////////////////////////////////////////////////////////////
}

void MainWindow::start_server()
{
    int CNT = 0;
    int C_SOCK[THREAD_NUM];
    pthread_t client_t[THREAD_NUM];
    pthread_create(&client_t[CNT], nullptr, &main_client, (void *)&C_SOCK[CNT]);
    timer->start(33);
    timer2->start(33);
//    sleep(1);
//    c_thread->start();

//    timer->start(33);
}

void MainWindow::Print_UI()
{
    HGR = HGR_img;
    if(HGR.empty())
    {

    }
//        //cout << "NO HGR_IMG !!!!" << endl;
    else {
        //cout << last_type_tmp << endl;
        //cout << strGesture[last_type_tmp] << endl;

        cvtColor(HGR, HGR, cv::COLOR_BGR2RGB);
        cv::resize(HGR, HGR, cv::Size(cam_w, cam_h));
        QImage dest((const uchar *)HGR.data, HGR.cols, HGR.rows, HGR.step, QImage::Format_RGB888);
        dest.bits();

        QPixmap q_p_album = QPixmap::fromImage(dest);
        ui->HGR_I->setPixmap(q_p_album.scaled(cam_w,cam_h,Qt::KeepAspectRatio));
        ui->HGR_I->repaint();
    }
}
void MainWindow::exit_GUI()
{
    timer->stop();
    timer2->stop();
    qApp->exit();
}

///MUSIC PLAYER///
void MainWindow::Print_Gesture()
{
//    ui->previous_2->setStyleSheet("background-color: white");
//    ui->next_2->setStyleSheet("background-color: white");
//    ui->play_2->setStyleSheet("background-color: white");
//    ui->stop_2->setStyleSheet("background-color: white");
//    ui->pause_2->setStyleSheet("background-color: white");
    //cout << strGesture[last_type_tmp] << endl;
    if(strGesture[gesture_idx] == "Thumb Right")
    {
        on_next_2_clicked();
        gesture_idx = 0;
    }
    else if(strGesture[gesture_idx] == "Thumb Left")
    {
        on_previous_2_clicked();
        gesture_idx = 0;
    }
    else if(strGesture[gesture_idx] == "Thumb Up")
    {

    }
    else if(strGesture[gesture_idx] == "Show Five Fingers")
    {
        on_pause_2_clicked();
        gesture_idx = 0;
    }
    else if(strGesture[gesture_idx] == "Zero")
    {
        on_stop_2_clicked();
        gesture_idx = 0;
    }
    else if(strGesture[gesture_idx] == "Show Two Fingers")
    {
        on_play_2_clicked();
        gesture_idx = 0;
    }
//    else {
//        QPixmap gesture_img("../hand_img/no_gesture.png");
//        ui->print->setPixmap(gesture_img.scaled(gesture_w, gesture_h, Qt::KeepAspectRatio));
//        ui->print->repaint();
//    }
//    timer->stop();
}


void MainWindow::on_previous_2_clicked()
{
    //qDebug() << now_track_num << endl;
    if(now_track_num != 0)
    {
        now_track_num--;
        find_soundfile_name();
        print_album_img(Q_file_name);
        A_playerlist->previous();
        ui->list->setCurrentRow(now_track_num);
        ui->previous_2->setChecked(true);
        ui->next_2->setChecked(false);
        ui->play_2->setChecked(false);
        ui->stop_2->setChecked(false);
        ui->pause_2->setChecked(false);
//        qDebug() << "Previous Music" << endl;
        ui->label->setText("Previous Track");
        ui->previous_2->setStyleSheet("background-color: orange");
        ui->next_2->setStyleSheet("background-color: white");
        ui->play_2->setStyleSheet("background-color: white");
        ui->stop_2->setStyleSheet("background-color: white");
        ui->pause_2->setStyleSheet("background-color: white");
        QPixmap q_p_album("../hand_img/thumb_left.png");
        ui->print->setPixmap(q_p_album.scaled(gesture_w,gesture_h,Qt::KeepAspectRatio));
        ui->print->repaint();
    }
}

void MainWindow::on_next_2_clicked()
{
    if(now_track_num < track_num && now_track_num >= 0)
    {
        now_track_num++;
        qDebug() << "++ : " << now_track_num << "\t" << track_num << endl;

        find_soundfile_name();
        print_album_img(Q_file_name);
        A_playerlist->next();
        ui->list->setCurrentRow(now_track_num);
        ui->previous_2->setChecked(false);
        ui->next_2->setChecked(true);
        ui->play_2->setChecked(false);
        ui->stop_2->setChecked(false);
        ui->pause_2->setChecked(false);
//        qDebug() << "Next Music" << endl;
        ui->label->setText("Next Track");
        ui->previous_2->setStyleSheet("background-color: white");
        ui->next_2->setStyleSheet("background-color: orange");
        ui->play_2->setStyleSheet("background-color: white");
        ui->stop_2->setStyleSheet("background-color: white");
        ui->pause_2->setStyleSheet("background-color: white");
        QPixmap q_p_album("../hand_img/thumb_right.png");
        ui->print->setPixmap(q_p_album.scaled(gesture_w,gesture_h,Qt::KeepAspectRatio));
        ui->print->repaint();
    }
}

void MainWindow::on_play_2_clicked()
{
    find_soundfile_name();
    print_album_img(Q_file_name);

    ui->list->setCurrentRow(now_track_num);
    A_player->play();
    ui->previous_2->setChecked(false);
    ui->next_2->setChecked(false);
    ui->play_2->setChecked(true);
    ui->stop_2->setChecked(false);
    ui->pause_2->setChecked(false);
//    change_Volume();
    //qDebug() << "Play Music" << endl;
    ui->label->setText("Play Track");
//    timer->start(1000);
    ui->previous_2->setStyleSheet("background-color: white");
    ui->next_2->setStyleSheet("background-color: white");
    ui->play_2->setStyleSheet("background-color: orange");
    ui->stop_2->setStyleSheet("background-color: white");
    ui->pause_2->setStyleSheet("background-color: white");
    QPixmap q_p_album("../hand_img/two_finger.png");
    ui->print->setPixmap(q_p_album.scaled(gesture_w,gesture_h,Qt::KeepAspectRatio));
    ui->print->repaint();
}

void MainWindow::on_stop_2_clicked()
{
    A_player->stop();
    ui->previous_2->setChecked(false);
    ui->next_2->setChecked(false);
    ui->play_2->setChecked(true);
    ui->stop_2->setChecked(false);
    ui->pause_2->setChecked(false);
//    change_Volume();
    //qDebug() << "Stop Music" << endl;
    ui->label->setText("Stop Track");
    ui->previous_2->setStyleSheet("background-color: white");
    ui->next_2->setStyleSheet("background-color: white");
    ui->play_2->setStyleSheet("background-color: white");
    ui->stop_2->setStyleSheet("background-color: orange");
    ui->pause_2->setStyleSheet("background-color: white");
    QPixmap q_p_album("../hand_img/zero_hand.png");
    ui->print->setPixmap(q_p_album.scaled(gesture_w,gesture_h,Qt::KeepAspectRatio));
    ui->print->repaint();
}

void MainWindow::on_pause_2_clicked()
{
    A_player->pause();
    ui->previous_2->setChecked(false);
    ui->next_2->setChecked(false);
    ui->play_2->setChecked(true);
    ui->stop_2->setChecked(false);
    ui->pause_2->setChecked(false);
//    change_Volume();
    //qDebug() << "Pause Music" << endl;
    ui->label->setText("Pause Track");
    ui->previous_2->setStyleSheet("background-color: white");
    ui->next_2->setStyleSheet("background-color: white");
    ui->play_2->setStyleSheet("background-color: white");
    ui->stop_2->setStyleSheet("background-color: white");
    ui->pause_2->setStyleSheet("background-color: orange");
    QPixmap q_p_album("../hand_img/five_fingers.png");
    ui->print->setPixmap(q_p_album.scaled(gesture_w,gesture_h,Qt::KeepAspectRatio));
    ui->print->repaint();
}

string MainWindow::qstring_2_string(QString qs)
{
    string tr_st = qs.toLocal8Bit().constData();
    return tr_st;
}

QString MainWindow::string_2_qstring(string str)
{
    QString qstr = QString::fromStdString(str);
    return qstr;
}

void MainWindow::print_album_img(QString name)
{
    QPixmap q_p_album(Q_path+"/"+name+"png");

    if(q_p_album.isNull())
    {
        q_p_album.load(Q_path+"/"+"eql.png");
        //qDebug() << "Eqalizer image print" << endl;
    }
    else
    {
        //qDebug() << " img load" << endl;
    }
    ui->album->setPixmap(q_p_album.scaled(cam_w,cam_h,Qt::KeepAspectRatio));
    ui->album->repaint();
}

void MainWindow::find_soundfile_name()
{
    string file_name = "";
    int tmp = 0;
    now_file_name = files.at(now_track_num);
    //qDebug() << "find sound name 1st " <<  now_file_name << endl;
    now_played_file = qstring_2_string(now_file_name);
    for(int i = 0; i <= 100; i++)
    {
        st2ch[i] = 0;
    }
    strcpy(st2ch,now_played_file.c_str());

    for(int i = 100; i >= 0; i--)
    {
        if(st2ch[i] != 0)
        {
            if(st2ch[i] == '.')
            {
                tmp = i;
                break;
            }
        }
    }
    file_name = "";
    for(int j = 0; j <= tmp; j++)
    {
        file_name += st2ch[j];
    }

    Q_file_name = string_2_qstring(file_name);
}

void *main_client(void *argv)
{
    struct sockaddr_in servaddr, cliaddr;
    int addrlen = sizeof(servaddr);
    int i, status;
    pid_t pid;
    short port_num = 7777;

    if ((listen_sock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket Fail");
        //cout << "socket fail" << endl;
        exit(0);
    }
    qDebug() << "Server Start" << endl;
    memset(&servaddr, 0, sizeof(servaddr)); //0으로 초기화
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port_num);



    int optvalue=1;
    setsockopt(listen_sock,SOL_SOCKET,SO_REUSEADDR,&optvalue,sizeof(optvalue));

    //bind 호출
    if (bind(listen_sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind Fail");
        //cout << "bind fail" << endl;
        exit(0);
    }

    while (1)
    {
        listen(listen_sock, LISTENQ);

        puts("client wait....");

        client_sock[cntNum] = accept(listen_sock, (struct sockaddr *)&cliaddr, (socklen_t *)&addrlen);
        if (client_sock[cntNum] < 0)
        {
            perror("accept fail");
            //cout << "accept fail" << endl;
            exit(0);
        }

        puts("ACCEPT....");

        if ((status = pthread_create(&tid[cntNum], NULL, &thClient, (void *)&client_sock[cntNum])) != 0)
        {
            //cout << cntNum << " thread create error : " << strerror(status) << endl;
            exit(0);
        }
        //cout << "client thread run....." << endl;

        //-종료대기 : 멀티 클라이언트를 핸들링하는 서버는 리스팅하고 이 루푸 밖에서 종료 대기해야 됨
        cntNum++;
        if (cntNum == 5)
            cntNum = 0;

        vclient.push_back(tid[cntNum]);
    }

    //cout << "client thread make ready to close---" << endl;

    for(auto& tid : vclient)
    {
        pthread_join(tid, nullptr);
    }

    //cout << "client thread END" << endl;


//    return 0;
}

void *thClient(void *arg)
{
    int client_sock = (int)*((int *)arg);
    char *buf = new char[cam_w * cam_h * 3];
    int w = cam_w;
    int h = cam_h;
    int count_predict[13];
//    std::string wndname = "Realsense";
//    namedWindow(wndname);
    MainWindow mw;
    while (true)
    {
        PACKET_HDR hdr;
        int nread = read(client_sock, &hdr, sizeof(hdr));
        if (nread < sizeof(hdr))
        {
            // 더 읽어야 된다.
            // 여기서는 에러 처리만 함.
            printf("recv --HDR-- buffer is too short\n");
//            SharedVars::getInstance().log(FORMAT("recv --HDR-- buffer is too short : received %d but should be %d", nread, sizeof(hdr)), true);
            //cout << "recv --HDR-- buffer is too short : received " << nread << " but should be " << sizeof(hdr) << endl;
            break;
        }

//        SharedVars::getInstance().log(FORMAT("PID = %d", hdr.pid), true);
        int nLeftOver = hdr.len;
        int nTotal = 0;
        while (true)
        {
            nread = read(client_sock, &buf[nTotal], nLeftOver);
            nLeftOver -= nread;
            nTotal += nread;

            if (nTotal >= hdr.len)
            {
                break;
            }
        }

        if (hdr.gid != GID_REALSENSE)
        {
            puts("Realsense only!!!!!!!");
            //cout << "Realsense only!!!!" << endl;
            sleep(1);
            continue;
        }

        cv::Mat image;

        switch (hdr.pid)
        {
        case PID_VIDEOTYPE_DEPTH:
        {
            puts("PID_VIDEOTYPE_DEPTH");
            Mat tmp(Size(w, h), CV_16UC1, (void *)buf, Mat::AUTO_STEP);
            tmp.convertTo(tmp, CV_8UC1, 255.0 / 1000.0);
            image = tmp;
        }
        break;
        case PID_VIDEOTYPE_DEPTH_COLOR:
        {
            puts("PID_VIDEOTYPE_DEPTH_COLOR");
            Mat tmp(Size(w, h), CV_8UC3, (void *)buf, Mat::AUTO_STEP);
            image = tmp;
//            SharedVars::getInstance().log("PID_VIDEOTYPE_DEPTH_COLOR image", true);
            //cout << "PID_VIDEOTYPE_DEPTH_COLOR image" << endl;
        }
        break;
        case PID_VIDEOTYPE_COLOR:
        {
            Mat tmp(Size(w, h), CV_8UC3, (void *)buf, Mat::AUTO_STEP);
//            //cout << tmp << endl;
            // cvtColor(tmp, tmp, cv::COLOR_BGR2RGB);
            image = tmp;
        }
        break;
        case PID_COMMAND_PREDICT:
        {
            int type = -1;
            memcpy(&type, buf, hdr.len);
//            printf("Predict as %d\n", type);
            if (type >= 0)
            {
                last_type = type;
                last_type_tmp = last_type - 1;
                //cout << last_type << endl;
                count_predict[last_type_tmp]++;
            }
            continue;
        }
        break;

        default:
            break;
        }

//        std::string txtPredict = "Predict" + std::to_string(last_type) + strGesture[last_type - 1].c_str();
//        cv::putText(image, txtPredict, cv::Point(10, 40), 2, 1.2, Scalar::all(255));
        if(count_predict[last_type_tmp] >= 5)
        {
            if(strGesture[last_type_tmp] == "Thumb Left" || strGesture[last_type_tmp] == "Thumb Right"
                    || strGesture[last_type_tmp] == "Show Two Fingers" || strGesture[last_type_tmp] == "Show Five Fingers"
                    || strGesture[last_type_tmp] == "Zero")
            {
                gesture_idx = last_type_tmp;
                std::string txtPredict = "Predict(" + std::to_string(last_type_tmp) + ") - " + strGesture[last_type_tmp].c_str();
                cv::putText(image, txtPredict, cv::Point(10, 40), 2, 1.2, Scalar::all(255));
            }

            HGR_img = image;
//            mw.Print_Gesture();
//            mw.timer->start();
            count_predict[last_type_tmp] = 0;
        }
    }

    if (buf)
    {
        delete[] buf;
        buf = nullptr;
    }
    close(client_sock);

//    SharedVars::getInstance().log("End of client socket", true);
    //cout << "END of client socket" << endl;
}
