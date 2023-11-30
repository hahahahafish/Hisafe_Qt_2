#include "widget.h"
#include "./ui_widget.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QMovie>
#include <QPixmap>
#include <QTableWidget>
#include <QHeaderView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("HiSafe");

    // System Information
    QMovie *movie_sys = new QMovie(":/myImage/image/sys.gif");
    ui->sysImg->setMovie(movie_sys);
    ui->sysImg->setScaledContents(true);
    movie_sys->start();

    // H/W Monitor
    QMovie *movie_hwm = new QMovie(":/myImage/image/hwm.gif");
    ui->hwmImg->setMovie(movie_hwm);
    ui->hwmImg->setScaledContents(true);
    movie_hwm->start();

    // Digital IO
    QMovie *movie_dio = new QMovie(":/myImage/image/DIO.gif");
    ui->dioImg->setMovie(movie_dio);
    ui->dioImg->setScaledContents(true);
    movie_dio->start();

    // WatchDog
    QMovie *movie_wdt = new QMovie(":/myImage/image/wdt.gif");
    ui->wdtImg->setMovie(movie_wdt);
    ui->wdtImg->setScaledContents(true);
    movie_wdt->start();

    // Smbus
    QMovie *movie_bus = new QMovie(":/myImage/image/bus.gif");
    ui->busImg->setMovie(movie_bus);
    ui->busImg->setScaledContents(true);
    movie_bus->start();

    // Smart Fan
    QMovie *movie_fan = new QMovie(":/myImage/image/fan.gif");
    ui->fanImg->setMovie(movie_fan);
    ui->fanImg->setScaledContents(true);
    movie_fan->start();

    // Backlight
    QMovie *movie_light = new QMovie(":/myImage/image/backlight.gif");
    ui->lightImg->setMovie(movie_light);
    ui->lightImg->setScaledContents(true);
    movie_light->start();

    connect(ui->tabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(on_tabWidget_currentChanged(int)));
    ui->comboBox->setStyleSheet("QComboBox{background-color:rgb(255,255,255);}");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_tabWidget_currentChanged(int index)
{
    if(index == 0){
        // System Information

    }else if(index == 1){
        // H/W Monitor

    }else if(index == 2){
        // Digital IO

        // table space
        /*ui->tableWidget->verticalHeader()->setDefaultSectionSize(65);
        ui->tableWidget->horizontalHeader()->resizeSection(0,250);
        ui->tableWidget->horizontalHeader()->resizeSection(1,250);
        ui->tableWidget->horizontalHeader()->resizeSection(2,350);
        ui->tableWidget->horizontalHeader()->resizeSection(3,350);*/

        // Setting Mode
        for (int i=0; i<4; i++) {

            // mode radiobutton
            outBtn = new QRadioButton(tr("Output"), this);
            outBtn->setObjectName("outBtn");
            outBtn->setStyleSheet("QRadioButton::unchecked{color:rgb(255, 255, 255);}\
                                   QRadioButton::checked{color:rgb(100, 149, 237);}\
                                   QRadioButton::indicator{width:15px;height:15px;border-radius:5px}\
                                   QRadioButton::indicator:unchecked{background-color:rgb(255, 255, 255);}\
                                   QRadioButton::indicator:checked{background-color:rgb(100, 149, 237);}");

            inBtn = new QRadioButton(tr("Input"), this);
            inBtn->setObjectName("inBtn");
            inBtn->setStyleSheet("QRadioButton::unchecked{color:rgb(255, 255, 255)}\
                                  QRadioButton::checked{color:rgb(144, 238, 144);}\
                                  QRadioButton::indicator{width:15px;height:15px;border-radius:5px}\
                                  QRadioButton::indicator:unchecked{background-color:rgb(255, 255, 255);}\
                                  QRadioButton::indicator:checked{background-color:rgb(144, 238, 144);}");

            modeGroup = new QButtonGroup(this);
            modeGroup->addButton(outBtn, 1);
            modeGroup->addButton(inBtn, 2);
            inBtn->setChecked(true);

            // layout
            modeWidget[i] = new QWidget(this);
            modeLayout[i] = new QHBoxLayout(modeWidget[i]);
            modeLayout[i]->addStretch(1);
            modeLayout[i]->addWidget(outBtn);
            modeLayout[i]->addStretch(1);
            modeLayout[i]->addWidget(inBtn);
            modeLayout[i]->addStretch(1);
            modeWidget[i]->setLayout(modeLayout[i]);

            ui->tableWidget->setCellWidget(i, 2, modeWidget[i]);

            inImg = new QLabel(this);
            inImg->setStyleSheet("border-image: url(:/myImage/image/in.png);");
            inImg->setFixedSize(90, 40);

            c_modeWidget[i] = new QWidget(this);
            c_modeLayout[i] = new QHBoxLayout(c_modeWidget[i]);
            c_modeLayout[i]->addWidget(inImg);
            c_modeLayout[i]->setAlignment(inImg, Qt::AlignCenter);
            c_modeWidget[i]->setLayout(c_modeLayout[i]);

            ui->tableWidget->setCellWidget(i, 0, c_modeWidget[i]);
        }

        for (int i=4; i<8; i++) {
            // mode radiobutton
            outBtn = new QRadioButton(tr("Output"),this);
            outBtn->setObjectName("outBtn");
            outBtn->setStyleSheet("QRadioButton::unchecked{color:rgb(255, 255, 255);}\
                                   QRadioButton::checked{color:rgb(100, 149, 237);}\
                                   QRadioButton::indicator{width:15px;height:15px;border-radius:5px}\
                                   QRadioButton::indicator:unchecked{background-color:rgb(255, 255, 255);}\
                                   QRadioButton::indicator:checked{background-color:rgb(100, 149, 237);}");

            inBtn = new QRadioButton(tr("Input"));
            inBtn->setObjectName("inBtn");
            inBtn->setStyleSheet("QRadioButton::unchecked{color:rgb(255, 255, 255);}\
                                  QRadioButton::checked{color:rgb(144, 238, 144);}\
                                  QRadioButton::indicator{width:15px;height:15px;border-radius:5px}\
                                  QRadioButton::indicator:unchecked{background-color:rgb(255, 255, 255);}\
                                  QRadioButton::indicator:checked{background-color:rgb(144, 238, 144);}");

            modeGroup = new QButtonGroup(this);
            modeGroup->addButton(outBtn, 1);
            modeGroup->addButton(inBtn, 2);
            outBtn->setChecked(true);

            // layout
            modeWidget[i] = new QWidget(this);
            modeLayout[i] = new QHBoxLayout(modeWidget[i]);
            modeLayout[i]->addStretch(1);
            modeLayout[i]->addWidget(outBtn);
            modeLayout[i]->addStretch(1);
            modeLayout[i]->addWidget(inBtn);
            modeLayout[i]->addStretch(1);
            modeWidget[i]->setLayout(modeLayout[i]);

            ui->tableWidget->setCellWidget(i, 2, modeWidget[i]);

            outImg = new QLabel(this);
            outImg->setStyleSheet("border-image: url(:/myImage/image/out.png);");
            outImg->setFixedSize(90, 40);
            c_modeWidget[i] = new QWidget(this);
            c_modeLayout[i] = new QHBoxLayout(c_modeWidget[i]);
            c_modeLayout[i]->addWidget(outImg);
            c_modeLayout[i]->setAlignment(outImg, Qt::AlignCenter);
            c_modeWidget[i]->setLayout(c_modeLayout[i]);

            ui->tableWidget->setCellWidget(i, 0, c_modeWidget[i]);
        }

        // Setting Value
        for (int i=0; i<8; i++) {

            // mode radiobutton
            lowBtn = new QRadioButton(tr("Low"),this);
            lowBtn->setObjectName("lowBtn");
            lowBtn->setStyleSheet("QRadioButton::unchecked{color:rgb(255, 255, 255);}\
                                  QRadioButton::checked{color:rgb(144, 238, 144);}\
                                  QRadioButton::indicator{width:15px;height:15px;border-radius:5px}\
                                  QRadioButton::indicator:unchecked{background-color:rgb(255, 255, 255);}\
                                  QRadioButton::indicator:checked{background-color:rgb(144, 238, 144);}");

            highBtn = new QRadioButton(tr("High"),this);
            highBtn->setObjectName("highBtn");
            highBtn->setStyleSheet("QRadioButton::unchecked{color:rgb(255, 255, 255);}\
                                   QRadioButton::checked{color:rgb(100, 149, 237);}\
                                   QRadioButton::indicator{width:15px;height:15px;border-radius:5px}\
                                   QRadioButton::indicator:unchecked{background-color:rgb(255, 255, 255);}\
                                   QRadioButton::indicator:checked{background-color:rgb(100, 149, 237);}");
            valueGroup = new QButtonGroup(this);
            valueGroup->addButton(lowBtn, 1);
            valueGroup->addButton(highBtn, 2);
            highBtn->setChecked(true);

            // layout
            valueWidget[i] = new QWidget(this);
            valueLayout[i] = new QHBoxLayout(valueWidget[i]);
            valueLayout[i]->addStretch(1);
            valueLayout[i]->addWidget(lowBtn);
            valueLayout[i]->addStretch(1);
            valueLayout[i]->addWidget(highBtn);
            valueLayout[i]->addStretch(1);
            valueWidget[i]->setLayout(valueLayout[i]);

            ui->tableWidget->setCellWidget(i, 3, valueWidget[i]);

            highImg = new QLabel(tr("High"),this);
            highImg->setStyleSheet("QLabel {color:rgb(100, 149, 237);}\
                                    QLabel {font-size:20px;}");
            c_valueWidget[i] = new QWidget(this);
            c_valueLayout[i] = new QHBoxLayout(c_valueWidget[i]);
            c_valueLayout[i]->addWidget(highImg);
            c_valueLayout[i]->setAlignment(highImg, Qt::AlignCenter);
            c_valueWidget[i]->setLayout(c_valueLayout[i]);

            ui->tableWidget->setCellWidget(i, 1, c_valueWidget[i]);
        }
        //ui->tableWidget->resizeColumnsToContents();
        //ui->tableWidget->resizeRowsToContents();
        QObject::connect(ui->dio_setBtn, SIGNAL(clicked(bool)), this, SLOT(on_dio_setBtn_clicked()));
    }else if(index == 3){
        // WatchDog

    }else if(index == 4){
        // Smbus

    }else if(index == 5){
        // Smart Fan
    }else if(index == 6){
        // Backlight
    }
}


