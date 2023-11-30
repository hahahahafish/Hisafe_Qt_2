#ifndef SYSTEM_H
#define SYSTEM_H

#include <QWidget>

namespace Ui {
class System;
}

class System : public QWidget
{
    Q_OBJECT

public:
    explicit System(QWidget *parent = nullptr);
    ~System();

public slots:
    void displaySys();

private:
    Ui::System *ui;
};

#endif // SYSTEM_H
