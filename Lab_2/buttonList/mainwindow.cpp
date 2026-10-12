#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    tool->addWidget(but);

    //Создание окна редактора текста
    textEd = new QTextEdit (this);
    setCentralWidget(textEd); //чтобы редактор занял всё окно

    connect (but, &button::SelectCol, this, &MainWindow::ColorText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Реализация слота, который ловит и красит текст
void MainWindow::ColorText (QColor color){
    textEd->setTextColor(color); //встроенная функия которая меняет цвет текста
}

