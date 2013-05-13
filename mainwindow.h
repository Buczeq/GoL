#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <zycie.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    
private:
    Ui::MainWindow *ui;

    Zycie *zycie;

    QVBoxLayout *layout;
    QHBoxLayout *paseklayout;
    QPushButton *startGuzik;
    QPushButton *stopGuzik;


};

#endif // MAINWINDOW_H
