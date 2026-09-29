#include "button.h"

//Конструктор
button::button(QWidget *parent) : QToolButton (parent) {
    isPressed=false;

    //Связка клика мышки со слотом
    connect (this, &QToolButton::clicked, this, &button::onButtonClicked);
}

//Метод закгрузки 2-х иконок
void button::setIcons (const QIcon &Icon1,const QIcon &Icon2 ) {
    icon1=Icon1;
    icon2=Icon2;

    //Ставим 1-ую иконку как стартовую

    setIcon(icon1);
}

//Внутренний слот-обработчик клика
void button::onButtonClicked () {
    isPressed = !isPressed; //Меняем значение на противоположное

    if (isPressed==true){
        setIcon(icon2);
    } else {
        setIcon(icon1);
    }
    emit ifPressed(isPressed);
}

