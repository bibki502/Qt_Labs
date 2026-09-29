#ifndef BUTTON_H
#define BUTTON_H

#include <QIcon>
#include <QToolButton>

class button : public QToolButton //Мой класс наследуется от QToolButton
{
    Q_OBJECT

public:
    //Конструктор
    button(QWidget *parent = nullptr);

    //Метод загрузки 2-х иконок
    void setIcons (const QIcon &Icon1,const QIcon &Icon2 );

private:
    QIcon icon1;
    QIcon icon2;
    bool isPressed;

signals:
    void ifPressed (bool IfPressed);

private slots:
    void onButtonClicked();
};

#endif // BUTTON_H

