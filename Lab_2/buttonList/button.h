#ifndef BUTTON_H
#define BUTTON_H

#include <QIcon>
#include <QToolButton>
#include <QMenu> //Для создания выпадающего меню
#include <QAction>
#include <QColor> //Для работы с цветами

class button : public QToolButton //Мой класс наследуется от QToolButton
{
    Q_OBJECT

public:
    //Конструктор
    button(QWidget *parent = nullptr);

    //Метод загрузки 2-х иконок
    void setIcons (const QIcon &Icon1,const QIcon &Icon2 );

private:
    QMenu* popmenu;
    QColor curCol; //переменная для хранения текущего света

signals:
    void SelectCol (QColor color);

private slots:
    void onButtonClicked();
    void SelectBlack ();
    void SelectRed ();
    void SelectGreen ();
    void SelectBlue ();
};

#endif // BUTTON_H

