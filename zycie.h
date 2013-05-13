#ifndef ZYCIE_H
#define ZYCIE_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <QRectF>
#include <QPainter>
#include <qmath.h>

class Zycie : public QWidget
{
    Q_OBJECT
public:
    explicit Zycie(QWidget *parent = 0);

private:
    bool tablicaKomorek[100][100];
    bool tablicaNastepna[100][100];
    QTimer* timer;

    void malujPiksele(QPainter &p);

    QColor m_masterColor;
    int rozmiar;
    int generacja;
    bool Dzialaj(int k, int j);


protected:
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);
    
signals:
private slots:

    void NowaGeneracja();

public slots:

    int interval(); // interval between generations
    void UstawInterval(int time); // set interval between generations
    void ZatrzymajTimer();
    void Start(const int &number = -1); // start
};

#endif // ZYCIE_H
