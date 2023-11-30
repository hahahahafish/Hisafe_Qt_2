#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QLabel>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_tabWidget_currentChanged(int index);

    void on_dio_setBtn_clicked();

private:
    Ui::Widget *ui;

    QWidget *modeWidget[8];
    QHBoxLayout *modeLayout[8];
    QRadioButton *outBtn;
    QRadioButton *inBtn;
    QButtonGroup *modeGroup;
    QWidget *c_modeWidget[8];
    QHBoxLayout *c_modeLayout[8];
    QLabel *outImg;
    QLabel *inImg;

    QWidget *valueWidget[8];
    QHBoxLayout *valueLayout[8];
    QRadioButton *lowBtn;
    QRadioButton *highBtn;
    QButtonGroup *valueGroup;
    QWidget *c_valueWidget[8];
    QHBoxLayout *c_valueLayout[8];
    QLabel *lowImg;
    QLabel *highImg;
};
#endif // WIDGET_H
