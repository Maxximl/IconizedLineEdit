#include "mainwidget.h"
#include "icon.h"
#include <QVBoxLayout>
#include <QFileDialog>

Mainwidget::Mainwidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *imainwidget = new QVBoxLayout;
    setLayout(imainwidget);

    iconLine = new Iconz(this);
    iconLine->setPlaceholderText("Click to open file");
    iconLine->setIconPixmap(QPixmap("/home/maxus/EditLine/images/folder.png"));
    iconLine->setIconVisibility(Iconz::IconAlwaysVisible);
    iconLine->setIconClickable(true);
    connect(iconLine,SIGNAL(iconPressed()),this,SLOT(slotChooseFile()));
    imainwidget->addWidget(iconLine);

    iconLine2 = new Iconz;
    iconLine->setPlaceholderText("Enter IP address");
    iconLine2->setIconPixmap(QPixmap("/home/maxus/EditLine/images/samba.png"));
    iconLine2->setIconVisibility(Iconz::IconAlwaysVisible);
    imainwidget->addWidget(iconLine2);

    iconLine3 = new Iconz;
    iconLine3->setPlaceholderText("");
    iconLine3->setIconPixmap(QPixmap("/home/maxus/EditLine/images/third.png"));
    iconLine3->setIconVisibility(Iconz::IconVisibleOnTextPresense);
    imainwidget->addWidget(iconLine3);

    iconLine4 = new Iconz;
    iconLine4->setPlaceholderText("Cannot be empty");
    iconLine4->setIconPixmap(QPixmap("/home/maxus/EditLine/images/clearable.png"));
    iconLine4->setIconVisibility(Iconz::IconVisibleOnEmptyText);
    imainwidget->addWidget(iconLine4);

    iconLine5 = new Iconz;
    iconLine5->setPlaceholderText("Clearable");
    iconLine5->setIconPixmap(QPixmap("/home/maxus/EditLine/images/allClear.png"));
    iconLine5->setIconVisibility(Iconz::IconVisibleOnTextPresense);
    iconLine5->setIconClickable(true);
    connect(iconLine5,SIGNAL(iconPressed()),iconLine5,SLOT(clear()));
    imainwidget->addWidget(iconLine5);

    QHBoxLayout *h_layout = new QHBoxLayout;

    btn = new QPushButton;
    btn->setText("OK");
    h_layout->addStretch();
    h_layout->addWidget(btn);

    imainwidget->addLayout(h_layout);

}

void Mainwidget::slotChooseFile()
{


QString iFileName =QFileDialog::getOpenFileName(this,"Open file");
iconLine->setText(iFileName);




}

