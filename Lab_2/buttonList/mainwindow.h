#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QTextEdit>
#include <QToolBar>
#include <button.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Конструктор
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void ColorText (QColor color);

private:
    QToolBar* tool;
    button* but;
    QTextEdit* textEd;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
