#include "system.h"
#include "ui_system.h"

#include <QMovie>

System::System(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::System)
{
    ui->setupUi(this);
}

System::~System()
{
    delete ui;
}

void displaySys()
{
    // System Information
    QMovie *movie_sys = new QMovie(":/myImage/image/sys.gif");
    ui->sysImg->setMovie(movie_sys);
    ui->sysImg->setScaledContents(true);
    movie_sys->start();
}
