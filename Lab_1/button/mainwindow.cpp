#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Создание панели инструментов
    tool = new QToolBar (this);
    addToolBar (tool);

    //Создание моей кнопки
    but = new button (this);

    //Иконки
    QIcon icon_1(":/6.jpg");
    QIcon icon_2(":/7.png");

    //Иконки внутрь кнопки
    but->setIcons(icon_1, icon_2 );

    //Размещаем кнопку
    tool->addWidget(but);
}

MainWindow::~MainWindow()
{
    delete ui;
}

