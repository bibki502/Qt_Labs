#include "button.h"
#include <QPixmap>

//Конструктор
button::button(QWidget *parent) : QToolButton (parent) {
    curCol=Qt::black;

    //Связка клика мышки со слотом
    connect (this, &QToolButton::clicked, this, &button::onButtonClicked);

    //Создание выпадающего меню
    popmenu = new QMenu (this);

    //Создание пунктов меню
    QPixmap pixBlack(16, 16); pixBlack.fill (Qt::black);
    QPixmap pixRed(16, 16); pixRed.fill (Qt::red);
    QPixmap pixGreen(16, 16); pixGreen.fill (Qt::green);
    QPixmap pixBlue(16, 16); pixBlue.fill (Qt::blue);


    QAction* actBlack =  new QAction (QIcon(pixBlack),"Black", this);
    QAction* actRed =  new QAction (QIcon(pixRed),"Red", this);
    QAction* actGreen =  new QAction (QIcon(pixGreen),"Green", this);
    QAction* actBlue =  new QAction (QIcon(pixBlue),"Blue", this);

    popmenu ->addAction(actBlack);
    popmenu ->addAction(actRed);
    popmenu ->addAction(actGreen);
    popmenu ->addAction(actBlue);

    connect (actBlack, &QAction::triggered, this, &button::SelectBlack);
    connect (actRed, &QAction::triggered, this, &button::SelectRed);
    connect (actGreen, &QAction::triggered, this, &button::SelectGreen);
    connect (actBlue, &QAction::triggered, this, &button::SelectBlue);

    //Прикрепляем меню к кнопке
    setMenu(popmenu);
    setPopupMode (QToolButton::MenuButtonPopup);


    //Дефолтная кнопка
    setIcon (QIcon(pixBlack));
}

//Внутренний слот-обработчик клика
void button::onButtonClicked () {
    emit SelectCol(curCol); //отправляем сигнал с текущим соранённым цветом
}

void button::SelectBlack() {
    QPixmap pix(16,16);
    pix.fill(Qt::black);
    setIcon (QIcon (pix));

    curCol=Qt::black;
    emit SelectCol(curCol);
}

void button::SelectRed() {
    QPixmap pix(16, 16);
    pix.fill(Qt::red);
    setIcon(QIcon(pix));

    curCol=Qt::red;
    emit SelectCol(curCol);
}

void button::SelectGreen() {
    QPixmap pix(16, 16);
    pix.fill(Qt::green);
    setIcon(QIcon(pix));

    curCol=Qt::green;
    emit SelectCol(curCol);
}

void button::SelectBlue() {
    QPixmap pix(16, 16);
    pix.fill(Qt::blue);
    setIcon(QIcon(pix));

    curCol=Qt::blue;
    emit SelectCol(curCol);
}


