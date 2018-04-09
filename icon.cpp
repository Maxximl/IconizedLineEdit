#include "icon.h"
#include <QStyle>
#include <QLabel>
#include <QWidget>
Iconz::Iconz(QWidget *parent) : QLineEdit(parent), mIconVisibilityMode(IconAlwaysVisible)
{
    mIconLabel = new QLabel(this); //Создаем метку, для того чтобы показать пиктограмму
    connect(this,SIGNAL(textChanged(QString)),this,SLOT(slotTextChanged(QString)),Qt::UniqueConnection);
    mIconLabel->installEventFilter(this);
}

bool Iconz::isIconVisible()
{
    return mIconLabel->isVisible();
}

void Iconz::setIconPixmap(const QPixmap &pPixmap)
{
    mIconLabel->setPixmap(pPixmap);
    updateIconPositionAndSize();
}

void Iconz::setIconTooltip(const QString &pToolTip)
{
    mIconLabel->setToolTip(pToolTip);
}

void Iconz::updateIconPositionAndSize()
{
    mIconLabel->setScaledContents(true);
    mIconLabel->setFixedSize(height(),height());
    QSize iSize = mIconLabel->size();
    mIconLabel->move(rect().right() - iSize.width(), (rect().bottom() + 1 - iSize.height())/2);

    if (mIconLabel->isVisible())
    {
        QMargins iMargins = textMargins();
        iMargins.setRight(mIconLabel->size().width()+1);
        setTextMargins(iMargins);
    }
    else
    {
        //Убрать отступы
        setTextMargins(QMargins(0,0,0,0));
    }
}

void Iconz::setIconVisibility(IconVisibilityMode pIconVisibilityMode)
{
    mIconVisibilityMode = pIconVisibilityMode;
    switch (pIconVisibilityMode)
    {
    case IconAlwaysVisible:
        setIconVisible(true);

        break;
    case IconVisibleOnEmptyText:
    case IconVisibleOnTextPresense:
        slotTextChanged(text());
        break;
    default:
    setIconVisible(true);
        break;
    }
}

void Iconz::slotTextChanged(const QString &pText)
{
    if (IconVisibleOnEmptyText==mIconVisibilityMode)
    {
        setIconVisible(pText.isEmpty());
    }
    else if (IconVisibleOnTextPresense==mIconVisibilityMode)
    {
        setIconVisible(!pText.isEmpty());
    }
}

void Iconz::setIconVisible(bool pIsVisible)
{
    mIconLabel->setVisible(pIsVisible);

}

void Iconz::resizeEvent(QResizeEvent *pEvent)
{
    updateIconPositionAndSize();
    QWidget::resizeEvent(pEvent);
}


bool Iconz::eventFilter(QObject *pObject, QEvent *pEvent)
{
    if(mIsIconClickable)
    {
        if((pObject==mIconLabel) &&(pEvent->type()==QEvent::MouseButtonPress))
        {
        emit iconPressed();
        return true;
        }
    }
    return false;
}
void Iconz::setIconClickable(bool pIsIconClickable)
{
    mIsIconClickable=pIsIconClickable;
    if(mIsIconClickable)
    {
        mIconLabel->setCursor(Qt::PointingHandCursor);
    }
    else
    {
        mIconLabel->setCursor(Qt::ArrowCursor);
    }

}

















