#ifndef ICON_H
#define ICON_H

#include <QLineEdit>
#include <QEvent>
class QLabel;
class Iconz : public QLineEdit
{
    Q_OBJECT
public:
    enum IconVisibilityMode {
        //Всегда отображать пиктограмму
        IconAlwaysVisible = 0,
        //Отображать при наведении курсора
        IconVisibleOnHover,
        //Показывать когда есть текст
        IconVisibleOnTextPresense,
        //Отображать когда нет текста
        IconVisibleOnEmptyText,
        //Всегда прятать пиктограмму
        IconAlwaysHidden
    };
    void setIconVisibility(IconVisibilityMode pIconVisibilityMode);

    explicit Iconz(QWidget *parent = 0);
public:
bool isIconVisible();
void setIconPixmap(const QPixmap &pPixmap);
void setIconTooltip(const QString &pToolTip);

void setIconClickable(bool pIsIconClickable);
signals:
void iconPressed();
protected:
bool eventFilter(QObject *pObject, QEvent *pEvent);
private:
    void updateIconPositionAndSize();
    void setIconVisible(bool pIsVisible);
    void resizeEvent(QResizeEvent *pEvent);
private:
    QLabel *mIconLabel;
    IconVisibilityMode mIconVisibilityMode;

    bool mIsIconClickable;


private slots:
    void  slotTextChanged(const QString &pText);

};

#endif // ICON_H
