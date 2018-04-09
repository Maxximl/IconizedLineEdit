#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QPushButton>
#include <QWidget>
class Iconz;

class Mainwidget : public QWidget
{
    Q_OBJECT
public:
    explicit Mainwidget(QWidget *parent = 0);

private:
    void createUi();
private:
    Iconz *iconLine;
    Iconz *iconLine2;
    Iconz *iconLine3;
    Iconz *iconLine4;
    Iconz *iconLine5;
    QPushButton *btn;
private slots:
     void slotChooseFile();
};

#endif // MAINWIDGET_H