void Widget::on_dio_setBtn_clicked()
{
    for(int i=0; i<ui->tableWidget->rowCount(); i++){
        QWidget *widget = ui->tableWidget->cellWidget(i, 2);
        if(widget){
            QRadioButton *radioButton = widget->findChild<QRadioButton*>("outBtn");
            if(radioButton && radioButton->isChecked()){
                outImg = new QLabel(this);
                outImg->setStyleSheet("border-image: url(:/myImage/image/out.png);");
                outImg->setFixedSize(90, 40);
                c_modeWidget[i] = new QWidget(this);
                c_modeLayout[i] = new QHBoxLayout(c_modeWidget[i]);
                c_modeLayout[i]->addWidget(outImg);
                c_modeLayout[i]->setAlignment(outImg, Qt::AlignCenter);
            }else{
                inImg = new QLabel(this);
                inImg->setStyleSheet("border-image: url(:/myImage/image/in.png);");
                inImg->setFixedSize(90,40);
                c_modeWidget[i] = new QWidget(this);
                c_modeLayout[i] = new QHBoxLayout(c_modeWidget[i]);
                c_modeLayout[i]->addWidget(inImg);
                c_modeLayout[i]->setAlignment(inImg, Qt::AlignCenter);
            }
            c_modeWidget[i]->setLayout(c_modeLayout[i]);
            ui->tableWidget->setCellWidget(i, 0, c_modeWidget[i]);
        }
    }

    for(int i=0; i<ui->tableWidget->rowCount(); i++){
        QWidget *widget = ui->tableWidget->cellWidget(i, 3);
        if(widget){
            QRadioButton *radioButton = widget->findChild<QRadioButton*>("lowBtn");
            if(radioButton && radioButton->isChecked()){
                lowImg = new QLabel(tr("Low"),this);
                lowImg->setStyleSheet("QLabel {color:rgb(144, 238, 144);}\
                                       QLabel {font-size:20px;}");
                c_valueWidget[i] = new QWidget(this);
                c_valueLayout[i] = new QHBoxLayout(c_valueWidget[i]);
                c_valueLayout[i]->addWidget(lowImg);
                c_valueLayout[i]->setAlignment(lowImg, Qt::AlignCenter);
            }else{
                highImg = new QLabel(tr("High"),this);
                highImg->setStyleSheet("QLabel {color:rgb(100, 149, 237);}\
                                        QLabel {font-size:20px;}");
                c_valueWidget[i] = new QWidget(this);
                c_valueLayout[i] = new QHBoxLayout(c_valueWidget[i]);
                c_valueLayout[i]->addWidget(highImg);
                c_valueLayout[i]->setAlignment(highImg, Qt::AlignCenter);
            }
            c_valueWidget[i]->setLayout(c_valueLayout[i]);
            ui->tableWidget->setCellWidget(i, 1, c_valueWidget[i]);
        }
    }
}
