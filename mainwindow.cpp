#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTextEdit>
#include <QSplitter>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "view.h"
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    view_ = new View(this);

    //    ui->setupUi(this);
    button_display = new QPushButton("Display",this);
    connect(button_display,SIGNAL(clicked()),this, SLOT(on_ButtonDisplay_Pushed()));

    button_magnification_up = new QPushButton("+25%",this);
    button_magnification_down = new QPushButton("-25%",this);
    button_magnification_reset = new QPushButton("100%",this);
    connect(button_magnification_up,SIGNAL(clicked()),view_, SLOT(on_ButtonMagnificationUp_Pushed()));
    connect(button_magnification_down,SIGNAL(clicked()),view_, SLOT(on_ButtonMagnificationDown_Pushed()));
    connect(button_magnification_reset,SIGNAL(clicked()),view_, SLOT(on_ButtonMagnificationReset_Pushed()));

    QWidget* central = new QWidget(this);
    this->setGeometry(0,0,700,700);
    QVBoxLayout* vLayout =new QVBoxLayout();
    vLayout->addWidget(button_magnification_up);
    vLayout->addWidget(button_magnification_reset);
    vLayout->addWidget(button_magnification_down);

    vLayout->addWidget(button_display);
    QHBoxLayout *hLayout = new QHBoxLayout(central);
    hLayout->addLayout(vLayout);

    hLayout->addWidget(view_);
    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonDisplay_Pushed()
{
    qDebug() << "onPushDisplay";
    timer = new QTimer();
    connect(timer, &QTimer::timeout,[this](){ onTimer(); });
    timer->start(1000);
}



void MainWindow::onTimer()
{
    QString fn=(i%2==0)?"c:\\a.jpg":"c:\\a2.jpg";
    qDebug("fn....:%s",fn.toUtf8().constData());

    QImage image(fn);
    view_->setImg(image);
    i++;
}

