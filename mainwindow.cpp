#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    zycie(new Zycie(this))
{
    ui->setupUi(this);
    QWidget * q = new QWidget();
    setCentralWidget(q);

    layout = new QVBoxLayout();
    paseklayout= new QHBoxLayout();
    dollayout = new QHBoxLayout();

    pasekParametrow= new QVBoxLayout();
    kontrolki= new QFormLayout();

    startGuzik = new QPushButton("Start");
    stopGuzik = new QPushButton("Stop");


    layout->addLayout(paseklayout);
    layout->addLayout(dollayout);

    dollayout->addWidget(zycie);
    dollayout->addLayout(pasekParametrow);
    pasekParametrow->addLayout(kontrolki);

    nameLabel = new QLabel(tr("&Name:"));
        //nameLabel->setBuddy(nameLineEdit);
    kontrolki->addRow("Nazwa", nameLabel );

    paseklayout->addWidget(startGuzik);
    paseklayout->addWidget(stopGuzik);
    q->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
